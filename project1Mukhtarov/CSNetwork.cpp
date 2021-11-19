#include "pch.h"
#include "CSNetwork.h"
#include "CS.h"

void CSNetwork::AddCS()
{
	CS cs;
	csNetwork.emplace(cs.id, cs);
}

void CSNetwork::ChangeCS()
{

}
