#include <iostream>

template <class T>
struct Node
{
	T data;
	struct Node *next;

public:
};
template <class T>
class queue
{
	Node<T> *Front_data, *Back_data;
	int n;

public:
	queue()
	{
		Front_data = nullptr; 
		Back_data = nullptr;
		n = 0;
	}
	queue(const queue<T> &rhs)
	{

		Front_data = Back_data = nullptr;
		Node<T> *temp = rhs.Front_data;

		while (temp != nullptr)
		{
			this->push(temp->data);
			temp = temp->next;
		}
	}
	queue &operator=(const queue<T> &rhs)
	{
		this->clear();
		Front_data = Back_data = nullptr;
		Node<T> *temp = rhs.Front_data;

		this->Front_data = temp;
		while (temp != nullptr)
		{
			this->push(temp->data);
			temp = temp->next;
		}
		return *this;
	}
	bool operator<(const queue<T> &rhs)
	{
		Node<T> *temp;
		temp = this->Front_data;
		Node<T> *temp2;
		temp2 = rhs.Front_data;
		while (temp != nullptr || temp2 != nullptr)
		{

			if (temp->data < temp2->data)
			{
				return true;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}
	bool operator<=(const queue<T> &rhs)
	{
		Node<T> *temp;
		temp = this->Front_data;
		Node<T> *temp2;
		temp2 = rhs.Front_data;
		while (temp != nullptr || temp2 != nullptr)
		{

			if (temp->data <= temp2->data)
			{
				return true;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}
	bool operator>(const queue<T> &rhs)
	{
		Node<T> *temp;
		temp = this->Front_data;
		Node<T> *temp2;
		temp2 = rhs.Front_data;
		while (temp != nullptr || temp2 != nullptr)
		{

			if (temp->data > temp2->data)
			{
				return true;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}
	bool operator>=(queue<T> &rhs)
	{
		Node<T> *temp;
		temp = this->Front_data;
		Node<T> *temp2;
		temp2 = rhs.Front_data;
		while (temp != nullptr || temp2 != nullptr)
		{

			if (temp->data >= temp2->data)
			{
				return true;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}
	bool operator==(queue<T> &rhs)
	{
		Node<T> *temp;
		temp = this->Front_data;
		Node<T> *temp2;
		temp2 = rhs.Front_data;
		while (temp != nullptr || temp2 != nullptr)
		{
			if (temp->data == temp2->data)
			{
				return true;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}
	void push(int val)
	{
		Node<T> *temp;
		temp = new Node<T>();
		if (temp != nullptr)
		{

			temp->data = val;
			temp->next = nullptr;
		}
		if (Front_data == nullptr)
		{
			Front_data = temp;
			Back_data = temp;
		}
		else
		{
			Back_data->next = temp;
			Back_data = temp;
		}

		n++;
	}
	void pop()
	{
		if (Front_data == nullptr)
		{
			throw("Stack underflow");
		}
		else
		{
			Node<T> *temp;
			temp = Front_data->next;
			Front_data = temp;
			delete temp;
			if (Front_data == nullptr)
			{
				Back_data = nullptr;
			}

			n--;
		}
	}
	T Front()
	{
		if (Front_data == nullptr)
		{
			throw("Stack underflow");
		}
		else
		{
			return Front_data->data;
		}
	}
	T Back()
	{
		if (Back_data == nullptr)
		{
			throw("stack underflow");
		}
		else
		{
			return Back_data->data;
		}
	}
	bool empty()
	{
		if (Front_data == nullptr)
			return true;
		else
			return false;
	}
	int size()
	{
		if (n > 0)
		{
			return n;
		}
		else
			throw("Queue is empty");
	}
	bool full()
	{
	}
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}
	void display()
	{
		Node<T> *ptr = Front_data;
		while (ptr != nullptr)
		{
			std::cout << ptr->data << " -> ";
			ptr = ptr->next;
		}
        std::cout<<"\n------------------------\n";
	}

};
int main()
{
	try
	{
		queue<int> obj_1;
		obj_1.push(2);
		obj_1.push(3);
        obj_1.push(4);
		std::cout << "Obj_1 data is : ";
		obj_1.display();
		queue<int> obj_2 = obj_1;
        std::cout << "Obj_2 data is : ";
		obj_2.display();
	
		std::cout << "operator<  " << (obj_1 < obj_2) << std::endl;
		std::cout << "operator>=  " << (obj_1 <= obj_2) << std::endl;
        std::cout << "operator<  " << (obj_1 > obj_2) << std::endl;
		std::cout << "operator>=  " << (obj_1 >= obj_2) << std::endl;
		std::cout << "operator==  " << (obj_1 == obj_2) << std::endl;

	}
	catch (const char *msg)
	{
		std::cout << msg << std::endl;
	}

	return 0;
}