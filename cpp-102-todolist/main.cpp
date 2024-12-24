// This file contains the 'main' function.
//
//
#include <iostream>
#include <string>
#include <list>
#include <ctime>

enum TodoStage {
    Pending,
    InProgress,
    Completed
};

class TodoItem {
private:
    int id;
    std::string description;
    TodoStage stage;

public:
    TodoItem(): id(0), description(""), stage(Pending) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // Generates a random integer between 1 and 100.
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }


    int getId() { return id; }
    std::string getDescription() { return description; }
    TodoStage getStage() { return stage; }
    void setStage(TodoStage new_stage) { stage = new_stage; }
};
int main()
{
    std::string version = "v0.2.0-alpha";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    char input_option;
    int input_id;
    std::string input_description;

    srand(time(NULL));


    todoItems.clear();


    while(1) {
        system("clear");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;
        
        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::string stage;
            switch (it->getStage()) {
            case Pending:
                stage = "Pending";
                break;
            case InProgress:
                stage = "In Progress";
                break;
            case Completed:
                stage = "Completed";
                break;
            }
            std::cout << it->getId() << " | " << it->getDescription() << " | " << stage << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo!" << std::endl;
        }
        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[u]pdate stage of a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "Choice: ";
        std::cin >> input_option;

        if (input_option=='q') {
            std::cout << "Have a great day now!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }


        else if (input_option == 'u') {
            std::cout << "Enter id to update a stage: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
            
                if (input_id == it->getId()) {
                    int stage_choice;
                    std::cout<< "Choose stage: [0] Pending, [1] In Progress, [2] Completed: ";
                    std::cin >> stage_choice;
                    if (stage_choice >= 0 && stage_choice <= 2) {
                        it->setStage(static_cast<TodoStage>(stage_choice));
                    } else {
                        std::cout << "Invalid stage choice!" << std::endl;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
