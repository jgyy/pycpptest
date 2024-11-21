#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Problem 1: Matrix Rotation
/**
 * Rotate a square matrix 90 degrees clockwise in-place
 * @param matrix Square matrix of integers
 */
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // First, transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Then reverse each row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Problem 2: Balanced Parentheses
/**
 * Check if a string of brackets is valid
 * Valid brackets are: (), [], {}
 * @param s String containing only brackets
 * @return true if brackets are valid, false otherwise
 */
bool isValid(string s) {
    stack<char> brackets;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else {
            if(brackets.empty() || brackets.top() != pairs[c]) {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}

// Problem 3: LRU Cache Implementation
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // (key, value) pairs
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            cache.erase(map[key]);
        } else if(cache.size() >= capacity) {
            map.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};

// Problem 4: Word Break
/**
 * Given a string s and a dictionary of strings wordDict,
 * return true if s can be segmented into a sequence of dictionary words.
 * @param s String to break
 * @param wordDict Dictionary of words
 * @return true if string can be segmented, false otherwise
 */
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    
    for(int i = 1; i <= s.length(); i++) {
        for(const string& word : wordDict) {
            if(word.length() <= i) {
                if(dp[i - word.length()] && 
                   s.substr(i - word.length(), word.length()) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.length()];
}

// Test functions
void testProblem1() {
    cout << "\nTesting Problem 1: Matrix Rotation" << endl;
    cout << string(40, '-') << endl;
    
    try {
        vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        vector<vector<int>> expected = {
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3}
        };
        rotateMatrix(matrix);
        assert(matrix == expected);
        cout << "✓ Test passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem2() {
    cout << "\nTesting Problem 2: Balanced Parentheses" << endl;
    cout << string(40, '-') << endl;
    
    try {
        assert(isValid("()[]{}") == true);
        assert(isValid("([)]") == false);
        assert(isValid("{[]}") == true);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem3() {
    cout << "\nTesting Problem 3: LRU Cache" << endl;
    cout << string(40, '-') << endl;
    
    try {
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        assert(cache.get(1) == 1);
        cache.put(3, 3);
        assert(cache.get(2) == -1);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem4() {
    cout << "\nTesting Problem 4: Word Break" << endl;
    cout << string(40, '-') << endl;
    try {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        assert(wordBreak(s, wordDict) == true);
        s = "applepenapple";
        wordDict = {"apple", "pen"};
        assert(wordBreak(s, wordDict) == true);
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
    cout << "Time allowed: 1 hour\n" << endl;
    cout << "Instructions:" << endl;
    cout << "- Implement the solution for each problem" << endl;
    cout << "- Use only standard C++ libraries" << endl;
    cout << "- Focus on both correctness and code quality" << endl;
    cout << "- Compile and run this file to test your solutions" << endl;
    vector<pair<int, string>> problems = {
        {1, "Rotate a square matrix 90 degrees clockwise in-place."},
        {2, "Check if a string of brackets (), [], {} is valid."},
        {3, "Implement an LRU (Least Recently Used) Cache."},
        {4, "Determine if a string can be segmented into dictionary words."}
    };
    for(const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }
    runAllTests();
    return 0;
}
