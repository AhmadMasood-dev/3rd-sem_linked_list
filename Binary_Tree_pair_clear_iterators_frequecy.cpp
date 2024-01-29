#include <iostream>
#include <string>
#include <fstream>
template <class T1, class T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair(T1 first = T1(), T2 second = T2()) // default values
    {
        this->first = first;
        this->second = second;
    }
};
template <class key_type, class value_type>
struct Node
{
    Node<key_type, value_type> *parent;
    Pair<key_type, value_type> data;
    Node<key_type, value_type> *left, *right;
    bool is_nil;
};
namespace mytree
{
    template <class key_type, class value_type>
    class Binary_Tree
    {
    private:
        Node<key_type, value_type> *head;
        int SIZE;
        void inOrderTraversal(Node<key_type, value_type> *node) const
        {
            if (node != head)
            {
                inOrderTraversal(node->left);
                std::cout << "(" << node->data.first << ", " << node->data.second << ") ";
                inOrderTraversal(node->right);
            }
        }
        void copy_r(Node<key_type, value_type> *ptr) // call by operator=
        {
            if (ptr != head)
            {
                insert({ptr->data.first, ptr->data.second});
                copy_r(ptr->left);
                copy_r(ptr->right);
            }
        }

    public:
        Binary_Tree()
        {
            head = new Node<key_type, value_type>;
            head->parent = head->left = head->right = head;
            head->is_nil = true;
            SIZE = 0;
        }
        Binary_Tree(const Binary_Tree &rhs)
        {
            head = new Node<key_type, value_type>;
            head->parent = head->left = head->right = head;
            head->is_nil = true;
            SIZE = 0;
            operator=(rhs);
        }
        bool empty() const
        {
            if (head->parent == head)
                return true;
            else
                return false;
        }
        bool full() const
        {
            Node<key_type, value_type> *temp;
            temp = new Node<key_type, value_type>;
            if (temp == nullptr)
                return true;
            else
            {
                delete temp;
                return false;
            }
        }
        int size() const
        {
            return SIZE;
        }

        void clear()
        {
            Node<key_type, value_type> *temp_left, *temp_right;
            temp_left = head->left;
            temp_right = head->right;
            // std::cout << head->right->data.first << head->right->data.second << " head->right\n";

            // std::cout << head->left->data.first << head->left->data.second << " head->left\n";
            // Left side
            while (temp_left->parent != head)
            {
                Node<key_type, value_type> *temp_check;
                if (temp_left->right != head) // if right node exists
                {
                    temp_check = temp_left->right;

                    if (temp_check->left != head) //  left exists
                    {
                        delete temp_check->left;
                        SIZE--;
                    }
                    if (temp_check->right != head) // right exists
                    {
                        delete temp_check->right;
                        SIZE--;
                    }
                    delete temp_left->right;
                    SIZE--;
                }
                temp_left = temp_left->parent;
                delete head->left;
                head->left = temp_left;
                SIZE--;
            }
            // Right side
            while (temp_right->parent != head)
            {
                Node<key_type, value_type> *temp_dr;
                if (temp_right->left != head) // if any left node exists
                {
                    temp_dr = temp_right->left;
                    if (temp_dr->left != head) // left exists
                    {
                        delete temp_dr->left;
                        SIZE--;
                    }
                    if (temp_dr->right != head) // right exists
                    {
                        delete temp_dr->right;
                        SIZE--;
                    }
                    delete temp_right->left;
                    SIZE--;
                }
                temp_right = temp_right->parent;
                delete head->right;
                head->right = temp_right;
                SIZE--;
            }
            // Root node
            if (temp_left->parent == head)
            {
                delete head->parent;
                head->left = head->right = head->parent = head;
                SIZE--;
            }

            if (head->parent == head && head->left == head && head->right == head)
            {
                std::cout << "Data has been Clear successfully \n";
            }
        }

        class iterator
        {
        private:
            Node<key_type, value_type> *ptr;
            friend class Binary_Tree;
            Node<key_type, value_type> *head_temp;
            int count = 0;

        public:
            bool operator!=(const iterator &rhs) const
            {
                if (this->ptr != rhs.ptr)
                    return true;
                else
                    return false;
            }

            bool operator==(const iterator &rhs) const
            {
                if (this->ptr == rhs.ptr)
                    return true;
                else
                    return false;
            }

            Pair<key_type, value_type> &operator*()
            {
                return ptr->data;
            }

            Pair<const key_type, value_type> *operator->()
            {
                return reinterpret_cast<Pair<const key_type, value_type> *>(&ptr->data);
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
        };
        class reverse_iterators
        {
            Node<key_type, value_type> *ptr;
            friend class Binary_Tree;
            Node<key_type, value_type> *head_temp;
            int count = 0;

        public:
            bool operator!=(const iterator &rhs) const
            {
                if (this->ptr != rhs.ptr)
                    return true;
                else
                    return false;
            }

