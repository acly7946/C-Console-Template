#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

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
			"  -h, --help	 Show help message and quit\n"
			"  -V, --version  Show version number and quit\n",
			NAME);
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("%s %s (%s License)\n", NAME, VERSION, LICENSE);
	exit(EXIT_SUCCESS);
}
