#pragma once
#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include "discloud/discloud.h"
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
        std::string get_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "GET");
        }
        /**
         * Make a request to the DisCloud API to put start application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string start_application_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "PUT");
        }
        /**
         * Make a request to the DisCloud API to put restart application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string restart_application_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "PUT");
        }
        /**
         * Make a request to the DisCloud API to put stóp application team.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string stop_application_team(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "PUT");
        }
    };
}
#endif // !USER_H
