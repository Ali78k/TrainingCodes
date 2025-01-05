#ifndef TODO_ITEM_H
#define TODO_ITEM_H

#include <string>

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
    TodoItem();
    ~TodoItem() = default;

    bool create(const std::string& new_description, int new_id = 0);

    int getId() const;
    std::string getDescription() const;
    TodoStage getStage() const;
    void setStage(TodoStage new_stage);
};

#endif // TODO_ITEM_H
