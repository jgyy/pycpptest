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

// Task 1 (20 points)
// Implement a function that takes a vector of integers
// Return a new vector containing only unique elements in ascending order
// Example: [3, 1, 4, 1, 5, 9, 2, 6, 5, 3] → [1, 2, 3, 4, 5, 6, 9]
std::vector<int> uniqueSorted(const std::vector<int>& numbers)
{
    // Your code here
}

// Task 2 (25 points)
// Create a class called 'TaskManager' that manages a priority queue of tasks
class TaskManager
{
private:
    // Define your data members here

public:
    // Constructor
    TaskManager()
    {
        // Your code here
    }

    // Add a task with priority (higher number = higher priority)
    // Return true if task added successfully
    // Return false if task with same name already exists
    bool addTask(std::string taskName, int priority)
    {
        // Your code here
    }

    // Remove and return the highest priority task
    // Return empty string if no tasks exist
    std::string getNextTask()
    {
        // Your code here
    }

    // Return number of tasks currently in the manager
    int taskCount()
    {
        // Your code here
    }

    // Return true if task exists, false otherwise
    bool hasTask(std::string taskName)
    {
        // Your code here
    }
};

// Task 3 (25 points)
// Implement a function that takes a string of words
// Return a map where keys are words and values are their frequencies
// Ignore case (convert all to lowercase) and punctuation
// Example: "The cat and the Cat." → {"the": 2, "cat": 2, "and": 1}
std::map<std::string, int> wordFrequency(const std::string& text)
{
    // Your code here
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
    const std::vector<std::pair<std::string, int>>& available_items,
    const std::vector<std::pair<std::string, int>>& shopping_list)
{
    // Your code here
}

// Test cases
int main()
{
    // Test Task 1: uniqueSorted
    std::cout << "\nTesting Task 1:\n";
    std::vector<int> test1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> test1_empty = {};
    std::vector<int> test1_single = {1};
    std::vector<int> test1_duplicates = {1, 1, 1, 1};
    
    // Add your test assertions here

    // Test Task 2: TaskManager
    std::cout << "\nTesting Task 2:\n";
    TaskManager tm;
    // Add your test assertions here

    // Test Task 3: wordFrequency
    std::cout << "\nTesting Task 3:\n";
    std::string text1 = "The cat and the Cat.";
    std::string text2 = "A, a, A, a, B, b, B, b!";
    std::string text3 = "";
    
    // Add your test assertions here

    // Test Task 4: checkShoppingList
    std::cout << "\nTesting Task 4:\n";
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
    
    // Add your test assertions here

    return 0;
}
