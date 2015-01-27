#include<stdio.h>
#include<curl/curl.h>
#include<iostream>

int main(void){
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		std::cout<< "Successfully init a curl object." << std::endl;
	}
	curl_easy_cleanup(curl);

	return 0;
}
