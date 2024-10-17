#include <iostream>

using namespace std;

class Interface {
public:
    virtual void display(void) = 0;
};

class ConcreteClass : public Interface {
public:
    void display(void);
};


void ConcreteClass::display() {
    cout << "From Concrete Class" << endl;
}



int main(int argc, const char * argv[]) {
    
    Interface *cl =new ConcreteClass();
    cl->display();
    
    cout << "Hello, World!\n";
    return 0;
}
