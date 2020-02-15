#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "Dll_t.hpp"

template <class T>
class Stack_l_t{
	private:
		Dll_t<T>    l_;
	public:	
		Stack_l_t(void):l_() {}

		~Stack_l_t(void) {}

		bool empty(void)
		{
			return l_.empty();
		}

		T top(void);

		void pop(void);

		void push(T dato);

		ostream& write(ostream& os);
};

