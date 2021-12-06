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
private:
	void insort(PipeNetwork&,CSNetwork&, std::vector<size_t>&, std::vector<size_t>&);
	void microdisconnect(size_t, PipeNetwork&, CSNetwork&);
	std::vector<size_t> idsorted;
	std::vector<size_t> idCSgraf;
	std::vector<size_t> idPipegraf;
	PipeNetwork& newPipeNetwork;
	CSNetwork& newCSNetwork;
};
#endif GASTRANSPORTSYSTEM_H
