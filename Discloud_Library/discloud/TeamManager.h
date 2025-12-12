#pragma once
#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl
{
  class team_manager : public DiscloudResponses
  {
  public:
    /**
     * Make a request to the DisCloud API to obtain teams data.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team_manager get_app_team(const dcl::discloud &discloud_token,
                                   const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/team", app_id), dcl::Method::GET);
      return *this;
    }
    /**
     * Make a request to the DisCloud API for to add members to application.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team_manager add_member_team(const dcl::discloud &discloud_token,
                                      const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/team", app_id), dcl::Method::POST);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to edit permissions to member of a team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     */
    dcl::team_manager edit_member_permissions(const dcl::discloud &discloud_token,
                                              const std::string &app_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/team", app_id), dcl::Method::PUT);
      return *this;
    }
    /**
     * Make a request to the DisCloud API to put st�p application team.
     * @param discloud_token The DisCloud API token.
     * @param app_id Your application ID.
     * @param mod_id The member ID to delete.
     */
    dcl::team_manager delete_member(const dcl::discloud &discloud_token,
                                    const std::string &app_id, const std::string &mod_id)
    {
      this->fetch_api(discloud_token, std::format("/app/{}/team/{}", app_id, mod_id), dcl::Method::DELETE);
      return *this;
    }
  };
} // namespace dcl
#endif // !TEAM_MANAGER_H
