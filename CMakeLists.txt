cmake_minimum_required(VERSION 3.16)
project(discloud VERSION 0.10.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

include(FetchContent)
FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG master)

FetchContent_MakeAvailable(nlohmann_json)

set(PROJECT_SOURCES 
	Discloud_Library/discloud/discloud.h
	# Discloud_Library/discloud/discloud.h
	Discloud_Library/discloud/application.h
	Discloud_Library/discloud/upload.h
	Discloud_Library/discloud/user.h
	Discloud_Library/main.cc

)

add_executable(discloud ${PROJECT_SOURCES})

target_link_libraries(discloud PRIVATE CURL::libcurl)
