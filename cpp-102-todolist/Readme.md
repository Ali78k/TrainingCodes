# To-Do List App

A simple To-Do List application written in C++ using classes. This project was inspired by a YouTube tutorial and serves as a starting point for learning object-oriented programming and basic project structure in C++.

## Features

- Add tasks to the to-do list.
- Mark tasks as completed.
- Display the list of tasks with their statuses.
- Update the stage of a task (Pending, In Progress, or Completed).

## Changelog
### **v0.3.0-clever**
- **Added:** Tasks can now be loaded from a JSON file (`todo_items.json`) at program start.
- **Fixed:** Console success message now properly displays after saving tasks to the JSON file.
- **Refactored:** Moved JSON handling code (loading and saving) into separate functions for better organization.

### **v0.2.0-bright**
- **New Feature:** Tasks now have stages: 
  - **Pending**
  - **In Progress**
  - **Completed**
- Added a menu option to update the stage of any task.
- Improved the display of tasks to dynamically show their current stage.
- Added a basic functionality to save tasks into a Json file.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang, or MSVC).

### Compilation

Compile the program using a command like:
```bash
g++ -o todo todo.cpp
```

### Running the Program

Run the compiled program:
```bash
./todo
```

## Usage

1. Follow the on-screen menu to add, complete, or view tasks.
2. Manage your tasks directly within the console application.

## Future Enhancements

### Planned Features

1. **File I/O**:
   - Add functionality to save the tasks to a file.
   - Enable reading tasks from a file when the program starts.

### Suggested Improvements

1. **Task Priority**:
   - Allow users to assign priorities (e.g., High, Medium, Low) to tasks.

2. **Task Deadlines**:
   - Add support for setting and displaying deadlines for tasks.

3. **Search and Filter**:
   - Include a feature to search tasks by name or filter them by status or priority.

4. **GUI**:
   - Transition to a graphical user interface for better usability.

5. **Cross-Platform Support**:
   - Test and adapt the application to work seamlessly on Windows, macOS, and Linux.

## Contributions

Feel free to fork this repository and submit pull requests for new features, bug fixes, or improvements.

## Acknowledgements
This project is based on the tutorial available at [https://www.youtube.com/watch?v=D17rZyd9r18](https://www.youtube.com/watch?v=D17rZyd9r18).

---

Happy coding!

