#include <iostream>
#include <nlohmann/json.hpp>
#include "discloud/discloud.h"
#include "discloud/user.h"
#include "discloud/application.h"

using json = nlohmann::json;

std::string token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjM5OTI1NDgzODQzODc4OTEzMCIsImtleSI6Indjd3JpQ3R0WkwifQ.f46S9t4ieYOk-mIdhVB30Vl8308R8uNeXE9K6kIN_ZQ";
std::string app = "1093178152055996509";

int main() {
    dcl::discloud discloud(token);
    dcl::application myApp = dcl::application();
    dcl::application app_status = dcl::application();
    dcl::application app_stop = dcl::application();
    dcl::user user = dcl::user();

    app_stop.start_application(discloud.get_token(), "/app/" + app + "/start");
    std::cout << "AppId: " << app_stop.get_message_start() << std::endl;
    return 0;
}