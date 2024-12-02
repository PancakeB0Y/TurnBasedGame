#include "RestartProgram.hpp"

void RestartProgram::Restart(int (*func)()){
    //Restart console
    char restart;

    do {
        std::cout << "\nType r to restart\n";
        std::cin >> restart;

        restart = std::tolower(restart);

        if (restart == 'r') {
            system("cls");
            func();
        }
    } while (restart != 'r');
}