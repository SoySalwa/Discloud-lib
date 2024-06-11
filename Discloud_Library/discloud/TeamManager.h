#pragma once
#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include "discloud.h"
#include <iostream>
#include <functional>
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
        std::string get_app_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "GET");
        }
        /**
         * Make a request to the DisCloud API to put start application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string add_member_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "POST");
        }
        /**
         * Make a request to the DisCloud API to put restart application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string edit_member_permissions(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "PUT");
        }
        /**
         * Make a request to the DisCloud API to put stóp application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string delete_member(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "DELETE");
        }
    };
}
#endif // !TEAM_MANAGER_H
