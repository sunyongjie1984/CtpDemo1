///框架类实现
/***********************************************************************
系统名称: 
模块名称:
文 件 名: frame_app.cpp
功能说明:
作    者:
开发日期: 2013-7-16   16:34:03
修改记录:
***********************************************************************/
#include <execinfo.h>
#include <ucontext.h>

#include <event_id.h>

#include "frame_app.h"


CFrameApp* pFrame_App = 0;

int32_t CFrameApp::init(int32_t argc, char** argv)
{
    /* 1.解析命令行参数 */
    int32_t iRet = COPTIONS->open(argc, argv);
    if (iRet != 0)
    {
        show_usage();
        exit(0);
    }
    /* 是否显示帮助信息 */
    if (COPTIONS->getHelpOpt())
    {
        show_usage();
        exit(0);
    }
    /* 是否显示版本信息 */
    if (COPTIONS->getVersionOpt())
    {
        show_version();
        exit(0);
    }
    /* 是否关闭进程 */
    if (COPTIONS->getShutdownOpt())
    {
        shutdown();
        exit(0);
    }
    /* 是否启动后台进程 */
    if (COPTIONS->getDaemonOpt())
    {
        daemon();
    }

    /* 不管前后台，均创建pid文件，屏蔽启动多个实例 */
    create_pid_file();

    /* 2.加载配置文件 */
    iRet = CCONFIG->open(COPTIONS->getCfgFileName());
    if (iRet != 0)
    {
        fprintf(stderr, "[%s:%d]open configuration file failed.\n", __FILE__, __LINE__);
        exit(-1);
    }

    /* 从配置文件读取主机名称 */
    const char* chValue = CCONFIG->GetString("APP", "app_name", NULL);
    if (chValue == NULL)
    {
        fprintf(stderr, "[%s:%d]get [APP] app_name failed.\n", __FILE__, __LINE__);
        exit(-1);
    }
    memcpy(m_chAppName, chValue, strlen(chValue));

    /* 3.初始化日志 */
    iRet = CLOG->open(COPTIONS->getLogType());
    if (iRet != 0)
    {
        fprintf(stderr, "[%s:%d]open log file failed.\n", __FILE__, __LINE__);
        exit(-1);
    }

    return 0;
}

int32_t CFrameApp::fini()
{
    /* 删除pid文件 */
    delete_pid_file();

    return 0;
}

const char* CFrameApp::version() const
{
    return FRAME_APP_VERSION;
}

const char* CFrameApp::getAppName() const
{
    return m_chAppName;
}

CLogInterface* CFrameApp::Log()
{
    return m_lpLog;
}

CConfigInterface* CFrameApp::Config()
{
    return m_lpConfig;
}

COptionsInterface* CFrameApp::Options()
{
    return m_lpOptions;
}

//////////////////////////////////////////////////////////////////////////
CFrameApp::CFrameApp()
: m_iShutdown(0)
, m_iPidFd(0)
, m_lpLog(CLOG)
, m_lpConfig(CCONFIG)
, m_lpOptions(COPTIONS)
{
    memset(m_chAppName, '\0', sizeof(m_chAppName));
    this->regist_app();
}

CFrameApp::~CFrameApp()
{
}

void CFrameApp::run(int32_t argc, char** argv)
{
    /* 1.初始化基类 */
    CFrameApp::init(argc, argv);

    /* 2.注册信号函数 */
    CFrameApp::regist_signal();

    /* 3.初始化派生类 */
    if (0 == this->init(argc, argv))
    {
        /* 4.主线程工作函数 */
        // CFrameApp::work();
        work();
    }

    /* 5.结束派生类 */
    this->fini();

    /* 6.结束基类 */
    CFrameApp::fini();

    return;
}

void CFrameApp::stop()
{
    m_iShutdown = 1;
    return;
}

//////////////////////////////////////////////////////////////////////////
void CFrameApp::regist_app() const
{
    ::pFrame_App = const_cast<CFrameApp*>(this);
    return;
}

/* 终止进程函数 */
static void sigHandler(int sig, siginfo_t* info, void* secret)
{
    /* 终止主线程 */
    pFrame_App->stop();

    /* 无效存储访问：把堆栈写入文件 */
    if (SIGSEGV == sig)
    {
        ucontext_t* uc = (ucontext_t*)secret;
        ERROR(COMMON_ERROR_MAIN_CORE_DUMP, "signal[%d], faulty address is:%p, from:%p", sig, info->si_addr, uc->uc_mcontext.gregs[REG_RIP]);

        void* addr[16];
        int32_t size = backtrace(addr, 16);
        char** msg = backtrace_symbols(addr, size);
        for (int i = 0; i < size; ++i)
        {
            ERROR(COMMON_ERROR_MAIN_CORE_DUMP, "core dump", "%s", msg[i]);
        }

        //free(msg);
        _exit(-1);
    }

    return;
}

