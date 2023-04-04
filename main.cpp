#include <iostream>
#include "Tasks/Task.h"

using namespace std;

int main() {
    Task::init();

    if(Task::issetTasks())
    {
        restart:
        Task::show();
        int statusExit = Task::run();

        int isStayInProgram = 0;
        std::cout << "Do you want to continue?" << std::endl;
        std::cin >> isStayInProgram;
        if(std::cin.fail())
        {
            std::cin.clear();
            goto exit;
        }
        switch (isStayInProgram) {
            case 1:
                goto restart;
            case 0:
            default:
                exit:
                    std::cout << "Push Enter for close program"<< std::endl;
                    fgetc(stdin);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return statusExit;
    } else{
        std::cout<<"Task not found!"<<std::endl;
        return EXIT_FAILURE;
    }
}
