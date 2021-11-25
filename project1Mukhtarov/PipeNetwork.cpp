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
	std::cout << "Âñåãî äîáàâëåíî òðóá: " << size(pipeCollection) << std::endl
		<< "Id äîñòóïíûå äëÿ ðåäàêòèðîâàíèÿ: ";
	for (const auto& el : pipeCollection)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (pipeCollection.empty())
	{
		Console::PrintErrorText("Âû íå äîáàâèëè íè îäíîé òðóáû, ðåäàêòèðîâàíèå íåäîñòóïíî!");
		return;
	}
	while (true)
	{
		changeId = Verification::getsize_t("\nInput id for change: ",
			"You input invalid line or id that doesnt exists.", 1, Pipe::MaxidPipe);
		if (pipeCollection.find(changeId) != pipeCollection.end())
		{
			std::cout << "Èçíà÷àëüíîå ñîñòîÿíèå òðóáû: "
				<< (pipeCollection[changeId].repair ? "â ðåìîíòå" : "íå â ðåìîíòå")
				<< std::endl;
			pipeCollection[changeId].GhangePipe();
		}
		else
			Console::PrintErrorText("Ïî óêàçàííîìó id íå íàéäåíî íè îäíîé òðóáû!!!");
		query = verification::GetBoolValue("\n\nÕîòèòå ëè âû ïðîäîëæèòü ðåäàêòèðîâàòü òðóáû, åñëè äà, òî êëèêíèòå \"y\", åñëè æå íåò, òî íàæìèòå íà \"n\": ",
			"\nÍåèçâåñòíàÿ êîìàíäà! Ïîâòîðèòå ââîä ïî óêàçàííûì âûøå ïðàâèëàì, êëèêíèòå ïî \"y\", åñëè äà, ïî \"n\", åñëè íåò!!!");
		if (!query)
			break;
	}
}