            bool operator==(const iterator &rhs) const
            {
                if (this->ptr == rhs.ptr)
                    return true;
                else
                    return false;
            }

            Pair<key_type, value_type> &operator*()
            {
                return ptr->data;
            }

            Pair<const key_type, value_type> *operator->()
            {
                return reinterpret_cast<Pair<const key_type, value_type> *>(&ptr->data);
            }
            iterator &operator++()
            {
                if (count == 0)
                {

                    count++;
                    head_temp = ptr->right;
                    ptr = ptr->right;
                }
                if (ptr->left == head_temp && ptr->right == head_temp)
                {
                    // std::cout << "ptr->data" << ptr->data << "\n";

                    while (ptr->data < ptr->parent->data)
                    {
                        ptr = ptr->parent;
                    }

                    ptr = ptr->parent;
                }
                else if (ptr->left != head_temp)
                {

                    ptr = ptr->left;
                    while (ptr->right != head_temp)
                    {
                        ptr = ptr->right;
                    }
                    // std::cout << "zain_left\n"            << ptr->data;
                }

                return *this;
            }
        };

        // BEGIN  END FUNCTION OF ITEARTORS
        iterator
        begin() const
        {
            iterator it;
            it.ptr = head->left;
            return it;
        }

        iterator end() const
        {
            iterator it;
            it.ptr = head;
            return it;
        }
        value_type &at(const key_type &key)
        {
            iterator it;
            it = this->find(key);
            if (it == end())
            {
                throw("out of range");
            }
            else
            {
                return it.ptr->data.second;
            }
        }
        value_type count(const key_type &key) const
        {
            iterator it;
            it = this->find(key);

            if (it == end())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        value_type contains(const key_type &key) const
        {
            iterator it;
            it = this->find(key);

            if (it == end())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        value_type &operator[](const key_type &key)
        {
            iterator it;
            it = this->find(key);
            if (it == end())
            {
                Pair<iterator, bool> pair_val = this->insert({key, value_type()});
                return pair_val.first->second;
            }
            else
            {
                return it.ptr->data.second;
            }
        }

        Binary_Tree &operator=(const Node<key_type, value_type> &rhs)
        {
            if (this != rhs)
            {

                this->clear();
                copy_r(rhs.head->parent);
            }
            return *this;
        }

        iterator find(const key_type &key)
        {
            Node<key_type, value_type> *temp;
            temp = head->parent;
            iterator itr;
            while (temp != head)
            {
                if (key == temp->data.first) // find specific key
                {
                    itr.ptr = temp;
                    return itr;
                }
                else if (key < temp->data.first)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            itr.ptr = head; // if value not found in the tree
            return itr;
        }

        // Insert function
        Pair<iterator, bool> insert(const Pair<key_type, value_type> &val)
        {

            Node<key_type, value_type> *new_node = new Node<key_type, value_type>;
            new_node->data = val;
            // new_node->data.first = val.first;
            // new_node->data.second = val.second;
            new_node->left = new_node->right = head;
            new_node->is_nil = false;
            SIZE++;

            Pair<iterator, bool> pair_val;
            iterator it;
            it.ptr = new_node;
            pair_val.first = it;
            pair_val.second = true;

            if (head->parent == head) // for first node
            {
                head->parent = head->left = head->right = new_node; // equalling dummy head to first node
                new_node->parent = head;
                return pair_val; // to come out of function after inserting first value
            }
            Node<key_type, value_type> *temp;
            temp = head->parent;
            while (true) // infinite values(terminates on return)
            {
                if (new_node->data.first == temp->data.first) // for duplicate values
                {
                    it.ptr = temp;
                    pair_val.first = it;
                    pair_val.second = false;
                    delete new_node;
                    SIZE--;
                    return pair_val;
                }
                else if (new_node->data.first < temp->data.first) // value is small
                {
                    if (temp->left == head) // space avalaible
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        if (new_node->data.first < head->left->data.first) // for smallest value
                        {
                            head->left = new_node;
                        }

                        return pair_val;
                    }
                    else
                        temp = temp->left; // if no space avalaible
                }
                else // value is large
                {
                    if (temp->right == head) // space available
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        if (new_node->data.first > head->right->data.first) // largest value
                            head->right = new_node;
                        return pair_val;
                    }
                    else
                        temp = temp->right; // if no space available
                }
            }
        }
        int erase(const key_type &key)
        {
            iterator it;
            it = find(key);
            if (it.ptr == head)
            {
                return 0;
            }
            Node<key_type, value_type> *to_del, *parent_to_del;
            to_del = it.ptr;
            parent_to_del = to_del->parent;
            // leaf node
            if (to_del->left == head && to_del->right == head)
            {
                if (parent_to_del == head)
                {
                    head->parent = head->left = head->right = head;
                    delete to_del;
                    SIZE--;
                    return 1;
                }
                else if (to_del == parent_to_del->left)
                {
                    parent_to_del->left = head;
                }
                else if (head->left == to_del)
                {
                    head->left = parent_to_del;
                }
                else
                {
                    parent_to_del->right = head;
                    if (head->right == to_del)
                    {
                        head->right = parent_to_del;
                    }
                }
                delete to_del;
                SIZE--;
                return 1;
            }
            // left child exit
            else if (to_del->left != head && to_del->right == head)
            {
                if (parent_to_del == head)
                {
                    head->parent = to_del->left;
                }
                else if (head->right == to_del)
                {
                    Node<key_type, value_type> *pred;
                    pred = to_del->left;
                    while (pred->right != head)
                    {
                        pred = pred->right;
                    }
                    head->right = pred;
                }
                else if (to_del == parent_to_del->left)
                {
                    parent_to_del->left = to_del->left;
                    to_del->parent = parent_to_del;
                }
                delete to_del;
                SIZE--;
                return 1;
            } // both left and right child
            else if (to_del->left != head && to_del->right != head)
            {
                Node<key_type, value_type> *node;
                node = to_del->left;
                while (node->right != head)
                {
                    node = node->right;
                }
                Pair<key_type, value_type> temp = to_del->data;
                to_del->data = node->data;
                node->data = temp;
                if (node->left == head && node->right == head)
                {
                    if (node->parent->right->data.first == key)
                    {
                        node->parent->right = head;
                    }
                    else
                        node->parent->left = node->left;
                }
                delete node;
                SIZE--;
                return 1;
            }
            return 0;
        }

        void display() const
        {
            if (head->parent != head)
            {
                inOrderTraversal(head->parent);
            }
            else
            {
                std::cout << "Binary_Tree is empty." << std::endl;
            }
        }
    };
}
bool stop_word(const std::string &word)
{
    std::string stop_word_array[] = {" the ", " and ", " is ", " in ", " of "};

    for (int i = 0; i < 5; i++)
    {
        if (word == stop_word_array[i])
        {
            return true;
        }
    }

    return false;
}
int main(int argc, char *argv[])
{
    try
    {
        std::string file_name;
        if (argc == 0)
        {
            std::cout << "Enter file name \n";
            std::cin >> file_name;
        }
        else
        {

            if (argc < 2)
            {
                throw("please give proper command line\n");
            }
            else
            {
                mytree::Binary_Tree<int, std::string> obj_1;

                obj_1.insert({17, "zain"});
                obj_1.insert({25, "ali"});
                obj_1.insert({6, "ahmad"});
                obj_1.insert({8, "dani"});
                obj_1.display();
                mytree::Binary_Tree<int, std::string>::iterator it;
                it = obj_1.find(6);
                if (it == obj_1.end())
                    std::cout << "Data not found " << std::endl;
                else
                {
                    std::cout << "Data Found " << std::endl;
                    std::cout << (*it).second << std::endl;
                }
                std::cout << "-----------------------------------------\n";

                it->second = "Gondal";
                std::cout << "after changing data part" << std::endl;
                std::cout << (*it).second << std::endl;
                std::cout << "-----------------------------------------\n";

                mytree::Binary_Tree<int, std::string> obj_2;
                obj_2 = obj_1;
                bool op = obj_1.erase(8);
                std::cout << "Data of obj_1 copy to obj_2\n";
                std::cout << "-----------------------------------------\n";
                if (op == 0)
                {
                    std::cout << "Data not found  " << std::endl;
                }
                else
                {
                    std::cout << "Data found and delete  " << std::endl;
                }
                std::cout << "-----------------------------------------\n";
                obj_1.clear();
                std::cout << "Total size of tree after clear function is : " << obj_1.size() << std::endl;
                std::cout << "-----------------------------------------\n";

                char read_or_not;

                file_name = argv[1];
                std::fstream file(file_name, std::ios::in);
                mytree::Binary_Tree<std::string, int> dic;
                std::string punctuation_array[] = {"'", ";", "[", "]", ".", ",", ":", "}", "{"};
                int punctuation_count;
                while (file.good())
                {
                    std::string word;
                    file >> word;
                    punctuation_count = 0;

                    for (int i = 0; i < 10; i++) // removing punctuations
                    {
                        if (word == punctuation_array[i])
                        {
                            punctuation_count++;
                        }
                    }
                    if (punctuation_count > 0)
                    {
                        continue;
                    }
                    else if (stop_word(word))
                    {
                        continue;
                    }
                    else
                    {

                        dic[word]++;
                    }
                }
                file.close();
                std::ofstream file2;
                file2.open("zain.txt");
                mytree::Binary_Tree<std::string, int>::iterator itr = dic.begin();
                while (itr != dic.end())
                {
                    file2 << "\"" << itr->first << "\"," << itr->second << std::endl;
                    ++itr;
                }
                file2.close();
            }
        }
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }

    return 0;
}