#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH "/usr/bin/true"
#define ARGV0 "true"
#define CWD "/tmp"

int
main(int argc, char *argv[]) {
	char *cwd = realpath(CWD, NULL);

	printf("spec:image-exec "
	       "subject.pid=%i "
	       "image.path="PATH" "
	       "argv="ARGV0" "
	       "cwd=%s\n",
	       getpid(), cwd);
	fflush(stdout);

	chdir(CWD);
	execl(PATH, ARGV0, (char*)0);
	perror("exec");

	return 0;
}

