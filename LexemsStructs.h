#ifndef LEXSTRUCTS_H
#define LEXSTRUCTS_H
#include <iostream>
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
	int index = 0;
	LexemsChoose();
	void createChoosenLexem();
	
	vector<pair<string, string>> lexems;
};

class Mail
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "< h1 class = \"hdr__inner\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "datetime=\"" },
		{ "articlePieceStart", "article__item article__item_alignment_left article__item_html\"><p>"},
		{ "articlePieceEnd", "</p" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipQuote", ">" },
		{ "hrefSkipEnd", "</a>" },
		{ "nobrSkipOpen", "nobr"}
	};
};

class MKRU
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

class Vesti
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class=\"article__title\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "<div class=\"article__date\">" },
		{ "articlePieceStart", "<div class=\"js - mediator - article\">"},
		{ "articlePieceEnd", "<span class=\"article_end\"></span>" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipQuote", ">" },
		{ "hrefSkipEnd", "</a>" },
		{ "contentSource", "<meta property=\"og:site_name\" content=\"vesti.ru\">"}
	};
};

class RBC
{
public:
	vector<pair<string, string>> lexems = {
		{ "headerStart", "<h1 class=\"article__header__title - in js - slide - title\" itemprop=\"headline\">" },
		{ "headerEnd", "</h1" },
		{ "dateStart", "itemprop = \"datePublished\" content = \""},
		{ "articlePieceStart", "<div class=\"article g - relative js - rbcslider - article \">"},
		{ "articlePieceEnd", "<div class=\"article__tags\">" },
		{ "hrefSkipStart", "<a href" },
		{ "hrefSkipQuote", ">" },
		{ "hrefSkipEnd", "</a>" },
		{ "nobrSkipOpen", "&nbsp"},
		{ "contentSource", "<meta property=\"og:site_name\" content=\"пай\">"}
	};
};

#endif LEXSTRUCTS_H