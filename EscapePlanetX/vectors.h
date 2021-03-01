#pragma once
#include <iostream>

template<typename T>
class vector2
{
public:
	T x, y;


	static vector2& get() 
	{
		vector2 instance;
		return instance;
	}

	vector2()
	{

	}


	vector2(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	~vector2()
	{

	}

private:

	



};


template <typename T>
vector2<T> operator +(const vector2<T>& left, const vector2<T>& right)
{
	return vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
vector2<T> operator -(const vector2<T>& left, const vector2<T>& right)
{
	return vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
vector2<T> operator /(const vector2<T>& left, T value)
{
	return vector2<T>(left.x/value, left.y/value);
}


