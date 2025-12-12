#pragma once
#ifndef USER_H
#define USER_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl
{
  class user : public DiscloudResponses
  {
  public:
    user() {};

    ~user() = default;
    // user(const user&) = delete;
    // user& operator =(const user&) = delete;
    /**
     * Make a request to the DisCloud API to obtain user data.
     * @param discloud_token The DisCloud API token.
     */
    dcl::user get_user(const dcl::discloud &discloud_token,
                       const std::string &end_point)
    {
      this->fetch_api(discloud_token, std::format("/user"), dcl::Method::GET);
      return *this;
    }

    /**
     * Get the message received for Discloud API for the user info.
     * @return Message of the Discloud API.
     */
    const std::string get_message()
    {
      try
      {
        json response_data = json::parse(response);

        std::string message = response_data["message"];
        return message;
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Gets the user id.
     * @return A value of type string with the id of the user.
     */
    const std::string user_id()
    {
      try
      {
        json response_data = json::parse(response);

        json user = response_data["user"];

        std::string id = user["userID"];
        return id;
      }
      catch (...)
      {
        return "";
      }
    }

    /**
     * Gets the total ram of this user.
     * @return A value of type string with the total ram of the user.
     */
    const std::string total_ram() const
    {
      try
      {
        json response_data = json::parse(response);

        json total_ram = response_data["user"];

        int total = total_ram["totalRamMb"];
        return std::to_string(total) + "MB";
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Gets the used ram of this user.
     * @return A value of type string with the used ram of the user.
     */
    const std::string ram_used() const
    {
      try
      {
        json response_data = json::parse(response);

        json ram_used = response_data["user"];

        int used = ram_used["ramUsedMb"];
        return std::to_string(used) + "MB";
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Gets the sub domains of this user.
     * @return A value of type string with the sub domains of the user.
     */
    const std::string sub_domains() const
    {
      try
      {
        json response_data = json::parse(response);

        json domains = response_data["user"];

        std::vector<std::string> vt_subdomains = domains["subdomains"];
        std::string st_subdomains;
        for (const auto &custom : st_subdomains)
        {
          st_subdomains += custom + ", ";
        }
        if (!st_subdomains.empty())
        {
          st_subdomains.pop_back();
          st_subdomains.pop_back();
        }
        return st_subdomains;
      }
      catch (...)
      {
        return "[ ]";
      }
    }
    /**
     * Gets the custom domains of this user.
     * @return A value of type string with the custom domains of the user.
     */
    const std::string custom_domains() const
    {
      try
      {
        json response_data = json::parse(response);

        json cdomains = response_data["user"];

        std::vector<std::string> vt_customDomains = cdomains["customdomains"];
        std::string st_customDomains;
        for (const auto &custom : st_customDomains)
        {
          st_customDomains += custom + ", ";
        }
        if (!st_customDomains.empty())
        {
          st_customDomains.pop_back();
          st_customDomains.pop_back();
        }
        return st_customDomains;
      }
      catch (...)
      {
        return "[ ]";
      }
    }
    /**
     * Gets the apps of this user.
     * @return A value of type string with the apps of the user.
     */
    const std::string apps() const
    {
      try
      {
        json response_data = json::parse(response);

        json user_apps = response_data["user"];

        std::vector<std::string> vt_apps = user_apps["apps"];
        std::string st_apps;
        for (const auto &app : vt_apps)
        {
          st_apps += app + ", ";
        }
        if (!st_apps.empty())
        {
          st_apps.pop_back();
          st_apps.pop_back();
        }
        return st_apps;
      }
      catch (...)
      {
        return "[]";
      }
    }
    /**
     * Gets the actual plan of this user.
     * @return A value of type string with the plan of the user.
     */
    const std::string plan() const
    {
      try
      {
        json response_data = json::parse(response);

        json user_plan = response_data["user"];

        std::string plan = user_plan["plan"];
        return plan;
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Gets the locale of this user.
     * @return A value of type string with the locale of the user.
     */
    const std::string locale() const
    {
      try
      {
        json response_data = json::parse(response);

        json user_locale = response_data["user"];

        std::string locale = user_locale["locale"];
        return locale;
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Make a request to the DisCloud API to put set language of the user.
     * @param discloud_token The DisCloud API token.
     * @param locale The locale to set for the user.
     */
    dcl::user set_locale(const dcl::discloud &discloud_token,
                         const std::string &locale)
    {
      this->fetch_api(discloud_token, std::format("/locale/{}", locale), dcl::Method::GET);
      return *this;
    }
    /**
     * Get the language locale of the user.
     * @return The locale as a string.
     */
    const std::string get_locale() const
    {
      try
      {
        json response_data = json::parse(response);

        std::string locale = response_data["locale"];
        return locale;
      }
      catch (...)
      {
        return "";
      }
    }
    /**
     * Get the response Json received of Discloud API.
     * @return The response json, the response already parsed.
     */
    std::string get_json() const
    {
      try
      {
        json response_data = json::parse(response);
        return "Discloud Response: " + response_data.dump(4);
      }
      catch (const json::parse_error &e)
      {
        throw std::runtime_error("JSON parse error: " + std::string(e.what()));
      }
    }

  private:
    std::string response;
    std::string _response;

    void set_response(const std::string &new_response)
    {
      response = new_response;
    }
  };
} // namespace dcl
#endif // !USER_H
