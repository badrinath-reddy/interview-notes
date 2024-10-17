#include <iostream>

using namespace std;

enum Size {
    SMALL = 1,
    MEDIUM = 2,
    BIG = 3
};

enum LockerState {
    OPEN = 1,
    CLOSE = 2
};

class Customer {
    int id;
    
};

class Product {
    int id;
    Size size;
};

class Locker {
    int id;
    Size size;
    LockerState state;
    string location;
};

class LockerHub {
    vector<string> getAllLocations();
    Locker* getLocker(string location);
};


class Order {
    Customer *customer;
    Locker *locker;
    Product *product;
    
    
    bool placeOrder()
};



int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    return 0;
}
