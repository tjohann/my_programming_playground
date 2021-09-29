/*
 * some stuff around memfd topics
 *
 * initialy taken from the man page:
 * https://man7.org/linux/man-pages/man2/memfd_create.2.html
 */

#define _GNU_SOURCE
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define err_exit(msg) do { perror(msg); exit(EXIT_FAILURE);	\
	} while (0)


int main(int argc, char *argv[])
{
	int fd;
	unsigned int seals;

	if (argc != 2) {
		fprintf(stderr, "%s /proc/PID/fd/FD\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		err_exit("open");

	seals = fcntl(fd, F_GET_SEALS);
	if (seals == -1)
		err_exit("fcntl");

	printf("Existing seals:");
	if (seals & F_SEAL_SEAL)
		printf(" SEAL");
	if (seals & F_SEAL_GROW)
		printf(" GROW");
	if (seals & F_SEAL_WRITE)
		printf(" WRITE");
	if (seals & F_SEAL_FUTURE_WRITE)
		printf(" FUTURE_WRITE");
	if (seals & F_SEAL_SHRINK)
		printf(" SHRINK");
	printf("\n");

	/* Code to map the file and access the contents of the
	   resulting mapping omitted. */
	exit(EXIT_SUCCESS);
}
