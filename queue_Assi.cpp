#include <iostream>
#include <queue>
using namespace std;

int main()
{

    std::queue<std::pair<int, std::string>> obj_1[20];

    int size;
    std::cout << "Enter number of queues";
    cin >> size;
    int id;
    std::string name;
    std::string queue_name[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Name of queue is : ";
        cin >> queue_name[i];
    }
    int option;
    do
    {
        for (int i = 0; i < size; i++)
        {
            cout << "queue is " << queue_name[i] << std::endl;
        }

    } while (option != 3);
    switch (option)
    {
    case 1:
    {
        std::cout << "Enter name of patient";
        cin >> name;
        cout << "enter id of patient";
        cin >> id;
        obj_1[0].push({id,name});
    }

    break;

    default:
        break;
    }
    return 0;
}
