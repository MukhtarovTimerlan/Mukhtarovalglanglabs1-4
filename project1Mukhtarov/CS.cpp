#include "pch.h"
#include "CS.h"
#include "Verification.h"

CS::CS() 
{
	MaxidCS++;
	this->id = MaxidCS;
	this->count_of_CS = Verification::getint("Input amount of CS(in range of [1,30): ", "Error. Use only integers that more than 0 and less than 30", 0, 30);
	this->count_of_CS_in_work = Verification::getint("Input amount of CS in work(CS in work < total number of CS: ", "Error. Use only integers that more than 0 and less than total number of CS", 0, count_of_CS);
	this->effective = Verification::getint("Input effective (in range of [1,100]): ", "Error. Use only integers that more than 0 and less than 100", 0, 100);
	this->name_CS = Verification::getstring("Input name of CS. Word length must be less than 30 symbols without empty input", "You input very long word or empty line.", 30);
}

void CS::ChangeCS()
{
	this->count_of_CS_in_work = Verification::getint("Input new amount CS in work.(CS in work < total number of CS: ", "Error. Use only integers that more than 0 and less than total number of CS", 0, count_of_CS);
}
