#include <iostream>
#include <string>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *createNode(char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
struct node *insertNode(struct node *node, char val)
{
    if (node == NULL)
        return createNode(val);
    if (val <= node->data)
        node->left = insertNode(node->left, val);
    else if (val > node->data)
        node->right = insertNode(node->right, val);
    return node;
}
int main()
{
    string num;
    getline(cin, num);
    struct node *root = NULL;
    for (int i = 0; i < num.length(); i++)
    {
        root = insertNode(root, num[i]);
    }

    preorder(root);
    return 0;
}