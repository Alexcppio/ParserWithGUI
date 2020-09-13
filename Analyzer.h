#ifndef ANALYZER_H
#define ANALYZER_H
#include <iostream>
#include <fstream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class AnalyzeMail
{
public:
	AnalyzeMail(string sourceText);
	void getTitle();
	void getDate();
	void getArticle();
	void save(string path);
private:
	string sourceText, titleText, dateText, articleText;
};

#endif ANALYZER_H
