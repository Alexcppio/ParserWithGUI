#ifndef LEXSTRUCTS_H
#define LEXSTRUCTS_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

class LexemsChoose
{
public:
	LexemsChoose(string adressHttps);
	void createChoosenLexem();
	vector<pair<string, string>> returnChoosenLexems();
	int returnIndex();
private:
	string sourceText;
	vector<pair<string, string>> lexems;
	int index = -1;
	vector <string> source{
	"mail.ru",
	"mk.ru",
	"vesti.ru",
	"rbc.ru"
	};
};

struct Mail
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class=\"hdr__inner\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "datetime=\"" },
		{ "articlePieceStart", "article__item article__item_alignment_left article__item_html\"><p>"},
		{ "articlePieceEnd", "</p" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipQuote", ">" },
		{ "hrefSkipEnd", "</a>" },
		{ "nobrSkipOpen", "nobr"},
		{ "contentSource", "<meta property =\"og:site_name\" content = \"Новости Mail.ru\">"}
	};
};

struct MKRU
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class = \"article__title\" itemprop = \"headline\">" },
		{ "headerEnd", "< / h1>" },
		{ "dateStart", "datetime = \"" },
		{ "articlePieceStart", "<div class = \"article__body\" itemprop = \"articleBody\"><p>"},
		{ "articlePieceEnd", "< a _fcksavedurl" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipQuote", ">" },
		{ "hrefSkipEnd", "</a>" }
	};
};

struct Vesti
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class=\"article__title\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "<div class=\"article__date\">			" },
		{ "articlePieceStart", "<div class=\"article__text\">"},
		{ "articlePieceEnd", "<div class=\"vgtrk-cke_iframe\"" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipEnd", "</a" },
		{ "parOpen", "<p" },
		{ "parClose", "</p>" },
		{ "quotes", "&quot" },
		{ "ndash", "&ndash" },
		{ "garb", "<div class=\"js-mediator-article\"" },
		{ "contentSource", "<meta property=\"og:site_name\" content=\"vesti.ru\">"}
	};
};

struct RBC
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class=\"article__header__title - in js - slide - title\" itemprop=\"headline\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "itemprop = \"datePublished\" content = \""},
		{ "articlePieceStart", "<div class=\"article g - relative js - rbcslider - article \">"},
		{ "articlePieceEnd", "<div class=\"article__tags\">" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipEnd", "</a>" },
		{ "parOpen", "<p>" },
		{ "parClose", "</p>" },
		{ "nobrSkipOpen", "&nbsp"},
		{ "contentSource", "<meta property=\"og:site_name\" content=\"РБК\">"}
	};
};

#endif LEXSTRUCTS_H