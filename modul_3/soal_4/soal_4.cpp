#include <iostream>

using namespace std;

struct AVLNode
{
	int key;
	AVLNode *left;
	AVLNode *right;
	int height;
};

class AVLTree
{
public:
	AVLNode *root;

	int height(AVLNode *node)
	{
		if (!node)
			return 0;
		return node->height;
	}

	int balance(AVLNode *node)
	{
		if (!node)
			return 0;
		return height(node->left) - height(node->right);
	}

	void updateHeight(AVLNode *node)
	{
		if (!node)
			return;
		node->height = 1 + max(height(node->left), height(node->right));
	}

	AVLNode *rotateRight(AVLNode *y)
	{
		AVLNode *x = y->left;
		AVLNode *T2 = x->right;

		x->right = y;
		y->left = T2;

		updateHeight(y);
		updateHeight(x);

		return x;
	}

	AVLNode *rotateLeft(AVLNode *x)
	{
		AVLNode *y = x->right;
		AVLNode *T2 = y->left;

		y->left = x;
		x->right = T2;

		updateHeight(x);
		updateHeight(y);

		return y;
	}

	AVLNode *insert(AVLNode *root, int key)
	{
		if (!root)
			return new AVLNode{key, nullptr, nullptr, 1};

		if (key < root->key)
			root->left = insert(root->left, key);
		else if (key > root->key)
			root->right = insert(root->right, key);
		else
			return root;

		updateHeight(root);

		int balance = this->balance(root);

		if (balance > 1)
		{
			if (key < root->left->key)
				return rotateRight(root);
			else
			{
				root->left = rotateLeft(root->left);
				return rotateRight(root);
			}
		}
		if (balance < -1)
		{
			if (key > root->right->key)
				return rotateLeft(root);
			else
			{
				root->right = rotateRight(root->right);
				return rotateLeft(root);
			}
		}

		return root;
	}

	AVLNode *minValueNode(AVLNode *node)
	{
		AVLNode *current = node;
		while (current->left)
			current = current->left;
		return current;
	}

	AVLNode *deleteNode(AVLNode *root, int key)
	{
		if (!root)
			return root;

		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else
		{
			if (!root->left || !root->right)
			{
				AVLNode *temp = root->left ? root->left : root->right;
				if (!temp)
				{
					temp = root;
					root = nullptr;
				}
				else
					*root = *temp;
				delete temp;
			}
			else
			{
				AVLNode *temp = minValueNode(root->right);
				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key);
			}
		}

		if (!root)
			return root;

		updateHeight(root);

		int balance = this->balance(root);

		if (balance > 1)
		{
			if (this->balance(root->left) >= 0)
				return rotateRight(root);
			else
			{
				root->left = rotateLeft(root->left);
				return rotateRight(root);
			}
		}
		if (balance < -1)
		{
			if (this->balance(root->right) <= 0)
				return rotateLeft(root);
			else
			{
				root->right = rotateRight(root->right);
				return rotateLeft(root);
			}
		}

		return root;
	}

	void inorderTraversal(AVLNode *root)
	{
		if (root)
		{
			inorderTraversal(root->left);
			cout << root->key << " ";
			inorderTraversal(root->right);
		}
	}
};

int main()
{
	AVLTree avlTree;
	while (true)
	{
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1:
			int element;
			cin >> element;
			avlTree.root = avlTree.insert(avlTree.root, element);
			break;

		case 2:
			int element;
			cin >> element;
			avlTree.root = avlTree.deleteNode(avlTree.root, element);
			break;

		case 3:
			avlTree.inorderTraversal(avlTree.root);
			cout << endl;
			break;

		case 4:
			break;
		}
		return 0;
	}
}