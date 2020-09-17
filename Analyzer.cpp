#include "Analyzer.h"

Analyzer::Analyzer(string sourceText, vector<pair<string, string>> lexems)
{
	this->index = index;
	this->sourceText += sourceText;
	this->lexems.assign(lexems.begin(), lexems.end());
	foundStart = 0;
	foundEnd = 0;
}

void Analyzer::makeArticle()
{
	size_t i = 0;
	int evenOdd = 0;

	//it = this->lexems.begin();
	/*
	string str;
	titleText += "2";
	for (pair<string, string> n : this->lexems)
	{
		titleText += "2";
		if (n.first == (str = ("headerStart")))
		{
			foundStart = sourceText.find(n.second) + n.second.length();
			titleText += "2";
			str = "";
		} 
		else if (n.first == (str = ("headerEnd")))
		{
			foundEnd = sourceText.find(n.second);
			titleText += "2";
			//titleText.append(sourceText, foundStart, (foundEnd - foundStart));
		}

		else if (n.first == "dateStart" && sourceText.find(n.second)) 
		{
			foundStart = sourceText.find(n.second) + n.second.length();
			dateText.append(sourceText, foundStart, 10);
		}
		else if (n.first == "articlePieceStart" && sourceText.find(n.second)) 
		{
			foundStart = sourceText.find(n.second) + n.second.length();
		}
		else if (n.first == "articlePieceEnd" && sourceText.find(n.second)) 
		{
			foundEnd = sourceText.find(n.second);
			articleText.append(sourceText, foundStart, (foundEnd - foundStart));
			articleText.append("\n");
		}
		else if (n.first == "hrefSkipStart" && articleText.find(n.second))
		{
			foundStart = sourceText.find(n.second) + n.second.length();
		}
		else if (n.first == "hrefSkipQuote" && articleText.find(n.second)) 
		{
			foundEnd = articleText.find(n.second, foundStart);
			articleText.erase(foundStart, (foundEnd - foundStart + 1));
		}
		else if (n.first == "hrefSkipEnd" && articleText.find(n.second)) 
		{
			foundStart = articleText.find(n.second);
			foundEnd = foundStart + n.second.length();
			articleText.erase(foundStart, (foundEnd - foundStart + 1));
		}
		else if (n.first == "nobrSkipOpen" && articleText.find(n.second))
		{
			foundStart = articleText.find(n.second);
			foundEnd = foundStart + n.second.length();
			articleText.erase(foundStart - 1, (foundEnd - foundStart + 2));
		}
	}
	*/
}

void Analyzer::save(string path)
{
	std::ofstream fin(path);
	fin << titleText << endl;
	fin << dateText << endl;
	fin << articleText << endl;
	//fin << sourceText << endl;
	
	fin << "Received" << endl;

	for (pair<string, string> n : lexems)
	{
		fin << n.first;
		fin << " - ";
		fin << n.second << endl;
	}

	fin.close();
}