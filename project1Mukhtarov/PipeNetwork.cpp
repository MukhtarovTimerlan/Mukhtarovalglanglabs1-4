#include "pch.h"
#include "PipeNetwork.h"
#include <iomanip>
#include "Verification.h"
#include "Console.h"
using std::cout;
using std::endl;

void PipeNetwork::AddPipe()
{
	Pipe pipe;
	pipeNetwork.emplace(pipe.id, pipe);
}

void PipeNetwork::changePipe()
{
	size_t changeId;
	bool query;
	std::cout << "Current pipes: " << pipeNetwork.size() << std::endl
		<< "Id for available for change: ";
	for (const auto& el : pipeNetwork)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (pipeNetwork.empty())
	{
		Console::PrintErrorText("There are no pipes.");
		return;
	}
	while (true)
	{
		changeId = Verification::getsize_t("\nInput id for change: ",
			"You input invalid line or id that doesnt exists.", 1, Pipe::MaxidPipe);
		if (pipeNetwork.find(changeId) != pipeNetwork.end())
		{
			std::cout << "Pipe before change: "
				<< (pipeNetwork[changeId].remont ? "in repair" : "not in repair")
				<< std::endl;
			pipeNetwork[changeId].ChangePipe();
		}
		else
			Console::PrintErrorText("There is not pipe with this id");
		query = Verification::getbool("Do u want to continue change pipes? Yes - 1, No - 0\n",
			"Your input is invalid. Use only 1 or 0.\n");
		if (!query)
			break;
	}
}

/*void PipeNetwork::DeletePipe()
{
	size_t deleteId;
	bool query;
	std::cout << "Current CS: " << pipeNetwork.size() << std::endl
		<< "Id available for delete: ";
	for (const auto& el : pipeNetwork)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (pipeNetwork.empty())
	{
		Console::PrintErrorText("There are no pipes.");
		return;
	}
	while (true)
	{
		deleteId = Verification::getsize_t("\nInput id for delete: ",
			"You input invalid line or id that doesnt exists.", 1, Pipe::MaxidPipe);
		if (pipeNetwork.find(deleteId) != pipeNetwork.end())
		{
			std::cout << "Pipe before delete: \n";
			std::cout << "Diametr of pipe - " << pipeNetwork[deleteId].diametr << std::endl;
			std::cout << "Length of pipe - " << pipeNetwork[deleteId].length << std::endl;
			std::cout << "Repair status -" << pipeNetwork[deleteId].remont << std::endl;
			query = Verification::getbool("Are you sure that you want delete this pipe?\n Yes - 1, No - 0\n", "Your input is invalid. Use only 1 or 0.\n");
			if (query = 1)
				pipeNetwork.erase(deleteId);
			else
			{
				query = Verification::getbool("Do u want to continue delete pipe? Yes - 1, No - 0\n",
					"Your input is invalid. Use only 1 or 0.\n");
				if (!query)
					break;
			}
		}
		else
			Console::PrintErrorText("There is not pipe with this id");
		query = Verification::getbool("Do u want to delete pipes? Yes - 1, No - 0\n",
			"Your input is invalid. Use only 1 or 0.\n");
		if (!query)
			break;
	}
}*/

void PipeNetwork::ShowAllPipes()
{
	int tabulation_20 = 20, tabulation_30 = 30;
	Console::PrintTitleText("\n\t\t\t\tTable of pipes");
	std::cout << std::setw(tabulation_20) << "ID" << std::setw(tabulation_30) << "LENGTH" << std::setw(tabulation_30) << "DIAMETER" << std::setw(tabulation_30) << "REPAIR" << std::setw(tabulation_20) <<std::endl;
	for (const auto& p : pipeNetwork)
	{
		std::cout << std::setw(tabulation_20) << p.second.id << std::setw(tabulation_30) << p.second.length << std::setw(tabulation_30) << p.second.diametr << std::setw(tabulation_30) << p.second.remont << std::setw(tabulation_20) << std::endl;
	}
}

bool PipeNetwork::emptyPnetwork()
{
	if (pipeNetwork.empty())
		return true;
	else
		return false;
}

void PipeNetwork::FilterPipe()
{    
	bool query;
	query = Verification::getbool("If you want to see pipes in repair - input 1, another way - 0","Wrong input. Use only 1 or 0");
	for (const auto& el : pipeNetwork)
		if (el.second.remont == query)
			idfilter.push_back(el.first);

}

void PipeNetwork::ShowFilterPipe()
{
	int tabulation_20 = 20, tabulation_30 = 30, tableWidth = 131;
	Console::PrintTitleText("Filtered pipes");
	std::cout << std::setw(tabulation_20) << "ID" << std::setw(tabulation_30) << "LENGTH" << std::setw(tabulation_30) << "DIAMETER" << std::setw(tabulation_30) << "REPAIR" << std::setw(tabulation_20) << std::endl;
	for (const auto& id : idfilter)
	{
		std::cout << std::setw(tabulation_20) << pipeNetwork[id].id << std::setw(tabulation_30) << pipeNetwork[id].length << std::setw(tabulation_30) << pipeNetwork[id].diametr << std::setw(tabulation_30) << pipeNetwork[id].remont << std::setw(tabulation_20) << std::endl;
	}
}

