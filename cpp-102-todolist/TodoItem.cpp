#include "TodoItem.h"
#include <cstdlib>
#include <ctime>

TodoItem::TodoItem() : id(0), description(""), stage(Pending) {}

bool TodoItem::create(const std::string& new_description, int new_id) {
    // If no id provided, generate a random integer between 1 and 100.
    id = (new_id == 0) ? rand() % 100 + 1 : new_id;
    description = new_description;
    return true;
}

int TodoItem::getId() const { return id; }
std::string TodoItem::getDescription() const { return description; }
TodoStage TodoItem::getStage() const { return stage; }
void TodoItem::setStage(TodoStage new_stage) { stage = new_stage; }
