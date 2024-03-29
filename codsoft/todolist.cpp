#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].completed) {
                    std::cout << " (Completed)";
                }
                std::cout << "\n";
            }
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\n===== TO-DO LIST MANAGER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Ignore any newline character left in the buffer
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
