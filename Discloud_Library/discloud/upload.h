#pragma once
#ifndef UPLOAD_H
#define UPLOAD_H

#include "discloud.h"
#include "discloudResponses.h"
#include <functional>
#include <iostream>
#include <string>

namespace dcl
{
  class upload
  {
  public:
    /**
     * Make a request to the DisCloud API to upload a file.
     * @param discloud_token The DisCloud API token.
     * @param file_path, it's the file to upload.
     * @return The API response as a string (JSON).
     */
    dcl::upload send_upload(const dcl::discloud &discloud_token,
                            const std::string &file_path = "")
    {
      discloud_responses.fetch_api(discloud_token, "/upload", "POST", file_path);
      return *this;
    }
    /**
     * Get the message received for Discloud API upload info.
     * @return Message of the Discloud API.
     */
    std::string get_message() const
    {
      return discloud_responses.get_json<std::string>("message");
    };

  private:
    dcl::DiscloudResponses discloud_responses;
  };
} // namespace dcl
#endif // !UPLOAD_H
