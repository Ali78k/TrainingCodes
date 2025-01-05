#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <list>
#include <string>
#include "TodoItem.h"

void saveToJson(const std::list<TodoItem>& todoItems, const std::string& filename);
void loadFromJson(std::list<TodoItem>& todoItems, const std::string& filename);

#endif // JSON_UTILS_H
