#include <iostream>
#include <queue>
#include <string>
using namespace std;
// class queue
// {
// private:
//    int id;
//    std::string name;
//    std::string **queue_name;

// public:
//     void set_Data(){
//         queue_name=new string*[3];
//         for (int i = 0; i < 3; i++)
//         queue_name[i] = new string[20];
//     }
// };

int main(int argc,char *argv[])
{

    std::queue<std::pair<int, std::string>> obj_1[20];
    int new_data = -1;
    int size;
    std::cout << "Enter number of queues";
    cin >> size;
    int id;
    std::string name;
    std::string *queue_name;
    queue_name = new std::string[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Name of queue is : ";
        cin >> queue_name[i][0];
    }
    int choice;
    int option;
    do
    {
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << "." << queue_name[i] << std::endl;
        }
        cout << "Enter index number ";
        cin >> choice;
        switch (option)
        {
        case 1:
        {
            new_data++;
            ;
            std::cout << "Enter name of patient";
            cin >> name;
            cout << "enter id of patient";
            cin >> id;
            obj_1[new_data].push({id, name});
        }
        break;
        case 2:
        {
            cout << "exting ...";
        }
        break;
        default:
            break;
        }
    } while (option != 2);
    return 0;
}
