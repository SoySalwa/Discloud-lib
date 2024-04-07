#pragma once
#ifndef DISCLOUD_H
#define DISCLOUD_H

#include <iostream>
#include <functional>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace dcl {
    class discloud {
    public:
        /**
          * Constructor for initializing DisCloud API access.
          * @param token A string representing the DisCloud API token.
          */
        discloud(const std::string& token) : discloud_token(token) {};
        
        /**
        * Function for to add a endpoint in the discloud url.
        * @param end_point A url that represents the endpoint you want to access.
        */
        std::string route(const std::string& end_point, const std::string& method) {
            CURL* curl = curl_easy_init();

            if (!curl) {
                throw std::runtime_error("Error initializing Curl.");
            }

            std::string url = base_url + end_point;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            std::string auth_header = "api-token: " + discloud_token;
            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, auth_header.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, dcl::discloud::WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1L);

            CURLcode res = curl_easy_perform(curl);
            json response_data = json::parse(response);
            if (res != CURLE_OK) {
                curl_slist_free_all(headers);
                curl_easy_cleanup(curl);
                throw std::runtime_error("cURL request failed: " + std::string(curl_easy_strerror(res)));
            }
            else {
                
                std::cout << "Discloud Response: " << response_data.dump(4) << std::endl;
               return this->get_response(response);
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        /**
          * Function for to get DisCloud API Token in format string.
          * @return discloud_token A string representing the DisCloud API token.
          */
        dcl::discloud get_token() const {
            return discloud_token;
        }

        std::string get_response(std::string& response) const {
            return response;
        }
        
    private:
        std::string discloud_token;
        std::string response;
        const std::string base_url = "https://api.discloud.app/v2";

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
            size_t total_size = size * nmemb;
            userp->append(static_cast<char*>(contents), total_size);
            return total_size;
        }
    };
}

#endif // !DISCLOUD_H
