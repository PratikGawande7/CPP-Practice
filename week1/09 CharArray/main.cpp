// Today we will learn about character arrays and strings.

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// 1. Character arrays
// -----------------------------------------------------------------------------

// A character array stores characters of type char.
// A group of characters that represents text is called a C-string.

// Example:
// char name[20];
// This creates space for 20 characters.

// A character array can be initialized with individual characters:
// char name[] = {'L', 'o', 'v', 'e', '\0'};

// It can also be initialized using a string literal:
// char name[] = "Love";
// The compiler stores: 'L', 'o', 'v', 'e', and '\0'.

// '\0' is called the null character.
// It marks the end of a C-string and has ASCII value 0.
// The null character is not the same as the character '0'.

// A string literal needs one extra array position for '\0'.
// char name[5] = "Love"; // Correct: 4 letters + '\0'
// char name[4] = "Love"; // Incorrect: no space for '\0'

// -----------------------------------------------------------------------------
// 2. ASCII values and character conversion
// -----------------------------------------------------------------------------

// Every character has a numerical ASCII value.
// For example, 'A' and 'a' have different ASCII values.

// Lowercase to uppercase:
// uppercaseCharacter = lowercaseCharacter - 'a' + 'A';

// Uppercase to lowercase:
// lowercaseCharacter = uppercaseCharacter - 'A' + 'a';

// These formulas work because the uppercase and lowercase letters have
// the same order in the ASCII table.

// -----------------------------------------------------------------------------
// 3. cout behavior for int arrays and char arrays
// -----------------------------------------------------------------------------

// For a normal int array, cout does not print all elements automatically.
// We need a loop and an index to print every element:
// int numbers[] = {1, 2, 3};
// for (int index = 0; index < 3; index++) {
//     cout << numbers[index] << " ";
// }
// cout << numbers[0]; // Prints only the first element: 1

// When an array name is used with cout, it usually becomes the address
// of its first element. Therefore, cout << numbers does not print all values
// of the int array as numbers.

// When a char array is sent directly to cout, cout treats it as a C-string
// and prints characters until it finds '\0'. Therefore, no loop is needed:
// char word[] = "Babbar";
// cout << word; // Prints Babbar

// This works because cout has special support for a char* pointing to a
// null-terminated C-string. It keeps reading and printing characters until
// the '\0' character is reached.

// Therefore, a character array must be properly null-terminated before it
// is printed as a string.

// -----------------------------------------------------------------------------
// 4. Custom character-array functions
// -----------------------------------------------------------------------------

// When a character array is passed to a function, we usually write:
// void printName(char arr[])
// We do not write the size inside the parameter because the array is passed
// as the address of its first element. The function receives that address,
// not a complete copy of the array.

// For a null-terminated C-string, the function can find the end by searching
// for '\0', so a separate length is not needed:
// char name[] = "Love Babbar";
// getLength(name);

// This works only when '\0' is present. If the character array is being used
// as a raw buffer, or it is not null-terminated, pass its size separately:
// void processCharacters(char arr[], int size);

// For functions that write into a character array, also make sure the
// destination array has enough capacity to hold the characters and '\0'.

// Return the number of characters before '\0'.
int getLength(char arr[]) {
	int count = 0;

	while (arr[count] != '\0') {
		count++;
	}

	return count;
}

// Append the characters of b to the end of a.
// The destination array must have enough unused space.
void concatArray(char a[], char b[]) {
	int aIndex = getLength(a);
	int bIndex = 0;

	while (b[bIndex] != '\0') {
		a[aIndex] = b[bIndex];
		aIndex++;
		bIndex++;
	}

	// Add the null character after the newly appended text.
	a[aIndex] = '\0';
}

// Copy all characters from actual into copy.
// The destination array must be large enough for the copied text and '\0'.
void copyArray(char actual[], char copy[]) {
	int actualIndex = 0;
	int copyIndex = 0;

	while (actual[actualIndex] != '\0') {
		copy[copyIndex] = actual[actualIndex];
		actualIndex++;
		copyIndex++;
	}

	copy[copyIndex] = '\0';
}

// Compare two character arrays character by character.
bool compareArray(char a[], char b[]) {
	int aIndex = 0;
	int bIndex = 0;

	while (a[aIndex] != '\0' || b[bIndex] != '\0') {
		if (a[aIndex] != b[bIndex]) {
			return false;
		}

		aIndex++;
		bIndex++;
	}

	return true;
}

