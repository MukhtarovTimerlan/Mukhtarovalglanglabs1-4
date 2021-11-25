#include "pch.h"
#include "Pipe.h"
#include "Verification.h"

Pipe::Pipe()
{
	MaxidPipe++;
	this->id = MaxidPipe;
	this->length = Verification::getdouble("Input length of pipe in range [10,100] of km.", "Your input isn't valid.Use only numbers and '.'", 10, 100);
	this->diametr = Verification::getint("Input diametr of pipe in range [500,1400] of mm.", "Your input isn't valid. Use only integers numbers", 500, 1400);
	this->remont = Verification::getbool("Input repair status:\nYes-1, No - 0", "Your input isn't valid. Use only 1 or 0");
}

void Pipe::ChangePipe()
{
	this->remont = Verification::getbool("Choose new pipe condition.\n Yes - 1, No - 0", "Your input isn't valid. Use only 1 or 0");
}

