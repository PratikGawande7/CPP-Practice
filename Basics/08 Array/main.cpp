// Today we will learn about one-dimensional and two-dimensional arrays. 

#include <iostream>
using namespace std;

// An array is a collection of elements of the same data type.
// It allows us to store many values using one variable name.

// Why do we need arrays?
// If we need to store 400, 10,000, or 1,000,000 numbers, creating
// separate variables for every number is impractical.
// An array allocates space for many values in a single line of code.

// -----------------------------------------------------------------------------
// 1. Array declaration and initialization
// -----------------------------------------------------------------------------

// Array declaration syntax:
// data_type array_name[size];
// Example:
// int arr[8];
// This creates an integer array with 8 elements.

// The size is normally required during declaration so the compiler knows
// how much memory to reserve.
// int arr[]; // Invalid: the compiler cannot determine the size.

// An array can be initialized while it is declared:
// int arr[5] = {10, 20, 30, 40, 50};

// During initialization, the size can be omitted because the compiler
// counts the provided values:
// int arr[] = {10, 20, 30}; // The size becomes 3.

// If fewer values are provided than the declared size, the remaining
// elements are initialized to 0:
// int arr[5] = {10, 20, 30}; // {10, 20, 30, 0, 0}

// This initializes every element to 0:
// int arr[5] = {0};

// An uninitialized local array contains indeterminate values.
// int arr[5]; // Do not read its elements before assigning values.

// Providing more values than the declared size is invalid:
// int arr[3] = {10, 20, 30, 40}; // Error: too many initializer values.

// -----------------------------------------------------------------------------
// 2. Indexing and traversing an array
// -----------------------------------------------------------------------------

// Array indexing starts from 0.
// For int arr[5], valid indexes are 0, 1, 2, 3, and 4.
// The last valid index is always size - 1.

// arr[0] means the first element, arr[1] means the second element, and so on.
// Accessing an index outside the valid range causes undefined behavior.

// Traversing means visiting every element, usually with a for loop.
// The loop condition can be index < size or index <= size - 1.

// -----------------------------------------------------------------------------
// 3. Functions with one-dimensional arrays
// -----------------------------------------------------------------------------

// When an array is passed to a function, pass its size as a separate argument.
// The array does not carry its size automatically in the function parameter.
// In the parameter int arr[], arr behaves like a pointer to the first element.
// Therefore, sizeof(arr) inside the function does not give the full array size.
// Example: printArray(arr, 5);
void printArray(int arr[], int size) {
	for (int index = 0; index < size; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;
}

// Calculate the sum of array elements.
int calculateSum(int arr[], int size) {
	int sum = 0;

	for (int index = 0; index < size; index++) {
		sum = sum + arr[index];
	}

	return sum;
}

// Store the multiplication table of 10 in an array.
void storeTableOfTen(int arr[], int size) {
	int count = 1;

	for (int index = 0; index < size; index++) {
		arr[index] = 10 * count;
		count++;
	}
}

// Flip every 0 to 1 and every 1 to 0 in a binary array.
void flipZeroAndOne(int arr[], int size) {
	for (int index = 0; index < size; index++) {
		if (arr[index] == 1) {
			arr[index] = 0;
		} else {
			arr[index] = 1;
		}
	}
}

// -----------------------------------------------------------------------------
// 4. Two-dimensional arrays
// -----------------------------------------------------------------------------

// A two-dimensional array represents data in rows and columns, like a grid.
// int arr[3][4]; means 3 rows and 4 columns, for 12 total elements.

// An element is accessed using two indexes:
// arr[row_index][column_index]

// Example:
// arr[0][0] is the element in the first row and first column.
// arr[2][3] is the element in the third row and fourth column.

// A two-dimensional array is initialized row by row:
// int arr[3][4] = {
//     {10, 20, 30, 40},
//     {11, 12, 13, 14},
//     {21, 22, 23, 24}
// };

// Traversing a 2D array requires nested loops:
// The outer loop handles rows because we finish each row before moving to the next;
// the inner loop handles the columns within the current row.
void print2DArray(int arr[][4], int rowSize, int columnSize) {
	for (int row = 0; row < rowSize; row++) {
		for (int column = 0; column < columnSize; column++) {
			cout << arr[row][column] << " ";
		}
		cout << endl;
	}
}

// A 2D-array function needs a fixed column size, but can accept any number of rows:
// void print2DArray(int arr[][4], int rows);
// The compiler uses the column size to locate each element.

int main() {
	// Traversing and printing an initialized array.
	int multiplesOfTwo[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	cout << "Multiples of two: ";
	printArray(multiplesOfTwo, 10);

	// Taking input for every element of an array.
	int inputArray[5];
	for (int index = 0; index < 5; index++) {
		cout << "Enter value for arr[" << index << "]: ";
		cin >> inputArray[index];
	}

	cout << "Entered array: ";
	printArray(inputArray, 5);

	// Calculating the sum of array elements.
	int numbers[5] = {10, 20, 30, 40, 50};
	cout << "Total sum: " << calculateSum(numbers, 5) << endl;

	// Storing and printing the multiplication table of 10.
	int table[10];
	storeTableOfTen(table, 10);
	cout << "Table of 10: ";
	printArray(table, 10);

	// Flipping 0s to 1s and 1s to 0s.
	int binaryArray[8] = {1, 1, 0, 0, 1, 0, 1, 0};
	flipZeroAndOne(binaryArray, 8);
	cout << "Flipped binary array: ";
	printArray(binaryArray, 8);

	// Initializing and printing a two-dimensional array.
	int grid[3][4] = {
		{10, 20, 30, 40},
		{11, 12, 13, 14},
		{21, 22, 23, 24}
	};

	cout << "Two-dimensional array:" << endl;
	print2DArray(grid, 3, 4);

	return 0;
}

// -----------------------------------------------------------------------------
// Homework given by Love Babbar
// -----------------------------------------------------------------------------

// 1. Write a function to populate an array with multiples of 10.

// 2. Initialize an array with -1 in each block.
//    Try doing this using a for loop and also explore memset().

// 3. Print the sum of all elements of an array.

// 4. Write a function to reverse an array.
//    Also find out what swap() is and how it can be used to exchange
//    two array elements.

// 5. Flip 1 to 0 and 0 to 1 in an array.

/*
PRACTICAL USE OF THIS TOPIC:

An array stores many values of the same datatype under one name. It is useful
when a program needs to keep related data such as marks, prices, scores,
temperatures, or binary values.

Use an index to access one element. Indexing starts at 0, so for an array of
size 5 the valid indexes are 0 through 4. A loop is normally used to visit or
process every element.

Pass an array to a function when you want a separate function to print,
calculate, update, or search its values. Pass the size as well because a raw
array does not automatically carry its number of elements.

Use a two-dimensional array when the data has rows and columns, such as a
table, seating arrangement, game board, or grid. Nested loops are used to
process its rows and columns.

Always stay within the valid index range. Accessing an invalid index can cause
undefined behavior and may produce incorrect results or crash the program.
*/