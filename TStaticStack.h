#ifndef T_STATIC_STACK
#define T_STATIC_STACK

#include <stdexcept>
#include <ostream>




template<typename T, size_t CAP> // CAP - �� ����� capacity (�������)
class TStaticStack
{
private:
	T mArr[CAP];
	int mTop;

public:
	// ����������� �� ���������
	TStaticStack() :mArr{}, mTop { -1 } {}


	// ��������� ���� �� �������
	bool empty() const noexcept { return mTop == -1; }
	// ��������� �� ������ ���������� �����
	bool full() const noexcept { return mTop + 1 == CAP; }


	// ���������� ������� ������ �����
	size_t size() const noexcept { return mTop + 1; }
	// ���������� �������
	size_t capacity() const noexcept { return CAP; }


	// ��������� ������� �� ������� �����
	void push(const T& elem)
	{
		if (full())
			throw std::out_of_range{ "stack overflow" };

		mArr[++mTop] = elem;
	}
	// ������� ������� � ������� �����
	T pop()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		return mArr[mTop--];
	}
	// ��������� �������� �������� �� ������� �����
	T top()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		return mArr[mTop];
	}
};





#endif // T_STATIC_STACK
