/*
60-Minute C++ Beginner Coding Test: Data Structures and Algorithms

Instructions:
1. Implement all the required functions according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases and efficiency
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Focus: Basic data structures, string manipulation, and problem-solving

Good luck!
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cassert>

// Task 1 (25 points)
// Create a Stack class using a vector as the underlying container
// Implement push, pop, top, size, and isEmpty operations
// The stack should store integers
class Stack {
private:
    // Define your data members here

public:
    Stack() {
        // Your constructor code here
    }

    // Push an element onto the stack
    void push(int value) {
        // Your code here
    }

    // Remove and return the top element
    // Throw std::runtime_error if stack is empty
    int pop() {
        // Your code here
    }

    // Return the top element without removing it
    // Throw std::runtime_error if stack is empty
    int top() const {
        // Your code here
    }

    // Return current number of elements
    size_t size() const {
        // Your code here
    }

    // Return true if stack is empty
    bool isEmpty() const {
        // Your code here
    }
};

// Task 2 (25 points)
// Implement a function that processes a sequence of brackets
// Return true if brackets are properly matched, false otherwise
// Valid brackets are: (), [], {}
// Example: "({[]})" → true
// Example: "([)]" → false
// Example: "((())" → false
bool isValidBracketSequence(const std::string& brackets) {
    // Your code here
}

// Task 3 (25 points)
// Create a PhoneBook class that stores phone numbers and names
// Implement functions to add contacts and search by name prefix
class PhoneBook {
private:
    // Define your data members here

public:
    PhoneBook() {
        // Your constructor code here
    }

    // Add or update a contact
    // If contact exists, update their number
    // Return true if new contact added, false if updated
    bool addContact(const std::string& name, const std::string& phoneNumber) {
        // Your code here
    }

    // Remove a contact by name
    // Return true if contact was found and removed
    bool removeContact(const std::string& name) {
        // Your code here
    }

    // Find all contacts whose names start with the given prefix
    // Return vector of pairs (name, phone_number)
    // Return empty vector if no matches found
    std::vector<std::pair<std::string, std::string>> searchByPrefix(const std::string& prefix) {
        // Your code here
    }

    // Return total number of contacts
    size_t contactCount() const {
        // Your code here
    }
};

// Task 4 (25 points)
// Implement a function that finds the longest subsequence of increasing numbers
// Return the length of the longest increasing subsequence
// Example: [10, 9, 2, 5, 3, 7, 101, 18] → 4 (the subsequence is [2, 5, 7, 101])
// Example: [0, 1, 0, 3, 2, 3] → 4 (the subsequence is [0, 1, 2, 3])
int longestIncreasingSubsequence(const std::vector<int>& numbers) {
    // Your code here
}

// Test cases
int main()
{
    // Test Task 1: Stack
    Stack stack;
    assert(stack.isEmpty());
    assert(stack.size() == 0);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(!stack.isEmpty());
    assert(stack.size() == 3);
    assert(stack.top() == 3);

    assert(stack.pop() == 3);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);
    assert(stack.isEmpty());

    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (const std::runtime_error&) {
        // Should catch error
    }

    // Test Task 2: Bracket Matching
    assert(isValidBracketSequence("({[]})") == true);
    assert(isValidBracketSequence("([)]") == false);
    assert(isValidBracketSequence("((())") == false);
    assert(isValidBracketSequence("") == true);
    assert(isValidBracketSequence("()[]{}") == true);
    assert(isValidBracketSequence("}") == false);

    // Test Task 3: PhoneBook
    PhoneBook phoneBook;
    assert(phoneBook.addContact("John Doe", "1234567890") == true);
    assert(phoneBook.addContact("Jane Doe", "0987654321") == true);
    assert(phoneBook.addContact("John Smith", "5555555555") == true);

    auto results = phoneBook.searchByPrefix("John");
    assert(results.size() == 2);
    assert(phoneBook.removeContact("Jane Doe") == true);
    assert(phoneBook.removeContact("Not Found") == false);
    assert(phoneBook.contactCount() == 2);

    // Test Task 4: Longest Increasing Subsequence
    assert(longestIncreasingSubsequence({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(longestIncreasingSubsequence({0, 1, 0, 3, 2, 3}) == 4);
    assert(longestIncreasingSubsequence({7, 7, 7, 7}) == 1);
    assert(longestIncreasingSubsequence({1, 2, 3, 4, 5}) == 5);
    assert(longestIncreasingSubsequence({5, 4, 3, 2, 1}) == 1);
    assert(longestIncreasingSubsequence({}) == 0);

    std::cout << "All tests passed successfully!\n";
    return 0;
}
