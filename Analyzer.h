#ifndef ANALYZER_H
#define ANALYZER_H
#include "LexemsStructs.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <utility>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Analyzer
{
public:
	Analyzer(string sourceText, vector<pair<string, string>> lexems);
	void makeArticle();
	void save(string path);
private:
	string sourceText, titleText, dateText, articleText;
	size_t foundStart, foundEnd;
	int index = 100;
	vector<pair<string, string>> lexems;
	vector<pair<string, string>>::iterator it;
};

#endif ANALYZER_H
