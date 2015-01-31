#include<stdio.h>
#include<curl/curl.h>
#include<iostream>
#include<string>
#include<fstream>
#include<libxml/HTMLparser.h>
#include<queue>

std::queue<std::string> urls;

int writer_callback(char *data, size_t size, size_t nmemb, std::string *buffer){
	if (buffer == NULL)
		return 0;

	buffer->append(data, size * nmemb);
	return size * nmemb;
}

static void walkTree(xmlNode * a_node)
{
	xmlNode *cur_node = NULL;
	xmlAttr *cur_attr = NULL;
	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		// do something with that node information, like¡­ printing the tag¡¯s name and attributes
		printf("Got tag : %s\n", cur_node->name);
		/*if (cur_node->name != NULL){
		std::string nodeName((char*)cur_node->name);
		printf("Got tag : %s\n", cur_node->name);
		}*/
		for (cur_attr = cur_node->properties; cur_attr; cur_attr = cur_attr->next) {
			printf("->with attribute : %s\n", cur_attr->name);
			printf("->with values : %s\n", xmlNodeGetContent(cur_attr->children));
			/*
			std::string attrName((char*)cur_attr->name);
			std::string hrefstring("href");
			if (attrName == hrefstring){
			std::cout << "tag:" << cur_node->name << std::endl;
			std::cout << "attribute:" << cur_attr->name << std::endl;
			std::cout << "value:" << xmlNodeGetContent(cur_attr->children) << std::endl;
			//printf("->with attribute : %s\n", attrName.c_str());
			//printf("->has document: %s\n", xmlNodeGetContent(cur_attr->children));
			}*/
		}

		walkTree(cur_node->children);
	}
	return;
}

int main(void){
	CURL *curl;
	CURLcode res;

	//Initialization
	curl = curl_easy_init();


	std::string buffer;

	//fout.open("G:/test.html", std::ios::out | std::ios::binary);

	if (curl) {
		//Setting options
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.umac.mo/");

		//Data callback
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		//Perform the request, res will get the return code
		curl_easy_perform(curl);

		htmlParserCtxtPtr parser = htmlCreatePushParserCtxt(NULL, NULL, NULL, 0, NULL, XML_CHAR_ENCODING_NONE);
		htmlCtxtUseOptions(parser, HTML_PARSE_RECOVER | HTML_PARSE_NOBLANKS);
		htmlParseChunk(parser, buffer.c_str(), buffer.size(), 0);

		walkTree(xmlDocGetRootElement(parser->myDoc));
		std::cout << buffer << std::endl;
	}

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
