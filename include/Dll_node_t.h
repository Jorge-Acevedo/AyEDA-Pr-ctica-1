#include <cassert>
#include <iostream>
#include <cstdio>

template <class T>
class <Dll_node_t> 
{
	private:
		<Dll_node_t><T>* 	next_;
		<Dll_node_t><T>* 	prev_;
		T              		data_;

	public:
		<Dll_node_t>();
		<Dll_node_t>(const T& data);

		virtual ~<Dll_node_t>(void);

		void set_next(<Dll_node_t><T>*);
		void set_prev(<Dll_node_t><T>*);

		<Dll_node_t><T>* get_next(void) const;
		<Dll_node_t><T>* get_prev(void) const;

		void set_data(const T& data);
		T get_data(void) const;
		
		ostream& write(ostream& os) const;
};
