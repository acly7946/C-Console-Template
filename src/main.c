#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM "a.out"
#define VERSION "0.0.0"
#define AUTHOR "AUTHOR"

static void usage(void);

int main(int argc, char *argv[])
{
	int optc;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
	};

	while((optc = getopt_long(argc, argv, "hV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'V':
				printf("%s, %s, %s\n", PROGRAM, VERSION, AUTHOR);
				exit(EXIT_SUCCESS);

			default:
				usage();
				break;
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
	"Usage: %s [-hV]\n"
	"\n"
	"  -h, --help	 Print this help message and immediately quit\n"
	"  -V, --version  Print version number and immediately quit\n"
	, PROGRAM);
	exit(EXIT_FAILURE);
}
