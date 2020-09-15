#include "LexemsStructs.h"

LexemsChoose::LexemsChoose()
{
	vector <string> source{
	"<meta property=\"og:site_name\" content=\"vesti.ru\">",
	"<meta property=\"og:site_name\" content=\"vesti.ru\">",
	"<meta property=\"og:site_name\" content=\"vesti.ru\">",
	"<meta property=\"og:site_name\" content=\"пай\">"
	};
	vector<string>::iterator it = source.begin();

	string test = "<meta property=\"og:site_name\" content=\"vesti.ru\">";

	for (string n : source)
	{
		if (!test.find(n))
		{
			this->index = it - source.begin();
		}
		++it;
	}
}

void LexemsChoose::createChoosenLexem()
{

	if (index == 0)
	{
		Mail mail;
		this->lexems.assign(mail.lexems.begin(), mail.lexems.end());
	}
	else if (index == 1)
	{
		MKRU mk;
		this->lexems.assign(mk.lexems.begin(), mk.lexems.end());
	}
	else if (index == 2)
	{
		Vesti vesti;
		this->lexems.assign(vesti.lexems.begin(), vesti.lexems.end());
	}
	else if (index == 3)
	{
		RBC rbc;
		this->lexems.assign(rbc.lexems.begin(), rbc.lexems.end());
	}
	vector<pair<string, string>>::iterator it = this->lexems.begin();
	for (pair<string, string> n : this->lexems)
	{
		cout << n.first << " - " << n.second << endl;
		++it;
	}
}