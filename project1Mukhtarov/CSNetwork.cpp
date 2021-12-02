#include "pch.h"
#include "CSNetwork.h"
#include "CS.h"
#include <iomanip>
#include "Verification.h"
#include "Console.h"

void CSNetwork::AddCS()
{
	CS cs;
	csNetwork.emplace(cs.id, cs);
}

void CSNetwork::ChangeCS()
{
	size_t changeId;
	bool query;
	std::cout << "Current CS: " << csNetwork.size() << std::endl
		<< "Id available for change: ";
	for (const auto& el : csNetwork)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (csNetwork.empty())
	{
		Console::PrintErrorText("There are no CS.");
		return;
	}
	while (true)
	{
		changeId = Verification::getsize_t("\nInput id for change: ",
			"You input invalid line or id that doesnt exists.", 1, CS::MaxidCS);
		if (csNetwork.find(changeId) != csNetwork.end())
		{
			std::cout << "CS before change: \n";
			std::cout << "Count of CS - " << csNetwork[changeId].count_of_CS << std::endl;
				std::cout << "Count of CS in work -" << csNetwork[changeId].count_of_CS_in_work<< std::endl;
			csNetwork[changeId].ChangeCS();
		}
		else
			Console::PrintErrorText("There is not CS with this id");
		query = Verification::getbool("Do u want to continue change CS? Yes - 1, No - 0\n",
			"Your input is invalid. Use only 1 or 0.\n");
		if (!query)
			break;
	}
}

/*void CSNetwork::DeleteCS()
{
	size_t deleteId;
	bool query;
	std::cout << "Current CS: " << csNetwork.size() << std::endl
		<< "Id available for delete: ";
	for (const auto& el : csNetwork)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (csNetwork.empty())
	{
		Console::PrintErrorText("There are no CS.");
		return;
	}
	while (true)
	{
		deleteId = Verification::getsize_t("\nInput id for delete: ",
			"You input invalid line or id that doesnt exists.", 1, CS::MaxidCS);
		if (csNetwork.find(deleteId) != csNetwork.end())
		{
			std::cout << "CS before delete: \n";
			std::cout << "Name of CS - " << csNetwork[deleteId].name_CS << std::endl;
			std::cout << "Count of CS - " << csNetwork[deleteId].count_of_CS << std::endl;
			std::cout << "Count of CS in work -" << csNetwork[deleteId].count_of_CS_in_work << std::endl;
			std::cout << "Effective of CS - " << csNetwork[deleteId].effective << std::endl;
			query = Verification::getbool("Are you sure that you want delete this CS?\n Yes - 1, No - 0\n", "Your input is invalid. Use only 1 or 0.\n");
			if (query == 1)
				csNetwork.erase(deleteId);
			else
			{query = Verification::getbool("Do u want to continue change CS? Yes - 1, No - 0\n",
					"Your input is invalid. Use only 1 or 0.\n");
			if (!query)
				break;
			}
		}
		else
			Console::PrintErrorText("There is not CS with this id");
		query = Verification::getbool("Do u want to continue change CS? Yes - 1, No - 0\n",
			"Your input is invalid. Use only 1 or 0.\n");
		if (!query)
			break;

	}

}*/

void CSNetwork::ShowAllCS()
{
	int tabulation_20 = 20, tabulation_30 = 30;
	Console::PrintTitleText("\n\t\t\t\tTable of CS");
	std::cout << std::setw(tabulation_20) << "ID" << std::setw(tabulation_30) << "Count of CS" << std::setw(tabulation_30) << "Count of CS in work" << std::setw(tabulation_30) << "Effective" << std::setw(tabulation_20) << "Name of CS"<< std::endl;
	for (const auto& p : csNetwork)
	{
		std::cout << std::setw(tabulation_20) << p.second.id << std::setw(tabulation_30) << p.second.count_of_CS << std::setw(tabulation_30) << p.second.count_of_CS_in_work << std::setw(tabulation_30) << p.second.effective << std::setw(tabulation_20) << p.second.name_CS << std::endl;
	}
}

bool CSNetwork::emptyCnetwork()
{
	if (csNetwork.empty())
		return true;
	else
		return false;
}

