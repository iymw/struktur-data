#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
}; typedef Node *nodePtr;

int main () {
    int n;

    nodePtr head = nullptr;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        nodePtr newNode = new Node;
        newNode->data = n;
        newNode->link = head;
        head = newNode;
    }

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->link;
    }
}