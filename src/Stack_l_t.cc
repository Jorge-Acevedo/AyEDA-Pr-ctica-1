#include "Stack_l_t.h"

T Stack_l_t::top(void)
{
  assert(!empty());
  Dll_node_t<T>* node = l_.get_head();
  T data = node->get_data();
  return (data);
}

void  Stack_l_t::pop(void)
{
  assert(!empty());			
  Dll_node_t<T>* node = l_.extract_head();
  delete node;
}

void Stack_l_t::push(T dato)
{
  Dll_node_t<T>* node = new Dll_node_t<T>(dato);
  l_.insert_head(node);
}

ostream& Stack_l_t::write(ostream& os)
{  
  Dll_node_t<T>* aux = l_.get_head();
  while(aux != NULL)
  {
    std::cout << " │ " << setw(2)<< aux->get_data() << "  │" << endl;
    aux = aux->get_next();
  }
  std::cout << " └─────┘" << endl; 
}
