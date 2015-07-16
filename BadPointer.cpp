#include <iostream>

using namespace std;

class A {
    public:
    string data;
};

int main()
{
  A *p;
  p = new(A);
  p -> data = "878e880769f005b613245a8b54f7ca6c";
  return 0;
}
