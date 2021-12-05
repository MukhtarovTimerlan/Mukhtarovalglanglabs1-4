#include "pch.h"
#include "CS.h"
#include "Verification.h"
#include <iomanip>

CS::CS() 
{
	MaxidCS++;
	this->id = MaxidCS;
	this->count_of_CS = Verification::getint("Input amount of CS(in range of [1,30): ", "Error. Use only integers that more than 0 and less than 30", 0, 30);
	this->count_of_CS_in_work = Verification::getint("Input amount of CS in work(CS in work < total number of CS: ", "Error. Use only integers that more than 0 and less than total number of CS", 0, count_of_CS);
	this->effective = Verification::getint("Input effective (in range of [1,100]): ", "Error. Use only integers that more than 0 and less than 100", 0, 100);
	this->name_CS = Verification::getstring("Input name of CS. Word length must be less than 30 symbols without empty input", "You input very long word or empty line.", 30);
}

CS::CS(std::ifstream& fin)
{
	{
		fin >> this->id;
		fin.ignore(10000, '\n');
		getline(fin, this->name_CS);
		fin >> this->count_of_CS
			>> this->count_of_CS_in_work
			>> this->effective
			>> this->stepenzahoda
			>> this->stepenishoda;
	}
}

void CS::ChangeCS()
{
	this->count_of_CS_in_work = Verification::getint("Input new amount CS in work.(CS in work < total number of CS: ", "Error. Use only integers that more than 0 and less than total number of CS", 0, count_of_CS);
}

void CS::SaveToFile(std::ofstream& fout)
{
	fout << id << std::endl
		<< name_CS << std::endl
		<< count_of_CS << std::endl
		<< count_of_CS_in_work << std::endl
		<< effective << std::endl
		<< stepenzahoda << std::endl
		<< stepenishoda << std::endl;
}
