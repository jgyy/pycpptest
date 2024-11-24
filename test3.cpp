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
#include <iomanip>
#include <cassert>

// Task 1 (20 points)
// Implement a function that takes a string and returns the string with
// all vowels (a,e,i,o,u - both lowercase and uppercase) removed
// Example: "Hello World" → "Hll Wrld"
// Example: "QUIET" → "QT"
std::string removeVowels(const std::string &input)
{
    // Your code here
    std::string result;
    for (char c : input)
    {
        char lower = std::tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' &&
            lower != 'o' && lower != 'u')
            result += c;
    }
    return result;
}

// Task 2 (25 points)
// Create a class called 'Logger' that writes messages to a file
// The class should support different message types: INFO, WARNING, ERROR
class Logger
{
private:
    // Add necessary member variables
    std::string filename;
    std::ofstream logFile;
    int messageCount;

public:
    enum LogLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor that takes a filename where logs will be written
    Logger(const std::string &filename) : filename(filename), messageCount(0)
    {
        // Your code here
        logFile.open(filename, std::ios::app);
    }

    // Destructor (make sure to close the file properly)
    ~Logger()
    {
        // Your code here
        if (logFile.is_open())
            logFile.close();
    }

    std::string getCurrentTimestamp()
    {
        auto now = std::time(nullptr);
        auto localTime = std::localtime(&now);
        std::ostringstream timestamp;
        timestamp << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
        return timestamp.str();
    }

    std::string getLevelString(LogLevel level)
    {
        switch (level)
        {
            case INFO:
                return "INFO";
            case WARNING:
                return "WARNING";
            case ERROR:
                return "ERROR";
            default:
                return "UNKNOWN";
        }
    }

    // Method to log a message with timestamp and log level
    // Format: [TIMESTAMP] [LEVEL] Message
    // Example: [2024-03-24 10:30:15] [ERROR] Failed to connect
    void log(LogLevel level, const std::string &message)
    {
        // Your code here
        if (!logFile.is_open())
            throw std::runtime_error("Log file is not open");
        logFile << "[" << getCurrentTimestamp() << "] "
            << "[" << getLevelString(level) << "] "
            << message << std::endl;
        ++messageCount;
    }

    // Method to get the total number of messages logged
    int getMessageCount()
    {
        // Your code here
        return messageCount;
    }

    // Method to clear the log file
    void clearLog()
    {
        // Your code here
        logFile.close();
        logFile.open(filename, std::ios::trunc);
        messageCount = 0;
    }
};

// Task 3 (25 points)
// Implement a function that processes a CSV string and returns a vector of vectors
// Each line in the CSV is separated by newline (\n)
// Each value in a line is separated by comma (,)
// Handle cases where values might contain quotes and commas
// Example: "name,age\nJohn,30\n\"Doe,Jane\",25" →
// [["name", "age"], ["John", "30"], ["Doe,Jane", "25"]]
std::vector<std::vector<std::string>> parseCSV(const std::string &csvContent)
{
    // Your code here
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> row;
    std::string cell;
    bool inQuotes = false;
    for (size_t i = 0; i < csvContent.length(); ++i)
    {
        char c = csvContent[i];
        if (c == '"')
            inQuotes = !inQuotes;
        else if (c == ',' && !inQuotes)
        {
            row.push_back(cell);
            cell.clear();
        }
        else if (c == '\n' && !inQuotes)
        {
            row.push_back(cell);
            result.push_back(row);
            row.clear();
            cell.clear();
        }
        else
            cell += c;
    }
    if (!cell.empty() || !row.empty())
    {
        row.push_back(cell);
        result.push_back(row);
    }
    return result;
}

// Task 4 (30 points)
// Create a template class 'CircularBuffer' that implements a circular buffer
// A circular buffer is a fixed-size buffer that wraps around when full
template<typename T, size_t Size>
class CircularBuffer
{
private:
    // Add necessary member variables
    T buffer[Size];
    size_t head;
    size_t tail;
    size_t elements;

public:
    // Constructor
    CircularBuffer() : head(0), tail(0), elements(0) {}

    // Add an element to the buffer
    // If buffer is full, overwrite the oldest element
    void push(const T &element)
    {
        // Your code here
        buffer[head] = element;
        head = (head + 1) % Size;
        if (elements < Size)
            ++elements;
        else
            tail = (tail + 1) % Size;
    }

    // Remove and return the oldest element
    // Throw std::runtime_error if buffer is empty
    T pop()
    {
        // Your code here
        if (isEmpty())
            throw std::runtime_error("Buffer is empty");
        T element = buffer[tail];
        tail = (tail + 1) % Size;
        --elements;
        return element;
    }

    // Return current number of elements in buffer
    size_t count() const
    {
        // Your code here
        return elements;
    }

    // Return true if buffer is full
    bool isFull() const
    {
        // Your code here
        return elements == Size;
    }

    // Return true if buffer is empty
    bool isEmpty() const
    {
        // Your code here
        return elements == 0;
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

    std::vector<std::string> expected_row0;
    expected_row0.push_back("name");
    expected_row0.push_back("age");
    assert(result[0] == expected_row0);

    std::vector<std::string> expected_row1;
    expected_row1.push_back("John");
    expected_row1.push_back("30");
    assert(result[1] == expected_row1);

    std::vector<std::string> expected_row2;
    expected_row2.push_back("Doe,Jane");
    expected_row2.push_back("25");
    assert(result[2] == expected_row2);

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
        // Should catch error
    }

    std::cout << "All tests passed! Great job!\n";
    return 0;
}
