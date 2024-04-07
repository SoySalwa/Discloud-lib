#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "discloud.h"
#include "snowflake.h"
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace dcl {
	class application {
	public:
		application() {}

		template<typename T>
		typename std::enable_if<std::is_pointer<T>::value, application*>::type operator->() {
			return this;
		}
		/**
		 * Make a request to the DisCloud API to obtain app data.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		std::string get_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			_response = discloud.route(end_point, "GET");
			set_response(discloud.get_response(_response));
			return _response;
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
				// Capturar cualquier excepción y devolver una cadena vacía
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
		std::string get_status_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			_response = discloud.route(end_point, "GET");
			set_response(discloud.get_response(_response));
			//return _response;
		}

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
		const std::string uptime() const {
			try {
				json response_data = json::parse(response);
				std::string time = response_data["last_restart"];
				return time;
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
		std::string get_logs_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			return discloud.route(end_point, "GET");
		}
		/**
         * Make a request to the DisCloud API to obtain backup data application.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
		std::string get_backup_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			return discloud.route(end_point, "GET");
		}
		/**
         * Make a request to the DisCloud API to put start the application.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
		std::string start_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			return discloud.route(end_point, "PUT");
		}
		/**
		 * Make a request to the DisCloud API to put restart the application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		std::string restart_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			return discloud.route(end_point, "PUT");
		}
		/**
		 * Make a request to the DisCloud API to put stop the application.
		 * @param discloud_token The DisCloud API token.
		 * @param end_point The API endpoint to make the request to.
		 * @return The API response as a string (JSON).
		 */
		std::string stop_application(const dcl::discloud& discloud_token, const std::string& end_point) {
			dcl::discloud discloud(discloud_token);
			return discloud.route(end_point, "PUT");
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