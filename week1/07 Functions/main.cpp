// Today we will learn about functions.

#include <iostream>
using namespace std;

// A function is a named block of code that performs a specific task.
// A function can take input, process it, and return an output.
// Example: a flour mill takes wheat as input, processes it, and gives flour as output.

// Why do we use functions?
// 1. They avoid repeating the same code.
// 2. They make code reusable and easier to read.
// 3. They make programs easier to maintain and debug.
// 4. They divide a large program into smaller logical parts.

// General syntax:
// return_type function_name(parameter_list) {
//     // function body
//     return value;
// }

// A parameter is a variable written in the function definition.
// An argument is the actual value passed when the function is called.

// Function declaration:
// A declaration tells the compiler the function's return type, name,
// and parameter types before the function is used.
// int add(int a, int b);

// Function definition:
// A definition contains the actual body and implementation of the function.
// int add(int a, int b) {
//     return a + b;
// }

// The function must be declared or defined before it is called.

// Example of a function that returns an integer:
int add(int a, int b) {
	return a + b;
}

// A void function does not return any value.
// The return statement can be used without a value to exit early.
// Returning a value from a void function causes a compilation error.
void printMessage() {
	cout << "Hello from a function" << endl;
	// return;       // Valid: exits the function early.
	// return 10;    // Invalid: a void function cannot return a value.
}

// A function can perform a calculation and return its result.
int getMultiplication(int x, int y, int z) {
	return x * y * z;
}

// Converts Fahrenheit into Celsius.
int convertIntoCelsius(int fahrenheit) {
	return (fahrenheit - 32) * 5 / 9;
}

// A function can also print output instead of returning a value.
void printCounting() {
	for (int number = 1; number <= 10; number++) {
		cout << number << " ";
	}
	cout << endl;
}

int main() {
	// Calling a function and storing its returned value.
	int sum = add(10, 20);
	cout << "Sum: " << sum << endl;

	// Calling a function that returns the multiplication result.
	int multiplication = getMultiplication(5, 4, 3);
	cout << "Multiplication: " << multiplication << endl;

	// Calling a function that converts Fahrenheit into Celsius.
	int celsius = convertIntoCelsius(32);
	cout << "Celsius: " << celsius << endl;

	// Calling a void function.
	printMessage();
	printCounting();

	return 0;
}

