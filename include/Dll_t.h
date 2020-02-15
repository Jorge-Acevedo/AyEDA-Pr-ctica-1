#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include "Dll_node_t.hpp"


template <class T>
class Dll_t 
{
    private:	
			Dll_node_t<T>*  head_;
			Dll_node_t<T>*  tail_;
			int             sz_;

    public:
			Dll_t(void);
			virtual ~Dll_t(void); 

			void insert_tail(Dll_node_t<T>*);
			void insert_head(Dll_node_t<T>*);

			Dll_node_t<T>* extract_tail(void);
			Dll_node_t<T>* extract_head(void);

			Dll_node_t<T>* get_tail(void);
			Dll_node_t<T>* get_head(void);

			bool empty(void);

			void remove(Dll_node_t<T>*);

			int get_size(void);

			ostream& write(ostream& os);
};

