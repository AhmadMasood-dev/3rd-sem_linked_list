#include <iostream>
#include <string>
template <class T1, class T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair(T1 fi = T1(), T2 se = T2()) // giving default values
    {
        first = fi;
        second = se;
    }
};
template <class key_type, class value_type>
struct tnode
{
    tnode<key_type, value_type> *parent;
    Pair<key_type, value_type> val;
    tnode<key_type, value_type> *left, *right;
    bool is_nil;
};
namespace cs211
{
    template <class key_type, class value_type>
    class map
    {
    private:
        tnode<key_type, value_type> *H;
        int SIZE;

    public:
        map()
        {
            H = new tnode<key_type, value_type>;
            H->parent = H->left = H->right = H;
            H->is_nil = true;
            SIZE = 0;
        }

        bool empty() const
        {
            if (H->parent == H)
                return true;
            else
                return false;
        }
        bool full() const
        {
            tnode<key_type, value_type> *temp;
            temp = new tnode<key_type, value_type>;
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
        //	tnode<key_type, value_type>* temp_l, * temp_r;
        //	temp_l = H->left;
        //	temp_r = H->right;
        //		//for clearing left side
        //		while (temp_l->parent != H)
        //		{
        //			tnode<key_type, value_type>* temp_d;
        //			if (temp_l->right != H)//if any right node exists
        //			{
        //				temp_d = temp_l->right;

        //				if (temp_d->left != H)
        //				{//if its left exists
        //					delete temp_d->left;
        //					SIZE--;
        //				}
        //				if (temp_d->right != H)
        //				{//if its right exists
        //					delete temp_d->right;
        //					SIZE--;
        //				}
        //				delete temp_l->right;
        //				SIZE--;
        //			}
        //			temp_l = temp_l->parent;
        //			delete H->left;
        //			H->left = temp_l;
        //			SIZE--;
        //		}
        //		//for clearing right side
        //		while (temp_r->parent != H)
        //		{
        //			tnode<key_type, value_type>* temp_dr;
        //			if (temp_r->left != H)//if any left node exists
        //			{
        //				temp_dr = temp_r->left;
        //				if (temp_dr->left != H)
        //				{//if its left exists
        //					delete temp_dr->left;
        //					SIZE--;
        //				}
        //				if (temp_dr->right != H)
        //				{//if its right exists
        //					delete temp_dr->right;
        //					SIZE--;
        //				}
        //				delete temp_r->left;
        //				SIZE--;
        //			}
        //			temp_r = temp_r->parent;
        //			delete H->right;
        //			H->right = temp_r;
        //			SIZE--;
        //		}
        //		//clearing the root node
        //		if (temp_l->parent == H)
        //		{
        //			delete H->parent;
        //			H->left = H->right = H->parent = H;
        //			SIZE--;
        //		}
        //	}
        //}
        class iterator
        {
        private:
            tnode<key_type, value_type> *ptr;
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
            it.ptr = H->left;
            return it;
        }

        iterator end() const
        {
            iterator it;
            it.ptr = H->right;
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
            tnode<key_type, value_type> *temp;
            temp = H->parent;
            iterator itr;
            while (temp != H)
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
            itr.ptr = H; // if value not found in the tree
            return itr;
        }

        // INSERT FUNCTION
        /*void insert(const Pair<key_type, value_type>& val)
        {
            tnode<key_type, value_type>* nn;
            nn = new tnode<key_type, value_type>;
            nn->val = val;
            nn->left = nn->right = H;
            nn->is_nil = false;
            SIZE++;
            if (H->parent == H)//for first node
            {
                H->parent = H->left = H->right = nn;//equalling dummy head to first node
                nn->parent = H;
                return;//to come out of function after inserting first value
            }
            tnode<key_type, value_type>* temp;
            temp = H->parent;
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
                    if (temp->left == H)//space avalaible
                    {
                        temp->left = nn;
                        nn->parent = temp;
                        if (val.first < H->left->val.first)//for smallest value
                            H->left = nn;
                        return;
                    }
                    else
                        temp = temp->left;//if no space avalaible
                }
                else//(val.first > temp->val.first)value is large
                {
                    if (temp->right == H)//space available
                    {
                        temp->right = nn;
                        nn->parent = temp;
                        if (val.first > H->right->val.first)//largest value
                            H->right = nn;
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

            tnode<key_type, value_type> *new_node;
            new_node = new tnode<key_type, value_type>;
            new_node->val = val;
            new_node->left = new_node->right = H;
            new_node->is_nil = false;
            SIZE++;

            Pair<iterator, bool> ret;
            iterator it;
            it.ptr = new_node;
            ret.first = it;
            ret.second = true;

            if (H->parent == H) // for first node
            {
                H->parent = H->left = H->right = new_node; // equalling dummy head to first node
                new_node->parent = H;
                return ret; // to come out of function after inserting first value
            }
            tnode<key_type, value_type> *temp;
            temp = H->parent;
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
                    if (temp->left == H) // space avalaible
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        if (val.first < H->left->val.first) // for smallest value
                            H->left = new_node;
                        return ret;
                    }
                    else
                        temp = temp->left; // if no space avalaible
                }
                else //(val.first > temp->val.first)value is large
                {
                    if (temp->right == H) // space available
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        if (val.first > H->right->val.first) // largest value
                            H->right = new_node;
                        return ret;
                    }
                    else
                        temp = temp->right; // if no space available
                }
            }
        }

        void clearHelper(tnode<key_type, value_type> *node)
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
            H->parent = H->left = H->right = H;
            SIZE = 0;
        }
    };
}
int main()
{
    std::pair<int, std::string> p;
    p.first = 15;
    p.second = "taha";
    cs211::map<int, std::string> m;

    // insert a pair
    //  m.insert(p);

    // insert a pair by initializing it in the brackets

    m.insert({7, "waj"});
    m.insert({25, "ibrahim"});
    m.insert({8, "hamad"});
    m.insert({6, "ahmed"});

    cs211::map<int, std::string>::iterator it;
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
    cs211::map<test,test>m1;
    m1.insert(t);
    cs211::map<test, test>::iterator sit;
    sit = m1.find(t);*/
    // std::cout << (*sit).first;

    return 0;
}