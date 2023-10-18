#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "File name is not given in command \n";
	}
	else
	{
		if (argc == 2)
		{
			std::ifstream file(argv[1], std::ios::in);

			if (file.is_open())
			{
				std::cout << "File open\n";
				std::string line;
				while (getline(file, line))
				{
					std::cout << line;
				}
				file.close();
			}
			else
			{

				std::cout << "File doesnot exit" << std::endl;
			}
		}
	}
}