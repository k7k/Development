#include <iostream> 
using namespace std; 
  
class Test 
{ 
public: 
    Test()  { cout << "Constructor is executed\n"; } 
    ~Test() { cout << "Destructor is executed\n";  } 
    friend void fun(Test t); 
}; 
void fun(Test t) 
{ 
    Test();
    cout<<"check 3\n";
    t.~Test(); 
} 
int main() 
{ 
    Test(); 
    cout<<"check 1\n";
    Test t; 
    cout<<"check 2\n";
    fun(t); 
	cout<<"funnnnn....\n";
    fun(t); 
    return 0; 
} 
