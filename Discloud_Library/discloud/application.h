#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "discloud.h"
#include "discloudResponses.h"
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

  dcl::application get_application(const dcl::discloud &discloud_token,
                                   const std::string &end_point) {

    discloud_responses.fetch_api(discloud_token, end_point, "GET");
    return *this;
  }

  /**
   * Make a request to the DisCloud API to obtain status data application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application get_status_application(const dcl::discloud &discloud_token,
                                          const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "GET");
    return *this;
  }

  /**
   * Make a request to the DisCloud API to obtain logs data application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application get_logs_application(const dcl::discloud &discloud_token,
                                        const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "GET");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to obtain backup data application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application get_backup_application(const dcl::discloud &discloud_token,
                                          const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "GET");
    return *this;
  }

  /**
   * Make a request to the DisCloud API to put start the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application start_application(const dcl::discloud &discloud_token,
                                     const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put restart the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application restart_application(const dcl::discloud &discloud_token,
                                       const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put stop the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application stop_application(const dcl::discloud &discloud_token,
                                    const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API for change the ram of the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application ram_application(const dcl::discloud &discloud_token,
                                   const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put commit file in the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application commit_application(const dcl::discloud &discloud_token,
                                      const std::string &end_point,
                                      const std::string file_path = "") {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API for to delete the application.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::application delete_application(const dcl::discloud &discloud_token,
                                      const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "DELETE");
    return *this;
  }
  /**
   * Get the message received for Discloud API.
   * @return Message of the Discloud API.
   */
  const std::string get_message() {
    return discloud_responses.get_json<std::string>("message");
  }
  /**
   * Gets the URL with the files of the APP.
   * @return The url with the files.
   */
  std::string get_backup() {
    return discloud_responses.get_json<std::string>("message");
  }

  /**
   *
   * Get the logs big from the API
   * @return A json as strings.
   * */
  std::string logs_big() const {
    return discloud_responses.get_json<std::string>("apps/terminal/big");
  }
  /**
   *
   * Get the logs small from the API
   * @return A json as strings.
   * */
  std::string logs_small() const {
    return discloud_responses.get_json<std::string>("apps/terminal/small");
  }
  /**
   * It's a value of type string, get the id of the application.
   * @return A value of type string with the id of the application.
   */
  std::string status_id() const {
    return discloud_responses.get_json<std::string>("apps/id");
  }

  /**
   * It's a value of type string, get the status of the application.
   * @return A value of type string with the status application.
   */
  std::string container() const {
    return discloud_responses.get_json<std::string>("apps/container");
  }
  /**
   * It's a value of type string, get the cpu of the application.
   * @return A value of type string with the cpu of the application.
   */
  std::string cpu() const {
    return discloud_responses.get_json<std::string>("apps/cpu");
  }
  /**
   * It's a value of type string, get the memory of the application.
   * @return A value of type string with the memory of the application.
   */
  std::string memory() const {
    return discloud_responses.get_json<std::string>("apps/memory");
  }
  /**
   * It's a value of type string, get the disk of the application.
   * @return A value of type string with the disk of the application.
   */
  std::string disk() const {
    return discloud_responses.get_json<std::string>("apps/ssd");
  }

  /**
   * It's a value of type string, get the uptime of the application.
   * @return A value of type string with the uptime of the application.
   */
  std::string uptime() const {
    return discloud_responses.get_json<std::string>("apps/last_restart");
  }
  /**
   *
   * It's the id of the application.
   * @return Id application.*/
  std::string id() const {
    return discloud_responses.get_json<std::string>("apps/id");
  }
  /**
   * It's the avatar of the application.
   * @return A string value as the avatar of application.
   */
  std::string avatarURL() {
    return discloud_responses.get_json<std::string>("apps/avatarURL");
  }
  /**
    It's the name of the application.
    * @return Name application.*/
  std::string name() const {
    return discloud_responses.get_json<std::string>("apps/name");
  }
  /**
   * It's a boolean value, if application is online return 1 or exception 0.
   * @return Boolean Value.
   */
  bool is_online() const {
    return discloud_responses.get_json<bool>("apps/online");
  }
  /**
   * It's a boolean value, if application isn't ram killed return 0 or
   * exception 1.
   * @return Boolean Value.
   */
  bool ram_killed() const {
    return discloud_responses.get_json<bool>("apps/ramKilled");
  }
  /**
   * It's a int value, it returns the ram comsumed by the application.
   * @return Integer value.
   */
  int ram() const { return discloud_responses.get_json<int>("apps/ram"); }
  /**
   * It's a string value, it returns the main file of the application.
   * @return The name application file as value.
   */
  std::string file_name() const {
    return discloud_responses.get_json<std::string>("apps/mainFile");
  }
  /**
   * It's a string value, it returns the language programmation used by the
   * application.
   * @return The name language programmation used by application.
   */
  std::string lang() const {
    return discloud_responses.get_json<std::string>("apps/lang");
  }

private:
  std::string response;
  std::string _response;
  json _parsed_response;
  dcl::DiscloudResponses discloud_responses;

  void set_response(const std::string &new_response) {
    response = new_response;
  }
  void parse_response() {
    if (!_response.empty()) {
      try {
        _parsed_response = json::parse(_response);
      } catch (const json::parse_error &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
      }
    }
  }

protected:
  void fetch_api(const dcl::discloud &discloud_token,
                 const std::string &end_point, const std::string &method) {
    try {
      dcl::discloud discloud(discloud_token);
      _response = discloud.route(end_point, method);
      parse_response();
    } catch (const std::exception &e) {
      std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
  }
  template <typename T>
  T get_json(const std::string &json_path, T default_value = T()) const {
    try {
      return _parsed_response.value(json::json_pointer("/" + json_path),
                                    default_value);
    } catch (...) {
      return default_value;
    }
  }
}; // class application
}; // namespace dcl
#endif // !APPLICATION_H