void CSNetwork::FilterCS()
{
	int command;
	std::cout << "\n\nChoose filter metod" << std::endl
		<< "1. Filter by name" << std::endl
		<< "2. Filter by percent of not working CS" << std::endl
		<< "3. Filter by 2 parametres" << std::endl;
	while (true)
	{
		std::cout << "\nInput command - ";
		command = Verification::getint("", "Wrong input. Use only 1-3 numbers.", 1, 3);
		switch (command)
		{
		case '1':
		{
			std::string nameCS;
			nameCS = Verification::getstring("Input name of CS. Word length must be less than 30 symbols without empty input", "You input very long word or empty line.", 30);
			for (const auto& el : csNetwork)
				if (el.second.name_CS == nameCS)
					idfilter.push_back(el.first);
			return;
		}
		case '2':
		{
			size_t lowPercent, upPercent, percent;
			lowPercent = Verification::getsize_t("Input lower percent in range of [0,100] in integers: ", "Wrong input. Use only integers 0-100", 0, 100);
			upPercent = Verification::getsize_t("Input higher percent in range of [0,100] in integers: ", "Wrong input. Use only integers 0-100", lowPercent, 100);
			for (const auto& el : csNetwork)
			{
				percent = static_cast<size_t>(round((static_cast<double>(el.second.count_of_CS) - el.second.count_of_CS_in_work) / el.second.count_of_CS * 100));
				if (percent >= lowPercent && percent <= upPercent)
					idfilter.push_back(el.first);
			}
			return;
		}
		case '3':
		{
			std::string nameCS;
			size_t lowPercent, upPercent, percent;
			nameCS = Verification::getstring("Input name of CS. Word length must be less than 30 symbols without empty input", "You input very long word or empty line.", 30);
			lowPercent = Verification::getsize_t("Input lower percent in range of [0,100] in integers: ", "Wrong input. Use only integers 0-100", 0, 100);
			upPercent = Verification::getsize_t("Input higher percent in range of [0,100] in integers: ", "Wrong input. Use only integers 0-100", lowPercent, 100);
			for (const auto& el : csNetwork)
			{
				percent = static_cast<size_t>(round((static_cast<double>(el.second.count_of_CS) - el.second.count_of_CS_in_work) / el.second.count_of_CS * 100));
				if (el.second.name_CS == nameCS && percent >= lowPercent && percent <= upPercent)
					idfilter.push_back(el.first);
			}
			return;
		}
		}
	}
}

void CSNetwork::ShowFilterCS()
{
	int tabulation_20 = 20, tabulation_30 = 30, tableWidth = 172;
	Console::PrintTitleText("Filtered CS");
	std::cout << std::setw(tabulation_20) << "ID" << std::setw(tabulation_30 + 1) << "NAME" << std::setw(tabulation_30) << "CountWorkShops" << std::setw(tabulation_30 + 10) << "CountWorkShopsInOperation" << std::setw(tabulation_30) << "EFFECTIVENESS" << std::setw(tabulation_20) << std::endl;
	for (const auto& id : idfilter)
	{
		std::cout << std::setw(tabulation_20) << csNetwork[id].id << std::setw(tabulation_30 + 1) << csNetwork[id].name_CS << std::setw(tabulation_30) << csNetwork[id].count_of_CS<< std::setw(tabulation_30 + 10) << csNetwork[id].count_of_CS_in_work << std::setw(tabulation_30) << csNetwork[id].effective << std::setw(tabulation_20) << std::endl;
	}

}
void CSNetwork::DeleteCS()
{
	if (csNetwork.empty())
	{
		Console::PrintErrorText("CS arent inputten!");
	}
	bool query;
	query = Verification::getbool("Delete 1 CS - 1, delete banch CS by filter - 0 ",
		"\nWrong input. Only 1 or 0\n");
	if (query)
	{
		std::cout << "\n\nAmount of CS: " << csNetwork.size() << std::endl
			<< "Id available for delete ";
		for (const auto& el : csNetwork)
			std::cout << el.first << "  ";
		std::set<size_t> setIdForDelete = Verification::getset(
			"\nInput id for delete with whitespace: ",
			"\nWrong input.Try again.");
		for (const auto id : setIdForDelete)
		{
			if (csNetwork.find(id) != csNetwork.end())
			{
				csNetwork.erase(id);
				Console::PrintTitleText("CS with id = " + std::to_string(id) + " was deleted!\n");
			}
			else
				Console::PrintErrorText("CS with id = " + std::to_string(id) + " wasnt founded!\n");
		}
	}
	else 
	{
		FilterCS();
		if (!idfilter.empty())
		{
			std::cout << "\n\nFiltered CS" << std::endl;
			ShowFilterCS();
			query = Verification::getbool("\n Delete all filtered CS - 1, part of them - 0: ",
				"\nWrong input. Only 1 or 0");
			if (query) 
			{
				for (const auto i : idfilter)
					csNetwork.erase(i);
				Console::PrintTitleText("\n\nCS were deleted.");
			}
			else 
			{
				std::set<size_t> setIdForDelete = Verification::getset(
					"\nInput id for change with whitespace: ",
					"\nWrong input, try again.");
				for (auto id : setIdForDelete)
				{
					auto it = std::find(idfilter.begin(), idfilter.end(), id);
					if (it != idfilter.end())
					{
						csNetwork.erase(id);
						Console::PrintTitleText("CS with id = " + std::to_string(id) + " was deleted.\n");
					}
					else
						Console::PrintErrorText("CS with id = " + std::to_string(id) + " wasnt finded in filtered CS!\n");
				}
			}
			idfilter.clear();
		}
		else
			Console::PrintErrorText("\nNo CS with this filter");
	}
	std::cout << std::endl;
	system("pause");
}


