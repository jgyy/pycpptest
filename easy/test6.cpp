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
vector<int> productSigns(const vector<int> &nums)
{
    // TODO: Implement your solution here
    int n = nums.size();
    vector<int> result(n);
    int negCount = 0;
    int zeroCount = 0;
    for (int num : nums)
    {
        if (num < 0) ++negCount;
        if (num == 0) ++zeroCount;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            if (zeroCount > 1)
                result[i] = 0;
            else
            {
                int currSign = 1;
                for (int j = 0; j < n; j++)
                    if (j != i && nums[j] != 0)
                        if (nums[j] < 0) currSign *= -1;
                result[i] = currSign;
            }
        }
        else
        {
            if (zeroCount > 0)
            {
                result[i] = 0;
                continue;
            }
            int currNegCount = negCount;
            if (nums[i] < 0) currNegCount--;
            result[i] = (currNegCount % 2 == 0) ? 1 : -1;
        }
    }
    return result;
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
string reverseWords(string str)
{
    // TODO: Implement your solution here
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    reverse(str.begin(), str.end());
    int start = 0;
    for (int i = 0; i <= str.length(); i++)
    {
        if (i == str.length() || str[i] == ' ')
        {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    string result;
    bool space = false;
    for (char c : str)
    {
        if (c == ' ')
        {
            if (!space)
            {
                result += c;
                space = true;
            }
        }
        else
        {
            result += c;
            space = false;
        }
    }
    return result;
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
class KAverage
{
private:
    // Add your member variables here
    queue<int> window;
    int k;
    double sum;

public:
    KAverage(int k) : k(k), sum(0) {}

    double add(int val)
    {
        // TODO: Implement add operation
        window.push(val);
        sum += val;
        if (window.size() > k)
        {
            sum -= window.front();
            window.pop();
        }
        return sum / window.size();
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
int scoreParentheses(string s)
{
    // TODO: Implement your solution here
    stack<int> st;
    st.push(0);
    for (char c : s)
    {
        if (c == '(')
            st.push(0);
        else
        {
            int curr = st.top();
            st.pop();
            int val = (curr == 0) ? 1 : curr * 2;
            st.top() += val;
        }
    }
    return st.top();
}

// Test functions
void testProblem1()
{
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
