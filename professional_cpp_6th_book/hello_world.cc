/*
 * up to side 15
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
#include <cstddef>

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

	/*
	 * std::byte
	 * it's not a character nor a arithmetic type
	 * only for bit operations!
	 * -> cast for println needed
	 */
	std::byte my_byte {10};
	std::println("Value of byte: {}", to_integer<int>(my_byte));
	// note: won't work!
	//if (my_byte != 0)
	//	std::println("Value of byte: {}", to_integer<int> my_byte);


	exit (EXIT_SUCCESS);
}
