#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "discloud.h"
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace dcl {
	class application {
	public:
		application() {};
		/**
		 * Make a request to the DisCloud API to obtain app data.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */

		void get_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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
		  It's the id of the application.
		  * @return Id application.*/
		const std::string id() const {
			try {
				json response_data = json::parse(response);
		
				json apps = response_data["apps"];
				
				std::string id = apps["id"];
				return id;
			}
			catch (...) {
				return "";
			}
		}
		/**
		* It's the avatar of the application.
		* @return A string value as the avatar of application.
		*/
		const std::string avatarURL() {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];
				std::string avatar_url = apps["avatarURL"];

				return avatar_url;
			}
			catch (...) {
				return "";
			}
		}
		/**
		  It's the name of the application.
		  * @return Name application.*/
		const std::string name() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];
				
				std::string name = apps["name"];
				return name;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a boolean value, if application is online return 1 or exception 0.	
		 * @return Boolean Value.
		 */ 
		const bool is_online() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];

				bool online = apps["online"];
				return online;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a boolean value, if application isn't ram killed return 0 or exception 1.
		 * @return Boolean Value.
		 */
		const bool ram_killed() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];

				bool ram_killed = apps["ramKilled"];
				return ram_killed;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a int value, it returns the ram comsumed by the application.
		 * @return Integer value.
		 */
		const int ram() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];

				int ram = apps["ram"];
				return ram;
			}
			catch (...) {
				return 0;
			}
		}
		/**
		 * It's a string value, it returns the main file of the application.
		 * @return The name application file as value.
		 */
		const std::string file_name() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];

				std::string file = apps["mainFile"];
				return file;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a string value, it returns the language programmation used by the application.
		 * @return The name language programmation used by application.
		 */
		const std::string lang() const {
			try {
				json response_data = json::parse(response);
				json apps = response_data["apps"];

				std::string lang = apps["lang"];
				return lang;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * Make a request to the DisCloud API to obtain status data application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		void get_status_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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
		 * It's a value of type string, get the id of the application.
		 * @return A value of type string with the id of the application.
		 */
		const std::string status_id() const {
			try {
				json response_data = json::parse(response);

				json apps = response_data["apps"];

				std::string id = apps["id"];
				return id;
			}
			catch (...) {
				return "";
			}
		}

		/**
		 * It's a value of type string, get the status of the application.
		 * @return A value of type string with the status application.
		 */
		const std::string container() const {
			try {
				json response_data = json::parse(response);

				json container = response_data["apps"];

				std::string online = container["container"];
				return online;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a value of type string, get the cpu of the application.
		 * @return A value of type string with the cpu of the application.
		 */
		const std::string cpu() const {
			try {
				json response_data = json::parse(response);

				json cpu = response_data["apps"];

				std::string cpuTo = cpu["cpu"];
				return cpuTo;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a value of type string, get the memory of the application.
		 * @return A value of type string with the memory of the application.
		 */
		const std::string memory() const {
			try {
				json response_data = json::parse(response);

				json memory = response_data["apps"];

				std::string memory_ram = memory["memory"];
				return memory_ram;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * It's a value of type string, get the disk of the application.
		 * @return A value of type string with the disk of the application.
		 */
		const std::string disk() const {
			try {
				json response_data = json::parse(response);

				json disk = response_data["apps"];

				std::string ssd = disk["memory"];
				return ssd;
			}
			catch (...) {
				return "";
			}
		}

		/**
		 * It's a value of type string, get the uptime of the application.
		 * @return A value of type string with the uptime of the application.
		 */
		const std::string uptime() const {
			try {
				json response_data = json::parse(response);
				json time = response_data["apps"];
				std::string uptime = time["last_restart"];
				return uptime;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * Make a request to the DisCloud API to obtain logs data application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		void get_logs_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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

		const std::string logs_big() const {
			try {
				json response_data = json::parse(_response);
				json terminal = response_data["apps"]["terminal"];
				std::string logs_big = terminal["big"];
				return logs_big;
			}
			catch (...) {
				return "";
			}
		}

		const std::string logs_small() const {
			try {
				json response_data = json::parse(_response);
				json terminal = response_data["apps"]["terminal"];
				std::string logs_small = terminal["small"];
				return logs_small;
			}
			catch (...) {
				return "";
			}
		}
		/**
         * Make a request to the DisCloud API to obtain backup data application.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint make the request to.
         * @return The API response as a string (JSON).
         */
		void get_backup_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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
		* Get the message received for Discloud API backup info.
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
		* Gets the URL with the files of the APP.
		* @return The url with the files.
		*/
		const std::string get_backup() {
			try {
				json response_data = json::parse(response);
				std::string backup = response_data["backups"]["url"];
				return backup;
			}
			catch (...) {
				return "";
			}
		}
		/**
         * Make a request to the DisCloud API to put start the application.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint make the request to.
         * @return The API response as a string (JSON).
         */
		void start_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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

		const std::string get_message_start() const {
			try {
				json response_data = json::parse(_response);
				std::string message = response_data["message"];
				return message;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * Make a request to the DisCloud API to put restart the application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		void restart_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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

		const std::string get_message_restart() const {
			try {
				json response_data = json::parse(_response);
				std::string message = response_data["message"];
				return message;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * Make a request to the DisCloud API to put stop the application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		void stop_application(const dcl::discloud& discloud_token, const std::string& end_point) {
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

		const std::string get_message_stop() const {
			try {
				json response_data = json::parse(_response);
				std::string message = response_data["message"];
				return message;
			}
			catch (...) {
				return "";
			}
		}
		/**
		 * Make a request to the DisCloud API for to delete the application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		void delete_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			try {
				dcl::discloud discloud(discloud_token);
				_response = discloud.route(end_point, "DELETE");

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

#endif // !APPLICATION_H