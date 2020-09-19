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

	for (pair<string, string> n : lexems)
	{
		if (n.first == "headerStart")
		{
			foundStart = sourceText.find(n.second) + n.second.length();

		}
		else if (n.first == "headerEnd")
		{
			foundEnd = sourceText.find(n.second);
			titleText.append(sourceText, foundStart, (foundEnd - foundStart));
		}
	}

	for (pair<string, string> n : lexems)
	{
		if (n.first == "dateStart")
		{
		foundStart = sourceText.find(n.second) + n.second.length();
		dateText.append(sourceText, foundStart, 10);
		}
	}
	
	for (pair<string, string> n : lexems)
	{
		if (n.first == "articlePieceStart")
		{
			foundStart = sourceText.find(n.second) + n.second.length();

			for (pair<string, string> n : lexems)
			{
				if (n.first == "articlePieceEnd")
				{
					foundEnd = sourceText.find(n.second);
					articleText.append(sourceText, foundStart, (foundEnd - foundStart));
					articleText.append("\n");
				}
			}
		}
	}
	
	size_t i = 0;
	for (pair<string, string> n : lexems)
	{
		i = 0;
		if (n.first == "hrefSkipStart")
		{
			for (i = articleText.find(n.second, i++); i != string::npos; i = articleText.find(n.second, i + 1))
			{
				if (articleText.find(n.second)) {
					foundStart = articleText.find(n.second);
					foundEnd = articleText.find(">", foundStart);
					articleText.erase(foundStart, (foundEnd - foundStart + 1));
				}
			}
		}
	}

	for (pair<string, string> n : lexems)
	{
		i = 0;
		if (n.first == "parClose" || n.first == "quotes" || n.first == "parOpen" || n.first == "hrefSkipEnd" || n.first == "ndash" || n.first == "garb")
		{
			for (i = articleText.find(n.second, i++); i != string::npos; i = articleText.find(n.second, i + 1))
			{
				if (articleText.find(n.second)) {
					foundStart = articleText.find(n.second);
					foundEnd = foundStart + n.second.length();
					articleText.erase(foundStart, (foundEnd - foundStart + 1));
				}
			}
		}
	}
	
}

void Analyzer::save(string path)
{
	std::ofstream fin(path, std::ios_base::out | std::ios_base::trunc);
	fin << titleText << endl;
	fin << dateText << endl;
	fin << articleText << endl;

	fin.close();
}