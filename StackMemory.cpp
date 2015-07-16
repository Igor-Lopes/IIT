#include <iostream>

using namespace std;

class Stack{

  public: void showResult(double d){
    double result;
    result = 1 - d;
    cout << "The result is:" << result << endl;
  }

};


int main (){
Stack s;
s.showResult(0.0163);

return 0;
}
