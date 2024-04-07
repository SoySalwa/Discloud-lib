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

     myApp.get_application(discloud.get_token(), "/app/" + app);

    /*std::cout << "It's information of your application: " << std::endl;
    std::cout << "\n";
    std::cout << "App Name: " << myApp.name() << std::endl;
    std::cout << "App Id: " << myApp.id() << std::endl;
    std::cout << "App Avatar: " << myApp.avatarURL() << std::endl;
    std::cout << "Online: " << myApp.is_online() << std::endl;
    std::cout << "Ram killed: " << myApp.ram_killed() << std::endl;
    std::cout << "Ram: " << myApp.ram() << std::endl;
    std::cout << "Main File: " << myApp.file_name() << std::endl;
    std::cout << "Language: " << myApp.lang() << std::endl;
    std::cout << "\n" << std::endl; */

     app_status.get_status_application(discloud.get_token(), "/app/" + app + "/status");
  /*  std::cout << "It's information of your status application: " << std::endl;
    std::cout << "\n";
    std::cout << "App Id: " << app_status.status_id() << std::endl;
    std::cout << "Online: " << app_status.container() << std::endl;
    std::cout << "CPU: " << app_status.cpu() << std::endl;
    std::cout << "Memory Ram: " << app_status.memory() << std::endl;
    std::cout << "Disk: " << app_status.disk() << std::endl;
    std::cout << "Uptime: " << app_status.uptime() << std::endl;

    std::cout << "\n" << std::endl;
    */
    return 0;
}