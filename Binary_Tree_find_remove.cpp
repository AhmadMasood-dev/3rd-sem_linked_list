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
    void find(T key)
    {
        std::cout << "Data is : " << key << std::endl;
        Node<T> *temp;
        temp = head->parent;
        while (temp != head)
        {
            if (temp->data == key)
            {
                std::cout << "Data Found"
                          << "\n";
                return;
            }
            else if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        throw("Data does not found");
    }
    void remove(T key)
    {
        std::cout << "Data is : " << key << std::endl;

        int count = 0;
        Node<T> *temp;
        temp = head->parent;
        while (temp != head)
        {
            if (temp->data == key)
            {
                std::cout << "Data Found"
                          << "\n";
                std::cout << "---------------------------------\n";
                count++;
                break;
            }
            else if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (count == 0)
        {
            throw("Data does not Found");
        }

        if (temp->left != head && temp->right != head)
        {
            Node<T> *node;
            node = temp->left;
            while (node->right != head)
            {
                node = node->right;
            }
            int node2;
            node2 = temp->data;
            temp->data = node->data;
            node->data = node2;
            if (node->left == head && node->right == head)
            {

                if (node->parent->right->data == key)
                {
                    node->parent->right = head;
                }
                else
                {
                    node->parent->left = node->left;
                }
            }

            delete node;
        }
        else if (temp->left == head && temp->right == head)
        {
            if (key < head->parent->data)
            {

                if (temp->parent->right->data == key)
                {
                    temp->parent->right = head;
                    delete temp;
                }
                else
                {
                    head->left = temp->parent;
                    temp->parent->left = head;
                    delete temp;
                }
            }
            else
            {
                head->right = temp->parent;
                temp->parent->left = head;
                delete temp;
            }
        }
        else if (temp->left != head && temp->right == head)
        {
            if (key < head->parent->data)
            {
                // std::cout << "zain";
                Node<T> *node;
                node = temp->left;

                int node2;
                node2 = temp->data;
                temp->data = node->data;
                node->data = node2;
                temp->left = node->left;
                head->left = temp;
                delete node;
            }
            else
            {
                //  std::cout << "zain";
                Node<T> *node;
                node = temp->left;

                int node2;
                node2 = temp->data;
                temp->data = node->data;
                node->data = node2;

                temp->left = node->left;
                head->right = temp;
                delete node;
            }
        }
        else if (temp->left == head && temp->right != head)
        {
            if (key > head->parent->data)
            {

                Node<T> *node;
                node = temp->right;

                int node2;
                node2 = temp->data;
                temp->data = node->data;
                node->data = node2;
                temp->right = node->right;
                head->right = temp;
                delete node;
            }
            else
            {

                Node<T> *node;
                node = temp->right;

                int node2;
                node2 = temp->data;
                temp->data = node->data;
                node->data = node2;

                temp->right = node->right;
                head->left = temp;
                delete node;
            }
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
    try
    {
        Binary_Tree<int> obj_1;
        obj_1.insert(15);
        obj_1.insert(7);
        obj_1.insert(25);
        obj_1.insert(20);
        obj_1.insert(22);
        obj_1.insert(2);
        obj_1.insert(9);
        obj_1.insert(11);
        obj_1.display();
        obj_1.remove(15);
        obj_1.remove(7);
        obj_1.display();
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    return 0;
}