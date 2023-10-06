#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
}; typedef Node *nodePtr;

int main () {
    int n, add = 0;

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
        add++;
    }

    cout << add;
}