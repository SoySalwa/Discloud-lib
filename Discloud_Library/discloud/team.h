#pragma once
#ifndef TEAM_H
#define TEAM_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl
{
  class team : public DiscloudResponses
  {
  public:
    /**
     * Make a request to the DisCloud API to obtain teams data.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team get_team(const dcl::discloud &discloud_token,
                       const std::string &end_point)
    {
      this->fetch_api(discloud_token, std::format("/team"), dcl::Method::GET);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put start application team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team start_application_team(const dcl::discloud &discloud_token,
                                     const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/start", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put restart application team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team restart_application_team(const dcl::discloud &discloud_token,
                                       const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/restart", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put stop application team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team stop_application_team(const dcl::discloud &discloud_token,
                                    const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/stop", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put commit app in a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team commit_app_team(const dcl::discloud &discloud_token,
                              const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/commit", app_id), dcl::Method::PUT);
      return *this;
    }

    /**
     * Make a request to the DisCloud API to obtain backup app in a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team get_team_backup(const dcl::discloud &discloud_token,
                              const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/backup", app_id), dcl::Method::GET);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to obtain logs app in a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team get_logs_team(const dcl::discloud &discloud_token,
                            const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/logs", app_id), dcl::Method::GET);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put ram in another app in a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team ram_application_team(const dcl::discloud &discloud_token,
                                   const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/ram", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to obtain status app in a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team get_status_application_team(const dcl::discloud &discloud_token,
                                          const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/team/{}/status", app_id), dcl::Method::GET);
      return *this;
    }
  };
} // namespace dcl
#endif // !TEAM_H
