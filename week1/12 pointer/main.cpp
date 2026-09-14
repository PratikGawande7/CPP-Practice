// Today we will learn about pointers and dynamic memory allocation.

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// 1. What is a pointer?
// -----------------------------------------------------------------------------

// A pointer is a variable that stores the memory address of another variable.
// A normal variable stores a value directly:
// int number = 50;
//
// A pointer stores the address where that value is located:
// int *ptr = &number;
//
// If number is stored at address 104, then:
// number  -> 50
// &number -> 104
// ptr     -> 104
// *ptr    -> 50
//
// The address shown by a real program is system-dependent. Values such as 104
// and 212 are only simple memory-box examples for understanding the concept.

// Pointer declaration syntax:
// data_type *pointer_name;
//
// The data type tells the compiler what type of value is stored at the address.
// The * in a declaration says that the variable is a pointer.
//
// Address-of operator (&): gives the address of a variable.
// Dereference operator (*): accesses the value stored at a pointer's address.

// Never use an uninitialized pointer:
// int *ptr; // Contains an indeterminate address. Do not dereference it.
//
// A pointer that does not point to an object should be initialized to nullptr:
// int *ptr = nullptr;
// nullptr clearly represents an empty pointer in modern C++.
// Older code may use 0 or NULL, but nullptr is safer and preferred.

// -----------------------------------------------------------------------------
// 2. Basic pointer example
// -----------------------------------------------------------------------------

void basicPointerExample() {
	int number = 50;
	int *ptr = &number;

	cout << "Value of number: " << number << endl;
	cout << "Address of number: " << &number << endl;
	cout << "Value stored in ptr: " << ptr << endl;
	cout << "Address of ptr: " << &ptr << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;

	// Change number indirectly through the pointer.
	(*ptr)++;
	cout << "Value of number after (*ptr)++: " << number << endl;
}

// A null pointer does not point to a valid object.
// Never dereference it:
// int *ptr = nullptr;
// cout << *ptr; // Undefined behavior; the program may crash.

// -----------------------------------------------------------------------------
// 3. Why do we need pointers?
// -----------------------------------------------------------------------------

// Pointers are useful for:
// 1. Accessing and changing a value through its memory address.
// 2. Allocating memory dynamically at runtime.
// 3. Working with arrays and their first-element address.
// 4. Passing large data efficiently when appropriate.
// 5. Building linked lists, trees, graphs, and other dynamic structures.

// -----------------------------------------------------------------------------
// 4. Stack memory and heap memory
// -----------------------------------------------------------------------------

// Stack memory:
// - Holds local variables and function-call data.
// - Variables are automatically removed when their scope ends.
// - It has a limited size.
//
// Heap memory:
// - Used for dynamic allocation during runtime.
// - Memory remains allocated until it is released manually.
// - It is accessed through pointers.
// - Forgetting to release it causes a memory leak.
//
// int n;
// cin >> n;
// int arr[n]; // Not standard C++ and may overflow the stack for a large n.
// Use new[] when a runtime-sized array is required.

// -----------------------------------------------------------------------------
// 5. Dynamic allocation of one variable
// -----------------------------------------------------------------------------

void singleHeapAllocation() {
	// The pointer variable itself is local, but the integer is on the heap.
	int *ptr = new int;
	*ptr = 100;

	cout << "Value on heap: " << *ptr << endl;

	// Release the memory allocated by new.
	delete ptr;
	ptr = nullptr;
}

// -----------------------------------------------------------------------------
// 6. Dynamic allocation of a one-dimensional array
// -----------------------------------------------------------------------------

void dynamicArrayExample() {
	int size;
	cout << "Enter dynamic array size: ";
	cin >> size;

	if (size <= 0) {
		cout << "Size must be positive." << endl;
		return;
	}

	int *arr = new int[size];

	for (int index = 0; index < size; index++) {
		arr[index] = (index + 1) * 10;
	}

	cout << "Dynamic array values: ";
	for (int index = 0; index < size; index++) {
		// arr[index] and *(arr + index) access the same element.
		cout << arr[index] << " ";
	}
	cout << endl;

	// Arrays allocated with new[] must be released with delete[].
	delete[] arr;
	arr = nullptr;
}

