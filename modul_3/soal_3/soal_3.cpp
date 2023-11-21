#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node);
    int getBalance(Node *node);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    Node *insert(Node *node, int key);
    Node *deleteNode(Node *node, int key);
    void inorderTraversal(Node *node);

public:
    AVLTree() : root(nullptr) {}
    void insert(int key);
    void deleteKey(int key);
    void printInorder();
};

int AVLTree::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int AVLTree::getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node *AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node *AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node *AVLTree::insert(Node *node, int key)
{
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *AVLTree::deleteNode(Node *node, int key)
{
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            Node *temp = node->left ? node->left : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = node->right;
            while (temp->left != nullptr)
                temp = temp->left;

            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == nullptr)
        return node;

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::deleteKey(int key)
{
    root = deleteNode(root, key);
}

void AVLTree::insert(int key)
{
    root = insert(root, key);
}

void AVLTree::inorderTraversal(Node *node)
{
    if (node)
    {
        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }
}

void AVLTree::printInorder()
{
    inorderTraversal(root);
}

int main()
{
    AVLTree avlTree;
    int key;

    while (true)
    {
        cin >> key;
        if (key == -1)
        {
            break;
        }
        avlTree.insert(key);
    }

    avlTree.printInorder();
    cout << endl;

    int deleteKey;
    cin >> deleteKey;
    avlTree.deleteKey(deleteKey);

    avlTree.printInorder();

    return 0;
}