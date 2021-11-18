#include "pch.h"
#include "Pipe.h"

void Pipe::set_id(int id_)
{
	Pipe::id = id_;
}

int Pipe::get_id()
{
	return Pipe::id;
}

void Pipe::set_diametr(int diametr_)
{
	Pipe::diametr = diametr_;
}

int Pipe::get_diametr()
{
	return Pipe::diametr;
}

void Pipe::set_length(double length_)
{
	Pipe::length = length_;
}

double Pipe::get_length()
{
	return Pipe::length;
}

void Pipe::set_remont(bool remont_)
{
	Pipe::remont = remont_;
}

bool Pipe::get_remont()
{
	return Pipe::remont;
}
