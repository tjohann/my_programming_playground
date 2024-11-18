/*
 * up to side 11
 */

/*
 * import std;
 * or
 * import <print>;
 * wont be fully supported with gcc-14.2
 */

#include <print>
#include <string>
#include <iostream>

namespace my_func {
	// no need to use std::
	using namespace std;

	void foo(void)
	{
		println("In {}", __FUNCTION__);
	}
}

using namespace my_func;

int main(void)
{
	std::string s {"Hallo \"Professional C++\" Buch :-)"};
	std::println("{}", s);

	// std::cerr
	std::println(std::cerr, "Error code: {}", -1);

	// within the namespaces using scope resolution operator
	my_func::foo();
	// using directive
	foo();

	exit (EXIT_SUCCESS);
}