void CSNetwork::BatchChangeCS()
{
	if (csNetwork.empty())
		Console::PrintErrorText("\nYou dont input CS.");
	bool query;
	query = Verification::getbool("\nChange all CS - 1, CS by filter - 0 ",
		"\nInput error.Try again.");
	if (!query)
	{
		FilterCS();
		if (!idfilter.empty())
		{
			ShowFilterCS();
			query = Verification::getbool("\nChange all filtered CS - 1, only part of them - 0",
				"\nWrong input. Only 1 or 0");
			if (query)
			{
				for (const auto& i : idfilter)
				{
					std::cout << "\n\nCS with id - " << csNetwork[i].id << " has amount of workshops: " << csNetwork[i].count_of_CS << std::endl
						<< "Workshops in work - " << csNetwork[i].count_of_CS_in_work << std::endl;
					csNetwork[i].count_of_CS_in_work = Verification::getint("Input new amount of workshops in work(less than all workshops: ",
						"Input error. Only integers in right interval", 0, csNetwork[i].count_of_CS);
					Console::PrintTitleText("CS with id - " + std::to_string(i) + " was changed");
				}
				Console::PrintTitleText("\n\nAll filtered CS were changed");
			}
			else 
			{
				std::set<size_t> setIdForChange = Verification::getset(
					"\nInput CS for change by whitespace: ",
					"\nWrong input. Try again.");
				for (const auto id : setIdForChange)
				{
					auto it = std::find(idfilter.begin(), idfilter.end(), id);
					if (it != idfilter.end())
					{
						std::cout << "\n\nCS with id " << csNetwork[id].id << " has amount of workshops: " << csNetwork[id].count_of_CS << std::endl
							<< "Workshops in work -  " << csNetwork[id].count_of_CS_in_work << std::endl;
						csNetwork[id].count_of_CS_in_work = Verification::getint("Input new amount of workshops in work(less than all workshops: ",
							"Input error. Only integers in right interval", 0, csNetwork[id].count_of_CS);
						Console::PrintTitleText("CS with id - " + std::to_string(id) + " was changed");
					}
					else
						Console::PrintErrorText("CS with id - " + std::to_string(id) + " wasnt finded.");
				}
			}
			idfilter.clear();
		}
		else
			Console::PrintErrorText("\nNo CS with this filter.");
	}
	else
	{
		ShowAllCS();
		for (auto& el : csNetwork)
		{
			std::cout << "\n\nCS with id -" << el.first << " has workshops: " << el.second.count_of_CS << std::endl
				<< "Workshops in work: " << el.second.count_of_CS_in_work << std::endl;
			el.second.count_of_CS_in_work = Verification::getint("Input new amount of workshops in work(less than all workshops: ",
				"Ooops. Sth going wrong. Try again", 0, el.second.count_of_CS);
			Console::PrintTitleText("CS with id - " + std::to_string(el.first) + " was changed");
		}
		Console::PrintTitleText("\n\nAll CS were changed");
	}
	idfilter.clear();
	system("pause");
}

void CSNetwork::SaveToFile(std::ofstream& fout)
{
	size_t percent = 0;
	if (csNetwork.empty())
	{
		Console::PrintErrorText("You dont add CS.");
		return;
	}
	fout << CS::MaxidCS << std::endl;
	for (auto& el : csNetwork)
		el.second.SaveToFile(fout);
	Console::PrintTitleText("\n\t\tCS are saved.");
}
void CSNetwork::DownloadFromFile(std::ifstream& fin)
{
	csNetwork.clear();
	size_t maxId;
	fin >> maxId;
	CS::MaxidCS = maxId;
	while (fin.peek() != ' ' && fin.peek() != -1)
	{
		CS compressorStation(fin);
		csNetwork.emplace(compressorStation.id, compressorStation);
		fin.ignore(1000, '\n');
	}
	Console::PrintTitleText("\nCS are downloaded");
}