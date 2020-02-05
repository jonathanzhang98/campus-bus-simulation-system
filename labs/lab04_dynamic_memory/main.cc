#include "array_pointer_test.h"

#include <iostream>

using std::cout;
using std::endl;

void Helper() {
  // This will allow you to see the duck_test being deleted
  cout << "Instantiating ArrayPointerTest, which creates my ducks arrays.\n";
  ArrayPointerTest duck_test(3);
  for (int i=1; i<5; i++) {
    duck_test.NameTheDucks(i);
  }
  duck_test.DisplayContents();
  cout << "All my ducks will be destroyed upon exit of helper()." << endl;
}

int main(void) {
  Helper();
  return 0;
}
