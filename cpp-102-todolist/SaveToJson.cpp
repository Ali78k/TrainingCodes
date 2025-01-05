#include "JsonUtils.h"
#include <fstream>
#include <iostream>

void saveToJson(const std::list<TodoItem>& todoItems, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    outFile << "[\n";
    for (auto it = todoItems.begin(); it != todoItems.end(); ++it) {
        outFile << "  {\n";
        outFile << "    \"id\": " << it->getId() << ",\n";
        outFile << "    \"description\": \"" << it->getDescription() << "\",\n";

        std::string stage;
        switch (it->getStage()) {
        case Pending:
            stage = "Pending";
            break;
        case InProgress:
            stage = "InProgress";
            break;
        case Completed:
            stage = "Completed";
            break;
        }
        outFile << "    \"stage\": \"" << stage << "\"\n";
        outFile << "  }";

        if (std::next(it) != todoItems.end()) {
            outFile << ",\n";
        }
    }
    outFile << "\n]";

    outFile.close();
    std::cout << "Tasks saved to " << filename << "." << std::endl;
}
