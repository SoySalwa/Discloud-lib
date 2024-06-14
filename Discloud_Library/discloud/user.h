#pragma once
#ifndef USER_H
#define USER_H

#include "discloud/discloud.h"
#include <iostream>
#include <functional>
#include <string>

namespace dcl {
    class user {
    public:
        user() = default;

        ~user() = default;
        // user(const user&) = delete;
        // user& operator =(const user&) = delete;
          /**
          * Make a request to the DisCloud API to obtain user data.
          * @param discloud_token The DisCloud API token.
          * @param end_point The API endpoint make the request to.
          */
        void get_user(const dcl::discloud& discloud_token, const std::string& end_point) {
            try {
                dcl::discloud discloud(discloud_token);
                _response = discloud.route(end_point, "GET");

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
         * Get the message received for Discloud API for the user info.
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
        }
        /**
         * Gets the user id.
         * @return A value of type string with the id of the user.
         */
        const std::string user_id() {
            try {
                json response_data = json::parse(response);

                json user = response_data["user"];

                std::string id = user["userID"];
                return id;
            }
            catch (...) {
                return "";
            }
        }

        /**
         * Gets the total ram of this user.
         * @return A value of type string with the total ram of the user.
         */
        const std::string total_ram() const {
            try {
                json response_data = json::parse(response);

                json total_ram = response_data["user"];

                int total = total_ram["totalRamMb"];
                return std::to_string(total) + "MB";
            }
            catch (...) {
                return "";
            }
        }
        /**
         * Gets the used ram of this user.
         * @return A value of type string with the used ram of the user.
         */
        const std::string ram_used() const {
            try {
                json response_data = json::parse(response);

                json ram_used = response_data["user"];

                int used = ram_used["ramUsedMb"];
                return std::to_string(used) + "MB";
            }
            catch (...) {
                return "";
            }
        }
        /**
          * Gets the sub domains of this user.
          * @return A value of type string with the sub domains of the user.
          */
        const std::string sub_domains() const {
            try {
                json response_data = json::parse(response);

                json domains = response_data["user"];

                std::string subdomains = domains["subdomains"];
                return subdomains;
            }
            catch (...) {
                return "";
            }
        }
        /**
         * Gets the custom domains of this user.
         * @return A value of type string with the custom domains of the user.
         */
        const std::string custom_domains() const {
            try {
                json response_data = json::parse(response);

                json cdomains = response_data["user"];

                std::string customDomains = cdomains["customdomains"];
                return customDomains;
            }
            catch (...) {
                return "";
            }
        }
        /**
         * Gets the apps of this user.
         * @return A value of type string with the apps of the user.
         */
        const std::string apps() const {
            try {
                json response_data = json::parse(response);

                json user_apps = response_data["user"];

                std::string apps = user_apps["apps"];
                return apps;
            }
            catch (...) {
                return "";
            }
        }
        /**
         * Gets the actual plan of this user.
         * @return A value of type string with the plan of the user.
         */
        const std::string plan() const {
            try {
                json response_data = json::parse(response);

                json user_plan = response_data["user"];

                std::string plan = user_plan["plan"];
                return plan;
            }
            catch (...) {
                return "";
            }
        }
        /**
        * Gets the locale of this user.
        * @return A value of type string with the locale of the user.
        */
        const std::string locale() const {
            try {
                json response_data = json::parse(response);

                json user_locale = response_data["user"];

                std::string locale = user_locale["locale"];
                return locale;
            }
            catch (...) {
                return "";
            }
        }
        /**
         * Make a request to the DisCloud API to put set language of the user.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint make the request to.
         */
        void get_locale(const dcl::discloud& discloud_token, const std::string& end_point) {
            try {
                dcl::discloud discloud(discloud_token);
                _response = discloud.route(end_point, "PUT");

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
        * Get the language locale of the user.
        * @return The locale as a string.
        */
        const std::string get_locale() const {
            try {
                json response_data = json::parse(response);

                std::string locale = response_data["locale"];
                return locale;
            }
            catch (...) {
                return "";
            }
        }
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
#endif // !USER_H