// C++ Beginner Coding Test (15 minutes)
// Write your solutions in the marked spaces below each question

/*
Question 1: Task Manager (5 minutes)
Create a class called Task that manages a simple to-do task.
The class should track a task's title, priority level (1-5), and completion status.
Implement the required methods to manage tasks.
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Task {
private:
    std::string title;
    int priority;
    bool isComplete;

public:
    // TODO: Write a constructor that takes the task's title and priority (1-5)
    //       Initialize isComplete as false
    //       Ensure priority is between 1-5, if not, set it to 1

    // TODO: Write a method called completeTask that marks the task as complete

    // TODO: Write a method called getPriority that returns the task's priority

    // TODO: Write a method called changePriority that takes a new priority value
    //       Only change if the new priority is between 1-5
    //       Return true if change was successful, false otherwise
};

/*
Question 2: Bank Account (5 minutes)
Create a class that simulates a basic bank account with deposits, 
withdrawals, and balance tracking.
*/

class BankAccount {
private:
    // TODO: Create member variables to store:
    //       - Account holder's name
    //       - Current balance
    //       - Transaction history (as a vector of doubles)

public:
    // TODO: Write a constructor that takes the account holder's name
    //       Initialize balance to 0.0

    // TODO: Write a method called deposit that:
    //       - Takes an amount to deposit
    //       - Adds it to the balance
    //       - Adds it to transaction history
    //       - Returns new balance
    //       - Only accept positive deposits

    // TODO: Write a method called withdraw that:
    //       - Takes an amount to withdraw
    //       - Subtracts from balance if sufficient funds
    //       - Adds to transaction history as negative number
    //       - Returns true if successful, false if insufficient funds

    // TODO: Write a method called getTransactionCount that returns
    //       the total number of transactions (deposits + withdrawals)
};

/*
Question 3: Array Statistics (5 minutes)
Complete the following functions to analyze vectors of numbers
*/

// TODO: Write a function that takes a vector of integers and returns
// a new vector containing only numbers that appear exactly once
// Example: [1,2,2,3,3,3,4] should return [1,4]
std::vector<int> findUniqueNumbers(const std::vector<int>& numbers) {
    // Your code here
}

// TODO: Write a function that takes a vector of integers and returns
// the second largest number in the vector
// If no second largest exists (empty or single element), return -1
int findSecondLargest(const std::vector<int>& numbers) {
    // Your code here
}

// Helper function to print vectors for testing
void printVector(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    // Test Task class
    std::cout << "\n=== Testing Task Class ===\n";
    
    // Test constructor and priority validation
    Task task1("High Priority Task", 2);    // Valid priority
    Task task2("Invalid Priority Task", 6);  // Invalid priority should default to 1
    Task task3("Another Task", 0);          // Invalid priority should default to 1
    
    std::cout << "Initial Priorities:\n";
    std::cout << "Task 1 Priority: " << task1.getPriority() << " (Expected: 2)\n";
    std::cout << "Task 2 Priority: " << task2.getPriority() << " (Expected: 1)\n";
    std::cout << "Task 3 Priority: " << task3.getPriority() << " (Expected: 1)\n";
    
    // Test priority change
    std::cout << "\nTesting Priority Changes:\n";
    bool change1 = task1.changePriority(4);  // Valid change
    bool change2 = task1.changePriority(6);  // Invalid change
    std::cout << "Valid change successful: " << std::boolalpha << change1 << " (Expected: true)\n";
    std::cout << "Invalid change successful: " << change2 << " (Expected: false)\n";
    std::cout << "New priority after changes: " << task1.getPriority() << " (Expected: 4)\n";
    
    // Test completion
    task1.completeTask();
    task2.completeTask();
    
    // Test BankAccount class
    std::cout << "\n=== Testing BankAccount Class ===\n";
    
    BankAccount account("John Doe");

    // Test deposits
    std::cout << "Testing Deposits:\n";
    double balance1 = account.deposit(100.50);  // Valid deposit
    double balance2 = account.deposit(-50.00);  // Invalid deposit
    std::cout << "Balance after valid deposit: $" << std::fixed << std::setprecision(2) 
              << balance1 << " (Expected: $100.50)\n";
    std::cout << "Balance after invalid deposit: $" << balance2 
              << " (Expected: $100.50, no change)\n";

    // Test withdrawals
    std::cout << "\nTesting Withdrawals:\n";
    bool withdrawal1 = account.withdraw(50.25);  // Valid withdrawal
    bool withdrawal2 = account.withdraw(100.00); // Invalid withdrawal (insufficient funds)
    std::cout << "Valid withdrawal successful: " << withdrawal1 << " (Expected: true)\n";
    std::cout << "Invalid withdrawal successful: " << withdrawal2 << " (Expected: false)\n";

    // Test transaction count
    std::cout << "\nTransaction count: " << account.getTransactionCount() 
              << " (Expected: 2)\n";

    // Test Array Statistics functions
    std::cout << "\n=== Testing Array Statistics ===\n";

    // Test findUniqueNumbers
    std::cout << "Testing findUniqueNumbers:\n";
    std::vector<int> test1 = {1, 2, 2, 3, 3, 3, 4};
    std::vector<int> test2 = {1, 1, 1, 1};
    std::vector<int> test3 = {1, 2, 3, 4, 5};

    printVector(findUniqueNumbers(test1), "Test 1");
    std::cout << "Expected: [1, 4]\n";

    printVector(findUniqueNumbers(test2), "Test 2");
    std::cout << "Expected: []\n";

    printVector(findUniqueNumbers(test3), "Test 3");
    std::cout << "Expected: [1, 2, 3, 4, 5]\n";

    // Test findSecondLargest
    std::cout << "\nTesting findSecondLargest:\n";
    std::vector<int> test4 = {5, 2, 8, 1, 9};
    std::vector<int> test5 = {1};
    std::vector<int> test6 = {4, 4, 4, 4};

    std::cout << "Test 4 (mixed numbers): " << findSecondLargest(test4) 
              << " (Expected: 8)\n";
    std::cout << "Test 5 (single element): " << findSecondLargest(test5) 
              << " (Expected: -1)\n";
    std::cout << "Test 6 (all same numbers): " << findSecondLargest(test6) 
              << " (Expected: -1)\n";

    return 0;
}
