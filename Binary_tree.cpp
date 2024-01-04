#include <iostream>
#include <string>
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

    public:
        Binary_Tree()
        {
            head = new Node<key_type, value_type>;
            head->parent = head->left = head->right = head;
            head->is_nil = true;
            SIZE = 0;
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
            std::cout << head->right->data.first << head->right->data.second << " head->right\n";

            std::cout << head->left->data.first << head->left->data.second << " head->left\n";
            // for clearing left side
            while (temp_left->parent != head)
            {
                Node<key_type, value_type> *temp_check;
                if (temp_left->right != head) // if any right node exists
                {
                    temp_check = temp_left->right;

                    if (temp_check->left != head)
                    { // if its left exists
                        delete temp_check->left;
                        SIZE--;
                    }
                    if (temp_check->right != head)
                    { // if its right exists
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
            // for clearing right side
            while (temp_right->parent != head)
            {
                Node<key_type, value_type> *temp_dr;
                if (temp_right->left != head) // if any left node exists
                {
                    temp_dr = temp_right->left;
                    if (temp_dr->left != head)
                    { // if its left exists
                        delete temp_dr->left;
                        SIZE--;
                    }
                    if (temp_dr->right != head)
                    { // if its right exists
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
            // clearing the root node
            if (temp_left->parent == head)
            {
                delete head->parent;
                head->left = head->right = head->parent = head;
                SIZE--;
            }
        }

        class iterator
        {
        private:
            Node<key_type, value_type> *ptr;
            friend class Binary_Tree;

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
                return reinterpret_cast<Pair<const key_type, value_type> *>(&ptr->val);
            }
        };

        // BEGIN  END FUNCTION OF ITEARTORS
        iterator begin() const
        {
            iterator it;
            it.ptr = head->left;
            return it;
        }

        iterator end() const
        {
            iterator it;
            it.ptr = head->right;
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
        value_type &operator[](const key_type &key)
        {
            iterator it;
            it = this->find(key);
            if (it == end())
            {
                Pair<iterator, bool> pair_val;
                pair_val = this->insert({key, value_type()});
                return pair_val.first->second;
            }
            else
            {
                it.ptr->data.second;
            }
        }

        // FIND FUNCTION
        iterator find(const key_type &key)
        {
            Node<key_type, value_type> *temp;
            temp = head->parent;
            iterator itr;
            while (temp != head)
            {
                if (key == temp->data.first)
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
                if (data.first == temp->data.first) // for duplicate values
                {
                    it.ptr = temp;
                    pair_val.first = it;
                    pair_val.second = false;
                    delete new_node;
                    SIZE--;
                    return pair_val;
                }
                else if (data.first < temp->data.first) // value is small
                {
                    if (temp->left == head) // space avalaible
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        if (data.first < head->left->data.first) // for smallest value
                        {
                        }
                        head->left = new_node;

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
                        if (data.first > head->right->data.first) // largest value
                            head->right = new_node;
                        return pair_val;
                    }
                    else
                        temp = temp->right; // if no space available
                }
            }
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
int main()
{
    mytree::Binary_Tree<int, std::string> m;

    m.insert({17, "zain"});
    m.insert({25, "ali"});
    m.insert({6, "ahmad"});
    m.insert({8, "dani"});
    m.display();
    mytree::Binary_Tree<int, std::string>::iterator it;
    it = m.find(6);
    if (it == m.end())
        std::cout << "value not found:" << std::endl;
    else
    {
        std::cout << "value has been found:" << std::endl;
        std::cout << (*it).second << std::endl;
        // it->first = 13;//will give error
        it->second = "taimoor";
        //(*it).first = 13;//willgive error
        //(*it).second = "ahmad";//will noyt give error
        std::cout << "after changing value part:" << std::endl;
        std::cout << (*it).second << std::endl;
    }

    // empty function
    if (m.empty() == true)
        std::cout << "Binary_Tree is empty:" << std::endl;
    else
        std::cout << "Binary_Tree is not empty:" << std::endl;

    // full function
    if (m.full() == true)
        std::cout << "Binary_Tree is full:" << std::endl;
    else
        std::cout << "Binary_Tree is not full:" << std::endl;

    // size function
    std::cout << "total size:" << m.size() << std::endl;

    m.clear();
    std::cout << "total size:" << m.size() << std::endl;

    // another method
    // pair<int, std::string>p1;
    // p1 = *it;
    // p1.first = 1;
    // for checking
    //(*it).first = 2;
    // std::cout << (*it).first << std::endl;

    /*struct test
    {
        int id;
        std::string name;
    };
    test t;
    t.id = 1;
    t.name = "tah";
    mytree::Binary_Tree<test,test>m1;
    m1.insert(t);
    mytree::Binary_Tree<test, test>::iterator sit;
    sit = m1.find(t);*/
    // std::cout << (*sit).first;

    return 0;
}