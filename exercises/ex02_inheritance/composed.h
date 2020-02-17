#ifndef COMPOSED_H_
#define COMPOSED_H_

using std::cout;
using std::endl;

class ComposedClass {
public:
  void Print() {
    cout << "in ComposedClass... " << endl;
    //cout << "var_a_ " << var_a_ << endl;
    //cout << "var_b_ " << var_b_ << endl;
    //cout << "object var_a_ " << object_.var_a_ << endl;
    //cout << "object var_b_ " << object_.var_b_ << endl;
    object_.Print();
  }
protected:
  // int var_b_;
private:
  ObjectClass object_;
  // int var_a_;
};

#endif
