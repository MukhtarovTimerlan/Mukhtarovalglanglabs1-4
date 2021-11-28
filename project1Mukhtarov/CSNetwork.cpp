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

void CSNetwork::DeleteCS()
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
			if (query = 1)
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

}

void CSNetwork::ShowAllCS()
{
	int tabulation_20 = 20, tabulation_30 = 30;
	Console::PrintTitleText("\n\t\t\t\tTable of CS");
	std::cout << "|" << std::setw(tabulation_20) << "ID" << std::setw(tabulation_30) << "Count of CS" << std::setw(tabulation_30) << "Count of CS in work" << std::setw(tabulation_30) << "Effective" << std::setw(tabulation_20) << "|" << std::endl;
	for (const auto& p : csNetwork)
	{
		std::cout << "|" << std::setw(tabulation_20) << p.second.id << std::setw(tabulation_30) << p.second.count_of_CS << std::setw(tabulation_30) << p.second.count_of_CS_in_work << std::setw(tabulation_30) << p.second.effective << std::setw(tabulation_20) << "|" << std::endl;
	}
}

bool CSNetwork::emptyCnetwork()
{
	if (csNetwork.empty())
		return true;
	else
		return false;
}
