#include "duck.h"

const int kMaxDuckCount = 10;

class ArrayPointerTest {
public:
  ArrayPointerTest(int count = kMaxDuckCount);
  ~ArrayPointerTest();
  void NameTheDucks(int array_number);
  void DisplayContents();

private:
  Duck ducks1_[kMaxDuckCount];
  Duck * ducks2_;
  Duck * ducks3_[kMaxDuckCount];
  Duck ** ducks4_;
  int count_;
};
