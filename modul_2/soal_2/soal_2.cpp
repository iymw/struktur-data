#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    preorder(root->left);
    preorder(root->right);
}

struct node *insertNode(struct node *node, int val)
{
    if (node == NULL)
        return createNode(val);

    if (val < node->data)
        node->left = insertNode(node->left, val);
    else if (val > node->data)
        node->right = insertNode(node->right, val);

    return node;
}

int main()
{
    int loop, num;
    cin >> loop;
    struct node *root = NULL;
    for (int i = 0; i < loop; i++)
    {
        cin >> num;
        root = insertNode(root, num);
    }

    preorder(root);

    return 0;
}