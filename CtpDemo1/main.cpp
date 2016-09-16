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
#include "event_id.h"
//#include "log_interface.h"
//#include "log_impl.h"
//#include "ts_app.h"
#else
#include <Windows.h>
#endif

int32_t main(int32_t argc, char** argv)
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    pFrame_App->run(argc, argv);
    return 0;
}
