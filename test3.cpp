/*
60-Minute C++ Beginner String and File Processing Test

Instructions:
1. Implement all the required functions and classes according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases and memory management
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Focus: String manipulation, File handling, and Basic OOP concepts
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

// Task 1 (20 points)
// Implement a function that takes a string and returns the string with
// all vowels (a,e,i,o,u - both lowercase and uppercase) removed
// Example: "Hello World" → "Hll Wrld"
// Example: "QUIET" → "QT"
std::string removeVowels(const std::string& input)
{
    // Your code here
    return "";
}

// Task 2 (25 points)
// Create a class called 'Logger' that writes messages to a file
// The class should support different message types: INFO, WARNING, ERROR
class Logger
{
private:
    // Add necessary member variables

public:
    enum LogLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor that takes a filename where logs will be written
    Logger(const std::string& filename)
    {
        // Your code here
    }

    // Destructor (make sure to close the file properly)
    ~Logger()
    {
        // Your code here
    }

    // Method to log a message with timestamp and log level
    // Format: [TIMESTAMP] [LEVEL] Message
    // Example: [2024-03-24 10:30:15] [ERROR] Failed to connect
    void log(LogLevel level, const std::string& message)
    {
        // Your code here
    }

    // Method to get the total number of messages logged
    int getMessageCount()
    {
        // Your code here
        return 0;
    }

    // Method to clear the log file
    void clearLog()
    {
        // Your code here
    }
};

// Task 3 (25 points)
// Implement a function that processes a CSV string and returns a vector of vectors
// Each line in the CSV is separated by newline (\n)
// Each value in a line is separated by comma (,)
// Handle cases where values might contain quotes and commas
// Example: "name,age\nJohn,30\n\"Doe,Jane\",25" →
// [["name", "age"], ["John", "30"], ["Doe,Jane", "25"]]
std::vector<std::vector<std::string>> parseCSV(const std::string& csvContent)
{
    // Your code here
    return std::vector<std::vector<std::string>>();
}

// Task 4 (30 points)
// Create a template class 'CircularBuffer' that implements a circular buffer
// A circular buffer is a fixed-size buffer that wraps around when full
template<typename T, size_t Size>
class CircularBuffer {
private:
    // Add necessary member variables

public:
    // Constructor
    CircularBuffer()
    {
        // Your code here
    }

    // Add an element to the buffer
    // If buffer is full, overwrite the oldest element
    void push(const T& element)
    {
        // Your code here
    }

    // Remove and return the oldest element
    // Throw std::runtime_error if buffer is empty
    T pop()
    {
        // Your code here
        return T();
    }

    // Return current number of elements in buffer
    size_t count() const
    {
        // Your code here
        return 0;
    }

    // Return true if buffer is full
    bool isFull() const
    {
        // Your code here
        return false;
    }

    // Return true if buffer is empty
    bool isEmpty() const
    {
        // Your code here
        return true;
    }
};

// Test cases
int main()
{
    // Test Task 1
    assert(removeVowels("Hello World") == "Hll Wrld");
    assert(removeVowels("QUIET") == "QT");
    assert(removeVowels("") == "");
    assert(removeVowels("xyz") == "xyz");

    // Test Task 2
    Logger logger("test.log");
    logger.log(Logger::INFO, "Application started");
    logger.log(Logger::WARNING, "Low memory");
    logger.log(Logger::ERROR, "Connection failed");
    assert(logger.getMessageCount() == 3);
    logger.clearLog();
    assert(logger.getMessageCount() == 0);

    // Test Task 3
    std::string csvTest = "name,age\nJohn,30\n\"Doe,Jane\",25";
    auto result = parseCSV(csvTest);
    assert(result.size() == 3);
    assert(result[0] == std::vector<std::string>{"name", "age"});
    assert(result[1] == std::vector<std::string>{"John", "30"});
    assert(result[2] == std::vector<std::string>{"Doe,Jane", "25"});

    // Test Task 4
    CircularBuffer<int, 3> buffer;
    assert(buffer.isEmpty());
    assert(!buffer.isFull());
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    assert(buffer.isFull());
    assert(buffer.count() == 3);

    buffer.push(4); // Should overwrite 1
    assert(buffer.pop() == 2);
    assert(buffer.pop() == 3);
    assert(buffer.pop() == 4);
    assert(buffer.isEmpty());

    try {
        buffer.pop(); // Should throw error
        assert(false); // Should not reach here
    } catch (const std::runtime_error&) {
        assert(true); // Should catch error
    }

    std::cout << "All tests passed! Great job!\n";
    return 0;
}
