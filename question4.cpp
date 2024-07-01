// Build a simple console-based to-do list
// manager that allows users to add, view, and
// delete tasks

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function to display the list of tasks
void displayTasks(const vector<Task>& tasks) {
    cout << "Task List:" << endl;
    int index = 1;
    for (const Task& task : tasks) {
        cout << index++ << ". " << (task.completed ? "[x] " : "[ ] ") << task.description << endl;
    }
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
    cout << "Enter a task description: ";
    string description;
    getline(cin, description);

    Task newTask = {"", false};
    newTask.description = description;
    tasks.push_back(newTask);
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    cout << "Enter the task number to mark as completed: ";
    int index;
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    cout << "Enter the task number to remove: ";
    int index;
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "-----------------" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Quit" << endl;
        cout << "Choose an option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    }

    return 0;
}