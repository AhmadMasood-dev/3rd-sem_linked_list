#include <iostream>

class AVLTree
{
private:
    struct Node
    {
        int key;
        Node *left;
        Node *right;
        int height;
    };
    Node *root;


    int getHeight(Node *n)
    {
        if (n == nullptr)
            return 0;
        return n->height;
    }

    Node *createNode(int key)
    {
        Node *node = new Node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getBalanceFactor(Node *n)
    {
        if (n == nullptr)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        //     y
        //  x      T3
        // T1  T2

        x->right = y;
        y->left = T2;

        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

        //      x
        //  T1      y
        //      T2     T3

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        //      x
        //  T1      y
        //      T2     T3

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

        //     y
        //  x      T3
        // T1  T2

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return createNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bf = getBalanceFactor(node);

        if (bf > 1 && key < node->left->key)
            return rightRotate(node);
        if (bf < -1 && key > node->right->key)
            return leftRotate(node);
        if (bf > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (bf < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void preOrder(Node *root)
    {
        if (root != nullptr)
        {
            std::cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void printPreOrder()
    {
        preOrder(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVLTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.printPreOrder();
    return 0;
}
