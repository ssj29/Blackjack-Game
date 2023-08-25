#include"FileRead.h"
#include"GameFlow.h"

void FileRead::CheckFile()
{
	file.open(file_name);

	if (file)
	{
		std::cout << "File Found......!!" << std::endl;
	}
	else
	{
		std::cout << "File not Found....!!\n Existing Application" << std::endl;
		system(0);
	}
}

void FileRead::PrintInput()
{
	char s;
	std::string s1;
	int count = 0;
	while (file)
	{	
		s = file.get();
		if (!isspace(s))
		{
			s1 = s1 + s;
			std::cout << s;
		}
		else
		{
			Inputs.push_back(s1);
			s1 = "";
			count++;
			std::cout <<"\n";
		}
	}
}


void FileRead::ReadInput()
{	
	std::cout << "Please Enter the file name" << std::endl;
	std::string fileName;
	std::cin >> fileName;
	SetName(fileName);
	
	std::cout << "Checking if file Exist....!!" << std::endl;
	CheckFile();

	std::cout << "Printing the input....\n\n" << std::endl;
	PrintInput();

	file.close();
	Start();
}

void FileRead::Start()
{
	std::cout << "STarting the game....\n";
	GameFlow g;
	for (int i = 0; i < Inputs.size(); i++)
	{
		g.GameStart(Inputs.at(i));
	}
}


