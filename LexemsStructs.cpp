#include "LexemsStructs.h"

bool contains(string sourceText, string key)
{
	return std::forward<string>(sourceText).find(std::forward<string>(key)) != std::remove_reference_t<string>::npos;
}

LexemsChoose::LexemsChoose(string adressHttps)
{
	vector<string>::iterator it = source.begin();
	for (string n : source)
	{
		if (contains(adressHttps, n))
		{
			index = it - source.begin();
		}

		if (it != source.end())
		{
			++it;
		}
	}
}

void LexemsChoose::createChoosenLexem()
{

	switch (this->index)
	{
	case 0:
	{
		Mail mail;
		this->lexems.assign(mail.lexems.begin(), mail.lexems.end());
		break;
	}
	case 1:
	{
		MKRU mk;
		this->lexems.assign(mk.lexems.begin(), mk.lexems.end());
		break;
	}
	case 2:
	{
		Vesti vesti;
		this->lexems.assign(vesti.lexems.begin(), vesti.lexems.end());
		break;
	}
	case 3:
	{
		RBC rbc;
		this->lexems.assign(rbc.lexems.begin(), rbc.lexems.end());
		break;
	}
	}
	
	//vector<pair<string, string>>::iterator it = this->lexems.begin();
	//for (pair<string, string> n : this->lexems)
	//{
		//cout << n.first << " - " << n.second << endl;
		//++it;
	//}
}

vector<pair<string, string>> LexemsChoose::returnChoosenLexems()
{
	return lexems;
}

int LexemsChoose::returnIndex()
{
	return index;
}