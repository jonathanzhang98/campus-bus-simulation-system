#ifndef DERIVED_H_
#define DERIVED_H_

#include "object.h"

using std::cout;
using std::endl;

class DerivedClass : public ObjectClass {
public:
  void Print() {
    cout << "in DerivedClass... " << endl;
    //cout << "var_a_ " << var_a_ << endl;
    //cout << "var_b_ " << var_b_ << endl;
    //cout << "object var_a_ " << ObjectClass::var_a_ << endl;
    //cout << "object var_b_ " << ObjectClass::var_b_ << endl;
    ObjectClass::Print();
  }
private:
  //int var_a_;
  //int var_b_;
};

#endif
