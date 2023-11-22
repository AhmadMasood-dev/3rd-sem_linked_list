#include <iostream>
using namespace std;
template <class T>
class queue_hospital
{
private:
    T *array;
    int Front_data, Back_data;
    int size;

public:
    queue_hospital(int queueSize)
    {
        Front_data = -1;
        Back_data = -1;
        size = queueSize;
        array = new T[size];
    }
    ~queue_hospital()
    {
    }
    bool isFull()
    {
        {
            return (Back_data + 1) % size == Front_data;
        }
    }
    void push(T val)
    {
        if ((Back_data + 1) % size == Front_data)
        {
            throw("This Queue is full");
        }
        else
        {
            Back_data = (Back_data + 1) % size;
            array[Back_data] = val;
        }
    }
    T pop()
    {
        T x;
        if (Front_data == Back_data)
        {
            throw("Queue is empty");
        }
        else
        {
            Front_data = (Front_data + 1) % size;

            x = array[Front_data];
        }
        return x;
    }
    bool isEmpty()
    {
        if (Back_data == Front_data)
        {
            return true;
        }
        else
            return false;
    }
    T Front()
    {
        if (Front_data == -1)
        {
            throw("queue underflow");
        }
        else
        {
            return array[Front_data];
        }
    }
    T Back()
    {
        if (Back_data == -1)
        {
            throw("queue underflow");
        }
        else
        {
            return array[Back_data];
        }
    }
    void display()
    {

        int i = Front_data + 1;

        do
        {
            cout << "i is : " << array[i] << "\n";
            i = (i + 1) % size;
        } while (i != (Back_data + 1) % size);

        cout << endl;
    }
    };
    template <class T>
    class HospitalQueueSystem : public queue_hospital<T>
    {
         private:
        int numQueues;
    public:
        HospitalQueueSystem(int numQueues, int queueSize) : QueueHospital(queueSize)
        {
            this->numQueues = numQueues;
        }

        void enqueue(int queueIndex, const T &patientName)
        {
            if (queueIndex >= 0 && queueIndex < this->numQueues)
            {
                this->push(patientName);
                cout << patientName << " added to the queue " << queueIndex << ".\n";
            }
            else
            {
                cout << "Invalid queue index.\n";
            }
        }

        void dequeue(int queueIndex)
        {
            if (queueIndex >= 0 && queueIndex < this->numQueues)
            {
                try
                {
                    T patient = this->pop();
                    cout << patient << " removed from the queue " << queueIndex << ".\n";
                }
                catch (const char *e)
                {
                    cout << e << "\n";
                }
            }
            else
            {
                cout << "Invalid queue index.\n";
            }
        }

        void viewQueue()
        {
            cout << "Queue contents:\n";
            this->display();
        }

   
    };

int main()
{
    try
    {
        int numQueues = 3;
        int queueSize = 4;

        HospitalQueueSystem <string> hospital(numQueues, queueSize);

        hospital.enqueue(0, "John");
        hospital.enqueue(0, "Alice");
        hospital.viewQueue();
      
        hospital.dequeue(0);
        hospital.viewQueue();
        hospital.enqueue(1, "Bob");
        hospital.enqueue(2, "Charlie");
        hospital.viewQueue();
        hospital.viewQueue();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}