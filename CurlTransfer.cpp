#include "CurlTransfer.h"

static int writer(char* data, size_t size, size_t nmemb, string *sourceText)
{
	int result = 0;
	if (sourceText != NULL)
	{
		sourceText->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

void initCurl(string& sourceText, string adressPath) {
	CURL* curl;
	CURLcode result;
	ifstream path;
	string temp;
	curl = curl_easy_init();
	adressPath += adressPath;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
		curl_easy_setopt(curl, CURLOPT_URL, adressPath.c_str());
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sourceText);
		result = curl_easy_perform(curl);
		if (result == CURLE_OK) {
		}
		else {
			cout << "Îøèáêà! " << errbuf << endl;
		}
	}
	curl_easy_cleanup(curl);
}