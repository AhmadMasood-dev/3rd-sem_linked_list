#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

struct Patient
{
    std::string name;
    int age;
    int Patient_id;
};

void displayMenu()
{
    std::cout << "\n-------Hospital Queue System-------\n";
    std::cout << "1. Add Patient to Queue\n";
    std::cout << "2. Remove Patient from Queue\n";
    std::cout << "3. Display Queue\n";
    std::cout << "4. save to file and Exit \n";
    std::cout << "------------------------------------------\n";
}
void queue_menu(std::string queue_names[], int size)
{
    std::cout << "\nQueues are : \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << queue_names[i] << std::endl;
    }
    std::cout << "------------------------------------------\n";
}
int main(int argc, char *argv[])
{
    try
    {

        if (argc < 2)
        {
            throw("please give proper command line\n");
        }
        else
        {
            char file_name[20] = "zain.txt";
            char read_or_not;
            fstream file1(file_name, std::ios::in);
            if (!file1.is_open())
            {
                throw("File cannot open due to error");
            }
            else
            {
                std::cout << "Enter y if you want to read from the file";
                cin >> read_or_not;
                std::cout << endl;
                if (read_or_not == 'y' || read_or_not == 'Y')
                {
                    string line;
                    while (getline(file1, line))
                    {
                        cout << line << std::endl;
                    }
                }
                file1.close();
            }
            int max_queues = 10;
            int number_queues;
            int k;
            char *ch = argv[1];
            number_queues = (*ch - '0');
            std::string queue_names[max_queues];
            int size;
            if (argc > 2)
            {
                if (number_queues != argc - 2)
                {
                    throw("The Entered size is not equal to number of given names");
                }
                else
                {
                    size = argc - 2;
                    for (int i = 0; i < size; i++)
                    {
                        queue_names[i] = argv[i + 2];
                    }
                }
            }
            else if (argc == 2)
            {
               
                size = number_queues;
                for (int i = 0; i < size; i++)
                {
                    std::cout << "Enter queue " << i + 1 << " name : ";
                    std::cin >> queue_names[i];
                }
            }

            if (number_queues <= 0 || number_queues > max_queues)
            {
                std::cout << "Invalid number of queues";
            }
            else
            {

                std::queue<Patient> hospitalQueues[max_queues];

                int choice;
                do
                {
                    displayMenu();
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;

                    switch (choice)
                    {
                    case 1:
                    {
                        queue_menu(queue_names, size);
                        int index;
                        std::cout << "Enter the queue number to add patient: ";
                        std::cin >> index;

                        if (index <= 0 || index >= number_queues + 1)
                        {
                            std::cout << "Invalid number of queues";
                        }
                        else
                        {
                            Patient patient;
                            std::cout << "Enter patient name: ";
                            std::cin >> patient.name;
                            std::cout << "Enter patient age: ";
                            std::cin >> patient.age;
                            while (patient.age < 0 || patient.age > 100)
                            {
                                std::cout << "Invalid age\nEnter again : ";
                                cin >> patient.age;
                            }

                            std::cout << "Enter patient ID: ";
                            std::cin >> patient.Patient_id;
                            hospitalQueues[index - 1].push(patient);
                            std::cout << "Patient Data is added to the queue successfully\n";
                        }
                        break;
                    }

                    case 2:
                    {
                        queue_menu(queue_names, size);
                        int index;
                        std::cout << "Enter the queue number to remove patient: ";
                        std::cin >> index;

                        if (index <= 0 || index >= number_queues + 1)
                        {
                            std::cout << "Invalid number of queues";
                        }
                        else if (hospitalQueues[index - 1].empty())
                        {
                            std::cout << "Queue is empty";
                        }
                        else
                        {
                            std::cout << "Patient removed from the queue\n";
                            hospitalQueues[index - 1].pop();
                        }
                        break;
                    }

                    case 3:
                    {
                        for (int i = 0; i < number_queues; ++i)
                        {
                            std::cout << queue_names[i] << " Queue Data \n";
                            std::queue<Patient> copyQueue = hospitalQueues[i];
                            while (!copyQueue.empty())
                            {
                                std::cout << "  " << k + 1 << ".  "
                                          << " Name is : " << copyQueue.front().name << "  Age is :  " << copyQueue.front().age << "  ID is :   " << copyQueue.front().Patient_id << ".\n";
                                copyQueue.pop();
                                k++;
                            }
                            k = 0;
                            std::cout << "\n";
                        }
                        break;
                    }

                    case 4:
                    {
                        ofstream file(file_name, std::ios::out | std::ios::app);
                        if (!file.is_open())
                        {
                            throw("File cannot open due to error");
                        }
                        else
                        {
                            for (int i = 0; i < number_queues; ++i)
                            {
                                file << queue_names[i] << " Queue Data \n";
                                std::queue<Patient> copyQueue = hospitalQueues[i];
                                while (!copyQueue.empty())
                                {
                                    file << "  " << k + 1 << ".  "
                                         << " Name is : " << copyQueue.front().name << "  Age is :  " << copyQueue.front().age << "  ID is :   " << copyQueue.front().Patient_id << "." << std::endl;
                                    copyQueue.pop();
                                    k++;
                                }
                                k = 0;
                                file << "\n";
                            }
                            file.close();
                            std::cout << "Data stored in text file successfully" << std::endl;
                            std::cout << "------------------------------------" << std::endl;
                        }
                    }
                        std::cout << "Exiting...\n";
                        break;

                    default:
                        std::cout << "Invalid choice\n";
                    }

                } while (choice != 4);
            }
        }
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}
