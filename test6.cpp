/**
 * C++ Coding Interview Questions (60 Minutes)
 * -----------------------------------------
 * Instructions:
 * 1. Implement solutions for all 4 problems
 * 2. Focus on code readability and efficiency
 * 3. All required headers are already included
 * 4. Run tests to verify your solutions
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Problem 1: Array Product Signs
/**
 * Given an array of integers, return a new array where each element is:
 * 1 if the product of all numbers except the current one is positive
 * -1 if the product of all numbers except the current one is negative
 * 0 if the product of all numbers except the current one is zero
 * 
 * Example:
 * Input: [1, -2, -3, 4]
 * Output: [24, -12, 8, -6]  ->  [1, -1, -1, 1]
 * 
 * @param nums Vector of integers
 * @return Vector containing signs of products
 */
vector<int> productSigns(const vector<int>& nums) {
    // TODO: Implement your solution here
    return {};
}

// Problem 2: Reverse Words
/**
 * Given a string containing words separated by spaces,
 * reverse the order of words while preserving the order of characters within each word.
 * Multiple spaces between words should be reduced to a single space.
 * Leading and trailing spaces should be removed.
 * 
 * Example:
 * Input: "  hello   world  python  "
 * Output: "python world hello"
 * 
 * @param str Input string containing words
 * @return String with reversed word order
 */
string reverseWords(string str) {
    // TODO: Implement your solution here
    return "";
}

// Problem 3: Last K Elements Average
/**
 * Implement a class that maintains a stream of integers and can calculate
 * the average of the last K elements added.
 * If fewer than K elements have been added, calculate average of all elements.
 * 
 * Example:
 * KAverage avg(3);
 * avg.add(5);    // returns 5.0
 * avg.add(8);    // returns 6.5
 * avg.add(3);    // returns 5.33
 * avg.add(2);    // returns 4.33 (only considers last 3: 8,3,2)
 */
class KAverage {
private:
    // Add your member variables here

public:
    KAverage(int k) {
        // Initialize your data structure
    }
    
    double add(int val) {
        // TODO: Implement add operation
        return 0.0;
    }
    
    // Add any helper methods you need
};

// Problem 4: Parentheses Score
/**
 * Given a balanced string containing only '(' and ')', compute its score:
 * - Empty string has score 0
 * - AB has score A + B where A and B are balanced strings
 * - (A) has score 2 * A where A is a balanced string
 * 
 * Example:
 * "()" = 1
 * "(())" = 2
 * "(()(()))" = 6
 * 
 * @param s String containing only parentheses
 * @return Score of the string
 */
int scoreParentheses(string s) {
    // TODO: Implement your solution here
    return 0;
}

// Test functions
void testProblem1() {
    cout << "\nTesting Problem 1: Array Product Signs" << endl;
    cout << string(40, '-') << endl;

    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, -2, -3, 4}, {1, -1, -1, 1}},
        {{1, 2, 3, 4}, {1, 1, 1, 1}},
        {{1, 0, -3}, {0, -1, 0}},
    };

    try {
        for (const auto& [input, expected] : testCases) {
            vector<int> result = productSigns(input);
            assert(result == expected);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem2() {
    cout << "\nTesting Problem 2: Reverse Words" << endl;
    cout << string(40, '-') << endl;

    vector<pair<string, string>> testCases = {
        {"  hello   world  python  ", "python world hello"},
        {"the sky is blue", "blue is sky the"},
        {"   spaces   ", "spaces"},
    };

    try {
        for (const auto& [input, expected] : testCases) {
            string result = reverseWords(input);
            assert(result == expected);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem3() {
    cout << "\nTesting Problem 3: Last K Elements Average" << endl;
    cout << string(40, '-') << endl;

    try {
        KAverage avg(3);
        assert(abs(avg.add(5) - 5.0) < 0.01);
        assert(abs(avg.add(8) - 6.5) < 0.01);
        assert(abs(avg.add(3) - 5.33) < 0.01);
        assert(abs(avg.add(2) - 4.33) < 0.01);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem4() {
    cout << "\nTesting Problem 4: Parentheses Score" << endl;
    cout << string(40, '-') << endl;

    vector<pair<string, int>> testCases = {
        {"()", 1},
        {"(())", 2},
        {"(()(()))", 6},
        {"((()))", 4},
    };

    try {
        for (const auto& [input, expected] : testCases) {
            int result = scoreParentheses(input);
            assert(result == expected);
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
        {1, "Calculate signs of products excluding each element"},
        {2, "Reverse the order of words in a string"},
        {3, "Implement a class to track averages of last K elements"},
        {4, "Calculate score of nested parentheses"}
    };

    for (const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }

    runAllTests();
    return 0;
}
