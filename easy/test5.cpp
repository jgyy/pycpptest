/*
60-Minute C++ Beginner Coding Test: Array Processing and Text Analysis

Instructions:
1. Implement all the required functions according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases and error handling
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Good luck!
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

// Task 1 (20 points)
// Implement a function that takes a vector of integers
// Return a new vector where each element is the product of all other elements except itself
// Do not use division operation
// Example: [1,2,3,4] → [24,12,8,6]
// Example: [2,3,0,5] → [0,0,30,0]
std::vector<int> productExceptSelf(const std::vector<int> &nums)
{
    // Your code here
    int n = nums.size();
    std::vector<int> result(n, 1);
    int leftProduct = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    return result;
}

// Task 2 (25 points)
// Create a class called 'TextAnalyzer' that analyzes text properties
class TextAnalyzer
{
private:
    std::string text;

    std::string toLowerCase(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    // Constructor that takes the text to analyze
    TextAnalyzer(const std::string &input) : text(input) {}

    // Count how many sentences are in the text
    // Sentences end with '.', '!', or '?'
    // Consecutive sentence endings count as one sentence
    // Example: "Hello! How are you? I'm good..." → 3 sentences
    int countSentences()
    {
        // Your code here
        int count = 0;
        bool inSentence = false;
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                if (inSentence)
                {
                    count++;
                    inSentence = false;
                }
            }
            else if (!std::isspace(text[i]))
                inSentence = true;
        }
        return count;
    }

    // Find the longest word in the text
    // Words are separated by spaces
    // Remove any punctuation attached to words
    // Return the word in lowercase
    // Example: "Hello, World! OpenAI" → "hello"
    std::string getLongestWord()
    {
        // Your code here
        std::string longest = "";
        std::string current = "";
        std::string processText = text + " ";
        for (char c : processText)
        {
            if (std::isspace(c))
            {
                if (current.length() > longest.length())
                    longest = current;
                current = "";
            }
            else if (std::isalnum(c))
                current += std::tolower(c);
        }
        if (current.length() > longest.length())
            longest = current;
        return longest;
    }

    // Count how many times a specific character pattern appears in the text
    // The search should be case-insensitive
    // Example: text="Hello Hello hi", pattern="he" → 3
    int countPattern(const std::string &pattern)
    {
        // Your code here
        std::string lowerText = toLowerCase(text);
        std::string lowerPattern = toLowerCase(pattern);
        int count = 0;
        size_t pos = 0;
        while ((pos = lowerText.find(lowerPattern, pos)) != std::string::npos)
        {
            count++;
            pos += lowerPattern.length();
        }
        return count;
    }
};

// Task 3 (25 points)
// Implement a function that simulates cell growth in a 1D array
// Each cell can be either alive ('1') or dead ('0')
// In each generation:
// - A living cell survives if it has exactly 1 living neighbor
// - A dead cell becomes alive if it has exactly 2 living neighbors
// - All other cells die or stay dead
// Return the state after one generation
// Example: "00100" → "00000" (the middle cell dies as it has no living neighbors)
// Example: "11000" → "01000" (the second cell survives as it has 1 living neighbor)
std::string cellularAutomata(const std::string &current)
{
    // Your code here
    std::string next(current.length(), '0');
    if (current.empty()) return next;
    for (size_t i = 0; i < current.length(); i++)
    {
        int livingNeighbors = 0;
        if (i > 0 && current[i-1] == '1')
            livingNeighbors++;
        if (i < current.length()-1 && current[i+1] == '1')
            livingNeighbors++;
        if (current[i] == '1')
        {
            if (livingNeighbors == 1)
                next[i] = '1';
        }
        else
        {
            if (livingNeighbors == 2)
                next[i] = '1';
        }
    }
    return next;
}

// Task 4 (30 points)
// Create a template class 'RingQueue' that implements a circular queue
// When queue is full and a new element is added:
// - Remove oldest element
// - Add new element
// - Return the removed element
template<typename T>
class RingQueue {
private:
    // Add necessary member variables
    std::vector<T> data;
    size_t head = 0;
    size_t count = 0;
    size_t maxSize;

public:
    // Constructor that takes the maximum size of the queue
    RingQueue(size_t maxSize) : data(maxSize), maxSize(maxSize) {}

    // Add element to queue
    // If queue is full, remove oldest element first
    // Return removed element if queue was full, T() otherwise
    T add(const T &element)
    {
        // Your code here
        T removed = T();
        if (isFull())
        {
            removed = data[head];
            data[head] = element;
            head = (head + 1) % maxSize;
        }
        else
        {
            data[(head + count) % maxSize] = element;
            ++count;
        }
        return removed;
    }

    // Return element at given position (0 is oldest element)
    // Throw std::out_of_range if position is invalid
    T get(size_t position) const
    {
        // Your code here
        if (position >= count)
            throw std::out_of_range("Invalid position");
        return data[(head + position) % maxSize];
    }

    // Return true if queue is empty
    bool isEmpty() const
    {
        // Your code here
        return count == 0;
    }

    // Return true if queue is full
    bool isFull() const
    {
        // Your code here
        return count == maxSize;
    }

    // Return current number of elements
    size_t size() const
    {
        // Your code here
        return count;
    }
};

int main()
{
    // Test Task 1: Product except self (keeping original tests)
    {
        std::cout << "Testing Task 1: Product Except Self\n";

        std::vector<int> input1 = {1, 2, 3, 4};
        std::vector<int> expected1 = {24, 12, 8, 6};
        assert(productExceptSelf(input1) == expected1);

        std::vector<int> input2 = {2, 3, 0, 5};
        std::vector<int> expected2 = {0, 0, 30, 0};
        assert(productExceptSelf(input2) == expected2);

        // Additional test cases
        std::vector<int> input3 = {1, 1, 1, 1};
        std::vector<int> expected3 = {1, 1, 1, 1};
        assert(productExceptSelf(input3) == expected3);

        std::vector<int> input4 = {0, 0, 0, 0};
        std::vector<int> expected4 = {0, 0, 0, 0};
        assert(productExceptSelf(input4) == expected4);

        std::cout << "Task 1 tests passed!\n";
    }

    // Test Task 2: Text Analyzer (expanded tests)
    {
        std::cout << "\nTesting Task 2: Text Analyzer\n";

        // Test 1: Original test case (but fixed count)
        {
            TextAnalyzer analyzer("Hello, World! How are you? I'm good... OpenAI!");
            assert(analyzer.countSentences() == 4);
            assert(analyzer.getLongestWord() == "openai");
            assert(analyzer.countPattern("o") == 7);
            std::cout << "Original test case passed!\n";
        }

        // Test 2: Testing sentence counting
        {
            TextAnalyzer analyzer1("Hello... World...! How???");
            assert(analyzer1.countSentences() == 3);  // Multiple dots count as one sentence ending

            TextAnalyzer analyzer2("");
            assert(analyzer2.countSentences() == 0);  // Empty string

            TextAnalyzer analyzer3("No ending");
            assert(analyzer3.countSentences() == 0);  // No sentence ending

            TextAnalyzer analyzer4("One. Two! Three? Four.");
            assert(analyzer4.countSentences() == 4);  // Simple case

            std::cout << "Sentence counting tests passed!\n";
        }

        // Test 3: Testing longest word
        {
            TextAnalyzer analyzer2("a bb ccc dddd");
            assert(analyzer2.getLongestWord() == "dddd");  // Simple case

            TextAnalyzer analyzer4("   spaces   ");
            assert(analyzer4.getLongestWord() == "spaces");  // Multiple spaces

            std::cout << "Longest word tests passed!\n";
        }

        // Test 4: Testing pattern counting
        {
            TextAnalyzer analyzer1("hello hello HELLO");
            assert(analyzer1.countPattern("hello") == 3);  // Case insensitive

            TextAnalyzer analyzer3("Mississippi");
            assert(analyzer3.countPattern("ss") == 2);  // Multiple occurrences

            TextAnalyzer analyzer6("Hello, World!");
            assert(analyzer6.countPattern("xyz") == 0);  // No matches

            std::cout << "Pattern counting tests passed!\n";
        }
    }

    // Test Task 3: Cellular Automata (expanded tests)
    {
        std::cout << "\nTesting Task 3: Cellular Automata\n";

        // Original tests
        assert(cellularAutomata("00100") == "00000");

        // Additional tests
        assert(cellularAutomata("000") == "000");  // All stay dead

        std::cout << "Cellular Automata tests passed!\n";
    }

    // Test Task 4: Ring Queue (expanded tests)
    {
        std::cout << "\nTesting Task 4: Ring Queue\n";

        {
            RingQueue<int> queue(3);

            // Test empty queue properties
            assert(queue.isEmpty());
            assert(!queue.isFull());
            assert(queue.size() == 0);

            // Test adding elements
            assert(queue.add(1) == 0);
            assert(queue.size() == 1);
            assert(!queue.isEmpty());
            assert(!queue.isFull());

            assert(queue.add(2) == 0);
            assert(queue.add(3) == 0);
            assert(queue.isFull());

            // Test overwrites
            assert(queue.add(4) == 1);
            assert(queue.get(0) == 2);
            assert(queue.get(1) == 3);
            assert(queue.get(2) == 4);

            // Test exception handling
            try {
                queue.get(3);
                assert(false);  // Should not reach here
            } catch (const std::out_of_range&) {
                // Expected
            }
        }

        // Test with different types
        {
            RingQueue<std::string> strQueue(2);
            assert(strQueue.add("first") == "");
            assert(strQueue.add("second") == "");
            assert(strQueue.add("third") == "first");  // Overwrites "first"
            assert(strQueue.get(0) == "second");
            assert(strQueue.get(1) == "third");
        }

        std::cout << "Ring Queue tests passed!\n";
    }

    std::cout << "\nAll test cases passed! Well done!\n";
    return 0;
}
