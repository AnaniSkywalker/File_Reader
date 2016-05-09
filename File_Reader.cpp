//Author: Anani Assoutovi
//CS1
//Basic File Reader

#include <iostream>		//To Support input/output stream such as cout, cin
#include <string>		// To support string lines
#include <fstream>		// TO support the file stream such as, ifstream (for inputing a File) and ofstream(for outputing the File)
#include <climits>

int ReadFile(std::string filename, int &Max_Value, int &Min_Value, int &size); // I will be calling min and max by reference, and this is just a prototype

int main()
{
	std::string filename;
	int minimum, maximum, size = 0;
	ReadFile(filename, maximum, minimum, size);

	system("pause");
}

int ReadFile(std::string filename, int &Max_Value, int &Min_Value, int &size)
{
	std::fstream myfile;
	int temp = 0, total = 0;
	std::cout << "Please Enter The Name Of The File" << std::endl;
	std::cin >> filename;

	myfile.open(filename);
	std::string lines;
	Max_Value = 0, Min_Value = 0, size = 0;

	while (!myfile.eof())
	{
		getline(myfile, lines);
		temp = atoi(lines.c_str());

		if (temp > Max_Value)
			Max_Value = temp;
		if (temp < Min_Value)
			Min_Value = temp;
		size++;
		total += temp;
	}
	std::cout << "------------------------------------------------------------------------------"<< std::endl;
	std::cout << "The Total Number of Integers In The File Is: " << size << std::endl;
	std::cout << "The Maximum Number In The File Is: " << Max_Value << std::endl;
	std::cout << "The Minimum Number In The File Is: " << Min_Value << std::endl;
	std::cout << "The Sum Of All The Integers In The File Is: " << total << std::endl;
	std::cout << "------------------------------------------------------------------------------\n" << std::endl;
	myfile.close();

	return 0;
}
//12