#include <iostream>
#include <curl/curl.h>

int main(int argc, char **argv) {
    std::cout << "Hello world" << std::endl;
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        std::cout << res << std::endl;
    }
}