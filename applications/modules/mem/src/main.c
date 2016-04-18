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


int bss_var;
int data_var0=1;


int proc_mem(void)
{
	printf("below are addresses of types of process's mem\n");
	printf("Text location:\n");
	printf("\tAddress of main(Code Segment):%p\n", proc_mem);
	printf("____________________________\n");

	int stack_var0=2;
	printf("Stack Location:\n");
	printf("\tInitial end of stack:%p\n", &stack_var0);

	int stack_var1=3;
	printf("\tnew end of stack:%p\n", &stack_var1);
	printf("____________________________\n");
	printf("Data Location:\n");
	printf("\tAddress of data_var(Data Segment):%p\n", &data_var0);

	static int data_var1=4;
	printf("\tNew end of data_var(Data Segment):%p\n",&data_var1);
	printf("____________________________\n");
	printf("BSS Location:\n");

	printf("\tAddress of bss_var:%p\n",&bss_var);
	printf("____________________________\n");

	char *b = sbrk((ptrdiff_t)0);
	printf("Heap Location:\n");
	printf("\tInitial end of heap:%p\n",b);

	brk(b+4);
	b=sbrk((ptrdiff_t)0);
	printf("\tNew end of heap:%p\n",b);

	return 0;
}

int max_alloc(void)
{
	int MB=0;

	while(malloc(1<<20))
		++MB;

	printf("Maximun allocated %d MB\n", MB);
	return 0;
}

typedef int (*pFunc)(void);

struct sItems{
	char description[128];
	pFunc f;
};

struct sItems gItems[] = {
	{
		.description = "try max allocate memory",
		.f = max_alloc,
	},
	{
		.description = "check process memory",
		.f = proc_mem,
	},
};

static void usage(void)
{
	int i;
	int num = sizeof(gItems) / sizeof(gItems[0]);

	printf("usage: \n\t./a.out -c <choice num>\n");

	for (i = 0; i < num; i++)
		fprintf(stderr, "\t\t%d: %s\n", i, gItems[i].description);

	exit(1);
}

int main(int argc, char *argv[])
{
	int c = -1;
	int choice;

	static struct option long_options[] = {
		{"type", 1, 0, 't'},
		{"input", 1, 0, 'i'},
	};

	while (1) {
		int option_index = -1;

		c = getopt_long(argc, argv, "hc:",
				long_options, &option_index);
		if (c == -1)
			break;

		switch(c) {
			case 'c':
				choice = strtol(optarg, NULL, 10);
				if (choice < 0 ||
					choice >= sizeof(gItems) / sizeof(gItems[0])) {
					printf("Invalid choice[%d]\n", choice);
					usage();
				}

				gItems[choice].f();

				break;

			default:
				usage();
		}
	}

	return 0;
}

