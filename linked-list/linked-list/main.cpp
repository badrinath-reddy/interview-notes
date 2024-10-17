//
//  main.cpp
//  linked-list
//
//  Created by Badrinath Reddy Gopugari on 10/13/24.
//

#include <iostream>

using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *prev;
    
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
