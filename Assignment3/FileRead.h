#pragma once
#include<iostream>
#include<fstream>
#include<vector>
class FileRead {
	public:
		std::ifstream file;
		std::vector<std::string> Inputs;
		void CheckFile();
		void ReadInput();
		void PrintInput();
		void Start();

		void SetName(std::string name)
		{
			file_name = name;
		}
		std::string GetName()
		{
			return file_name;
		}
	private:
		std::string file_name;
};