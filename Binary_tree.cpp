#include <iostream>
#include <string>
template <class T1, class T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair(T1 first = T1(), T2 second = T2()) // giving default values
    {
        this->first = first;
        this->second = second;
    }
};
template <class key_type, class value_type>
struct Node
{
    Node<key_type, value_type> *parent;
    Pair<key_type, value_type> val;
    Node<key_type, value_type> *left, *right;
    bool is_nil;
};
namespace mytree
{
    template <class key_type, class value_type>
    class map
    {
    private:
        Node<key_type, value_type> *head;
        int SIZE;

    public:
        map()
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

        // void clear()
        //{
        //	Node<key_type, value_type>* temp_l, * temp_r;
        //	temp_l = head->left;
        //	temp_r = head->right;
        //		//for clearing left side
        //		while (temp_l->parent != head)
        //		{
        //			Node<key_type, value_type>* temp_d;
        //			if (temp_l->right != head)//if any right node exists
        //			{
        //				temp_d = temp_l->right;

        //				if (temp_d->left != head)
        //				{//if its left exists
        //					delete temp_d->left;
        //					SIZE--;
        //				}
        //				if (temp_d->right != head)
        //				{//if its right exists
        //					delete temp_d->right;
        //					SIZE--;
        //				}
        //				delete temp_l->right;
        //				SIZE--;
        //			}
        //			temp_l = temp_l->parent;
        //			delete head->left;
        //			head->left = temp_l;
        //			SIZE--;
        //		}
        //		//for clearing right side
        //		while (temp_r->parent != head)
        //		{
        //			Node<key_type, value_type>* temp_dr;
        //			if (temp_r->left != head)//if any left node exists
        //			{
        //				temp_dr = temp_r->left;
        //				if (temp_dr->left != head)
        //				{//if its left exists
        //					delete temp_dr->left;
        //					SIZE--;
        //				}
        //				if (temp_dr->right != head)
        //				{//if its right exists
        //					delete temp_dr->right;
        //					SIZE--;
        //				}
        //				delete temp_r->left;
        //				SIZE--;
        //			}
        //			temp_r = temp_r->parent;
        //			delete head->right;
        //			head->right = temp_r;
        //			SIZE--;
        //		}
        //		//clearing the root node
        //		if (temp_l->parent == head)
        //		{
        //			delete head->parent;
        //			head->left = head->right = head->parent = head;
        //			SIZE--;
        //		}
        //	}
        //}
        class iterator
        {
        private:
            Node<key_type, value_type> *ptr;
            friend class map;

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
                return ptr->val;
            }

            Pair<const key_type, value_type> *operator->()
            {
                return reinterpret_cast<Pair<const key_type, value_type> *>(&ptr->val);
            }
        };

