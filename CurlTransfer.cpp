#include "CurlTransfer.h"


static int writer(char* data, size_t size, size_t nmemb, string* sourceText)
{
	int result = 0;
	if (sourceText != NULL)
	{
		sourceText->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

void getURL(string &sourceText, string adressPathCurl) {
	CURL* curlCurl;
	CURLcode resultCurl;
	ifstream pathCurl;
	string tempCurl;
	curlCurl = curl_easy_init();
	adressPathCurl += adressPathCurl;
	
	if (curlCurl)
	{
		curl_easy_setopt(curlCurl, CURLOPT_ERRORBUFFER, errbufCurl);
		curl_easy_setopt(curlCurl, CURLOPT_URL, adressPathCurl.c_str());
		curl_easy_setopt(curlCurl, CURLOPT_HEADER, 1);
		curl_easy_setopt(curlCurl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curlCurl, CURLOPT_WRITEDATA, &sourceText);
		resultCurl = curl_easy_perform(curlCurl);
		if (resultCurl == CURLE_OK) {
		}
		else {
			cout << "Îøèáêà! " << errbufCurl << endl;
		}
	}
	curl_easy_cleanup(curlCurl);
}