void PipeNetwork::DeletePipe()
{
	if (pipeNetwork.empty())
	{
		Console::PrintErrorText("You dont add pipes");
	}
	bool query;
	query = Verification::getbool("\nDelete pipes without filter - 1, delete banch of pipes with filter - 0", "Wrong input");
	if (query) 
	{
		std::cout << "\n\nAmount of pipes: " << pipeNetwork.size() << std::endl
			<< "Id available for delete: ";
		for (const auto& el : pipeNetwork)
			std::cout << el.first << "  ";
		std::set<size_t> setIdForDelete = Verification::getset(
			"\nInput id for delete with whitespace: ",
			"\nOOOOOPs, input error");
		for (const auto id : setIdForDelete)
		{
			if (pipeNetwork.find(id) != pipeNetwork.end())
			{
				pipeNetwork.erase(id);
				Console::PrintTitleText("Pipe with id - " + std::to_string(id) + " was deleted.\n");
			}
			else
				Console::PrintErrorText("Pipe with id - " + std::to_string(id) + " wasnt finded\n");
		}
	}
	else 
	{
		FilterPipe();
		if (!idfilter.empty())
		{
			std::cout << "\n\nFiltered pipes" << std::endl;
			ShowFilterPipe();
			query = Verification::getbool("\nDelete all filtered CS - 1, part of them - 0: ",
				"\nInput error. Try again");
			if (query) 
			{
				for (const auto& i : idfilter)
					pipeNetwork.erase(i);
				Console::PrintTitleText("\nAll filtered pipes were deleted.");
			}
			else 
			{
				std::set<size_t> setIdForDelete = Verification::getset(
					"\nInput id for delete with whitespace: ",
					"\nInput error. Try again.");
				for (auto id : setIdForDelete)
				{
					auto it = std::find(idfilter.begin(), idfilter.end(), id);
					if (it != idfilter.end())
					{
						pipeNetwork.erase(id);
						Console::PrintTitleText("Pipe with id = " + std::to_string(id) + " was deleted!\n");
					}
					else
						Console::PrintErrorText("Pipe with id = " + std::to_string(id) + " wasnt finded!\n");
				}
			}
			idfilter.clear();
		}
		else
			Console::PrintErrorText("\nNo pipes with filter");
	}
	std::cout << std::endl;
	system("pause");
}

void PipeNetwork::BatchChangePipe()
{
	if (pipeNetwork.empty())
	{
		Console::PrintErrorText("\nYou dont add pipes");
	}
	bool query;
	bool repairStatus;
	query = Verification::getbool("\nChange pipes without filters - 1, delete banch of pipes with filter - 0 ",
		"\nBludabadee dabuda. Try again.");
	if (!query) 
	{
		FilterPipe();
		if (!idfilter.empty())
		{
			ShowFilterPipe();
			query = Verification::getbool("\nChange all filtered pipes - 1, change part of them - 0",
				"\nInput error.");
			if (!query)
			{
				std::set<size_t> setIdForChange = Verification::getset(
					"\nInput id for change with whitespace: ",
					"\nInput error.Try again.");
				repairStatus = Verification::getbool("\n\nNew status for pipes. In repair - 1, Not in repair - 0", "Input error.");
				for (const auto id : setIdForChange)
				{
					auto it = std::find(idfilter.begin(), idfilter.end(), id);
					if (it != idfilter.end())
					{
						pipeNetwork[id].remont = repairStatus;
						Console::PrintTitleText("Pipe with id - " + std::to_string(id) + " was changed");
					}
					else
						Console::PrintErrorText("Pipe with id - " + std::to_string(id) + " wasnt finded in filtered pipes.\n");
				}
			}
			else 
			{
				repairStatus = Verification::getbool("\n\nNew status for pipes. In repair - 1, Not in repair - 0", "Input error.");
				for (const auto& i : idfilter)
					pipeNetwork[i].remont = repairStatus;
				Console::PrintTitleText("\nAll filtered pipes were changed!");
			}
		}
		else
			Console::PrintErrorText("\nYou dont input any pipes.");
		idfilter.clear();
	}
	else 
	{
		ShowAllPipes();
		repairStatus = Verification::getbool("\n\nNew status for pipes. In repair - 1, Not in repair - 0", "Input error.");
		for (auto& el : pipeNetwork)
			el.second.remont = repairStatus;
		Console::PrintTitleText("\nAll choosen pipes were changed");
	}
	system("pause");
}

void PipeNetwork::SaveToFile(std::ofstream& fout)
{
	if (pipeNetwork.empty())
	{
		Console::PrintErrorText("You dont input pipes");
		return;
	}
	fout << Pipe::MaxidPipe << std::endl;
	for (auto& el : pipeNetwork)
		el.second.SaveToFile(fout);
	Console::PrintTitleText("\n\t\tPipes saved.");
}

void PipeNetwork::DownloadFromFile(std::ifstream& fin)
{
	size_t maxId;
	fin >> maxId;
	if (maxId > Pipe::MaxidPipe)
		Pipe::MaxidPipe = maxId;
	while (fin.peek() != ' ' && fin.peek() != -1)
	{
		Pipe pipe(fin);
		pipeNetwork.emplace(pipe.id, pipe);
		fin.ignore(1000, '\n');
	}
	Console::PrintTitleText("\nPipes are downloaded!");
}

