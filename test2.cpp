/*
60-Minute C++ Beginner Coding Test (Containers Focus)

Instructions:
1. Implement all the required functions and the class according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases and container operations
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Good luck!
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
#include <sstream>
#include <cctype>

// Task 1 (20 points)
// Implement a function that takes a vector of integers
// Return a new vector containing only unique elements in ascending order
// Example: [3, 1, 4, 1, 5, 9, 2, 6, 5, 3] → [1, 2, 3, 4, 5, 6, 9]
std::vector<int> uniqueSorted(const std::vector<int> &numbers)
{
    // Your code here
    std::set<int> uniqueSet(numbers.begin(), numbers.end());
    return std::vector<int>(uniqueSet.begin(), uniqueSet.end());
}

// Task 2 (25 points)
// Create a class called 'TaskManager' that manages a priority queue of tasks
class TaskManager
{
private:
    // Define your data members here
    struct TaskPriority
    {
        std::string name;
        int priority;

        bool operator<(const TaskPriority &other) const
        {
            return priority < other.priority;
        }
    };

    std::priority_queue<TaskPriority> tasks;
    std::map<std::string, int> taskExists;
public:
    // Constructor
    TaskManager() {}

    // Add a task with priority (higher number = higher priority)
    // Return true if task added successfully
    // Return false if task with same name already exists
    bool addTask(std::string taskName, int priority)
    {
        // Your code here
        if (taskExists.find(taskName) != taskExists.end())
            return false;
        tasks.push({taskName, priority});
        taskExists[taskName] = priority;
        return true;
    }

    // Remove and return the highest priority task
    // Return empty string if no tasks exist
    std::string getNextTask()
    {
        // Your code here
        if (tasks.empty())
            return "";
        TaskPriority top = tasks.top();
        tasks.pop();
        taskExists.erase(top.name);
        return top.name;
    }

    // Return number of tasks currently in the manager
    int taskCount()
    {
        // Your code here
        return tasks.size();
    }

    // Return true if task exists, false otherwise
    bool hasTask(std::string taskName)
    {
        // Your code here
        return taskExists.find(taskName) != taskExists.end();
    }
};

// Task 3 (25 points)
// Implement a function that takes a string of words
// Return a map where keys are words and values are their frequencies
// Ignore case (convert all to lowercase) and punctuation
// Example: "The cat and the Cat." → {"the": 2, "cat": 2, "and": 1}
std::map<std::string, int> wordFrequency(const std::string &text)
{
    // Your code here
    std::map<std::string, int> frequencies;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word)
    {
        std::string cleanWord;
        for (char c : word)
            if (std::isalpha(c))
                cleanWord += std::tolower(c);
        if (!cleanWord.empty())
            ++frequencies[cleanWord];
    }
    return frequencies;
}

// Task 4 (30 points)
// Implement a function that simulates a basic shopping cart
// The function should take two vectors:
// - available_items: vector of pairs (item_name, quantity_in_stock)
// - shopping_list: vector of pairs (item_name, quantity_wanted)
// Return a vector of strings containing error messages for any problems:
// - "Not in stock: <item_name>" for items that don't exist
// - "Insufficient quantity: <item_name>" for items with insufficient stock
// Return empty vector if shopping list can be fulfilled
std::vector<std::string> checkShoppingList(
    const std::vector<std::pair<std::string, int>> &available_items,
    const std::vector<std::pair<std::string, int>> &shopping_list)
{
    // Your code here
    std::vector<std::string> errors;
    std::map<std::string, int> inventory;

    for (const auto &item : available_items)
        inventory[item.first] = item.second;
    for (const auto &item : shopping_list)
    {
        const std::string &itemName = item.first;
        int quantityWanted = item.second;
        auto it = inventory.find(itemName);
        if (it == inventory.end())
        {
            errors.push_back("Not in stock: " + itemName);
            continue;
        }
        if (it->second < quantityWanted)
            errors.push_back("Insufficient quantity: " + itemName);
    }
    return errors;
}

// Test cases
int main()
{
    // Test Task 1: uniqueSorted
    std::cout << "Testing Task 1:\n";
    std::vector<int> test1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> result1 = uniqueSorted(test1);
    assert(result1 == std::vector<int>({1, 2, 3, 4, 5, 6, 9}));

    std::vector<int> test1_empty = {};
    assert(uniqueSorted(test1_empty).empty());

    std::vector<int> test1_single = {1};
    assert(uniqueSorted(test1_single) == std::vector<int>({1}));

    std::vector<int> test1_duplicates = {1, 1, 1, 1};
    assert(uniqueSorted(test1_duplicates) == std::vector<int>({1}));

    // Test Task 2: TaskManager
    std::cout << "Testing Task 2:\n";
    TaskManager tm;
    assert(tm.taskCount() == 0);
    assert(tm.getNextTask() == "");

    assert(tm.addTask("Task1", 1) == true);
    assert(tm.addTask("Task2", 2) == true);
    assert(tm.addTask("Task1", 3) == false); // Duplicate task
    assert(tm.taskCount() == 2);
    assert(tm.hasTask("Task1") == true);
    assert(tm.hasTask("Task3") == false);

    assert(tm.getNextTask() == "Task2"); // Higher priority
    assert(tm.getNextTask() == "Task1");
    assert(tm.taskCount() == 0);

    // Test Task 3: wordFrequency
    std::cout << "Testing Task 3:\n";
    std::string text1 = "The cat and the Cat.";
    auto freq1 = wordFrequency(text1);
    assert(freq1["the"] == 2);
    assert(freq1["cat"] == 2);
    assert(freq1["and"] == 1);

    std::string text2 = "A, a, A, a, B, b, B, b!";
    auto freq2 = wordFrequency(text2);
    assert(freq2["a"] == 4);
    assert(freq2["b"] == 4);

    std::string text3 = "";
    assert(wordFrequency(text3).empty());

    // Test Task 4: checkShoppingList
    std::cout << "Testing Task 4:\n";
    std::vector<std::pair<std::string, int>> inventory = {
        {"apple", 5},
        {"banana", 2},
        {"orange", 0}
    };

    std::vector<std::pair<std::string, int>> shopping = {
        {"apple", 3},
        {"banana", 4},
        {"grape", 1},
        {"orange", 1}
    };

    auto errors = checkShoppingList(inventory, shopping);
    assert(errors.size() == 3);
    assert(std::find(errors.begin(), errors.end(), "Insufficient quantity: banana") != errors.end());
    assert(std::find(errors.begin(), errors.end(), "Not in stock: grape") != errors.end());
    assert(std::find(errors.begin(), errors.end(), "Insufficient quantity: orange") != errors.end());

    std::cout << "All tests passed!\n";
    return 0;
}
