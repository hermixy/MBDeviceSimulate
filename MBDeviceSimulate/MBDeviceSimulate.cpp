
#include "stdafx.h"

#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <signal.h>

#include "Controller.h"

void signal_callback_handler(int signum)
{
	exit(signum);
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((int) time(NULL));

	Controller controller;

	int status = controller.initialize();
	printf("init = %d\n", status);

	if (status == 0) {
		signal(SIGINT, signal_callback_handler);
		while (1) {
			controller.simulate();
			printf("----\n");
			Sleep(10000);
		}
	}

	return 0;
}

