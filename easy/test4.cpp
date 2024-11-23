/**
 * C++ Coding Test (60 Minutes)
 * ---------------------------
 * Instructions:
 * 1. Implement solutions for all problems
 * 2. Each implementation should handle edge cases
 * 3. Focus on code readability and efficiency
 * 4. All required headers are included
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
#include <sstream>

using namespace std;

// Problem 1: Palindrome Pairs
/**
 * Given a vector of unique strings, find all pairs of distinct indices (i, j) 
 * where the concatenation of strings[i] + strings[j] forms a palindrome.
 * 
 * Example:
 * Input: ["bat", "tab", "cat"]
 * Output: [[0,1], [1,0]] // "battab" and "tabbat" are palindromes
 * 
 * @param strings Vector of strings to check
 * @return Vector of index pairs that form palindromes when concatenated
 */
vector<vector<int>> findPalindromePairs(const vector<string> &strings)
{
    // TODO: Implement your solution here
    vector<vector<int>> result;
    int n = strings.size();

    auto isPalindrome = [](const string &s, int start, int end)
    {
        while (start < end)
            if (s[start++] != s[end--]) return false;
        return true;
    };

    unordered_map<string, int> strMap;
    for (int i = 0; i < n; i++)
        strMap[strings[i]] = i;
    for (int i = 0; i < n; i++)
    {
        const string &curr = strings[i];
        if (curr.empty())
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && isPalindrome(strings[j], 0, strings[j].length() - 1))
                {
                    result.push_back({i, j});
                    result.push_back({j, i});
                }
            }
            continue;
        }
        string rev = curr;
        reverse(rev.begin(), rev.end());
        if (strMap.count(rev) && strMap[rev] != i)
            result.push_back({i, strMap[rev]});
        for (int j = 1; j < curr.length(); j++)
        {
            if (isPalindrome(curr, j, curr.length() - 1))
            {
                string prefix = curr.substr(0, j);
                reverse(prefix.begin(), prefix.end());
                if (strMap.count(prefix))
                    result.push_back({i, strMap[prefix]});
            }
            if (isPalindrome(curr, 0, j - 1))
            {
                string suffix = curr.substr(j);
                reverse(suffix.begin(), suffix.end());
                if (strMap.count(suffix))
                    result.push_back({strMap[suffix], i});
            }
        }
    }
    return result;
}

// Problem 2: Min Stack with GetMin and GetMax
/**
 * Implement a stack that supports push, pop, top, getMin, and getMax operations,
 * all in O(1) time complexity.
 * 
 * Example:
 * MinMaxStack stack;
 * stack.push(3);  // stack: [3]
 * stack.push(1);  // stack: [3,1]
 * stack.getMin(); // returns 1
 * stack.getMax(); // returns 3
 * stack.pop();    // stack: [3]
 */
class MinMaxStack
{
private:
    // TODO: Add your member variables here
    stack<int> mainStack;
    stack<pair<int, int>> minMaxStack;

public:
    MinMaxStack() {}

    void push(int val)
    {
        // TODO: Implement push operation
        mainStack.push(val);
        if (minMaxStack.empty())
            minMaxStack.push({val, val});
        else
        {
            auto curr = minMaxStack.top();
            minMaxStack.push({
                min(val, curr.first),
                max(val, curr.second)
            });
        }
    }

    void pop()
    {
        // TODO: Implement pop operation
        if (!mainStack.empty())
        {
            mainStack.pop();
            minMaxStack.pop();
        }
    }

    int top()
    {
        // TODO: Implement top operation
        if (!mainStack.empty())
            return mainStack.top();
        throw runtime_error("Stack is empty");
    }

    int getMin()
    {
        // TODO: Implement getMin operation
        if (!minMaxStack.empty())
            return minMaxStack.top().first;
        throw runtime_error("Stack is empty");
    }

    int getMax()
    {
        // TODO: Implement getMax operation
        if (!minMaxStack.empty())
            return minMaxStack.top().second;
        throw runtime_error("Stack is empty");
    }
};

