#include "GasTransportSystem.h"

GasTransportSystem::GasTransportSystem(PipeNetwork& pipeNetwork_, CSNetwork& csNetwork_) : newPipeNetwork(pipeNetwork_), newCSNetwork(csNetwork_)
{
}

void GasTransportSystem::ConnectPipe()
{
	if (!newPipeNetwork.pipeNetwork.empty() && size(newCSNetwork.csNetwork)>1) {
		size_t idconnect, idout_, idin_;
		while (true) {
			idconnect = Verification::getsize_t("Input pipe id you want to connect", "Wrong input, use only integers.", 1, Pipe::MaxidPipe);
			if (newPipeNetwork.pipeNetwork[idconnect].remont == 0 && newPipeNetwork.pipeNetwork[idconnect].idin == 0) { break; }
			else {
				std::cout << "Error. Pipe mustn't be in repair or pipe has already taken part in connection.\n";
			}
		}
		idout_ = Verification::getsize_t("Input CS id you want to pipeout", "Wrong input, use only integers", 1, CS::MaxidCS);
		idin_ = Verification::getsize_t("Input CS id you want to pipein", "Wrong input, use only integers, id pipein must not be equal to id pipeout", 1, CS::MaxidCS, idout_);

		if (newPipeNetwork.pipeNetwork[idconnect].idin < 1 && newPipeNetwork.pipeNetwork[idconnect].idout < 1) {
			newPipeNetwork.pipeNetwork[idconnect].idin = idin_;
			newCSNetwork.csNetwork[idin_].stepenzahoda += 1;
			newPipeNetwork.pipeNetwork[idconnect].idout = idout_;
			newCSNetwork.csNetwork[idout_].stepenishoda += 1;
		}
		else {
			std::cout << "Pipe already connected: from CS id -" << newPipeNetwork.pipeNetwork[idconnect].idout << "- to CS id - " << newPipeNetwork.pipeNetwork[idconnect].idin << std::endl;
		}
	}
	else {
		std::cout << "There are no enough pipes or CS to make connection. At least should be 1 pipe and 2 CS\n";
	}
}

void GasTransportSystem::DisconnectPipe()
{
	if (!newPipeNetwork.pipeNetwork.empty()) {
		size_t iddisconnect;
		std::cout << "Input pipe id to disconnect:";
		iddisconnect = Verification::getsize_t("", "", 1, Pipe::MaxidPipe);
		if (newPipeNetwork.pipeNetwork[iddisconnect].idin < 1 && newPipeNetwork.pipeNetwork[iddisconnect].idout < 1) {
			std::cout << "Pipe hasnt got any connect.\n";
		}
		else
		{
			microdisconnect(iddisconnect, newPipeNetwork, newCSNetwork);
		}
	}
	else std::cout << "There are no pipes inputten to disconnect";
}

void GasTransportSystem::ShowConnections()
{
	int tabulation_20 = 20, tabulation_30 = 30;
	Console::PrintTitleText("\n\t\t\t\tTable of connections");
	std::cout << std::setw(tabulation_20) << "ID Pipe" << std::setw(tabulation_30) <<"Pipe has connection"<< std::setw(tabulation_30) << "CS id(pipe out)" << std::setw(tabulation_30) << "CS id(pipe in)" << std::endl;
	for (const auto& p : newPipeNetwork.pipeNetwork)
	{
		if (p.second.idin > 0 && p.second.idout > 0) {
			std::cout << std::setw(tabulation_20) << p.second.id << std::setw(tabulation_30) << "YES"<< std::setw(tabulation_30) << p.second.idout << std::setw(tabulation_30) << p.second.idin << std::endl;
		}
		else {
			std::cout << std::setw(tabulation_30) << p.second.id << std::setw(tabulation_30) << "NO" << std::setw(tabulation_30) << "NOPE" << std::setw(tabulation_30) << "NOPE" << std::endl;
		}
	}
}


void GasTransportSystem::microdisconnect(size_t iddisconnect, PipeNetwork& PipeNetwork, CSNetwork& CSNetwork)
{
	CSNetwork.csNetwork[PipeNetwork.pipeNetwork[iddisconnect].idin].stepenzahoda -= 1;
	CSNetwork.csNetwork[PipeNetwork.pipeNetwork[iddisconnect].idout].stepenishoda -= 1;
	PipeNetwork.pipeNetwork[iddisconnect].idin = 0;
	PipeNetwork.pipeNetwork[iddisconnect].idout = 0;
}

void GasTransportSystem::fillgraf()
{
	mapCSInUse.clear();
	mapPipeInUse.clear();
	for (auto& p : newPipeNetwork.pipeNetwork)
	{
		if (p.second.idin != 0) {
			mapPipeInUse.emplace(p.first, p.second);
		}
	}
	for (auto& p : newCSNetwork.csNetwork)
	{
		if (p.second.stepenishoda != 0 || p.second.stepenzahoda != 0) {
			mapCSInUse.emplace(p.first, p.second);
		}

	}
}



