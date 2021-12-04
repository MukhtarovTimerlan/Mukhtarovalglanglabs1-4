#include "GasTransportSystem.h"

GasTransportSystem::GasTransportSystem(PipeNetwork& pipeNetwork_, CSNetwork& csNetwork_) : newPipeNetwork(pipeNetwork_), newCSNetwork(csNetwork_)
{
}

void GasTransportSystem::ConnectPipe()
{
	size_t idconnect, idout_, idin_;
	idconnect = Verification::getsize_t("Input pipe id you want to connect", "Wrong input, use only integers", 0, Pipe::MaxidPipe);
	idout_ = Verification::getsize_t("Input CS id you want to pipeout", "Wrong input, use only integers", 0, CS::MaxidCS);
	idin_ = Verification::getsize_t("Input CS id you want to pipein", "Wrong input, use only integers and id pipein must not be equal to id pipeout", 0, CS::MaxidCS,idout_);
	if (newPipeNetwork.pipeNetwork[idconnect].idin < 1 && newPipeNetwork.pipeNetwork[idconnect].idout < 1) {
		newPipeNetwork.pipeNetwork[idconnect].idin = idin_;
		newCSNetwork.csNetwork[idin_].stepenzahoda +=1;
		newPipeNetwork.pipeNetwork[idconnect].idout = idout_;
		newCSNetwork.csNetwork[idout_].stepenishoda += 1;
	}
	else {
		std::cout << "Pipe already connected: from CS id -" << newPipeNetwork.pipeNetwork[idconnect].idin << "- to CS id - " << newPipeNetwork.pipeNetwork[idconnect].idout << std::endl;
	}
	
}

void GasTransportSystem::DisconnectPipe()
{
	size_t iddisconnect;
	std::cout << "Input pipe id to disconnect:";
	iddisconnect = Verification::getsize_t("", "", 0, Pipe::MaxidPipe);
	if (newPipeNetwork.pipeNetwork[iddisconnect].idin < 1 && newPipeNetwork.pipeNetwork[iddisconnect].idout < 1) {
		std::cout << "Pipe hasnt got any connect.\n";
	}
	else
	{
		microdisconnect(iddisconnect, newPipeNetwork, newCSNetwork);
	}
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

void GasTransportSystem::insort(PipeNetwork& sortPipeNetwork, CSNetwork& sortCSNetwork, std::vector<size_t>& idCSgraf, std::vector<size_t>& idPipegraf)
{
	size_t cycleschet = 0;
	size_t deletedpoints = 0;
	for (const auto id : idCSgraf) {
		if (sortCSNetwork.csNetwork[id].stepenzahoda == 0 && sortCSNetwork.csNetwork[id].stepenishoda != 0) {
			for (const auto it : idPipegraf) {
				if (sortPipeNetwork.pipeNetwork[it].idout == id) {
					microdisconnect(it, sortPipeNetwork, sortCSNetwork);
					idPipegraf.erase(std::find(idPipegraf.begin(), idPipegraf.end(), it));
				}
			}
			deletedpoints += 1;
			idsorted.push_back(id);
			idCSgraf.erase(std::find(idCSgraf.begin(), idCSgraf.end(),id));
		}
		if (sortCSNetwork.csNetwork[id].stepenzahoda != 0 && sortCSNetwork.csNetwork[id].stepenishoda != 0) {
			cycleschet += 1;
		}
		if (deletedpoints == 0 && cycleschet == size(idCSgraf)) {
			std::cout << "Cycle. Cant continue topological sort.";
			return;
		}
		if (sortCSNetwork.csNetwork[id].stepenzahoda == 0 && sortCSNetwork.csNetwork[id].stepenishoda == 0) {
			idsorted.push_back(id);
			idCSgraf.erase(std::find(idCSgraf.begin(), idCSgraf.end(), id));
		}
		if (idCSgraf.empty()) {
			return;
		}
		GasTransportSystem::insort(sortPipeNetwork, sortCSNetwork, idCSgraf,idPipegraf);
	}
}

void GasTransportSystem::SORT(PipeNetwork sortPipeNetwork, CSNetwork sortCSNetwork)
{
	idPipegraf.clear();
	idCSgraf.clear();
	for (const auto& p : sortPipeNetwork.pipeNetwork)
	{
		if (p.second.idin != 0) {
			idPipegraf.push_back(p.first);
		}
	}
	for (const auto& p : sortCSNetwork.csNetwork)
	{
		if (p.second.stepenishoda != 0 || p.second.stepenzahoda != 0) {
			idCSgraf.push_back(p.first);
		}
	}
	insort(sortPipeNetwork, sortCSNetwork,idCSgraf,idPipegraf);
	std::cout << "Topological sort: ";
	for (const auto& id : idsorted) {
		std::cout << id << " ";
	}
}

