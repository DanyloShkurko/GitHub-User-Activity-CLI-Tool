//
// Created by Danylo Shkurko on 01.02.2026.
//

#ifndef GITHUB_USER_ACTIVITY_APPLICATION_H
#define GITHUB_USER_ACTIVITY_APPLICATION_H


class Application {
public:
    Application() = default;
    ~Application() = default;

    static void run(const int& argc, char* argv[]);
};


#endif //GITHUB_USER_ACTIVITY_APPLICATION_H