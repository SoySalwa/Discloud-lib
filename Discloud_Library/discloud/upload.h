#ifndef UPLOAD_H
#define UPLOAD_H

#include "discloud.h"
#include <iostream>
#include <functional>
#include <string>

namespace dcl {
	class upload {
	public: 
        /**
         * Make a request to the DisCloud API to upload a file.
         * @param discloud_token The DisCloud API token.
         * @param end_point The API endpoint to make the request to.
         * @return The API response as a string (JSON).
         */
        std::string upload_file(const dcl::discloud& discloud_token, const std::string& end_point) {
            dcl::discloud discloud(discloud_token);
            return discloud.route(end_point, "POST");
        }
	};
}
#endif // !UPLOAD_H
