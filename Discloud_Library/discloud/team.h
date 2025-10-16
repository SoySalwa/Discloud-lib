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
  class team
  {
  public:
    /**
     * Make a request to the DisCloud API to obtain teams data.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team get_team(const dcl::discloud &discloud_token,
                       const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "GET");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put start application team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team start_application_team(const dcl::discloud &discloud_token,
                                     const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "PUT");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put restart application team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team restart_application_team(const dcl::discloud &discloud_token,
                                       const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "PUT");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put stop application team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team stop_application_team(const dcl::discloud &discloud_token,
                                    const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "PUT");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put commit app in a team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team commit_app_team(const dcl::discloud &discloud_token,
                              const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "PUT");
      return *this;
    }

    /**
     * Make a request to the DisCloud API to obtain backup app in a team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team get_team_backup(const dcl::discloud &discloud_token,
                              const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "GET");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to obtain logs app in a team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team get_logs_team(const dcl::discloud &discloud_token,
                            const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "GET");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put ram in another app in a team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team ram_application_team(const dcl::discloud &discloud_token,
                                   const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "PUT");
      return *this;
    }
    /**
     * Make a request to the DisCloud API to obtain status app in a team.
     * @param discloud_token The DisCloud API token.
     * @param end_point The API endpoint to make the request to.
     * @return The API response as a string (JSON).
     */
    dcl::team get_status_application_team(const dcl::discloud &discloud_token,
                                          const std::string &end_point)
    {
      discloud_responses.fetch_api(discloud_token, end_point, "GET");
      return *this;
    }

  private:
    dcl::DiscloudResponses discloud_responses;
  };
} // namespace dcl
#endif // !TEAM_H
