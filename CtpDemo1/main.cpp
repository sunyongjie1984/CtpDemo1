#include <iostream>
#include "MyTraderSpi.h"
#ifdef _linux
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "frame_app.h"
#include "event.h"
//#include "log_interface.h"
//#include "log_impl.h"
//#include "ts_app.h"
#else
#include <Windows.h>
#endif

int32_t main(int32_t argc, char** argv)
{
    pFrame_App->run(argc, argv);
    /*

    // 报单录入请求
    //pUserSpi->ReqOrderInsert(INSTRUMENT_ID, 4336.0, 1);
    // MySleep(1);
    // pUserSpi->ReqQryInstrument();
    // MySleep(1);
    // pUserSpi->ReqQryOrder();
    // MySleep(2);

    pUserApi->Join();
    // pUserApi->Release();

    */
    return 0;
}
