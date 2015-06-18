#include<iostream>

int main(void)
{
	int ival;
	while(std::cin >> ival, !std::cin.eof())
	{
		if(std::cin.bad())
		{
			std::cout << "IO stream corrupted! " << std::endl;
			return -1;
		}
		if(std::cin.fail())
		{
			std::cout << "data illegal, try again! " << std::endl;
			std::cin.clear();
			std::cin.ignore(1024,'\n');
			continue;
		}
		std::cout << "ival = " << ival << std::endl;
	}
	return 0;
}
