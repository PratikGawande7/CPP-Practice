// Today we will learn about arrays.

#include <iostream>
using namespace std;

// An array is a collection of elements of the same data type.
// The elements are stored in contiguous memory locations.

// Why do we use arrays?
// If we need to store many related values, an array lets us use one name
// instead of creating a separate variable for every value.

// Array declaration:
// data_type array_name[size];
// Example:
// int arr[5];
// This creates an integer array with space for 5 elements.
// During declaration, the size is normally required so the compiler knows
// how much memory to reserve.

// Array initialization:
// int arr[5] = {1, 2, 3, 4, 5};
// The values are assigned when the array is created.

// During initialization, the size may be omitted because the compiler
// can count the values and determine the size:
// int arr[] = {1, 2, 3, 4, 5}; // The size becomes 5.

// If fewer values are provided than the declared size, the remaining
// elements are initialized to 0:
// int numbers[5] = {1, 2}; // {1, 2, 0, 0, 0}

// The size cannot be omitted in a declaration without an initializer:
// int numbers[]; // Invalid: the compiler cannot determine the size.

// Array indexing starts from 0, not 1.
// For int arr[5], the valid indexes are 0, 1, 2, 3, and 4.
// arr[0] is the first element and arr[4] is the last element.

// Important points:
// 1. All elements must have the same data type.
// 2. The size of a normal array is fixed after declaration.
// 3. The last index is always size - 1.
// 4. Accessing an invalid index causes undefined behavior.

int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	// Accessing and changing an element using its index.
	cout << "First element: " << arr[0] << endl;
	cout << "Third element: " << arr[2] << endl;
	arr[2] = 10;
	cout << "Updated third element: " << arr[2] << endl;

	// Traversing an array means visiting every element.
	cout << "Array elements: ";
	for (int index = 0; index < 5; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;

	// Taking array values from the user.
	int numbers[5];
	cout << "Enter 5 numbers: ";
	for (int index = 0; index < 5; index++) {
		cin >> numbers[index];
	}

	cout << "You entered: ";
	for (int index = 0; index < 5; index++) {
		cout << numbers[index] << " ";
	}
	cout << endl;

	// sizeof gives the size in bytes.
	// sizeof(arr) gives the total size of the complete array.
	// sizeof(arr[0]) gives the size of one element.
	int arraySize = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of elements: " << arraySize << endl;

	// The array name represents the address of its first element.
	// The address of arr[0] and arr are the same address.
	cout << "Address of first element: " << arr << endl;
	cout << "Address of first element: " << &arr[0] << endl;

	// Invalid examples:
	// arr[5] = 100;  // Invalid: the last valid index is 4.
	// arr[-1] = 100; // Invalid: negative indexes are not valid.

	return 0;
}
