#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stddef.h>

#include "list.h"

struct list_head l;

struct student {
	char name[16];
	int age;
	int sex;
	struct list_head n;
};

int main(int argc, char *argv[])
{
	LIST_HEAD(l);

	// To be finished.
	// ...


	return 0;
}

