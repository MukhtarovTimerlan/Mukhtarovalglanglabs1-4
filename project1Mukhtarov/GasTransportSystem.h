#pragma once
#ifndef GASTRANSPORTSYSTEM_H
#define GASTRANSPORTSYSTEM_H
#include "PipeNetwork.h"
#include "CSNetwork.h"
#include "Verification.h"
#include "Console.h"
#include <iomanip>
#include "CS.h"
#include "Pipe.h"
#include <vector>


class GasTransportSystem
{
public:
	GasTransportSystem(PipeNetwork&, CSNetwork&);
	void ConnectPipe();
	void DisconnectPipe();
	void ShowConnections();
	void SORT(PipeNetwork, CSNetwork);
	std::vector<size_t> findPath(size_t, size_t);
	void printPath(const std::vector<size_t>&);
	void fillgraf();
	std::unordered_map<size_t, CS> mapCSInUse;
	std::unordered_map<size_t, Pipe> mapPipeInUse;
	double WAY;
private:
	void insort(PipeNetwork&,CSNetwork&, std::unordered_map<size_t, CS>&, std::unordered_map<size_t, Pipe>&);
	void microdisconnect(size_t, PipeNetwork&, CSNetwork&);
	std::vector<size_t> idsorted;
	PipeNetwork& newPipeNetwork;
	CSNetwork& newCSNetwork;
};
#endif GASTRANSPORTSYSTEM_H
