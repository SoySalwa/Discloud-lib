#pragma once
#ifndef USER_H
#define USER_H

#include "discloud/discloud.h"
#include <iostream>
#include <functional>
#include <string>

namespace dcl {
    class user {
    public:
        /**
         * Make a request to the DisCloud API to obtain user data.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string get_user(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "GET");
        }
        /**
         * Make a request to the DisCloud API to put set locale.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string get_locale(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "PUT");
        }
    };
}
#endif // !USER_H
