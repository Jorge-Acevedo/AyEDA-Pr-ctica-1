#include "Dll_t.h"

template <class T>
Dll_t<T>::Dll_t(void):head_(NULL), tail_(NULL),sz_(0) {}

template <class T>
Dll_t<T>::~Dll_t(void) 
{
    Dll_node_t<T>* aux = NULL;
    while (head_ != NULL) 
    {
      aux = head_;
      head_ = head_->get_next();
      delete aux;
      aux = NULL;
    }
    sz_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

template <class T>
bool Dll_t<T>::empty(void) 
{
  if (head_ == NULL)
  {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } 
  return false;
}

template <class T>
void Dll_t<T>::insert_head(Dll_node_t<T>* nodo) 
{
  assert(nodo != NULL);
  if (empty()) 
  {
      head_ = nodo;
      tail_ = head_;
  } 
  else 
  {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T>
void Dll_t<T>::insert_tail(Dll_node_t<T>* nodo) 
{
  assert(nodo != NULL);
  if (empty()) 
  {
      head_ = nodo;
      tail_ = head_;
  } 
  else 
  {
      tail_->set_next(nodo);
      nodo->set_prev(tail_);
      tail_ = nodo;
  }
  sz_++;
}

template <class T>
Dll_node_t<T>* Dll_t<T>::extract_tail(void) 
{
  assert(!empty());
  Dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();

  if (tail_ != NULL)
      tail_->set_next(NULL);
  else
      head_ = NULL;
  sz_--;
  
  aux->set_next(NULL);
  aux->set_prev(NULL);

  return aux;
}

template <class T>
Dll_node_t<T>* Dll_t<T>::extract_head(void) 
{
  assert(!empty());

  Dll_node_t<T>* aux = head_;
  head_ = head_->get_next();

  if (head_)
      head_->set_prev(NULL);
  else
      tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T>
Dll_node_t<T>* Dll_t<T>::get_head(void) 
{
  return head_;
}

template <class T>
Dll_node_t<T>* Dll_t<T>::get_tail(void) 
{
  return tail_;
}

template <class T>
ostream& Dll_t<T>::write(ostream& os) 
{    
  Dll_node_t<T>* aux = head_;

  while (aux != NULL) 
  {
      aux->write(os);
      aux = aux->get_next();
  }

  return os;
}

template <class T>
void Dll_t<T>::remove(Dll_node_t<T>* nodo) 
{        
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
      nodo->get_prev()->set_next(nodo->get_next());
  else
      head_ = nodo->get_next();

  if (nodo->get_next() != NULL)
      nodo->get_next()->set_prev(nodo->get_prev());
  else
      tail_ = nodo->get_prev();

  delete nodo;
  sz_--;
}

template <class T>
int Dll_t<T>::get_size(void) 
{
    return sz_;
}	