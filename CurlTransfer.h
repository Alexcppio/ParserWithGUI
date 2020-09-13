#ifndef cURL_H
#define cURL_H

#define CURL_STATICLIB

#ifdef _DEBUG
#pragma comment (lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment (lib, "../curl/libcurl_a.lib")
#endif
#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "advapi32.lib")
#pragma comment (lib, "Crypt32.lib")

#include <iostream>
#include <string>
#include "../curl/curl.h"
#include <fstream>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
#include <iostream>
#include <string>

static char errbufCurl[CURLOPT_ERRORBUFFER];
static int writer(char* data, size_t size, size_t nmemb, string* sourceText);

void getURL(string& sourceText, string adressPathCurl);


#endif cURL_H
