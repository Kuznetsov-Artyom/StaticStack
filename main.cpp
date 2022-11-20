#include <iostream>
#include "TStaticStack.h"





int main()
{
	TStaticStack<int, 10> stack;


	std::cout << stack.empty() << ' ' << stack.full() << '\n';

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i + 1 << '\n';
		stack.push(i + 1);
	}


	try
	{
		stack.push(123);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
	std::cout << stack.empty() << ' ' << stack.full() << '\n';

	for (int i = 0; i < 10; ++i)
		std::cout << stack.pop() << '\n';

	std::cout << stack.empty() << ' ' << stack.full() << '\n';



	return 0;
}