#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "discloud.h"
#include "discloudResponses.h"
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>
#include <format>

using json = nlohmann::json;

namespace dcl
{
  class application : public DiscloudResponses
  {
  public:
    application() = default;
    ~application() = default;
    /**
     * Make a request to the DisCloud API to obtain app data.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application get_application(const dcl::discloud &discloud_token,
                                     const std::string &app_id)
    {

      this->fetch_api(discloud_token, std::format("/app/{}", app_id), dcl::Method::GET);
      return *this;
    }

    /**
     * Make a request to the DisCloud API to obtain status data application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application get_status_application(const dcl::discloud &discloud_token,
                                            const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/status", app_id), dcl::Method::GET);
      return *this;
    }

    /**
     * Make a request to the DisCloud API to obtain logs data application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application get_logs_application(const dcl::discloud &discloud_token,
                                          const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/logs", app_id), dcl::Method::GET);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to obtain backup data application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application get_backup_application(const dcl::discloud &discloud_token,
                                            const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/backup", app_id), dcl::Method::GET);
      return *this;
    }

    /**
     * Make a request to the DisCloud API to put start the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application start_application(const dcl::discloud &discloud_token,
                                       const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/start", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put restart the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application restart_application(const dcl::discloud &discloud_token,
                                         const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/restart", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put stop the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application stop_application(const dcl::discloud &discloud_token,
                                      const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/stop", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API for change the ram of the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application ram_application(const dcl::discloud &discloud_token,
                                     const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/ram", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put commit file in the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application commit_application(const dcl::discloud &discloud_token,
                                        const std::string &app_id,
                                        const std::string &file_path = "")
    {
      this->fetch_api(discloud_token, std::format("/app/{}/commit", app_id), dcl::Method::PUT, file_path);
      return *this;
    }
    /**
     * Make a request to the DisCloud API for to delete the application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::application delete_application(const dcl::discloud &discloud_token,
                                        const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/delete", app_id), dcl::Method::DELETE);
      return *this;
    }
    /**
     * Get the message received for Discloud API.
     * @return Message of the Discloud API.
     */
    std::string get_message() const
    {
      return this->get_json<std::string>("message");
    }
    /**
     * Gets the URL with the files of the APP.
     * @return The url with the files.
     */
    std::string get_backup() const
    {
      return this->get_json<std::string>("backups/url");
    }

    /**
     *
     * Get the logs big from the API
     * @return A json as strings.
     * */
    std::string logs_big() const
    {
      return this->get_json<std::string>("apps/terminal/big");
    }
    /**
     *
     * Get the logs small from the API
     * @return A json as strings.
     * */
    std::string logs_small() const
    {
      return this->get_json<std::string>("apps/terminal/small");
    }
    /**
     * It's a value of type string, get the status of the application.
     * @return A value of type string with the status application.
     */
    std::string get_status() const
    {
      return this->get_json<std::string>("apps/container");
    }
    /**
     * It's a value of type string, get the cpu of the application.
     * @return A value of type string with the cpu of the application.
     */
    std::string cpu() const
    {
      return this->get_json<std::string>("apps/cpu");
    }
    /**
     * It's a value of type string, get the memory of the application.
     * @return A value of type string with the memory of the application.
     */
    std::string memory() const
    {
      return this->get_json<std::string>("apps/memory");
    }
    /**
     * It's a value of type string, get the disk of the application.
     * @return A value of type string with the disk of the application.
     */
    std::string disk() const
    {
      return this->get_json<std::string>("apps/ssd");
    }
    /**
     * Get the network down of the application.
     * @return A value of type string with the network down of the application.
     */
    std::string network_down() const
    {
      return this->get_json<std::string>("apps/netIO/down");
    }
    /**
     * Get the network up of the application.
     * @return A value of type string with the network up of the application.
     */
    std::string network_up() const
    {
      return this->get_json<std::string>("apps/netIO/up");
    }
    /**
     * Get the started at of the application.
     * @return A value of type string with the started at of the application.
     */
    std::string started_at() const
    {
      return this->get_json<std::string>("apps/startedAt");
    }
    /**
     * It's a value of type string, get the uptime of the application.
     * @return A value of type string with the uptime of the application.
     */
    std::string uptime() const
    {
      return this->get_json<std::string>("apps/last_restart");
    }
    /**
     *
     * It's the id of the application.
     * @return Id application.*/
    std::string id() const
    {
      return this->get_json<std::string>("apps/id");
    }
    /**
     * It's the avatar of the application.
     * @return A string value as the avatar of application.
     */
    std::string avatarURL() const
    {
      return this->get_json<std::string>("apps/avatarURL");
    }
    /**
      It's the name of the application.
      * @return Name application.*/
    std::string name() const
    {
      return this->get_json<std::string>("apps/name");
    }
    /**
     * It's a boolean value, if application is online return 1 or exception 0.
     * @return Boolean Value.
     */
    bool is_online() const
    {
      return this->get_json<bool>("apps/online");
    }
    /**
     * It's a boolean value, if application isn't ram killed return 0 or
     * exception 1.
     * @return Boolean Value.
     */
    bool ram_killed() const
    {
      return this->get_json<bool>("apps/ramKilled");
    }
    /**
     * It's a int value, it returns the ram comsumed by the application.
     * @return Integer value.
     */
    int ram() const { return this->get_json<int>("apps/ram"); }
    /**
     * It's a string value, it returns the main file of the application.
     * @return The name application file as value.
     */
    std::string file_name() const
    {
      return this->get_json<std::string>("apps/mainFile");
    }
    /**
     * It's a string value, it returns the language programmation used by the
     * application.
     * @return The name language programmation used by application.
     */
    std::string lang() const
    {
      return this->get_json<std::string>("apps/lang");
    }
    /**
     * Get the mods installed in the application.
     * @return A string with the mods installed in the application.
     */
    std::string get_mods() const
    {
      try
      {
        std::vector<std::string> mods = this->get_json<std::vector<std::string>>("apps/mods");

        std::string app_mods;
        for (const auto &mod : mods)
        {
          app_mods += mod + ", ";
        }
        if (!app_mods.empty())
        {
          app_mods.pop_back();
          app_mods.pop_back();
        }
        return app_mods;
      }
      catch (const std::out_of_range &e)
      {
        std::cerr << e.what() << std::endl;
        return {};
      }
    }
    /**
     * Verify if the application is auto deploy git.
     * @return The response as a string if is no or yes.
     */
    std::string is_auto_deploy_git() const
    {
      return this->get_json<std::string>("apps/autoDeployGit");
    }
    /**
     * Verify if the application can be auto restart.
     * @return The response as a boolean, can be true or false.
     */
    bool is_auto_restart() const
    {
      return this->get_json<bool>("apps/autoRestart");
    }
  }; // class application
}; // namespace dcl
#endif // !APPLICATION_H