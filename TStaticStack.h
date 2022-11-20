#ifndef T_STATIC_STACK
#define T_STATIC_STACK

#include <stdexcept>
#include <ostream>




template<typename T, size_t CAP> // CAP - от слова capacity (ёмкость)
class TStaticStack
{
private:
	T mArr[CAP];
	int mTop;

public:
	// Конструктор по умолчанию
	TStaticStack() :mArr{}, mTop { -1 } {}


	// Проверяет стек на пустоту
	bool empty() const noexcept { return mTop == -1; }
	// Проверяет на полное заполнение стека
	bool full() const noexcept { return mTop + 1 == CAP; }


	// Возвращает текущий размер стека
	size_t size() const noexcept { return mTop + 1; }
	// Возвращает ёмкость
	size_t capacity() const noexcept { return CAP; }


	// Добавляет элемент на вершину стека
	void push(const T& elem)
	{
		if (full())
			throw std::out_of_range{ "stack overflow" };

		mArr[++mTop] = elem;
	}
	// Удаляет элемент с вершины стека
	T pop()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		return mArr[mTop--];
	}
	// Проверяет значение элемента на вершине стека
	T top()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		return mArr[mTop];
	}
};





#endif // T_STATIC_STACK
