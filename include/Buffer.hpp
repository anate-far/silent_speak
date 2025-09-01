#ifndef	BUFFER_HPP
# define	BUFFER_HPP

#include <iostream>
#include <string>

class buffer{
	private :
		size_t	_capacity;
		size_t	_size;
		size_t	_head;
		size_t	_tail;
	public :
		std::string *_data;
		buffer(size_t capacity);
		~buffer();
		void push(const std::string &word);
		std::string pop();
		int	isEmpty();

};

#endif
