#pragma once
#ifndef UPLOAD_H
#define UPLOAD_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl {
class upload {
public:
  /**
   * Make a request to the DisCloud API to upload a file.
   * @param discloud_token The DisCloud API token.
   * @param end_point The API endpoint make the request to.
   * @param file_path, it's the file to upload.
   * @return The API response as a string (JSON).
   */
  dcl::upload send_upload(const dcl::discloud &discloud_token,
                          const std::string &end_point,
                          const std::string file_path = "") {
    discloud_responses.fetch_api(discloud_token, end_point, "POST", file_path);
    return *this;
  }
  /**
   * Get the message received for Discloud API upload info.
   * @return Message of the Discloud API.
   */
  const std::string get_message() {
    return discloud_responses.get_json<std::string>("message");
  };

private:
  std::string response;
  std::string _response;
  dcl::DiscloudResponses discloud_responses;

  void set_response(const std::string &new_response) {
    response = new_response;
  }
};
} // namespace dcl
#endif // !UPLOAD_H
