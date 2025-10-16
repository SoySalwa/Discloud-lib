#include "discloud/application.h"
#include "discloud/discloud.h"
#include "discloud/upload.h"
#include "discloud/user.h"
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string token;
const std::string appId = "1744325859747";

int main()
{

  std::cout << "Login with your API token: " << std::endl;
  std::getline(std::cin, token);

  dcl::discloud discloud(token);

  // std::cout << discloud.get_message;

  int entry;
  const std::string RESET = "\033[0m";
  const std::string BOLD = "\033[1m";
  const std::string RED = "\033[31m";
  const std::string GREEN = "\033[32m";
  const std::string YELLOW = "\033[33m";
  const std::string BLUE = "\033[34m";
  const std::string MAGENTA = "\033[35m";
  const std::string CYAN = "\033[36m";

  std::cout << BOLD << BLUE << "Here it's the list of functions available."
            << RESET << std::endl;
  std::cout << "\n";

  std::cout << BOLD << CYAN << "For information about the user." << RESET
            << std::endl;
  std::cout << "\n";
  std::cout << BLUE << "[0] User" << RESET << std::endl;
  std::cout << YELLOW << "[1] Locale" << RESET << std::endl;

  std::cout << "\n";

  std::cout << BOLD << CYAN << "For upload a file" << RESET << std::endl;
  std::cout << "\n";
  std::cout << GREEN << "[2] Upload" << RESET << std::endl;

  std::cout << "\n";

  std::cout << BOLD << CYAN
            << "For information about the applications with GET METHOD."
            << RESET << std::endl;
  std::cout << "\n";
  std::cout << BLUE << "[3] Application" << RESET << std::endl;
  std::cout << BLUE << "[4] Status" << RESET << std::endl;
  std::cout << BLUE << "[5] Logs" << RESET << std::endl;
  std::cout << BLUE << "[6] Backup" << RESET << std::endl;
  std::cout << "\n";

  std::cout << BOLD << CYAN << "For send a request PUT the API." << RESET
            << std::endl;
  std::cout << "\n";

  std::cout << YELLOW << "[7] Start" << RESET << std::endl;
  std::cout << YELLOW << "[8] Restart" << RESET << std::endl;
  std::cout << YELLOW << "[9] Stop" << RESET << std::endl;
  std::cout << YELLOW << "[10] Ram" << RESET << std::endl;
  std::cout << YELLOW << "[11] Commit" << RESET << std::endl;
  std::cout << "\n";

  std::cout << BOLD << CYAN << "I'm scared, it's a command danger." << RESET
            << std::endl;
  std::cout << "\n";

  std::cout << RED << "[12] Delete" << RESET << std::endl;

  std::cout << "\n";

  while (true)
  {
    std::cout << "Your option selected> ";
    std::cin >> entry;

    dcl::user user_data = dcl::user();
    dcl::upload upload_file = dcl::upload();

    // Variables for the application.
    dcl::application app = dcl::application();
    app.get_application(discloud.get_token(), appId);
    dcl::application app_backup = dcl::application();
    app_backup.get_backup_application(discloud.get_token(),
                                      appId); // Backup
    dcl::application app_start = dcl::application();
    app_start.start_application(discloud.get_token(), appId); // Start
    dcl::application app_restart = dcl::application();

    app_restart.restart_application(discloud.get_token(),
                                    appId); // Restart
    dcl::application app_stop = dcl::application();
    app_stop.stop_application(discloud.get_token(), appId); // Stop
    dcl::application app_ram = dcl::application();

    dcl::application app_status = dcl::application();
    app_status.get_backup_application(discloud.get_token(), appId);

    app_ram.ram_application(discloud.get_token(), appId); // Ram
    dcl::application app_commit = dcl::application();

    dcl::application app_delete = dcl::application();
    app_delete.delete_application(discloud.get_token(),
                                  appId); // Delete

    dcl::application app_logs = dcl::application();
    app_logs.get_logs_application(discloud.get_token(), appId); // Logs

    // Another Variables.
    std::string lang;
    std::string file;
    std::string option;

    int op;
    switch (entry)
    {
    case 0:

      user_data.get_user(discloud.get_token(), "/user");
      std::cout << "\n";

      std::cout << "User ID: " << user_data.user_id() << std::endl;
      std::cout << "Type Plan: " << user_data.plan() << std::endl;
      std::cout << "Total Ram: " << user_data.total_ram() << std::endl;
      std::cout << "Ram Used: " << user_data.ram_used() << std::endl;
      std::cout << "Sub Domains: " << user_data.sub_domains() << std::endl;
      std::cout << "Custom Domains: " << user_data.custom_domains()
                << std::endl;
      std::cout << "Apps: " << user_data.apps() << std::endl;
      std::cout << "\n";
      std::cout << "Message: " << user_data.get_message() << std::endl;

      break;
    case 1:
      std::cout << "\n";

      std::cout << "Your language preferred (en-US or pt-BR): ";
      std::cin >> lang;
      user_data.set_locale(discloud.get_token(), "/locale/" + lang);

      std::cout << "Message: " << user_data.get_locale() << std::endl;
      break;
    case 2:
      std::cout << "\n";

      std::cout << "Your file in format .ZIP: ";
      std::cin >> lang;
      upload_file.send_upload(discloud.get_token(), "/upload" + file);

      std::cout << "Message: " << upload_file.get_message() << std::endl;
      break;
    case 3:
      std::cout << app.get_message() << std::endl;
      break;
    case 4:
      std::cout << "Selected Status Application." << std::endl;

      std::cout << "App Name: " << app_status.name();
      break;
    case 5:
      std::cout << "Select an option: " << std::endl;
      std::cout << "[0] Log Small" << std::endl;
      std::cout << "[1] Log Big" << std::endl;

      std::cout << "Your selection: " << std::endl;
      std::cin >> op;

      if (op == 0)
      {
        std::cout << "Selected Log Small: " << std::endl;
        std::cout << app_logs.logs_small() << std::endl;
      }
      else if (op == 1)
      {
        std::cout << "Selected Log Big: " << std::endl;
        std::cout << app_logs.logs_big() << std::endl;
      }
      break;
    case 6:
      std::cout << "\n";
      std::cout << "Message Backup: " << app_backup.get_message() << std::endl;
      std::cout << "Your backup: " << app_backup.get_backup() << std::endl;
      break;
    case 7:
      std::cout << "You're sure of start application? (Y/N): ";
      std::cin >> option;

      if (option == "Y" || option == "y")
      {
        std::cout << "\n";
        std::cout << "Message Start: " << app_start.get_message() << std::endl;
      }
      break;
    case 8:
      std::cout << "You're sure of restart application? (Y/N): ";
      std::cin >> option;

      if (option == "Y" || option == "y")
      {
        std::cout << "\n";
        std::cout << "Message Restart: " << app_restart.get_message()
                  << std::endl;
      }
      break;
    case 9:
      std::cout << "You're sure of stop application? (Y/N): ";
      std::cin >> option;

      if (option == "Y" || option == "y")
      {
        std::cout << "\n";
        std::cout << "Message Stop: " << app_stop.get_message() << std::endl;
      }
      break;
    case 10:
      break;
    case 11:
      std::cout << "Your file to commit: ";
      std::cin >> file;
      app_commit.commit_application(discloud.get_token(), appId,
                                    file); // Commit

      std::cout << "Message commit: " << app_commit.get_message();
      break;
    case 12:
      std::cout << "You're sure of delete application? (Y/N): ";
      std::cin >> option;

      if (option == "Y" || option == "y")
      {
        std::cout << "\n";
        std::cout << "Message Delete: " << app_delete.get_message()
                  << std::endl;
      }
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
    }
  }
  return 0;
}
