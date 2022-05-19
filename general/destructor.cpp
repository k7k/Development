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

/* output:

Constructor is executed
Destructor is executed
check 1
Constructor is executed
check 2
Constructor is executed
Destructor is executed
check 3
Destructor is executed
Destructor is executed  << in case of fun(Test &t) one destructor wont be called >>
funnnnn....
Constructor is executed
Destructor is executed
check 3
Destructor is executed
Destructor is executed
Destructor is executed

*/
