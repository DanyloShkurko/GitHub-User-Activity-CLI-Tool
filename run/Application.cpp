//
// Created by Danylo Shkurko on 01.02.2026.
//

#include "Application.h"

#include <iostream>

#include "../cli/CliHelper.h"

void Application::run(const int &argc, char *argv[]) {
    const auto apiClient = std::make_shared<ApiClient>();
    CliHelper cli(apiClient);

    if (argc == 1) {
        cli.help();
    } else if (argc == 2) {
        std::string res = cli.getInfo(argv[1]);
        std::cout << "\n" << res << "\n" << std::endl;
    }
}