// -----------------------------------------------------------------------------
// 5. C-string library functions
// -----------------------------------------------------------------------------

// The <cstring> header provides ready-made functions for C-strings:
// strlen(array)       returns the length, excluding '\0'.
// strcpy(destination, source) copies source into destination.
// strcmp(first, second) compares two C-strings character by character.
// It returns:
// - 0 when both strings are equal.
// - A negative value when first comes before second.
// - A positive value when first comes after second.
// The comparison is based on the character values, such as ASCII values.
// strcat(destination, source) appends source to destination.

// The destination array must always have enough space when using strcpy()
// or strcat().

// -----------------------------------------------------------------------------
// 6. C++ strings
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
//
// Example:
// char characterArray[] = "Love"; // C-string: includes '\0'
// string cppString = "Love";      // C++ string object
//
// Main differences:
// - A character array has a fixed size; std::string can grow or shrink.
// - A character array needs null termination for C-string functions;
//   std::string manages its internal storage automatically.
// - A character array cannot be directly reassigned after declaration;
//   std::string can be reassigned directly.
// - std::string provides functions such as length(), find(), substr(),
//   and insert() for common string operations.

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
// str.find(target) searches for target and returns its starting index.
// str.substr(start, length) returns a part of the string.
// str.insert(position, text) inserts text at a position.

// string::npos means that find() did not find the requested text.
// It is a special value of type string::size_type, not a normal index.

int main() {
	// A character array is printed as a C-string until '\0'.
	char name[] = "Love Babbar";
	cout << "Name: " << name << endl;
	cout << "Length: " << getLength(name) << endl;

	// ASCII arithmetic for converting lowercase to uppercase.
	char lowercaseCharacter = 'k';
	char uppercaseCharacter = lowercaseCharacter - 'a' + 'A';
	cout << "Uppercase character: " << uppercaseCharacter << endl;

	// Concatenation using a custom function.
	char firstName[20] = "Love ";
	char lastName[] = "Babbar";
	concatArray(firstName, lastName);
	cout << "Concatenated: " << firstName << endl;

	// Copying using a custom function.
	char actual[] = "Babbar";
	char copiedName[10];
	copyArray(actual, copiedName);
	cout << "Copied array: " << copiedName << endl;

	// Comparing two character arrays.
	char firstWord[] = "Love";
	char secondWord[] = "Love";
	cout << "Comparison: "
		 << (compareArray(firstWord, secondWord) ? "Equal" : "Not equal")
		 << endl;

	// C-string library functions.
	char source[] = "Babbar";
	char destination[10];
	strcpy(destination, source);
	cout << "Library length: " << strlen(source) << endl;
	cout << "Library copy: " << destination << endl;
	cout << "Library comparison: "
		 << (strcmp(source, destination) == 0 ? "Equal" : "Not equal")
		 << endl;

	// std::string functions and string::npos.
	string sentence = "My Name is Love Babbar";
	string target = "Love";
	size_t foundIndex = sentence.find(target);

	if (foundIndex != string::npos) {
		cout << "Found at index: " << foundIndex << endl;
	}

	cout << "Substring: " << sentence.substr(foundIndex, target.length())
		 << endl;
	sentence.insert(0, "Hello! ");
	cout << "Inserted string: " << sentence << endl;

	return 0;
}

// -----------------------------------------------------------------------------
// Homework and spoken questions from the lecture
// -----------------------------------------------------------------------------

// 1. Look up the ASCII table and observe the values of uppercase and
//    lowercase characters.

// 2. Try to reassign a character array after declaration:
//    char name[] = "Babbar";
//    name = "Love"; // Error: a character array cannot be reassigned directly.

// 3. Explore strcat() and understand how it appends one C-string to another.

// 4. Find out what value string::npos represents and why find() uses it.

// 5. Reverse a string using two indexes and swap().

// 6. Check whether a string is a palindrome.

// 7. Count the vowels and consonants in a string.

// 8. Check whether two strings are valid anagrams.

// 9. Convert lowercase letters to uppercase and uppercase letters to
//    lowercase using ASCII formulas.

// 10. Convert a string containing digits, such as "1234", into an integer.
