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

// Arrays do not pass their size automatically to a function. For example,
// an int array has no special end marker, so pass its element count:
// void printNumbers(int arr[], int size);
//
// A C-string is different: its '\0' marks the end of its text. A function
// can search for '\0' to find the text length, so it does not need a separate
// length argument just to process that text:
// void printName(char arr[]);
// char name[] = "Love Babbar";
// printName(name);
//
// The '\0' is still one array element, but it is not part of the text.
// For example, "cat" has text length 3 and needs 4 array elements including
// '\0'. getLength(name) returns the text length, not the array's capacity.
//
// This only works when the character array is guaranteed to contain '\0'.
// For a raw character buffer that may not contain it, pass the capacity:
// void processCharacters(char arr[], int size);
//
// If size is passed, it means the array capacity. Valid indexes are always
// 0 through size - 1 for both int and char arrays. For a C-string, stop at
// '\0' as well, because the text may end before the array is full:
// void printName(char arr[], int size) {
//     for (int i = 0; i < size && arr[i] != '\0'; i++) {
//         cout << arr[i];
//     }
// }
// char shortName[20] = "Hi"; // '\0' is at index 2, not index 19
// printName(shortName, 20);
//
// Do not use size - 2 as the general last index for a C-string. That would
// only fit a string that has exactly size - 1 text characters. The '\0' check
// handles where the text ends; size prevents going beyond the array.

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
// getLength(a) counts the characters before '\0', so its result is the index
// where a's '\0' currently sits. Start writing there to replace that terminator
// with the first character of b. For example, "Love" has length 4, and a[4]
// is '\0', so appending starts at index 4.
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

// Compare two null-terminated character arrays character by character.
//
// This version uses ||, meaning the loop continues while at least one string
// has not reached '\0'. If only one string ends, the next comparison is
// '\0' versus a non-null character, so the function returns false.
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

// The same comparison can be written using &&: continue only while both
// strings still have characters, then check that they ended at the same time.
// If one string is a prefix of the other, only one current character is '\0',
// so the final condition returns false.
//
// bool compareArray(char a[], char b[]) {
//     int aIndex = 0;
//     int bIndex = 0;
//
//     while (a[aIndex] != '\0' && b[bIndex] != '\0') {
//         if (a[aIndex] != b[bIndex]) {
//             return false;
//         }
//         aIndex++;
//         bIndex++;
//     }
//
//     return a[aIndex] == '\0' && b[bIndex] == '\0';
// }
//
// Both versions assume a and b are valid null-terminated C-strings.

// -----------------------------------------------------------------------------
// 5. C-string library functions
// -----------------------------------------------------------------------------

// The <cstring> header provides ready-made functions for C-strings. These can
// be used instead of writing the equivalent custom functions above:
// strlen(array) returns the number of characters before '\0' (it excludes
// '\0'), like getLength(array).
//
// strcpy(destination, source) copies source into destination, including its
// terminating '\0', like copyArray(source, destination).
//
// strcmp(first, second) compares two C-strings character by character, like
// compareArray(). It returns:
// - 0 when both strings are equal.
// - A negative value when first comes before second.
// - A positive value when first comes after second.
// The comparison is based on character values, such as ASCII values.
//
// Unlike compareArray(), strcmp() does not return a bool. Check whether its
// result is 0 to test if the strings are equal:
// strcmp(first, second) == 0
//
// strcat(destination, source) appends source at destination's existing '\0'
// and copies source's terminating '\0' too, like
// concatArray(destination, source).

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
