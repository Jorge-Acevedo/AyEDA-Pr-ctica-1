#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "round_vector_t.hpp"

#define MAX_STACK_SIZE 20

using namespace std;

namespace AED {

	template <class T>
	class queue_v_t{
	private:

		round_vector_t<T> v_;
		int         front_;
		int         back_;

	public:	
		queue_v_t(int max_sz):
		v_(max_sz),
		front_(0),
		back_(-1) {}

		queue_v_t(void):
		v_(MAX_STACK_SIZE),
		front_(0),
		back_(-1) {}

		~queue_v_t(void) {}

		bool empty(void){
			return (back_ < front_);
		}

		bool full(void){
			return (size() >= v_.get_sz() - 1);
		}

		int size(void)
		{
		 	return back_ - front_ + 1;
		}

		T front(void){

			assert(!empty());
			return v_.get_v(front_);
		}

		T back(void){

			assert(!empty());
			return v_.get_v(back_);
		}

		void pop(void){

			assert(!empty());			
			front_++;
		}

		void push(T dato){

			assert(!full());

			back_++;
			v_.get_set_v(back_) = dato;
		}

		ostream& write(ostream& os){

			for(int i = back_; i >= front_; i--)
				os << setw(4) << v_.get_v(i);  

			os << endl;

 
			return os;
		}

	};
}
