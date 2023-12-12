#include <iostream>
using namespace std;

template <class T>
struct Node
{
    struct Node<T> *next;
    struct Node<T> *back;
    T data;
};

template <class T>
class Browser_History
{
private:
    Node<T> *head;
    int node_size;
    Node<T> *current; // keep track of current position

public:
    Browser_History(T name)
    {
        node_size = 0;
        head = new Node<T>();
        head->back = head;
        head->next = head;
        head->data = name;
        current = head;
    }

    void push_back(T value)
    {
        Node<T> *temp;
        Node<T> *back_address;
        if (head->next == head)
        {
            temp = new Node<T>();
            temp->data = value;
            temp->back = head;
            temp->next = head;
            head->next = temp;
            head->back = temp;
        }
        else
        {
            back_address = head->back;
            temp = new Node<T>();
            temp->data = value;
            temp->next = head;
            head->back = temp;
            temp->back = back_address;
            back_address->next = temp;
        }

        node_size++;
        current = head;
    }

    void pop_back()
    {
        if (head->next == head)
        {
            throw("linked underflow");
        }
        else
        {
            Node<T> *temp;
            temp = head->back;
            temp->back->next = head;
            head->back = temp->back;
            delete temp;
            node_size--;
        }
    }

    bool empty()
    {
        if (head->next == head)
            return true;
        else
            return false;
    }

    bool full()
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (temp == NULL)
            return true;
        else
        {
            delete temp;
            return false;
        }
    }

    void visit(T name)
    {
        push_back(name);
        std::cout << "Site is visited successfully\n";
    }

    string Backward(int steps)
    {
        int flag = 0;
        for (int i = 0; i < steps; i++)
        {
            if (current->back != head)
            {
                current = current->back;
            }
            else
            {
                if (flag == 0)
                {
                    flag++;
                    std::cout << " Maximum steps back reached\n";
                }
            }
        }
        return current->data;
    }

    string Forward(int steps)
    {
        int flag = 0;
        for (int i = 0; i < steps; i++)
        {
            if (current->next != head)
            {
                current = current->next;
            }
            else
            {
                if (flag == 0)
                {
                    flag++;
                    std::cout << " Maximum steps forward reached\n";
                }
            }
        }
        return current->data;
    }

    void Display()
    {
        Node<T> *ptr;
        ptr = head->next;
        while (ptr != head)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n------------------------------------------\n";
    }
};

int main()
{
    try
    {
        Browser_History<std::string> browserHistory("Example.com");
        std::string site_name;
        int choice, option;
        do
        {
            std::cout << "--------- Browser History Menu ---------\n";
            std::cout << "1.  Visit\n";
            std::cout << "2.  Forward\n";
            std::cout << "3.  Backward\n";
            std::cout << "4.  Display\n";
            std::cout << "5.  Exit\n";
            std::cout << "------------------------------------------\n";
            std::cout << "Enter one option\n";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                std::cout << "Enter website name : ";
                std::cin >> site_name;
                browserHistory.visit(site_name);
                std::cout << "------------------------------------------\n";
            }
            break;
            case 2:
            {
                int steps;
                std::cout << "Enter number of steps to move forward : ";
                std::cin >> steps;
                std::cout << "Current URL: " << browserHistory.Forward(steps) << endl;
                std::cout << "------------------------------------------\n";
            }
            break;
            case 3:
            {
                int steps;
                std::cout << "Enter number of steps to move backward : ";
                std::cin >> steps;
                std::cout << "Current URL: " << browserHistory.Backward(steps) << endl;
                std::cout << "------------------------------------------\n";
            }
            break;
            case 4:
            {
                browserHistory.Display();
            }
            break;
            case 5:
            {
                std::cout << "Exiting...\n";
            }
            break;

            default:
                break;
            }
        } while (choice != 5);
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}
