// Today we will learn about character arrays and C-strings.

#include <cstring>
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// 1. Character arrays
// -----------------------------------------------------------------------------

// A character array stores characters of type char.
// A group of characters that represents text is called a C-string.
// Each char normally occupies 1 byte, while an int commonly occupies 4 bytes.
// Like other arrays, a character array uses zero-based indexing.
// The exact size of an int is implementation-defined; sizeof(int) tells us
// its size on the current system. sizeof(char) is always 1 byte in C++.

// Example:
// char name[20];
// This creates space for 20 characters.

// A character array can be initialized with individual characters:
// char name[] = {'L', 'o', 'v', 'e', '\0'};

// It can also be initialized using a string literal:
// char name[] = "Love";
// The compiler stores: 'L', 'o', 'v', 'e', and '\0'.
// The size can be omitted here; the compiler infers it, including space for '\0'.

// '\0' is called the null character.
// It marks the end of a C-string and has ASCII value 0.
// The null character is not the same as the character '0'.

// A string literal needs one extra array position for '\0'.
// char name[5] = "Love"; // Correct: 4 letters + '\0'
// char name[4] = "Love"; // Error: not enough space for the terminating '\0'

// When manually filling a character array, add '\0' before treating it as a
// C-string:
// char letters[4];
// letters[0] = 'a';
// letters[1] = 'b';
// letters[2] = 'c';
// letters[3] = '\0';

// -----------------------------------------------------------------------------
// 2. ASCII values and character conversion
// -----------------------------------------------------------------------------

// Every character has a numerical ASCII value.
// For example, 'A' and 'a' have different ASCII values.
// 'A' to 'Z' have ASCII values 65 to 90.
// 'a' to 'z' have ASCII values 97 to 122.
// '0' to '9' have ASCII values 48 to 57.

// Lowercase to uppercase:
// uppercaseCharacter = lowercaseCharacter - 'a' + 'A';

// Uppercase to lowercase:
// lowercaseCharacter = uppercaseCharacter - 'A' + 'a';

// These formulas work because the uppercase and lowercase letters have
// the same order in the ASCII table.

// Convert lowercase letters in a complete C-string to uppercase.
void convertToUppercase(char str[]) {
	int index = 0;

	while (str[index] != '\0') {
		if (str[index] >= 'a' && str[index] <= 'z') {
			str[index] = str[index] - 'a' + 'A';
		}

		index++;
	}
}

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
// for '\0', so a separate length is not needed just to find the text's end:
// char name[] = "Love Babbar";
// getLength(name);

// If it is a raw buffer or may not contain '\0', pass its size separately
// to avoid reading or writing beyond its bounds:
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
// These functions do not automatically resize the destination array. If the
// destination is too small, writing past its end causes undefined behavior.
// The source and destination must also be valid null-terminated C-strings.

int main() {
	// A character array is printed as a C-string until '\0'.
	char name[] = "Love Babbar";
	cout << "Name: " << name << endl;
	cout << "Length: " << getLength(name) << endl;

	// ASCII arithmetic for converting lowercase to uppercase.
	char lowercaseCharacter = 'k';
	char uppercaseCharacter = lowercaseCharacter - 'a' + 'A';
	cout << "Uppercase character: " << uppercaseCharacter << endl;

	// ASCII conversion for every lowercase letter in a C-string.
	char wordToConvert[] = "babbar";
	convertToUppercase(wordToConvert);
	cout << "Uppercase word: " << wordToConvert << endl;

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

	// Library concatenation. The destination must have enough unused space.
	char greeting[20] = "Hello ";
	strcat(greeting, "Babbar");
	cout << "Library concatenation: " << greeting << endl;

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

/*
PRACTICAL USE OF THIS TOPIC:

A character array is used to store text as a sequence of char values. A
null-terminated character array is called a C-string and can be used for:
1. Storing names, words, and short messages.
2. Reading or processing text one character at a time.
3. Working with older C-style libraries and functions.
4. Practicing how text is stored in memory.

The '\0' character tells the program where the text ends. Always leave enough
space for every character plus '\0'. Functions such as strcpy() and strcat()
do not increase the destination array's size, so the destination must have
enough capacity before writing into it.

Use indexing or a loop when changing individual characters. Use strlen(),
strcpy(), strcmp(), and strcat() when their behavior matches the task.
When a character array is sent to cout, it is printed as text only when it is
properly null-terminated.
*/

