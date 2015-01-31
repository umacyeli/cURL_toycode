#include<stdio.h>
#include<curl/curl.h>
#include<iostream>
#include<string>
#include<fstream>

int writer_callback(char *data, size_t size, size_t nmemb, std::string *buffer){
	if(buffer == NULL)
		return 0;

	buffer->append(data, size * nmemb);
	
	buffer->append("\nhahahaha\n");

	return size * nmemb;	
}

int writer_callback_file(char *data, size_t size, size_t nmemb, std::ofstream* out){

	out->write(data, size * nmemb);
	return size * nmemb;
}

int main(void){
	CURL *curl;
	CURLcode res;

	//Initialization
	curl = curl_easy_init();

	//std::ofstream fout;
	std::string buffer;
	
	
	//fout.open("G:/test.html", std::ios::out | std::ios::binary);
	
	if(curl) {
		//Setting options
		curl_easy_setopt(curl, CURLOPT_URL, "www.umac.mo");
		
		//Data callback

		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		
		//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer_callback_file);
		//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fout);
		
		//Perform the request, res will get the return code
		curl_easy_perform(curl);
		std::cout << buffer << std::endl;
		std::cout << buffer << std::endl;
	}
	
	//fout.close();
	//always cleanup
	curl_easy_cleanup(curl);

	return 0;
} 


/*
int main(void){
	CURL *curl;

	//Gloabal Initialization
	curl_global_init(CURL_GLOBAL_DEFAULT);

	//Initialization
	curl = curl_easy_init();

	//Setting options
	curl_easy_setopt(curl, CURLOPT_URL, "google.com");
	//curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);


	//Perform the request, res will get the return code
	curl_easy_perform(curl);


	//always cleanup
	curl_easy_cleanup(curl);

	//Global cleanup
	curl_global_cleanup();

	return 0;
}
*/