        // BEGIN / END FUNCTION OF ITEARTORS
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
                return it.ptr->val.second;
            }
        }
        value_type &operator[](const key_type &key)
        {
            iterator it;
            it = this->find(key);
            if (it == end())
            {
                Pair<iterator, bool> ret;
                ret = this->insert({key, value_type()});
                return ret.first->second;
            }
            else
            {
                it.ptr->val.second;
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
                if (key == temp->val.first)
                {
                    itr.ptr = temp;
                    return itr;
                }
                else if (key < temp->val.first)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            itr.ptr =head; // if value not found in the tree
            return itr;
        }

        // INSERT FUNCTION
        /*void insert(const Pair<key_type, value_type>& val)
        {
            Node<key_type, value_type>* nn;
            nn = new Node<key_type, value_type>;
            nn->val = val;
            nn->left = nn->right =head;
            nn->is_nil = false;
            SIZE++;
            if (H->parent ==head)//for first node
            {
               head->parent =head->left =head->right = nn;//equalling dummy head to first node
                nn->parent =head;
                return;//to come out of function after inserting first value
            }
            Node<key_type, value_type>* temp;
            temp =head->parent;
            while (true)//infinite values(terminates on return)
            {
                if (val.first == temp->val.first)//for duplicate values
                {
                    delete nn;
                    SIZE--;
                    return;
                }
                else if (val.first < temp->val.first)//value is small
                {
                    if (temp->left ==head)//space avalaible
                    {
                        temp->left = nn;
                        nn->parent = temp;
                        if (val.first <head->left->val.first)//for smallest value
                           head->left = nn;
                        return;
                    }
                    else
                        temp = temp->left;//if no space avalaible
                }
                else//(val.first > temp->val.first)value is large
                {
                    if (temp->right ==head)//space available
                    {
                        temp->right = nn;
                        nn->parent = temp;
                        if (val.first >head->right->val.first)//largest value
                           head->right = nn;
                        return;
                    }
                    else
                        temp = temp->right;//if no space available
                }
            }
        }*/

        // INSERT OVERLOAD FUNCTION
        Pair<iterator, bool> insert(const Pair<key_type, value_type> &val)
        {

            Node<key_type, value_type> *new_node;
            new_node = new Node<key_type, value_type>;
            new_node->val = val;
            new_node->left = new_node->right =head;
            new_node->is_nil = false;
            SIZE++;

            Pair<iterator, bool> ret;
            iterator it;
            it.ptr = new_node;
            ret.first = it;
            ret.second = true;

            if (H->parent ==head) // for first node
            {
               head->parent =head->left =head->right = new_node; // equalling dummy head to first node
                new_node->parent =head;
                return ret; // to come out of function after inserting first value
            }
            Node<key_type, value_type> *temp;
            temp =head->parent;
            while (true) // infinite values(terminates on return)
            {
                if (val.first == temp->val.first) // for duplicate values
                {
                    it.ptr = temp;
                    ret.first = it;
                    ret.second = false;
                    delete new_node;
                    SIZE--;
                    return ret;
                }
                else if (val.first < temp->val.first) // value is small
                {
                    if (temp->left ==head) // space avalaible
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        if (val.first <head->left->val.first) // for smallest value
                           head->left = new_node;
                        return ret;
                    }
                    else
                        temp = temp->left; // if no space avalaible
                }
                else //(val.first > temp->val.first)value is large
                {
                    if (temp->right ==head) // space available
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        if (val.first >head->right->val.first) // largest value
                           head->right = new_node;
                        return ret;
                    }
                    else
                        temp = temp->right; // if no space available
                }
            }
        }

        void clearHelper(Node<key_type, value_type> *node)
        {
            if (node == nullptr || node->is_nil)
            {
                return;
            }

            // Recursively clear the left and right subtrees
            clearHelper(node->left);
            clearHelper(node->right);

            // Delete the current node
            delete node;
        }

        void clear()
        {
            // Start the clear operation from the root
            clearHelper(H->parent);

            // Reset the dummy head to its initial state
           head->parent =head->left =head->right =head;
            SIZE = 0;
        }
        void displayInOrder(Node<key_type, value_type> *node)
        {
            if (node !=head)
            {
                displayInOrder(node->left);
                std::cout << node->val << " ";
                displayInOrder(node->right);
            }
        }
        void display()
        {
            std::cout << "In-order traversal: ";
            displayInOrder(H->parent);
            std::cout << std::endl;
        }
    };
}
int main()
{
    std::pair<int, std::string> p;
    p.first = 15;
    p.second = "taha";
    mytree::map<int, std::string> m;

    // insert a pair
    //  m.insert(p);

    // insert a pair by initializing it in the brackets

    m.insert({7, "waj"});
    m.insert({25, "ibrahim"});
    m.insert({8, "hamad"});
    m.insert({6, "ahmed"});
    m.display();
    mytree::map<int, std::string>::iterator it;
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
        std::cout << "map is empty:" << std::endl;
    else
        std::cout << "map is not empty:" << std::endl;

    // full function
    if (m.full() == true)
        std::cout << "map is full:" << std::endl;
    else
        std::cout << "map is not full:" << std::endl;

    // size function
    std::cout << "total size:" << m.size() << std::endl;

    // m.clear();
    // std::cout << "total size:" << m.size() << std::endl;

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
    mytree::map<test,test>m1;
    m1.insert(t);
    mytree::map<test, test>::iterator sit;
    sit = m1.find(t);*/
    // std::cout << (*sit).first;

    return 0;
}