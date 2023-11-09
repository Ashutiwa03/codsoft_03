#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "To-Do List" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. List Tasks" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    Task newTask;
                    std::cin.ignore();  // Clear the newline character from the previous input
                    std::cout << "Enter task description: ";
                    std::getline(std::cin, newTask.description);
                    newTask.completed = false;
                    tasks.push_back(newTask);
                    std::cout << "Task added!" << std::endl;
                    break;
                }
            case 2:
                {
                    int index;
                    std::cout << "Enter the task number to remove: ";
                    std::cin >> index;
                    if (index >= 1 && index <= tasks.size()) {
                        tasks.erase(tasks.begin() + index - 1);
                        std::cout << "Task removed!" << std::endl;
                    } else {
                        std::cout << "Invalid task number." << std::endl;
                    }
                    break;
                }
            case 3:
                std::cout << "Tasks:" << std::endl;
                for (int i = 0; i < tasks.size(); i++) {
                    std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << std::endl;
                }
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
