#pragma once
#ifndef UPLOAD_H
#define UPLOAD_H

#include "discloud.h"
#include <iostream>
#include <functional>
#include <string>

namespace dcl {
	class upload {
	public:
        /**
         * Make a request to the DisCloud API to upload a file.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint make the request to.
         * @param file_path, it's the file to upload.
         * @return The API response as a string (JSON).
         */
        void send_upload(const dcl::discloud& discloud_token, const std::string& end_point, const std::string file_path = "") {
            try {
                dcl::discloud discloud(discloud_token);
                std::string _response = discloud.route(end_point, "POST", file_path);

                if (!_response.empty()) {
                    try {
                        auto json_response = nlohmann::json::parse(_response);
                        set_response(_response);
                    }
                    catch (const nlohmann::json::parse_error& e) {
                        std::cerr << "JSON parse error: " << e.what() << std::endl;
                    }
                }
                else {
                    std::cerr << "The response is null or empty." << std::endl;
                }
            }
            catch (const std::runtime_error& e) {
                std::cerr << "An error occurred: " << e.what() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
            }
        }
        /**
        * Get the message received for Discloud API upload info.
        * @return Message of the Discloud API.
        */
        const std::string get_message() {
            try {
                json response_data = json::parse(response);


                std::string message = response_data["message"];
                return message;
            }
            catch (...) {
                return "";
            }
        };
        /**
        * Get the response Json received of Discloud API.
        * @return The response json, the response already parsed.
        */
        std::string get_json() const {
            try {
                json response_data = json::parse(response);
                return "Discloud Response: " + response_data.dump(4);
            }
            catch (const json::parse_error& e) {
                throw std::runtime_error("JSON parse error: " + std::string(e.what()));
            }
        }

    private:
        std::string response;
        std::string _response;

        void set_response(const std::string& new_response) {
            response = new_response;
        }
	};
}
#endif // !UPLOAD_H
