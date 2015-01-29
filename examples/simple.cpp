#include<stdio.h>
#include<curl/curl.h>
#include<iostream>
#include<string>

static std::string buffer;

static int writer_callback(char *data, size_t size, size_t nmemb, std::string *buffer){
	if(buffer == NULL)
		return 0;
	
	buffer->append(data, size * nmemb);
	
	return size * nmemb;	
}


int main(void){
	CURL *curl;
	CURLcode res;
		
	//Initialization
	curl = curl_easy_init();
	
	if(curl) {
		//Setting options
		curl_easy_setopt(curl, CURLOPT_URL, "www.umac.mo");
		
		//If url is redirected, we tell libcurl to follow redirection
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		//Data callback
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		//Perform the request, res will get the return code
		curl_easy_perform(curl);
		std::cout << buffer << std::endl;
		std::cout<< "Successfully init a curl object." << std::endl;
	}

	//always cleanup
	curl_easy_cleanup(curl);

	return 0;
}
