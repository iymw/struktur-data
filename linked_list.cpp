// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
}; typedef Node *nodePtr;

int main() {
    nodePtr head = nullptr;
    nodePtr one = nullptr;
    nodePtr two = nullptr;
    nodePtr three = nullptr;
    nodePtr four = nullptr;
    nodePtr five = nullptr;
    
    head = new Node;
    one = new Node;
    two = new Node;
    three = new Node;
    four = new Node;
    five = new Node;
    
    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;
    five->data = 5;
    
    one->link = two;
    two->link = three;
    three->link = four;
    four->link = five;
    five->link = nullptr;
    
    head = one;
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->link;
    }
    
    return 0;
}