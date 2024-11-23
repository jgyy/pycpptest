/**
 * C++ Coding Interview Questions (60 Minutes)
 * -----------------------------------------
 * Instructions:
 * 1. Implement solutions for all 4 problems
 * 2. Each problem has a different focus area
 * 3. Run the tests to verify your solutions
 * 4. Focus on code readability and efficiency
 * Time: 60 minutes
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Problem 1: Array Transformation
/**
 * Given an array of integers and a target sum, find two numbers that add up to the target.
 * Return the indices of these numbers.
 * You may assume exactly one solution exists.
 * 
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1] (because nums[0] + nums[1] = 2 + 7 = 9)
 * 
 * @param nums Vector of integers
 * @param target Target sum to find
 * @return Vector containing indices of two numbers that sum to target
 */
vector<int> findTwoSum(const vector<int>& nums, int target) {
    // TODO: Implement your solution here
    return {};
}

// Problem 2: String Manipulation
/**
 * Given a string containing lowercase letters, return the longest substring
 * that contains no repeating characters.
 * 
 * Example:
 * Input: "abcabcbb"
 * Output: "abc"
 * Input: "bbbbb"
 * Output: "b"
 * 
 * @param s Input string
 * @return Longest substring without repeating characters
 */
string longestNonRepeatingSubstring(const string& s) {
    // TODO: Implement your solution here
    return "";
}

// Problem 3: Data Structure Design
/**
 * Design a data structure that implements a simple task scheduler.
 * The scheduler should support:
 * - Adding tasks with priorities
 * - Getting the highest priority task
 * - Removing the highest priority task
 * 
 * Example usage:
 * TaskScheduler scheduler;
 * scheduler.addTask("Task1", 3);
 * scheduler.addTask("Task2", 1);
 * scheduler.getNextTask(); // Returns "Task1" (priority 3)
 */
class TaskScheduler {
private:
    // TODO: Add your member variables here

public:
    TaskScheduler() {
        // Initialize your data structure
    }
    
    void addTask(string taskName, int priority) {
        // TODO: Implement adding a task
    }
    
    string getNextTask() {
        // TODO: Implement getting highest priority task
        return "";
    }
    
    bool removeTask() {
        // TODO: Implement removing highest priority task
        return false;
    }
};

// Problem 4: Mathematical Problem
/**
 * Given a positive integer n, return the minimum number of perfect squares
 * that sum up to n.
 * A perfect square is an integer that is the square of another integer.
 * 
 * Example:
 * Input: n = 12
 * Output: 3 (12 = 4 + 4 + 4)
 * Input: n = 13
 * Output: 2 (13 = 4 + 9)
 * 
 * @param n Target number
 * @return Minimum number of perfect squares needed
 */
int minPerfectSquares(int n) {
    // TODO: Implement your solution here
    return 0;
}

// Test functions for each problem
void testProblem1() {
    cout << "\nTesting Problem 1: Two Sum" << endl;
    cout << string(40, '-') << endl;
    
    vector<pair<pair<vector<int>, int>, vector<int>>> testCases = {
        {{{2, 7, 11, 15}, 9}, {0, 1}},
        {{{3, 2, 4}, 6}, {1, 2}},
        {{{3, 3}, 6}, {0, 1}}
    };
    
    try {
        for (const auto& test : testCases) {
            vector<int> result = findTwoSum(test.first.first, test.first.second);
            assert(result == test.second);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem2() {
    cout << "\nTesting Problem 2: Longest Non-Repeating Substring" << endl;
    cout << string(40, '-') << endl;
    
    vector<pair<string, string>> testCases = {
        {"abcabcbb", "abc"},
        {"bbbbb", "b"},
        {"pwwkew", "wke"}
    };
    
    try {
        for (const auto& test : testCases) {
            string result = longestNonRepeatingSubstring(test.first);
            assert(result == test.second);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem3() {
    cout << "\nTesting Problem 3: Task Scheduler" << endl;
    cout << string(40, '-') << endl;
    
    try {
        TaskScheduler scheduler;
        scheduler.addTask("Task1", 3);
        scheduler.addTask("Task2", 1);
        scheduler.addTask("Task3", 2);
        
        assert(scheduler.getNextTask() == "Task1");
        assert(scheduler.removeTask() == true);
        assert(scheduler.getNextTask() == "Task3");
        
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem4() {
    cout << "\nTesting Problem 4: Minimum Perfect Squares" << endl;
    cout << string(40, '-') << endl;
    
    vector<pair<int, int>> testCases = {
        {12, 3},
        {13, 2},
        {1, 1},
        {4, 1}
    };
    try {
        for (const auto& test : testCases) {
            int result = minPerfectSquares(test.first);
            assert(result == test.second);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void printProblemDescription(int problemNum, const string& description) {
    cout << "\nProblem " << problemNum << endl;
    cout << string(40, '=') << endl;
    cout << description << endl;
    cout << string(40, '-') << endl;
}

void runAllTests() {
    cout << "\n=== Running Tests ===" << endl;
    auto start = high_resolution_clock::now();
    testProblem1();
    testProblem2();
    testProblem3();
    testProblem4();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nAll tests completed in " << fixed << setprecision(2)
         << duration.count() / 1000.0 << " seconds" << endl;
}

int main() {
    cout << "\nC++ Coding Interview Questions" << endl;
    cout << string(30, '=') << endl;
    cout << "Time allowed: 60 minutes\n" << endl;
    cout << "Instructions:" << endl;
    cout << "- Implement the solution for each problem" << endl;
    cout << "- Use only standard C++ libraries" << endl;
    cout << "- Focus on both correctness and code quality" << endl;
    cout << "- Run this file to test your solutions" << endl;
    vector<pair<int, string>> problems = {
        {1, "Find two numbers in an array that sum to a target"},
        {2, "Find longest substring without repeating characters"},
        {3, "Implement a priority-based task scheduler"},
        {4, "Find minimum number of perfect squares summing to n"}
    };
    for (const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }
    runAllTests();
    return 0;
}
