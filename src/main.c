#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM "a.out"
#define VERSION "0.0.0"
#define AUTHOR "AUTHOR"
#define LICENSE "MIT"

static void usage(void);
static void version(void);

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
				version();

			default:
				usage();
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

static void version(void)
{
	printf(
	"%s %s\n"
	"Copyright (c) %s %s\n"
	"%s License\n"
	, PROGRAM, __DATE__ + 7, VERSION, AUTHOR, LICENSE);
	exit(EXIT_SUCCESS);
}
