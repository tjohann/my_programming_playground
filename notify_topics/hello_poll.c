/*
 * some stuff around poll of a gpio pin@raspi2
 */

#include <stdio.h>
#include <poll.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


/* gpio pin@raspi 2 -> for poweroff notification*/
#define POWEROFF_BUTTON  26  /* pin 37 */
#define GPIO_VALUE_PATH "/sys/class/gpio/gpio%d/value"

int gpio_fd_open(int pin)
{
#define READ_MAX_LEN 30
	char str[READ_MAX_LEN];
	memset(&str, 0, READ_MAX_LEN);

	snprintf(str, READ_MAX_LEN, GPIO_VALUE_PATH, pin);
	printf("open file: %s \n", str);

	int fd = open(str, O_RDONLY);
	if (fd < 0)
		goto error;

	return fd;
error:
	perror("error opening gpio file");

	return -1;
}


int main(void)
{
	int fd = gpio_fd_open(POWEROFF_BUTTON);
	if (fd < 0)
		exit(EXIT_FAILURE);

//	char *buf[MAX_BUF];
//	ssize_t len;
	int ready;

	struct pollfd fdset;
	fdset.fd = fd;
	fdset.events =  POLLPRI | POLLERR | POLLHUP | POLLNVAL;

	for (;;) {
		ready = poll(&fdset, 1, -1);
		if (ready < 0) {
			perror("error poll");
			continue;
		}

		if (fdset.revents & POLLIN) {
			printf("read value -> POLLIN... \n");
		}

		printf("other than POLLIN ... \n");
	}


	close(fd);

	exit(EXIT_SUCCESS);
}
