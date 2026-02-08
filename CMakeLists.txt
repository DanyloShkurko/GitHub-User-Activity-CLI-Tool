cmake_minimum_required(VERSION 4.1)
project(GitHub_User_Activity)

set(CMAKE_CXX_STANDARD 20)

add_executable(github-activity main.cpp
        run/Application.cpp
        run/Application.h
        cli/CliHelper.cpp
        cli/CliHelper.h
        api/ApiClient.cpp
        api/ApiClient.h
        event/Event.cpp
        event/Event.h
)

find_package(nlohmann_json 3.12.0 REQUIRED)
find_package(OpenSSL REQUIRED)
target_link_libraries(github-activity
        PRIVATE
        nlohmann_json::nlohmann_json
        OpenSSL::SSL
        OpenSSL::Crypto
)
target_include_directories(github-activity PRIVATE "httplib.h destination")
