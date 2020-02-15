#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

template <class T>
class Vector_t
{
	private:
		T*      v_;
		int     sz_;

	public:

		vector_t(void):v_(NULL),sz_(0) {}

		vector_t(int sz):v_(NULL), sz_(sz) 
		{
			crea_vector();
		}

		~vector_t(void)
		{
			destruye_vector();
		}

		void resize(int sz);

		int get_sz(void) const
		{
			return sz_;
		}
		virtual T get_v(int pos) const;
		virtual T& get_set_v(int pos);
		ostream& write(ostream& os) const;
		istream& read(istream& is);

	private:
		void crea_vector(void)
		{
			v_ = new T[sz_];
		}
		void destruye_vector(void);
};

		
		

	

