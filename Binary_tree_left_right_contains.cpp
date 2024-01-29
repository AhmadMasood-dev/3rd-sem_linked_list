#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    { 
        this ->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;
    int size;

public:
    BinarySearchTree() { root = nullptr; }
    void destroy(Node *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        size++;
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
                return false;
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    int Size()
    {
        return size;
    }
    bool contains(int value)
    {
        if (root == nullptr)
            return false;
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    BinarySearchTree *myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    cout << "Contains 27: " << myBST->contains(27);
    cout << "\n\nContains 17: " << myBST->contains(17);
}
