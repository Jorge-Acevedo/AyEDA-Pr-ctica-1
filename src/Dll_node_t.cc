#include "Dll_node_t.h"

template <class T>
Dll_node_t<T>::Dll_node_t():next_(NULL), prev_(NULL),data_() {}

template <class T>
Dll_node_t<T>::Dll_node_t(const T& data):next_(NULL),prev_(NULL),data_(data) {}

template <class T>
Dll_node_t<T>::~Dll_node_t(void) 
{
	prev_ = NULL;
	next_ = NULL;
}

template <class T>
void Dll_node_t<T>::set_next(Dll_node_t<T>* next)
{
	next_ = next;
}

template <class T>
Dll_node_t<T>* Dll_node_t<T>::get_next(void) const
{
	return next_;
}

template <class T>
void Dll_node_t<T>::set_prev(Dll_node_t<T>* prev)
{
	prev_ = prev;
}

template <class T>
Dll_node_t<T>* Dll_node_t<T>::get_prev(void) const
{
	return prev_;
}

template <class T>
void Dll_node_t<T>::set_data(const T& data)
{
	data_ = data;
}

template <class T>
T Dll_node_t<T>::get_data(void) const
{
	return data_;
}

template <class T>
ostream& Dll_node_t<T>::write(ostream& os) const
{
	os << data_;
	return os;
}

