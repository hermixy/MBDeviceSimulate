
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
	printf("init = %d\n", controller.initialize());


	if (status == 0) {
		signal(SIGINT, signal_callback_handler);
		while (1) {
			printf("invoke\n");
			controller.simulate();
			Sleep(5000);
		}
	}

	return 0;
}

