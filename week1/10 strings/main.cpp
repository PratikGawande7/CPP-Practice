// Today we will learn about C++ strings.

#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// 1. C++ strings
// -----------------------------------------------------------------------------

// A string is a sequence of characters used to represent text.
// In C++, text can be stored using a character array or using std::string.
//
// A character array used as text is called a C-string when it ends with '\0'.
// It has a fixed capacity, and we must manage copying, concatenation, and
// null termination carefully.
//
// std::string is the C++ string class from the <string> header.
// It stores text and manages its memory and length automatically.
// It can also be reassigned and modified using convenient member functions.
// std::string is a class type, not the built-in char data type. A string object
// contains a sequence of characters; char stores only one character.
//
// Example:
// char characterArray[] = "Love"; // C-string: includes '\0'
// string cppString = "Love";      // C++ string object
//
// A std::string can be declared first and built one character at a time:
// string name;
// name.push_back('a');
// name.push_back('b');
// name.push_back('c');
// cout << name; // Prints abc
//
// A character array also allows individual elements to be assigned:
// char arr[100];
// arr[0] = 'a';
// arr[1] = 'b';
// arr[2] = 'c';
// However, arr must contain '\0' before it can safely be printed as a
// C-string. For example: arr[3] = '\0';
//
// A std::string can be initialized and reassigned directly:
// string surname = "Babbar";
// surname = "Love";
// A character array cannot be reassigned this way after declaration.
//
// Main differences:
// - A character array has a fixed size; std::string can grow or shrink.
// - A character array needs null termination for C-string functions;
//   std::string manages its internal storage automatically.
// - A character array cannot be directly reassigned after declaration;
//   std::string can be reassigned directly.
// - A character array has no built-in length or capacity management;
//   std::string provides size(), length(), and capacity-related operations.

// std::string is a C++ class that makes string handling easier.
// It can grow or shrink at runtime and handles null termination internally.

// Character array:
// - Has a fixed size.
// - Requires manual null termination for C-string operations.
// - Cannot be directly reassigned after declaration.
//
// std::string:
// - Manages its size dynamically.
// - Handles termination automatically.
// - Can be reassigned directly.

// Important string functions:
// str.length() or str.size() returns the string length.
// str.push_back(character) appends one character.
// str.append(text) appends text to the end of the string.
// str.find(target) searches for target and returns its starting index.
// str.substr(start, length) returns a part of the string.
// str.insert(position, text) inserts text at a position.
// str.compare(other) compares two strings lexicographically and returns 0
// when they are equal.

// std::string can contain an embedded '\0' character, but C-string functions
// stop at the first '\0'. For normal text, this distinction is usually not
// visible. Use std::string::size() to get the full std::string length.

// string::npos means that find() did not find the requested text.
// It is a special value of type string::size_type, not a normal index.

int main() {
	string sentence = "My Name is Love Babbar";
	string target = "Love";

	cout << "String: " << sentence << endl;
	cout << "Length: " << sentence.length() << endl;

	// Add one character to the end of a string.
	sentence.push_back('!');
	cout << "After push_back: " << sentence << endl;

	// Search for text and check whether it was found.
	size_t foundIndex = sentence.find(target);
	if (foundIndex != string::npos) {
		cout << "Found at index: " << foundIndex << endl;
		cout << "Substring: " << sentence.substr(foundIndex, target.length())
				 << endl;
	}

	// Insert text at a position.
	sentence.insert(0, "Hello! ");
	cout << "Inserted string: " << sentence << endl;

	return 0;
}

// -----------------------------------------------------------------------------
// Homework and spoken questions from the lecture
// -----------------------------------------------------------------------------

// 1. Try to reassign a character array after declaration:
//    char name[] = "Babbar";
//    name = "Love"; // Error: a character array cannot be reassigned directly.

// 2. Find out what value string::npos represents and why find() uses it.

// 3. Reverse a string using two indexes and swap().

// 4. Check whether a string is a palindrome.

// 5. Count the vowels and consonants in a string.

// 6. Check whether two strings are valid anagrams.

// 7. Convert lowercase letters to uppercase and uppercase letters to
//    lowercase using ASCII formulas.

// 8. Convert a string containing digits, such as "1234", into an integer.
