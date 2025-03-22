#pragma once
#ifndef DISCLOUDRESPONSES_H
#define DISCLOUDRESPONSES_H

#include "discloud.h"
#include <nlohmann/json.hpp>

namespace dcl {
class DiscloudResponses {
public:
  DiscloudResponses() {};
  void parse_response() {
    if (!_response.empty()) {
      try {
        _parsed_response = json::parse(_response);
      } catch (const json::parse_error &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
      }
    }
  }

  void fetch_api(const dcl::discloud &discloud_token,
                 const std::string &end_point, const std::string &method,
                 const std::string &file_path = std::string()) {
    try {
      dcl::discloud discloud(discloud_token);
      _response = discloud.route(end_point, method, file_path);
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

private:
  std::string _response;
  json _parsed_response;

};
}; // namespace dcl
#endif // !DISCLOUDRESPONSES_H
