/*
  2-clause BSD License

  (c) 2021, thorsten.johannvorderbrueggen@t-online.de

  see https://opensource.org/licenses/BSD-2-Clause
*/

#include "ttenv.h"

static void
function_1()
{
	printf("in function_1\n");
}

static void
function_2()
{
	printf("in function_2\n");
}

static void
function_3()
{
	printf("in function_3\n");
}

static void
function_4()
{
	printf("in function_4\n");
}

static void
fiber_1 (void)
{
	function_1();
}

static void
fiber_2 (void)
{
	function_2();
	function_2();
	function_3();
	function_4();
}

size_t num_fiber_elements = 2;
fiber_element_t fiber_array[] =
{
	{
		.func = fiber_1,
		.sched_param = { .sched_priority = 89,
		},
		.cpu = 0,
		.policy = SCHED_FIFO,
		.dt = MS_TO_NS(10),
	},
	{
		.func = fiber_2,
		.sched_param = { .sched_priority = 90,
		},
		.cpu = 1,
		.policy = SCHED_RR,
		.dt = MS_TO_NS(100),
	}
};

int
main(int argc, char *argv[])
{
	show_clock_resolution();

	if (check_for_rtpreempt() == false)
		puts("NO (RT-)PREEMPT support");
	else
                puts("(RT-)PREEMPT support");

	if (build_sched_table(fiber_array, num_fiber_elements) != 0) {
		puts("can't build_sched_table");
		exit(EXIT_FAILURE);
	}

	if (set_sched_props(fiber_array, num_fiber_elements) != 0) {
		puts("can't set sched prop");
		exit(EXIT_FAILURE);
	}

	fflush(stdout);

	if (start_sched_table(fiber_array, num_fiber_elements) != 0) {
		puts("can't start sched table");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
