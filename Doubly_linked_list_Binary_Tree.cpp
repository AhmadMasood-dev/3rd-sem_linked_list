#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    struct Node<T> *left;
    struct Node<T> *right;
    struct Node<T> *parent;
};
template <class T>
class Binary_Tree
{
private:
    Node<T> *head;

public:
    Binary_Tree()
    {
        head = new Node<T>();
        head->left = head->right = head->parent = head;
    }
    void insert(const T &val)
    {
        Node<T> *new_node;
        new_node = new Node<T>();
        new_node->data = val;
        new_node->right = new_node->left = head;
        if (head->parent == head)
        {
            head->parent = new_node;
            new_node->parent = head;
            head->left = head->right = new_node;
        }
        else
        {
            Node<T> *temp;
            temp = head->parent;
            while (true)
            {

                if (new_node->data == temp->data)
                {
                    cout << "duplicate";
                    return;
                }
                else if (new_node->data < temp->data)
                {

                    if (temp->left == head)
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        head->left = new_node;
                        return;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {

                    if (temp->right == head)
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        head->right = new_node;
                        return;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    void displayInOrder(Node<T> *node)
    {
        if (node != head)
        {
            displayInOrder(node->left);
            cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void display()
    {
        cout << "In-order traversal: ";
        displayInOrder(head->parent);
        cout << endl;
    }
};
int main()
{
    Binary_Tree<int> obj_1;
    obj_1.insert(15);
    obj_1.insert(7);
    obj_1.insert(25);
    obj_1.insert(2);
    obj_1.display();
    return 0;
}