void GasTransportSystem::insort(PipeNetwork& sortPipeNetwork, CSNetwork& sortCSNetwork, std::unordered_map<size_t, CS>& idCSgraf, std::unordered_map<size_t, Pipe>& idPipegraf)
{
	size_t cycleschet = 0;
	size_t deletedpoints = 0;
	std::vector<size_t> deletedpipesid;
	std::vector<size_t> deletedcsid;
	deletedcsid.clear();
	bool flag;
	for (auto& id : idCSgraf) {
		flag = false;
		deletedpipesid.clear();
		if (sortCSNetwork.csNetwork[id.first].stepenzahoda == 0 && sortCSNetwork.csNetwork[id.first].stepenishoda != 0) {
			for (auto& it : idPipegraf) {
				if (sortPipeNetwork.pipeNetwork[it.first].idout == id.first) {
					deletedpipesid.push_back(it.first);
				}
			}
			flag = true;
			for (const auto& it : deletedpipesid) {
			microdisconnect(it, sortPipeNetwork, sortCSNetwork);
			idPipegraf.erase(it);
		}
			deletedpoints += 1;
			deletedcsid.push_back(id.first);

		}
			if (sortCSNetwork.csNetwork[id.first].stepenzahoda != 0 && sortCSNetwork.csNetwork[id.first].stepenishoda != 0) {
				cycleschet += 1;
			}
			if (sortCSNetwork.csNetwork[id.first].stepenzahoda == 0 && sortCSNetwork.csNetwork[id.first].stepenishoda == 0 && flag==false) {
				deletedcsid.push_back(id.first);
			}
		
	}
	for (const auto& id : deletedcsid) {
		idsorted.push_back(id);
		idCSgraf.erase(id);
	}
		if (deletedpoints == 0 && cycleschet == size(idCSgraf)) {
			return;
		}
		if (idCSgraf.empty()) {
			return;
		}
	GasTransportSystem::insort(sortPipeNetwork, sortCSNetwork, idCSgraf, idPipegraf);
}

void GasTransportSystem::SORT(PipeNetwork sortPipeNetwork, CSNetwork sortCSNetwork)
{
	idsorted.clear();
	fillgraf();
	size_t check = size(mapCSInUse);
	insort(sortPipeNetwork, sortCSNetwork,mapCSInUse,mapPipeInUse);
	if (!idsorted.empty() && check==size(idsorted)) {
		std::cout << "Topological sort: ";
		for (const auto id : idsorted) {
			std::cout << id << " ";
		}
	}
	else {
		std::cout << "Cant sort because of cycle.";
	}
}

std::vector<size_t> GasTransportSystem::findPath(size_t outID, size_t inID)
{
	const size_t SIZE = mapCSInUse.size();
	std::vector<size_t> resultPath;
	std::vector<std::vector<double>> a; a.resize(SIZE);
	std::vector<double> d; d.resize(SIZE); 
	std::vector<size_t> v; v.resize(SIZE); 
	std::unordered_map<size_t, size_t> mapIdIndex; 
	double temp, min;
	size_t minindex;
	size_t counter = 0;
	for (const auto& cs : mapCSInUse)
		mapIdIndex.emplace(cs.first, counter++);
	for (size_t i = 0; i < SIZE; i++)
		a[i].resize(SIZE);

	for (const auto& pipe : mapPipeInUse)
		a[mapIdIndex[pipe.second.idout]][mapIdIndex[pipe.second.idin]] = pipe.second.length;
	for (size_t i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	size_t begin_index = mapIdIndex[outID];
	d[begin_index] = 0;

	do {
		minindex = 10000;
		min = 10000;
		for (size_t i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{ 
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000)
		{
			for (size_t i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	if (d[mapIdIndex[inID]] == 10000)
		throw - 1;
	WAY = d[mapIdIndex[inID]];
	std::vector<size_t> ver; 
	size_t end = mapIdIndex[inID]; 
	ver.push_back(end); 
	size_t weight = d[end]; 
	while (end != begin_index) 
	{
		for (size_t i = 0; i < SIZE; i++) 
			if (a[i][end] != 0)  
			{
				size_t temp = weight - a[i][end]; 
				if (temp == d[i]) 
				{                 
					weight = temp; 
					end = i;       
					ver.push_back(i); 
				}
			}
	}
	for (size_t i = 0; i < ver.size(); i++)
	{
		for (const auto& el : mapIdIndex)
			if (el.second == ver[i])
				resultPath.push_back(el.first);
	}
	std::reverse(resultPath.begin(), resultPath.end());
	return resultPath;

}

void GasTransportSystem::printPath(const std::vector<size_t>& vectorPath)
{
	std::cout << "Length of the shortest way = " << WAY << '\n';
	Console::PrintTitleText("\n\nShortest way");
	std::cout << "|";
	for (const auto& id : vectorPath)
		std::cout << std::setw(10) << id << std::setw(10) << "|";
	std::cout << std::endl;
}
