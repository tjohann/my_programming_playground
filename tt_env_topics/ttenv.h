/*
  2-clause BSD License

  (c) 2021, thorsten.johannvorderbrueggen@t-online.de

  see https://opensource.org/licenses/BSD-2-Clause
*/

#ifndef _TTENV_H_
#define _TTENV_H_

#ifndef __USE_GNU
#define __USE_GNU
#endif
#define _GNU_SOURCE

// more or less common inc
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <syslog.h>
#include <wait.h>
#include <limits.h>
#include <linux/limits.h>
#include <sysexits.h>
#include <ctype.h>
#include <pthread.h>
#include <bsd/stdlib.h>
#include <sys/utsname.h>
#include <sched.h>
#include <time.h>
#include <sys/times.h>
#include <sys/sysinfo.h>
#include <semaphore.h>
#include <sys/syscall.h>

#define BASE_SAFE_SIZE 1024

#define MS_TO_NS(val) (val * 1000000)
#define NSEC_PER_SEC 1000000000

typedef struct {
	pid_t kernel_tid;
	pthread_t tid;
	void (*func) (void);
	struct sched_param sched_param;
	struct timespec t;
	int policy;
	int cpu;
	int dt;
} fiber_element_t;


/* show clock resolution */
void
show_clock_resolution(void);

/* pre-alloc stack memory */
void
stack_prefault(size_t size);

/* pre-alloc heap memory */
int
heap_prefault(size_t size);

/* check for at least PREEMPT kernel */
bool
check_for_rtpreempt();

/* see https://en.wikipedia.org/wiki/Fiber_%28computer_science%29 */
void *
fiber(void *arg);

/* build table of functions for a fiber */
int
build_sched_table(fiber_element_t fiber_array[], int count);

/* set scheduling properties of a fiber */
int
set_sched_props(fiber_element_t fiber_array[], int count);

/* start a fiber -> wait for pthread_exit */
int
start_sched_table(fiber_element_t fiber_array[], int count);

#endif
