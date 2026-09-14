// Today we will learn about C++ strings.

#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// 1. C++ strings
// -----------------------------------------------------------------------------

// A string is a group of characters used to represent text.
// In C++, text can be stored in a character array or in a std::string.
//
// A character array used for text is called a C-string when it ends with '\0'.
// Its size is fixed when we create it. We must manage its space, copying,
// joining, and null character ourselves.
//
// std::string is a class from the <string> header.
// It stores text and manages its length and memory for us.
// When more space is needed, std::string automatically increases its capacity.
// Therefore, a std::string can grow and shrink while the program is running.
// We do not need to manually add '\0' when using normal std::string functions.
//
// char stores one character, while std::string stores a sequence of characters.
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
// A character array also allows individual characters to be assigned:
// char arr[100];
// arr[0] = 'a';
// arr[1] = 'b';
// arr[2] = 'c';
// arr[3] = '\0'; // Required before safely printing arr as a C-string.
//
// A std::string can be initialized and reassigned directly:
// string surname = "Babbar";
// surname = "Love";
// A character array cannot be reassigned this way after declaration.
//
// Example:
// string surname = "Babbar";
// surname = "Love"; // Allowed for std::string.
// cout << surname;   // Prints Love.

// String input:
// cin >> name reads only up to the first space.
// getline(cin, name) reads the complete line, including spaces.
// Use getline when the input can contain more than one word.
// If getline() is used after cin >>, remove the leftover newline first:
// cin.ignore();

// A string uses two important ideas:
// size() is the number of characters currently stored in the string.
// capacity() is the amount of storage currently available internally.
// The capacity can be greater than the size.
// When the available capacity is not enough, std::string automatically
// obtains more memory and moves its characters into that new storage.
// This is why a std::string can grow without declaring a new array size.
//
// Main differences:
// - Character array: fixed size and manual null termination.
// - std::string: size adjusts automatically and memory is managed internally.
// - Character array: cannot be directly reassigned after declaration.
// - std::string: can be directly reassigned after declaration.

// Important string functions:
// str.length() or str.size() gives the number of characters in the string.
// str.push_back(character) adds one character at the end.
// str.pop_back() removes the last character.
// str.append(text) adds text at the end.
// str += text also adds text at the end.
// str[index] accesses the character at an index starting from 0.
// str.front() gives the first character and str.back() gives the last one.
// str.empty() checks whether the string has no characters.
// str.clear() removes all characters from the string.
// str.find(target) searches for text and gives its starting index.
// str.substr(start, length) gives a part of the string.
// str.insert(position, text) inserts text at a position.
// str.compare(other) compares two strings:
// - It returns 0 when both strings are equal.
// - It returns a negative value when str comes before other.
// - It returns a positive value when str comes after other.
// The exact negative or positive number is not important; only its sign is.
// string::npos means that find() could not find the requested text.
// The name npos means "no position".
// It is a special value of type string::size_type. Do not treat it as a
// normal index; compare the result of find() with string::npos.
// It is commonly defined as string::size_type(-1); its exact numeric value
// depends on the size of the type on the system.

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
	} else {
		cout << "Target not found in the string" << endl;
	}

	// Example of a target that is not present in the string.
	string missingTarget = "Lover";
	size_t missingIndex = sentence.find(missingTarget);
	if (missingIndex == string::npos) {
		cout << "Missing target not found in the string" << endl;
	} else {
		cout << "Missing target found at index: " << missingIndex << endl;
	}

	// Insert text at a position.
	sentence.insert(0, "Hello! ");
	cout << "Inserted string: " << sentence << endl;

	// Append text at the end of a string.
	sentence.append(" Welcome");
	cout << "Appended string: " << sentence << endl;
	sentence += "!";
	cout << "After +=: " << sentence << endl;

	// substr() can extract any part of a string using a starting index
	// and the number of characters to extract.
	string statement = "Statement";
	cout << "Substring 1: " << statement.substr(5, 4) << endl;
	cout << "Substring 2: " << statement.substr(3, 3) << endl;

	// insert() can also insert text at a position other than index 0.
	string insertExample = "Babbar";
	insertExample.insert(3, "Love");
	cout << "Inserted at index 3: " << insertExample << endl;

	// compare() checks strings lexicographically, character by character.
	string firstString = "Apple";
	string secondString = "Banana";
	int comparisonResult = firstString.compare(secondString);
	cout << "Compare result: " << comparisonResult << endl;

	string equalFirst = "Love";
	string equalSecond = "Love";
	if (equalFirst.compare(equalSecond) == 0) {
		cout << "Strings are equal" << endl;
	} else {
		cout << "Strings are not equal" << endl;
	}

	return 0;
}

// -----------------------------------------------------------------------------
// Homework and spoken questions from the lecture
// -----------------------------------------------------------------------------

// 1. Try to reassign a character array after declaration:
//    char name[] = "Babbar";
//    name = "Love"; // Error: a character array cannot be reassigned directly.

// 2. Take a full name as input using getline().

// 3. Find out what value string::npos represents and why find() uses it.

// 4. Reverse a string using two indexes and swap().

// 5. Check whether a string is a palindrome.

// 6. Count the vowels and consonants in a string.

// 7. Check whether two strings are valid anagrams.

// 8. Convert lowercase letters to uppercase and uppercase letters to
//    lowercase using ASCII formulas.

// 9. Convert a string containing digits, such as "1234", into an integer.
