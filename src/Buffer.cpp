#include "Buffer.hpp"


buffer::buffer(size_t capacity) : _capacity(capacity), _size(0), _head(0), _tail(0)
{
	_data = new std::string[_capacity];
};

buffer::~buffer()
{
	delete[] _data;
}

void	buffer::push(const std::string &word)
{
	_data[_tail] = word;
	_tail = (_tail + 1) % _capacity;
	if (_size < _capacity)
		_size++;
	else
		_head = (_head + 1) % _capacity;
}

std::string	buffer::pop()
{
	if (_size == 0)
		return ("");
	std::string result = _data[_head];
	_head = (_head + 1) % _capacity;
	_size --;
	return (result);
}

int	buffer::isEmpty()
{
	if (_size > 0)
		return (0);
	return (1);
}
