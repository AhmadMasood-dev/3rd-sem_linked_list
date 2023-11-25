#include <iostream>
#include <queue>
#include <string>

struct Patient
{
    std::string name;
    int age;
};

void displayMenu()
{
    std::cout << "\nHospital Queue System\n";
    std::cout << "1. Add Patient to Queue\n";
    std::cout << "2. Remove Patient from Queue\n";
    std::cout << "3. Display Queue\n";
    std::cout << "4. Exit\n";
}

int main(int argc, char *argv[])
{
    std::cout<<"asd";
    // if (argc < 2)
    // {
    //     std::cout << "please give proper command line\n";
    // }
    // else
    // {
        int max_queues = 10;
        // char *ch = argv[1];
        // ch = ch - '0';
        int number_queues = 6;
        //std::cout<<"char is "<<ch<<"*ch"<<*ch<<" number quues "<<number_queues<<std::endl;
        if (number_queues <= 0 || number_queues > max_queues)
        {
            std::cout << "Invalid number of queues\n";
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
                    int index;
                    std::cout << "Enter the queue number to add patient: ";
                    std::cin >> index;

                    if (index < 0 || index >= number_queues)
                    {
                        std::cout << "Invalid queue number\n";
                    }
                    else
                    {
                        Patient patient;
                        std::cout << "Enter patient name: ";
                        std::cin >> patient.name;
                        std::cout << "Enter patient age: ";
                        std::cin >> patient.age;

                        hospitalQueues[index].push(patient);
                        std::cout << "Patient added to the queue\n";
                    }
                    break;
                }

                case 2:
                {
                    int index;
                    std::cout << "Enter the queue number to remove patient: ";
                    std::cin >> index;

                    if (index < 0 || index >= number_queues)
                    {
                        std::cout << "Invalid queue number\n";
                    }
                    else if (hospitalQueues[index].empty())
                    {
                        std::cout << "Queue is empty\n";
                    }
                    else
                    {
                        std::cout << "Patient removed from the queue\n";
                        hospitalQueues[index].pop();
                    }
                    break;
                }

                case 3:
                {
                    for (int i = 0; i < number_queues; ++i)
                    {
                        std::cout << "Queue " << i << ": ";
                        std::queue<Patient> copyQueue = hospitalQueues[i];
                        while (!copyQueue.empty())
                        {
                            std::cout << copyQueue.front().name << " ";
                            copyQueue.pop();
                        }
                        std::cout << "\n";
                    }
                    break;
                }

                case 4:
                    std::cout << "Exiting the program\n";
                    break;

                default:
                    std::cout << "Invalid choice\n";
                }

            } while (choice != 4);
        //}
    }
    return 0;
}
