#include "Analyzer.h"

AnalyzeMail::AnalyzeMail(string sourceText)
{
	this->sourceText += sourceText;
}

void AnalyzeMail::getTitle()
{
	string headerStart = "<h1 class=\"hdr__inner\">";
	string headerEnd = "</h1";
	size_t foundStart = 0;
	size_t foundEnd = 0;
	if (sourceText.find(headerStart)) {
		foundStart = sourceText.find(headerStart) + headerStart.length();
		if (sourceText.find(headerEnd)) {
			foundEnd = sourceText.find(headerEnd);
		}
	}
}

void AnalyzeMail::getDate()
{
	string dateStart = "datetime=\"";
	size_t foundStart = 0;
	if (sourceText.find(dateStart)) {
		foundStart = sourceText.find(dateStart) + dateStart.length();
	}
}

void AnalyzeMail::getArticle()
{
	string articlePieceStart = "article__item article__item_alignment_left article__item_html\"><p>";
	string articlePieceEnd = "</p";
	string hrefSkipStart = "<a href";
	string hrefSkipQuote = ">";
	string hrefSkipEnd = "</a>";
	string nobrSkipOpen = "nobr";
	size_t foundStart = 0;
	size_t foundEnd = 0;
	size_t i = 0;
	int evenOdd = 0;
	for (i = sourceText.find(articlePieceStart, i++); i != string::npos; i = sourceText.find(articlePieceStart, i + 1))
	{
		if (sourceText.find(articlePieceStart)) {
			foundStart = sourceText.find(articlePieceStart, i++) + articlePieceStart.length();

			if (sourceText.find(articlePieceEnd, foundStart)) {
				foundEnd = sourceText.find(articlePieceEnd, foundStart);

			}
		}
		articleText.append(sourceText, foundStart, (foundEnd - foundStart));
		articleText.append("\n");
	}
	i = 0;
	for (i = articleText.find(hrefSkipStart, i++); i != string::npos; i = articleText.find(hrefSkipStart, i + 1))
	{
		if (articleText.find(hrefSkipStart)) {
			foundStart = articleText.find(hrefSkipStart);
			foundEnd = articleText.find(hrefSkipQuote, foundStart);
			articleText.erase(foundStart, (foundEnd - foundStart + 1));
		}
	}
	i = 0;
	for (i = articleText.find(hrefSkipEnd, i++); i != string::npos; i = articleText.find(hrefSkipEnd, i + 1))
	{
		if (articleText.find(hrefSkipEnd)) {
			foundStart = articleText.find(hrefSkipEnd);
			foundEnd = foundStart + hrefSkipEnd.length();
			articleText.erase(foundStart, (foundEnd - foundStart + 1));
		}
	}

	i = 0;
	for (i = articleText.find(nobrSkipOpen, i++); i != string::npos; i = articleText.find(nobrSkipOpen, i + 1))
	{
		++evenOdd;
		if (articleText.find(nobrSkipOpen)) {
			foundStart = articleText.find(nobrSkipOpen);
			foundEnd = foundStart + nobrSkipOpen.length();
			if (evenOdd % 2 != 0) {
				articleText.erase(foundStart - 1, (foundEnd - foundStart + 2));
			}
			else if (evenOdd % 2 == 0) {
				articleText.erase(foundStart - 2, (foundEnd - foundStart + 3));
			}
		}
	}
}

void AnalyzeMail::save(string path)
{
	std::ofstream fin(path);
	fin << titleText << endl;
	fin << dateText << endl;
	fin << articleText << endl;
	fin << "123" << endl;
	fin.close();
}