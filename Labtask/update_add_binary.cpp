#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct student
{
    int rollnumber;
    char name[20];
};

void data(student s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter roll number of student " << i + 1 << std::endl;
        std::cout << "Roll number is: ";
        std::cin >> s[i].rollnumber;
        std::cin.ignore();
        std::cout << "Name is: ";
        std::cin.getline(s[i].name, sizeof(s[i].name));
    }
}

void store(char filename[], student s[], int size)
{
    std::ofstream myfile(filename, std::ios::binary);
    if (!myfile.is_open())
    {
        std::cout << "File cannot be opened" << std::endl;
    }
    else
    {
        myfile.write((char *)s, sizeof(student) * size);
        std::cout << "Stored data successfully" << std::endl;
        myfile.close();
    }
}

void exist(std::fstream &file)
{
    student std2;
    std::cout << "Student Records are : " << std::endl;
    while (file.read((char *)&std2, sizeof(student)))
    {
        std::cout << "Roll number is : " << std2.rollnumber << std::endl;
        std::cout << "Name is : " << std2.name << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}

void display(student s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        std::cout << "Roll number is : " << s[i].rollnumber << std::endl;
        std::cout << "Name is : " << s[i].name << std::endl;
    }
}

int main(int argc, char *argv)
{
    // std::fstream file("record.bin", std::ios::binary | std::ios::in);
    // if (!file.is_open())
    // {
    //     std::cout << "File does not exist" << std::endl;
    //     file.open("record.bin", std::ios::out | std::ios::binary);
    // }
    // else
    // {
    //     exist(file);
    // }
    // int size;
    // std::cout << "Enter the number of students: ";
    // std::cin >> size;
    // student std1[20];
    // data(std1, size);
    // if (argc == 3)
    // {
    //     int flag = std::stoi(argv[1]);
    //     for (int i = 0; i < size; i++)
    //     {
    //         if (flag == std1[i].rollnumber)
    //         {
    //             std::cin.ignore();
    //             strcpy(std1[i].name, argv[2]);
    //         }
    //     }
    // }
    // if (argc == 4)
    // {
    //     int flag = std::stoi(argv[2]);
    //     char n[20] = argv[3];
    //     size++;
    //     std1[size - 1].rollnumber = flag;
    //     std::cin.ignore();
    //     std::strcpy(std1[size - 1].name, argv[3]);
    // }
    // store("record.bin", std1, size);
    // display(std1, size);

    return 0;
}
