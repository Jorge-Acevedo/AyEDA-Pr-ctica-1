#include "Vector_t.h"

template <class T>
void Vector_t::resize(int sz)
{
  destruye_vector();
  sz_ = sz;
  crea_vector();
}

template <class T>
virtual T Vector_t::get_v(int pos) const
{  
  assert((pos < sz_) && ((pos >= 0)));
  return v_[pos];
}

template <class T>
virtual T& Vector_t::get_set_v(int pos)
{
  assert((pos < sz_) && ((pos >= 0)));
  return v_[pos];
}

template <class T>
ostream& Vector_t::write(ostream& os) const
{	
  os << setw(5) <<  sz_ << endl;
  os << endl;
  for(int i = 0; i < sz_; i ++)
  {
    v_[i].write(os);
    os << " ";
  }
  return os;
}

template <class T>
istream& Vector_t::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for(int i = 0; i < sz_; i ++)
    is >> v_[i];
  return is;
}

template <class T>
void Vector_t::destruye_vector(void)
{
  if (v_ != NULL)
  {
    delete [] v_;
    v_ = NULL;
  }
}

template <>
ostream& Vector_t<double>::write(ostream& os) const
{
  os << setw(6) <<  sz_ << endl;
  for(int i = 0; i < sz_; i ++)
    os << setw(8) << fixed << setprecision(2) << v_[i] << " ";
  return os;
}

template <>
ostream& Vector_t<int>::write(ostream& os) const
{
  os << setw(8) <<  sz_ << endl;
  for(int i = 0; i < sz_; i ++)
    os << setw(8)  << v_[i] << " ";
  return os;
}