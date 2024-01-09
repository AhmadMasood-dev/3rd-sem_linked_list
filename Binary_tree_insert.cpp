#include <iostream>
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
    void insert(const T &data)
    {
        if (head->parent == head)
        {
            Node<T> *newnode = new Node<T>;
            newnode->data = data;
            head->parent = newnode;
            head->left = newnode;
            head->right = newnode;
            newnode->parent = head;
            newnode->left = newnode->right = head;
            return;
        }

        Node<T> *temp = head->parent;
        while (temp != head)
        {
            if (temp->data == data)
            {
                std::cout << "duplicate";
                return;
            }

            if (data < temp->data)
            {
                if (temp->left == head)
                {
                    Node<T> *newnode = new Node<T>;
                    temp->left = newnode;
                    newnode->data = data;
                    newnode->parent = temp;
                    newnode->left = newnode->right = head;
                    if (data < head->left->data)
                    {
                        head->left = newnode;
                    }
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
                    Node<T> *newnode = new Node<T>;
                    temp->right = newnode;
                    newnode->data = data;
                    newnode->parent = temp;
                    newnode->left = newnode->right = head;
                    if (data > head->right->data)
                    {
                        head->right = newnode;
                    }

                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void displayInOrder(Node<T> *node)
    {
        if (node != head)
        {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }
    class iterator
    {
    private:
        Node<T> *ptr;
        Node<T> *head_temp;
        int count = 0;

    public:
        friend class Binary_Tree;
        iterator()
        {
        }
        T *operator->()
        {
            return &ptr->data;
        }
        T operator*()
        {
            return ptr->data;
        }
        iterator &operator++()
        {
            if (count == 0)
            {
                head_temp = ptr->left;
                count++;
            }
            if (ptr->left == head_temp && ptr->right == head_temp)
            {
                // std::cout << "ptr->data" << ptr->data << "\n";

                while (ptr->data > ptr->parent->data)
                {
                    ptr = ptr->parent;
                }

                ptr = ptr->parent;
            }
            else if (ptr->right != head_temp)
            {

                ptr = ptr->right;
                while (ptr->left != head_temp)
                {
                    ptr = ptr->left;
                }
                // std::cout << "zain_left\n"            << ptr->data;
            }

            return *this;
        }
        bool operator!=(const iterator &rhs) const
        {
            if (this->ptr != rhs.ptr)
                return true;
            else
                return false;
        }
    };
    iterator begin()
    {
        iterator it;
        it.ptr = head->left;
        return it;
    }
    iterator end()
    {
        iterator it;
        it.ptr = head->right;
        return it;
    }
    void display()
    {
        std::cout << "In-order traversal: ";
        displayInOrder(head->parent);
        std::cout << std::endl;
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
        obj_1.insert(5);
        obj_1.insert(9);
        obj_1.insert(8);
        obj_1.insert(11);
        obj_1.insert(23);
        obj_1.insert(27);
        obj_1.display();
        Binary_Tree<int>::iterator it_obj;
        std::cout << "---------------------------\n";
        std::cout << "In-order using Iterators \n";
        it_obj = obj_1.begin(); // begin () smallest value
        while (it_obj != obj_1.end())
        {
            std::cout << " " << *it_obj << "  ";
            ++it_obj;
        }
        std::cout << " " << *it_obj << "  "; // show last element in tree because end() is head->right(greatest value)
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    return 0;
}