// Problem 3: Interval Merge
/**
 * Given a collection of intervals, merge all overlapping intervals.
 * Each interval is represented as a pair of integers [start, end].
 * 
 * Example:
 * Input: [[1,3], [2,6], [8,10], [15,18]]
 * Output: [[1,6], [8,10], [15,18]]
 * 
 * @param intervals Vector of interval pairs to merge
 * @return Vector of merged intervals
 */
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // TODO: Implement your solution here
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (merged.back()[1] >= intervals[i][0])
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        else
            merged.push_back(intervals[i]);
    }
    return merged;
}

// Problem 4: Word Pattern
/**
 * Given a pattern and a string, determine if the string follows the same pattern.
 * Each letter in the pattern maps to a word in the string.
 * 
 * Example:
 * pattern = "abba", str = "dog cat cat dog" -> true
 * pattern = "abba", str = "dog cat cat fish" -> false
 * pattern = "abc", str = "dog cat dog" -> false
 * 
 * @param pattern Pattern string containing only lowercase letters
 * @param str Space-separated string of words
 * @return true if str follows pattern, false otherwise
 */
bool followsPattern(string pattern, string str)
{
    // TODO: Implement your solution here
    istringstream ss(str);
    string word;
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
    int i = 0;

    while (ss >> word)
    {
        if (i >= pattern.length()) return false;
        if (p2s.count(pattern[i]) && p2s[pattern[i]] != word) return false;
        if (s2p.count(word) && s2p[word] != pattern[i]) return false;
        p2s[pattern[i]] = word;
        s2p[word] = pattern[i++];
    }
    return i == pattern.length();
}

// Test functions
void testProblem1()
{
    cout << "\nTesting Problem 1: Palindrome Pairs" << endl;
    cout << string(40, '-') << endl;
    // Test case 1: Basic palindrome pairs
    vector<string> input1 = {"bat", "tab", "cat"};
    vector<vector<int>> expected1 = {{0,1}, {1,0}};
    // Test case 2: Empty string cases
    vector<string> input2 = {"", "ab", "ba", ""};
    vector<vector<int>> expected2 = {{0,1}, {1,0}, {2,3}, {3,2}};
    // Test case 3: Single character cases
    vector<string> input3 = {"a", ""};
    vector<vector<int>> expected3 = {{0,1}, {1,0}};
}

void testProblem2()
{
    cout << "\nTesting Problem 2: MinMaxStack" << endl;
    cout << string(40, '-') << endl;
    MinMaxStack stack;
    // Test pushing elements
    stack.push(3);
    stack.push(1);
    stack.push(5);
    // Test min/max operations
    assert(stack.getMin() == 1);
    assert(stack.getMax() == 5);
    // Test pop operations
    stack.pop();
    assert(stack.getMax() == 3);
    assert(stack.getMin() == 1);
}

void testProblem3()
{
    cout << "\nTesting Problem 3: Interval Merge" << endl;
    cout << string(40, '-') << endl;
    // Test case 1: Basic overlapping intervals
    vector<vector<int>> input1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> expected1 = {{1,6}, {8,10}, {15,18}};
    // Test case 2: No overlapping intervals
    vector<vector<int>> input2 = {{1,2}, {3,4}, {5,6}};
    vector<vector<int>> expected2 = {{1,2}, {3,4}, {5,6}};
    // Test case 3: Complete overlap
    vector<vector<int>> input3 = {{1,4}, {2,3}};
    vector<vector<int>> expected3 = {{1,4}};
}

void testProblem4()
{
    cout << "\nTesting Problem 4: Word Pattern" << endl;
    cout << string(40, '-') << endl;
    // Test case 1: Valid patterns
    assert(followsPattern("abba", "dog cat cat dog") == true);
    // Test case 2: Invalid patterns
    assert(followsPattern("abba", "dog cat cat fish") == false);
    // Test case 3: Length mismatch
    assert(followsPattern("abc", "dog cat dog") == false);
    // Test case 4: Bijection violation
    assert(followsPattern("abba", "dog dog dog dog") == false);
}

int main()
{
    cout << "Running test cases..." << endl;
    testProblem1();
    testProblem2();
    testProblem3();
    testProblem4();
    cout << "\nAll test cases completed!" << endl;
    return 0;
}
