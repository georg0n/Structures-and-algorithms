//
// Created by George on 04.04.2023.
//

#ifndef STRUCTURES_AND_ALGORITHMS_TASK_H


#include <string>
#include <map>

#define STRUCTURES_AND_ALGORITHMS_TASK_H

// Статика является фабрикой для задач
class Task{
    static std::map<std::string, Task*> tasks;
    static void reg(Task *);

public:
    static void init();
    static bool issetTasks();

    static void show();
    static int run();

    virtual std::string getName() = 0;
    virtual std::string getId() = 0;

    virtual int execute() = 0;
};



#define STRUCTURES_AND_ALGORITHMS_TASK_H

#endif //STRUCTURES_AND_ALGORITHMS_TASK_H
