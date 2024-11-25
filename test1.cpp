// C++ Coding Test (60 minutes)
// Each question includes test cases and sample inputs
// Implement the required functionality for each question

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// Question 1: String Manipulation (15 points)
// Write a function that takes a string and returns the number of unique characters
// Example: "hello" -> 4 unique characters (h,e,l,o)
int countUniqueChars(const std::string& input)
{
    // Your implementation here
    if (input.length() == 0)
        return 0;
    std::unordered_set<char> unique(input.being(), input.end());
    return unique.size();
}

// Test cases for Question 1
void testCountUniqueChars()
{
    assert(countUniqueChars("hello") == 4);
    assert(countUniqueChars("programming") == 7);
    assert(countUniqueChars("aaa") == 1);
    assert(countUniqueChars("") == 0);
}

// Question 2: Vector Operations (20 points)
// Create functions to:
// 1. Remove all duplicates from a vector of integers
// 2. Find the second largest element
// 3. Calculate the sum of even numbers
std::vector<int> removeDuplicates(std::vector<int>& nums)
{
    // Your implementation here
    if (nums.size() <= 1)
        return nums;
    std::set<int> unique(nums.begin(), nums.end());
    std::vector<int> result(unique.begin(), unique.end());
    return result;
}

int findSecondLargest(const std::vector<int>& nums)
{
    // Your implementation here
    if (nums.size() <= 1)
        return 0;
    std::vector<int> temp = nums;
    std::set<int> unique(temp.begin(), temp.end());
    std::sort(unique.rbegin(), unique.rend());
    if (unique.size( <= 1))
        return 0;
    return (temp[1]);
}

int sumEvenNumbers(const std::vector<int>& nums)
{
    // Your implementation here
    if (nums.size() == 0)
        return 0;
    int sum = 0;
    for (int x : nums)
    {
        if (x % 2 == 0)
            sum += x;
    }
    return sum;
}

// Test cases for Question 2
void testVectorOperations()
{
    std::vector<int> test1 = {1, 2, 2, 3, 3, 4};
    std::vector<int> test2 = {5, 2, 8, 1, 9};
    std::vector<int> test3 = {2, 4, 6, 7, 8};

    // Test removeDuplicates
    assert(removeDuplicates(test1) == std::vector<int>{1, 2, 3, 4});

    // Test findSecondLargest
    assert(findSecondLargest(test2) == 8);

    // Test sumEvenNumbers
    assert(sumEvenNumbers(test3) == 20);
}

// Question 3: Student Grade Calculator (25 points)
class Student
{
private:
    std::string name;
    std::vector<int> grades;

public:
    Student(const std::string& studentName) : name(studentName) {}

    // Implement these methods:
    // 1. Add a grade (0-100)
    void addGrade(int grade)
    {
        grades.push_back(grade);
    }
    // 2. Calculate average grade
    double getAverage()
    {
        if (grades.empty())
            return 0.0;
        int i = 0;
        int total = 0;
        for (; i < grades.size(); i++)
        {
            total += grades[i];
        }
        double average = total / (i + 1);
        return average;
    }
    // 3. Get highest and lowest grades
    int getHighestGrade()
    {
        if (grades.empty())
            return 0;
        int result = 0;
        for (int i : grades)
        {
            if (i > result)
                result = i;
        }
        return result;
    }

    int getLowestGrade()
    {
        if (grades.empty())
            return 0;
        int result = 100;
        for (int i : grades)
        {
            if (i < result)
                result = i;
        }
        return result;
    }
    // 4. Get number of passing grades (>= 60)
    int getPassingGrades()
    {
        if (grades.empty())
            return 0;
        int count = 0;
        for (int i : grades)
        {
            if (i >= 60)
                count++;
        }
        return count;
    }
};

// Test cases for Question 3
void testStudentGrades()
{
    Student student("John");
    student.addGrade(85);
    student.addGrade(92);
    student.addGrade(78);
    student.addGrade(95);

    assert(student.getAverage() == 87.5);
    assert(student.getHighestGrade() == 95);
    assert(student.getLowestGrade() == 78);
    assert(student.getPassingGrades() == 4);
}

// Question 4: Text Analyzer (40 points)
// Create a class that analyzes text and provides:
// 1. Word frequency count
// 2. Most common word
// 3. Number of sentences
// 4. Average words per sentence
class TextAnalyzer
{
private:
    std::string sentences;
    std::map<std::string, int> wordCount;
    std::map<std::string, int> sentenceCount;
    std::map<std::string, int> wordSentenceCount;

    std::string lowerCase(std::string s)
    {
        std::string low = "";
        for (char c : s)
        {
            low += tolower(c);
        }
        return low;
    }
public:
    // Your implementation here
    TextAnalyzer() : sentences("") {}

    void setText(std::string text)
    {
        std::stringstream words(lowerCase(text));
        std::string word = "";
        sentences = text;

        while (words >> word)
        {
            wordCount[word]++;
        }
    }

    int getWordCount(std::string word)
    {
        if (sentences.length() == 0)
            return 0;
        int count = 0;
        return wordCount[word];
    }

    std::string getMostCommonWord()
    {
        if (sentences.length() == 0)
            return 0;
        std::string word = "";
        return word;
    }

    int getSentenceCount()
    {
        if (sentences.length() == 0)
            return 0;
        return sentenceCount.size();
    }

    double getAverageWordsPerSentence()
    {
        if (sentences.length() == 0)
            return 0.0;
        double average = 0.0;
        return average;
    }
};

// Test cases for Question 4
void testTextAnalyzer()
{
    TextAnalyzer analyzer;
    analyzer.setText("Hello world. This is a test. Hello again!");

    assert(analyzer.getWordCount("hello") == 2);
    assert(analyzer.getMostCommonWord() == "hello");
    assert(analyzer.getSentenceCount() == 3);
    assert(analyzer.getAverageWordsPerSentence() == 2.33);
}

int main()
{
    // Run all test cases
    testCountUniqueChars();
    testVectorOperations();
    testStudentGrades();
    testTextAnalyzer();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
