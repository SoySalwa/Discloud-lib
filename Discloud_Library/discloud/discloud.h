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
        discloud(const std::string& token) : discloud_token(token) {}

        /**
         * Function to add an endpoint in the discloud URL.
         * @param end_point A URL that represents the endpoint you want to access.
         * @param method The HTTP method to use for the request.
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
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                curl_slist_free_all(headers);
                curl_easy_cleanup(curl);
                throw std::runtime_error("cURL request failed: " + std::string(curl_easy_strerror(res)));
            }

            // Ensure response is a valid JSON
            try {
                json response_data = json::parse(response);
                std::cout << "Discloud Response: " << response_data.dump(4) << std::endl;
                this->get_response(response);
            }
            catch (const json::parse_error& e) {
                throw std::runtime_error("JSON parse error: " + std::string(e.what()));
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);

            return response;
        }

        /**
         * Function to get DisCloud API Token in string format.
         * @return A string representing the DisCloud API token.
         */
        std::string get_token() const {
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

#endif // DISCLOUD_H