// C++ Coding Test
// Time limit: 60 minutes
// Instructions: Complete all the functions below according to their specifications.
// Each function has its own test cases that must pass.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stack>
#include <cstring>
#include <algorithm>

class Solution
{
public:
    // Task 1: Implement a custom string class with basic operations
    class MyString
    {
    private:
        char *data;
        size_t length;

    public:
        // Constructor
        MyString(const char *str = "")
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }

        // Destructor
        ~MyString()
        {
            delete []data;
        }

        // Copy constructor
        MyString(const MyString &other)
        {
            // TODO: Implement deep copy constructor
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }

        // Assignment operator
        MyString &operator=(const MyString &other)
        {
            // TODO: Implement deep copy assignment operator
            if (this != &other)
            {
                delete []data;
                length = other.length;
                data = new char[length + 1];
                strcpy(data, other.data);
            }
            return *this;
        }

        // Get string length
        size_t size() const
        {
            return length;
        }

        // Convert to C-style string
        const char *c_str() const
        {
            // TODO: Return pointer to internal string
            return data;
        }
    };

    // Task 2: Find the longest palindromic substring
    std::string longestPalindrome(std::string s)
    {
        /*
        * Find the longest palindromic substring in the given string
        * 
        * Example:
        * Input: "babad"
        * Output: "bab" or "aba"
        */
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 1;
        int n = s.length();

        auto expandAroundCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (right - left + 1 > maxLength)
                {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }
        return s.substr(start, maxLength);
    }

    // Task 3: Implement a queue using two stacks
    class MyQueue {
    private:
        std::stack<int> stack1;
        std::stack<int> stack2;

        void moveElements()
        {
            if (stack2.empty())
            {
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
        }
    public:
        MyQueue()
        {}

        void push(int x)
        {
            // TODO: Implement push operation
            stack1.push(x);
        }

        int pop()
        {
            // TODO: Implement pop operation
            moveElements();
            int val = stack2.top();
            stack2.pop();
            return val;
        }

        int peek()
        {
            // TODO: Implement peek operation
            moveElements();
            return stack2.top();
        }

        bool empty()
        {
            // TODO: Implement empty check
            return stack1.empty() && stack2.empty();
        }
    };

    // Task 4: Find the kth largest element in an array
    int findKthLargest(std::vector<int> &nums, int k)
    {
        /*
        * Find the kth largest element in an unsorted array
        * 
        * Example:
        * Input: nums = [3,2,1,5,6,4], k = 2
        * Output: 5
        */
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int partition(std::vector<int> &nums, int left, int right, int pivot_idx)
    {
        int pivot_value = nums[pivot_idx];
        std::swap(nums[pivot_idx], nums[right]);
        int store_idx = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] < pivot_value)
            {
                std::swap(nums[i], nums[store_idx]);
                store_idx++;
            }
        }
        std::swap(nums[right], nums[store_idx]);
        return store_idx;
    }

    int quickSelect(std::vector<int> &nums, int left, int right, int k)
    {
        if (left == right) return nums[left];
        int pivot_idx = left + rand() % (right - left + 1);
        pivot_idx = partition(nums, left, right, pivot_idx);
        if (k == pivot_idx) return nums[k];
        else if (k < pivot_idx) return quickSelect(nums, left, pivot_idx - 1, k);
        else return quickSelect(nums, pivot_idx + 1, right, k);
    }
};

// Test cases
void runTests()
{
    Solution sol;

    // Test Task 1
    {
        Solution::MyString str1("Hello");
        assert(str1.size() == 5);
        assert(strcmp(str1.c_str(), "Hello") == 0);
        Solution::MyString str2 = str1;  // Test copy constructor
        assert(strcmp(str2.c_str(), "Hello") == 0);
        Solution::MyString str3;
        str3 = str1;  // Test assignment operator
        assert(strcmp(str3.c_str(), "Hello") == 0);
    }

    // Test Task 2
    {
        assert(sol.longestPalindrome("babad") == "bab" || 
               sol.longestPalindrome("babad") == "aba");
        assert(sol.longestPalindrome("cbbd") == "bb");
        assert(sol.longestPalindrome("a") == "a");
    }

    // Test Task 3
    {
        Solution::MyQueue queue;
        queue.push(1);
        queue.push(2);
        assert(queue.peek() == 1);
        assert(queue.pop() == 1);
        assert(!queue.empty());
        assert(queue.pop() == 2);
        assert(queue.empty());
    }

    // Test Task 4
    {
        std::vector<int> nums1 = {3,2,1,5,6,4};
        assert(sol.findKthLargest(nums1, 2) == 5);
        std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
        assert(sol.findKthLargest(nums2, 4) == 4);
    }

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    runTests();
    return 0;
}
