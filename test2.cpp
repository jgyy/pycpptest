// C++ Beginner Coding Test (15 minutes)
// Write your solutions in the marked spaces below each question

/*
Question 1: Library Book (5 minutes)
Create a class called Book that manages library books.
The class should track a book's title, whether it's checked out, and its due date.
Implement the required methods to check out and return books.
*/
#include <iostream>
#include <string>
#include <vector>

class Book 
{
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;

public:
    // TODO: Write a constructor that takes the book's title
    //       Initialize isCheckedOut as false
    Book(std::string title) : title(title), isCheckedOut(false), dueDate("") {}

    // TODO: Write a method called checkOut that takes a due date string
    //       and marks the book as checked out
    void checkOut(std::string checkOutDate)
    {
        dueDate = checkOutDate;
        isCheckedOut = true;
    }

    // TODO: Write a method called returnBook that marks the book as returned
    //       and clears the due date
    void returnBook()
    {
        dueDate = "";
        isCheckedOut = false;
    }

    // TODO: Write a method called isAvailable that returns whether
    //       the book can be checked out (not already checked out)
    bool isAvailable()
    {
        return !isCheckedOut;
    }
};

/*
Question 2: Temperature Tracker (5 minutes)
Create a class that tracks daily temperatures and provides temperature statistics.
*/

class TemperatureTracker
{
private:
    // TODO: Create a vector to store daily temperatures (as doubles)
    std::vector<double> temperatures;

public:
    TemperatureTracker() {}

    // TODO: Write a method to add a temperature reading
    void addTemperature(double temp)
    {
        temperatures.push_back(temp);
    }

    // TODO: Write a method to get the highest recorded temperature
    double getHighestTemperature()
    {
        double highest = 0.0f;
        for (double temp : temperatures)
            if (temp > highest)
                highest = temp;
        return highest;
    }

    // TODO: Write a method to get the average temperature
    double getAverageTemperature()
    {
        double average = 0.0f;
        double total = 0.0f;
        for (double temp : temperatures)
            total += temp;
        average = total / temperatures.size();
        return average;
    }

    // TODO: Write a method that returns how many days were above
    //       a specified temperature threshold
    int getDaysAboveThreshold(double temp)
    {
        int count = 0;
        for (double current : temperatures)
            if (current > temp)
                count++;
        return count;
    }
};

/*
Question 3: String Processing (5 minutes)
Complete the following functions to process strings
*/

// TODO: Write a function that takes a string and returns
// true if the string is a palindrome (reads the same forwards and backwards)
// Ignore spaces and capitalization
// Example: "Race Car" should return true
bool isPalindrome(const std::string& text)
{
    // Your code here
    std::string filtered;
    for (char c : text)
        if (std::isalnum(c))
            filtered += std::tolower(c);
    size_t start = 0;
    size_t end = filtered.length() - 1;
    while (start < end)
    {
        if (filtered[start] != filtered[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// TODO: Write a function that takes a string and returns
// a new string with all vowels removed
// Example: "Hello World" should return "Hll Wrld"
std::string removeVowels(const std::string& text)
{
    // Your code here
    std::string removed = "";
    for (char c : text)
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            removed += c;
    }
    return removed;
}

int main()
{
    // Test Book class
    std::cout << "\n=== Testing Book Class ===\n";
    Book book1("The Great Gatsby");
    Book book2("1984");

    std::cout << "Initial availability check:\n";
    std::cout << "Book 1 available: " << book1.isAvailable() << std::endl;
    std::cout << "Book 2 available: " << book2.isAvailable() << std::endl;

    book1.checkOut("2024-12-01");
    std::cout << "\nAfter checking out book1:\n";
    std::cout << "Book 1 available: " << book1.isAvailable() << std::endl;

    book1.returnBook();
    std::cout << "\nAfter returning book1:\n";
    std::cout << "Book 1 available: " << book1.isAvailable() << std::endl;

    // Test TemperatureTracker class
    std::cout << "\n=== Testing TemperatureTracker ===\n";
    TemperatureTracker tracker;

    // Add some temperature readings
    tracker.addTemperature(23.5);
    tracker.addTemperature(25.0);
    tracker.addTemperature(22.8);
    tracker.addTemperature(26.7);
    tracker.addTemperature(20.5);

    std::cout << "Highest temperature: " << tracker.getHighestTemperature() << std::endl;
    std::cout << "Average temperature: " << tracker.getAverageTemperature() << std::endl;
    std::cout << "Days above 25°C: " << tracker.getDaysAboveThreshold(25.0) << std::endl;

    // Test string processing functions
    std::cout << "\n=== Testing String Processing ===\n";

    // Test palindrome function
    std::vector<std::string> palindromeTests = {
        "Race Car",
        "A man a plan a canal Panama",
        "hello",
        "Madam Im Adam",
        "12321",
        "OpenAI"
    };

    std::cout << "Palindrome Tests:\n";
    for (const auto& test : palindromeTests) {
        std::cout << "\"" << test << "\" is" 
                  << (isPalindrome(test) ? "" : " not")
                  << " a palindrome" << std::endl;
    }

    // Test vowel removal function
    std::vector<std::string> vowelTests = {
        "Hello World",
        "OpenAI",
        "AEIOU",
        "rhythm",
        "Testing 123"
    };

    std::cout << "\nVowel Removal Tests:\n";
    for (const auto& test : vowelTests) {
        std::cout << "Original: \"" << test << "\" -> "
                  << "Without vowels: \"" << removeVowels(test) << "\""
                  << std::endl;
    }

    return 0;
}
