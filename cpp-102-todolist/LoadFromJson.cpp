#include "JsonUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

void loadFromJson(std::list<TodoItem>& todoItems, const std::string& filename) {
    std::ifstream inFile(filename);

    // Check if the file exists
    if (!inFile) {
        std::cout << "No existing JSON file found. Skipping import." << std::endl;
        return; // Skip importing
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.find("{") != std::string::npos) {  // Start of a new task
            int id = 0;
            std::string description;
            TodoStage stage = Pending;

            // Parse task fields
            while (std::getline(inFile, line)) {
                if (line.find("id") != std::string::npos) {
                    size_t pos = line.find(":") + 1;
                    id = std::stoi(line.substr(pos));
                } 
                else if (line.find("description") != std::string::npos) {
                    size_t pos = line.find(":") + 3;  // Skip past `:"`
                    description = line.substr(pos, line.size() - pos - 2);  // Remove quotes
                } 
                else if (line.find("stage") != std::string::npos) {
                    size_t pos = line.find(":") + 3;  // Skip past `:"`
                    std::string stageStr = line.substr(pos, line.size() - pos - 1);  // Remove quotes

                    if (stageStr == "Pending") {
                        stage = Pending;
                    } else if (stageStr == "InProgress") {
                        stage = InProgress;
                    } else if (stageStr == "Completed") {
                        stage = Completed;
                    }
                }

                if (line.find("}") != std::string::npos) {  // End of task
                    break;
                }
            }

            // Create and configure TodoItem
            TodoItem newItem;
            newItem.create(description, id);  // Pass both description and id
            newItem.setStage(stage);         // Set the stage

            // Add to the list
            todoItems.push_back(newItem);
        }
    }

    inFile.close();
    std::cout << "Tasks loaded from " << filename << std::endl;
}