void CFrameApp::regist_signal() const
{
    signal(SIGHUP, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);

    /* 初始化信号集 */
    struct sigaction act;
    sigemptyset(&act.sa_mask);

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigHandler;

    /* 注册信号捕捉函数：ctrl+c、kill、无效存储访问 */
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGTERM, &act, NULL);
    if (COPTIONS->getCoreOpt())
    {
        sigaction(SIGSEGV, &act, NULL);
    }

    return;
}

void CFrameApp::work() const
{
    /* 主线程等待系统终止信号 */
    while (m_iShutdown == 0)
    {
        usleep(100*1000);
    }
    return;
}

void CFrameApp::show_usage() const
{
    fprintf(stderr, "Usage: %s [-h][-v][-s][-c][-d][-m][-f <config_file>][-t <app_type>][-n <number>][-o <output_type>][-l <output_level>][-r <reserve>]\n", COPTIONS->getProName());
    fprintf(stderr, "h -- Show help information.\n");
    fprintf(stderr, "v -- Show version information.\n");
    fprintf(stderr, "s -- Stop the process.\n");
    fprintf(stderr, "c -- Forbid core dump file.\n");
    fprintf(stderr, "d -- Run as daemon.\n");
    fprintf(stderr, "m -- Set the smoke test.\n");
    fprintf(stderr, "f -- Set the config file.\n");
    fprintf(stderr, "t -- Set the app type.\n");
    fprintf(stderr, "n -- Set the process number.\n");
    fprintf(stderr, "o -- Set the output type.\n");
    fprintf(stderr, "     0  - STD_OUT [default]\n");
    fprintf(stderr, "     1  - LOG_FILE\n");
    fprintf(stderr, "l -- Set the output level.\n");
    fprintf(stderr, "     0  - EMERG - not to use\n");
    fprintf(stderr, "     1  - ALERT - not to use\n");
    fprintf(stderr, "     2  - CRIT\n");
    fprintf(stderr, "     3  - ERROR\n");
    fprintf(stderr, "     4  - WARNING\n");
    fprintf(stderr, "     5  - NOTICE\n");
    fprintf(stderr, "     6  - INFO\n");
    fprintf(stderr, "     7  - DEBUG [default]\n");
    fprintf(stderr, "r -- Set reserved option\n");
    return;
}

void CFrameApp::show_version() const
{
    fprintf(stderr, "\n------------------------------------------------------\n");
    fprintf(stderr, "NEEQ Inc. Copyright (c) 2013-2018 All Rights Reserved\n");
    fprintf(stderr, "Frame_app Version: %s\n", FRAME_APP_VERSION);
    fprintf(stderr, "%s Version: %s", COPTIONS->getProName(), this->version());
    fprintf(stderr, "\n------------------------------------------------------\n\n");

    return;
}

void CFrameApp::shutdown() const
{
    if (fork() != 0) exit(0);
    setsid();

    int iRet = execlp("killall", "killall", COPTIONS->getProName(), NULL);
    if (iRet == -1)
    {
        fprintf(stderr, "Kill the process failed, error:[%d]\n", errno);
    }

    return;
}

void CFrameApp::daemon()
{
    /* 父进程退出 */
    if (fork() != 0) exit(0);
    setsid(); /* 创建新会话，使子进程免受父进程退出影响 */

    /* 后台进程需要屏蔽无用的屏幕日志输出 */
    int fd = open("/dev/null", O_RDWR, 0);
    if (fd != -1)
    {
        dup2(fd, STDIN_FILENO); /* 后者被重定向到前者上 */
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }

    return;
}

void CFrameApp::create_pid_file()
{
    /* 创建进程pid文件 */
    char chPidFile[256];
    sprintf(chPidFile, "/tmp/%s#%d.pid", COPTIONS->getProName(), COPTIONS->getProNum());
    m_iPidFd = open(chPidFile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (m_iPidFd < 0)
    {
        fprintf(stderr, "Open pid file failed.\n");
        exit(-1);
    }

    /* 把pid文件锁上 */
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    if(fcntl(m_iPidFd, F_SETLK, &lock) < 0)
    {
        fprintf(stderr, "There has been another instance already.\n");
        exit(-1);
    }

    /* 写进程号到文件 */
    char chMsg[64];
    sprintf(chMsg, "%d", (int)getpid());
    int count = write(m_iPidFd, chMsg, strlen(chMsg));
    if (count != (int)strlen(chMsg))
    {
        fprintf(stderr, "Failed to write: %d-%d\n", count, (int)strlen(chMsg));
        exit(-1);
    }

    return;
}

void CFrameApp::delete_pid_file() const
{
    if (m_iPidFd < 0) return;

    /* 把pid文件解锁 */
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    if (fcntl(m_iPidFd, F_SETLK, &lock) < 0)
    {
        fprintf(stderr, "Unlock pid file failed.\n");
    }

    /* 关闭文件 */
    if (m_iPidFd > 0)
    {
        close(m_iPidFd);
    }

    /* 清除进程pid文件 */
    char chPidFile[256];
    sprintf(chPidFile, "/tmp/%s#%d.pid", COPTIONS->getProName(), COPTIONS->getProNum());
    unlink(chPidFile);

    return;
}
