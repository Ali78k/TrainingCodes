// This file contains the 'main' function.
//
//
#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem(): id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // Generates a random integer between 1 and 100.
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }


    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void setCompleted(bool val) { completed = val; }
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

//    TodoItem test;
//    test.create("this is a test");
//    todoItems.push_back(test);

    while(1) {
        system("clear");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;
        
        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::string completed = it->isCompleted() ? "Done" : "In Progress";
            std::cout << it->getId() << "| " << it->getDescription() << " | "
                << completed << std::endl;
        }
        if (todoItems.empty()) {
            std::cout << "Add your first todo!" << std::endl;
        }
        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]complete a Todo" << std::endl;
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


        else if (input_option == 'c') {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
            
                if (input_id == it->getId()) {
                    it->setCompleted(true);
                        break;
                }
            }
        }
    }

    return 0;
}

