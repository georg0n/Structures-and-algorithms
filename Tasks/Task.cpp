#include "Task.h"

#include "1.1/firstTask.h"

using namespace std;

void Task::init(){
    reg(new FirstTask());
}

bool Task::issetTasks(){
    return !tasks.empty();
}

int Task::run() {
    cout << ">> Number of task: ";
    string val;
    cin >> val;

    if(tasks.find(val) != tasks.end()){
        return tasks[val]->execute();
    }else{
        cout << "Number is not correct!" << endl;
        return EXIT_FAILURE;
    }
}

void Task::show() {
    cout << "Choose task for check: " << endl;

    for (const auto& [key, task]: tasks){
        cout << ">> " << key << " - " << task->getName() << endl;
    }
}

void Task::reg(Task *task) {
    if(tasks.find(task->getId()) != tasks.end()) {
        throw std::invalid_argument("This task has already been added");
    }
    Task::tasks[task->getId()] = task;
}