// -----------------------------------------------------------------------------
// 7. Pointer arithmetic
// -----------------------------------------------------------------------------

// Pointer arithmetic moves by elements, not by raw bytes.
// For an int pointer, ptr + 1 moves by sizeof(int) bytes.
// For a char pointer, ptr + 1 moves by sizeof(char), which is 1 byte.
//
// *ptr + 1 means: read the value, then add 1 to that value.
// *(ptr + 1) means: move to the next element, then read its value.
//
// Pointer subtraction is valid for pointers into the same array.
// ptr2 - ptr1 gives the number of elements between the two positions.
void pointerArithmeticExample() {
	int numbers[] = {10, 20, 30};
	int *ptr = numbers;

	cout << "First value: " << *ptr << endl;
	cout << "Second value: " << *(ptr + 1) << endl;
	cout << "Value plus one: " << *ptr + 1 << endl;
	cout << "Distance between array positions: "
			<< (&numbers[2] - &numbers[0]) << endl;
}

// -----------------------------------------------------------------------------
// 8. Arrays and pointers in function parameters
// -----------------------------------------------------------------------------

// In a normal parameter, int arr[] is adjusted to int *arr.
// The function receives a copy of the first-element address, not a complete
// copy of the array. That address still points to the original array memory.
// Therefore, changing arr[index] changes the original array.
// Pass the array size separately because the pointer does not store the size.
void changeArrayElement(int arr[], int size) {
	if (size > 0) {
		arr[0] = 99;
	}
}

// In main, sizeof(numbers) gives the complete array size in bytes.
// Inside a function parameter, sizeof(arr) gives pointer size because arr is
// treated as a pointer. It does not give the complete array size.

// -----------------------------------------------------------------------------
// 9. Double and triple pointers
// -----------------------------------------------------------------------------

// A double pointer stores the address of another pointer.
// A triple pointer stores the address of a double pointer.
void multiplePointerExample() {
	int a = 5;
	int *ptr = &a;
	int **doublePointer = &ptr;
	int ***triplePointer = &doublePointer;

	cout << "Value of a: " << a << endl;
	cout << "Value through *ptr: " << *ptr << endl;
	cout << "Value through **doublePointer: " << **doublePointer << endl;
	cout << "Value through ***triplePointer: " << ***triplePointer << endl;

	// All three expressions reach the same integer value 5.
}

// Memory relationship:
// a                  stores 5.
// ptr                stores the address of a.
// doublePointer      stores the address of ptr.
// triplePointer      stores the address of doublePointer.
// *ptr               gives 5.
// **doublePointer    gives 5.
// ***triplePointer   gives 5.

// -----------------------------------------------------------------------------
// 10. Pointer safety and practice questions
// -----------------------------------------------------------------------------

// 1. Void pointer:
//    A void* can store an address of any object type, but it must be converted
//    to the correct pointer type before dereferencing:
//    int number = 5;
//    void *ptr = &number;
//    cout << *(static_cast<int *>(ptr)) << endl;
//
// 2. Array of pointers versus pointer to an array:
//    int *pointerArray[5]; // Array containing 5 int pointers.
//    int (*arrayPointer)[5]; // Pointer to an array of 5 integers.
//
// 3. Dangling pointer:
//    int *ptr = new int(10);
//    delete ptr;
//    ptr = nullptr; // Do not use the old address after delete.
//
// 4. Inspect an array's behavior in a function:
//    Create an integer array, change an element inside a function, and print
//    the array in main to verify that the original element changed.
//
// 5. Compare *ptr + 1 with *(ptr + 1) using an integer array.
//
// 6. Create a double pointer and a triple pointer and trace every dereference.

int main() {
	cout << "Basic pointer example:" << endl;
	basicPointerExample();

	cout << endl << "Single heap allocation:" << endl;
	singleHeapAllocation();

	cout << endl << "Pointer arithmetic:" << endl;
	pointerArithmeticExample();

	cout << endl << "Array passed to a function:" << endl;
	int numbers[] = {1, 2, 3};
	changeArrayElement(numbers, 3);
	cout << "First array element: " << numbers[0] << endl;

	cout << endl << "Multiple pointers:" << endl;
	multiplePointerExample();

	// dynamicArrayExample();
	// Uncomment this call when you want to enter a runtime array size.

	return 0;
}
