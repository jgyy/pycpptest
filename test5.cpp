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
}

// Task 2 (25 points)
// Create a class called 'TextAnalyzer' that analyzes text properties
class TextAnalyzer
{
private:
    std::string text;

public:
    // Constructor that takes the text to analyze
    TextAnalyzer(const std::string &input)
    {
        // Your code here
    }

    // Count how many sentences are in the text
    // Sentences end with '.', '!', or '?'
    // Consecutive sentence endings count as one sentence
    // Example: "Hello! How are you? I'm good..." → 3 sentences
    int countSentences()
    {
        // Your code here
    }

    // Find the longest word in the text
    // Words are separated by spaces
    // Remove any punctuation attached to words
    // Return the word in lowercase
    // Example: "Hello, World! OpenAI" → "hello"
    std::string getLongestWord() {
        // Your code here
    }

    // Count how many times a specific character pattern appears in the text
    // The search should be case-insensitive
    // Example: text="Hello Hello hi", pattern="he" → 3
    int countPattern(const std::string& pattern) {
        // Your code here
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
std::string cellularAutomata(const std::string& current) {
    // Your code here
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

public:
    // Constructor that takes the maximum size of the queue
    RingQueue(size_t maxSize) {
        // Your code here
    }

    // Add element to queue
    // If queue is full, remove oldest element first
    // Return removed element if queue was full, T() otherwise
    T add(const T& element) {
        // Your code here
    }

    // Return element at given position (0 is oldest element)
    // Throw std::out_of_range if position is invalid
    T get(size_t position) const {
        // Your code here
    }

    // Return true if queue is empty
    bool isEmpty() const {
        // Your code here
    }

    // Return true if queue is full
    bool isFull() const {
        // Your code here
    }

    // Return current number of elements
    size_t size() const {
        // Your code here
    }
};

// Test cases
int main()
{
    // Test Task 1: Product except self
    {
        std::vector<int> input1 = {1, 2, 3, 4};
        std::vector<int> expected1 = {24, 12, 8, 6};
        assert(productExceptSelf(input1) == expected1);

        std::vector<int> input2 = {2, 3, 0, 5};
        std::vector<int> expected2 = {0, 0, 30, 0};
        assert(productExceptSelf(input2) == expected2);
    }

    // Test Task 2: Text Analyzer
    {
        TextAnalyzer analyzer("Hello, World! How are you? I'm good... OpenAI!");
        assert(analyzer.countSentences() == 4);
        assert(analyzer.getLongestWord() == "openai");
        assert(analyzer.countPattern("o") == 4);
    }

    // Test Task 3: Cellular Automata
    {
        assert(cellularAutomata("00100") == "00000");
        assert(cellularAutomata("11000") == "01000");
        assert(cellularAutomata("11111") == "00000");
    }

    // Test Task 4: Ring Queue
    {
        RingQueue<int> queue(3);
        assert(queue.isEmpty());
        assert(!queue.isFull());
        assert(queue.size() == 0);

        assert(queue.add(1) == 0);  // Returns 0 (default T) as queue wasn't full
        assert(queue.add(2) == 0);
        assert(queue.add(3) == 0);
        assert(queue.isFull());

        assert(queue.add(4) == 1);  // Returns 1 as it was removed
        assert(queue.get(0) == 2);  // Now 2 is the oldest element
        assert(queue.get(1) == 3);
        assert(queue.get(2) == 4);

        try {
            queue.get(3);  // Should throw
            assert(false);
        } catch (const std::out_of_range&) {
            // Expected
        }
    }

    std::cout << "All test cases passed! Well done!\n";
    return 0;
}
