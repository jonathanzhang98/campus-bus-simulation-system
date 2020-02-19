#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>

using std::cout;
using std::endl;

class ObjectClass {
public:
  ObjectClass() : var_a_(10), var_b_(15) {}
  ObjectClass(int a, int b) : var_a_(a), var_b_(b) {}
  void Print() {
    cout << "in ObjectClass. ";
    cout << "priv, prot =  " << var_a_ << ' '<< var_b_ << endl;
  }
private:
  int var_a_;
protected:
  int var_b_;
};

#endif
