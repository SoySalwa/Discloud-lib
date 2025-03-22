#pragma once
#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl {
class team_manager {
public:
  /**
   * Make a request to the DisCloud API to obtain teams data.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::team_manager get_app_team(const dcl::discloud &discloud_token,
                                 const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "GET");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put start application team.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::team_manager add_member_team(const dcl::discloud &discloud_token,
                                    const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "POST");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put restart application team.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::team_manager edit_member_permissions(const dcl::discloud &discloud_token,
                                            const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "PUT");
    return *this;
  }
  /**
   * Make a request to the DisCloud API to put stóp application team.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint to make the request to.
   * @return The API response as a string (JSON).
   */
  dcl::team_manager delete_member(const dcl::discloud &discloud_token,
                                  const std::string &end_point) {
    discloud_responses.fetch_api(discloud_token, end_point, "DELETE");
    return *this;
  }

private:
  dcl::DiscloudResponses discloud_responses;
};
} // namespace dcl
#endif // !TEAM_MANAGER_H
