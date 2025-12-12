#pragma once
#ifndef DISCLOUD_H
#define DISCLOUD_H

#include <curl/curl.h>
#include <exception>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>

using json = nlohmann::json;

namespace dcl
{

  enum class Method
  {
    GET,
    PUT,
    POST,
    DELETE
  };

  struct CurlDeleter
  {
    void operator()(CURL *ptr) const
    {
      if (ptr)
        curl_easy_cleanup(ptr);
    }
  };
  struct CurlSlistDeleter
  {
    void operator()(curl_slist *ptr) const
    {
      if (ptr)
        curl_slist_free_all(ptr);
    }
  };
  struct CurlMimeDeleter
  {
    void operator()(curl_mime *ptr) const
    {
      if (ptr)
        curl_mime_free(ptr);
    }
  };

  using CurlHandle = std::unique_ptr<CURL, CurlDeleter>;
  using CurlHeaders = std::unique_ptr<curl_slist, CurlSlistDeleter>;
  using CurlMime = std::unique_ptr<curl_mime, CurlMimeDeleter>;

  class discloud
  {
  public:
    /**
     * Constructor for initializing DisCloud API access.
     * @param token A string representing the DisCloud API token.
     */
    explicit discloud(const std::string &token) : discloud_token(token) {};
    discloud(const dcl::discloud &token)
        : discloud_token(token.discloud_token) {};

    /**
     * Function to get DisCloud API Token in dcl::discloud format.
     * @return The DisCloud API token.
     */
    dcl::discloud get_token() const { return *this; }

  protected:
    static constexpr std::string_view method_to_string(Method method)
    {
      switch (method)
      {
      case Method::GET:
        return "GET";
      case Method::PUT:
        return "PUT";
      case Method::POST:
        return "POST";
      case Method::DELETE:
        return "DELETE";
      default:
        return "GET";
        break;
      }
    };

  private:
    friend class DiscloudResponses;
    std::string discloud_token;
    std::string response;
    const std::string base_url = "https://api.discloud.app/v2";

    /**
     * Function to add an endpoint in the discloud URL.
     * @param end_point A URL that represents the endpoint you want to access.
     * @param method The HTTP method to use for the request.
     * @param file an optional argument (it's only for upload a file in the API)
     */
    std::string route(std::string_view end_point, Method method, std::string_view file = "") const
    {
      CurlHandle curl(curl_easy_init());
      if (!curl)
      {
        throw std::runtime_error("Fallo crítico: No se pudo inicializar cURL.");
      }

      std::string url = base_url + std::string(end_point);
      std::string response_buffer; // Local para thread-safety

      // Configuración básica
      curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl.get(), CURLOPT_TIMEOUT, 10L); // Aumenté un poco el timeout

      // Headers
      struct curl_slist *headers_raw = nullptr;
      std::string auth_header = "api-token: " + discloud_token;
      headers_raw = curl_slist_append(headers_raw, auth_header.c_str());

      CurlHeaders headers(headers_raw);
      curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, headers.get());
      curl_easy_setopt(curl.get(), CURLOPT_CUSTOMREQUEST, method_to_string(method).data());
      curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, discloud::WriteCallback);
      curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &response_buffer);

      CurlMime mime(nullptr);
      if (!file.empty())
      {
        mime.reset(curl_mime_init(curl.get()));
        curl_mimepart *part = curl_mime_addpart(mime.get());

        curl_mime_name(part, "file");
        curl_mime_filedata(part, std::string(file).c_str());

        curl_easy_setopt(curl.get(), CURLOPT_MIMEPOST, mime.get());
      }

      CURLcode res = curl_easy_perform(curl.get());
      if (res != CURLE_OK)
      {
        throw std::runtime_error(std::string("cURL request failed: ") + curl_easy_strerror(res));
      }

      return response_buffer;
    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                                std::string *userp)
    {
      size_t total_size = size * nmemb;
      userp->append(static_cast<char *>(contents), total_size);
      return total_size;
    }
  };
} // namespace dcl

#endif // DISCLOUD_H
