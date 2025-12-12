#pragma once
#ifndef DISCLOUDRESPONSES_H
#define DISCLOUDRESPONSES_H

#include "discloud.h"
#include <nlohmann/json.hpp>

namespace dcl
{
  class DiscloudResponses
  {
  public:
    DiscloudResponses() {};

    /**
     *
     Return the JSON as string format
     @return JSON */
    std::string get_raw_json_string(int indent = 4) const
    {
      if (_parsed_response.empty())
      {
        return "{}";
      }
      return _parsed_response.dump(indent);
    }

  protected:
    void parse_response()
    {
      if (_response.empty())
        return;
      {
        try
        {
          _parsed_response = json::parse(_response);
        }
        catch (const json::parse_error &e)
        {
          std::cerr << "JSON parse error: " << e.what() << std::endl;
          _parsed_response = json::object();
        }
      }
    }

    void fetch_api(const dcl::discloud &client,
                   const std::string &end_point, Method method,
                   const std::string &file_path = std::string())
    {
      try
      {
        /*         dcl::discloud discloud(discloud_token);
         */
        _response = client.route(end_point, method, file_path);
        parse_response();
      }
      catch (const std::exception &e)
      {
        std::cerr << " [CRITICAL] Error fetching data: " << e.what() << std::endl;
        _response.clear();
        _parsed_response = json::object();
      }
    }

    template <typename T>
    T get_json(const std::string &json_path, T default_value = T()) const
    {
      try
      {

        std::string path_str(json_path);
        if (path_str.front() != '/')
        {
          path_str.insert(0, "/");
        }

        std::replace(path_str.begin(), path_str.end(), '.', '/');

        return _parsed_response.value(json::json_pointer(path_str),
                                      default_value);
      }
      catch (...)
      {
        return default_value;
      }
    }

  private:
    std::string _response;
    json _parsed_response;
  };
}; // namespace dcl
#endif // !DISCLOUDRESPONSES_H
