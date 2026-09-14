// Today we will learn about reference variables.

#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// 1. What is a reference variable?
// -----------------------------------------------------------------------------

// A reference variable is another name, or an alias, for an existing variable.
// It does not create a separate variable or a separate memory block.
// It refers to the same memory location as the original variable.
//
// Real-world analogy from the lecture:
// One person can have many names, such as Babbar, Rana, Baby, Babu, or Sona.
// These names may be different, but they refer to the same person.
// In the same way, a reference variable has a different name but refers to
// the same variable and the same memory location.
//
// Core rule:
// A reference is an alias of an existing variable.
// If the value is changed using either name, the same value is changed.

// -----------------------------------------------------------------------------
// 2. Syntax and rules
// -----------------------------------------------------------------------------

// Syntax:
// data_type &reference_name = existing_variable;
//
// Example:
// int a = 5;
// int &temp = a;
//
// Read this as:
// temp is a reference to a.
// Both a and temp access the same integer value.

// Important rules:
// 1. A reference must be initialized when it is declared.
//    int &temp; // Error: a reference must refer to an object immediately.
//
// 2. A reference must refer to an existing variable or object.
//    int a = 5;
//    int &temp = a; // Correct.
//
// 3. A reference cannot be re-bound to another variable after initialization.
//    int a = 5;
//    int b = 10;
//    int &temp = a;
//    temp = b; // Does not make temp refer to b. It copies b's value into a.
//
// 4. A reference and its original variable have the same memory address.
//    &a and &temp print the same address.
//
// 5. A reference is used through the same syntax as the original variable.
//    No special operator is needed when reading or changing its value.

// -----------------------------------------------------------------------------
// 3. Pass by value and pass by reference
// -----------------------------------------------------------------------------

// Pass by value:
// - The function receives a separate copy of the argument.
// - Changes affect only the local parameter.
// - The original variable remains unchanged after the function returns.
//
// Pass by reference:
// - The function parameter is an alias for the caller's variable.
// - No separate copy is made for the reference parameter.
// - Changes affect the original variable directly.
//
// The parameter name is chosen by the programmer. These are equivalent:
// void solve(int &a);
// void solve(int &arr);
// void solve(int &value);
//
// The name after '&' is only the name used inside the function.
// The important part is '&', which makes the parameter a reference.
// For example, if main has int number = 20, then solve(number) connects
// the function's reference parameter to main's number.
// The function may call that parameter a, arr, or value; the result is the
// same as long as the type and reference symbol are correct.
//
// Primitive values and std::string are passed by value when & is not written.
// Use & in the parameter when the function must modify the caller's variable.
void incrementByValue(int number) {
	number = number + 10;
	cout << "Inside incrementByValue: " << number << endl;
}

void incrementByReference(int &number) {
	number = number + 10;
	cout << "Inside incrementByReference: " << number << endl;
}

// std::string can also be passed by value or by reference.
void changeStringByValue(string text) {
	text = "bove";
	cout << "Inside string pass by value: " << text << endl;
}

void changeStringByReference(string &text) {
	text = "babbar";
	cout << "Inside string pass by reference: " << text << endl;
}

void incrementCharacterByValue(char character) {
	character++;
	cout << "Inside char pass by value: " << character << endl;
}

void incrementCharacterByReference(char &character) {
	character++;
	cout << "Inside char pass by reference: " << character << endl;
}

// Important array rule:
// Arrays are commonly said to be passed by reference because a function gets
// access to the original array elements without making a complete array copy.
// In a normal parameter such as int arr[], the array name decays to a pointer
// to its first element. That pointer is passed by value, but it points to the
// original memory, so changing arr[index] changes the caller's array.
// This happens because arr[index] is equivalent to *(arr + index): the
// function follows the pointer to the original element and changes that value.
// The pointer itself is copied, but the array elements are not copied.
// Therefore, changing arr[index] affects the caller, while changing the local
// pointer would not change which array the caller owns.
// The parameter int arr[] is treated like int *arr inside the function.
// No extra '&' is needed for this behavior.
// Pass the size separately because the array does not carry its size here.
//
// Failed even-count version:
// void countEvenNumbers(int arr[], int size, int evenCount) {
//     // evenCount++ changes only a local copy.
// }
// The count in main would remain 0 after the function returns.
// The correct version below uses int &evenCount, so it updates main's count.
void countEvenNumbers(int arr[], int size, int &evenCount) {
	for (int index = 0; index < size; index++) {
		if (arr[index] % 2 == 0) {
			evenCount++;
		}
	}
}

// An array parameter gives the function access to the original elements.
void changeFirstElement(int arr[]) {
	arr[0] = 99;
}

// -----------------------------------------------------------------------------
// 4. Lecture example
// -----------------------------------------------------------------------------

int main() {
	int a = 5;

	// Creating a reference variable temp for a.
	int &temp = a;

	cout << "Initial value of temp: " << temp << endl;

	// Both names access the same memory location.
	temp--;
	cout << "After temp--: " << temp << endl;

	temp = temp * 10;
	cout << "After temp * 10: " << temp << endl;

	// Changing a also changes the value seen through temp.
	a++;
	cout << "After a++: " << a << endl;

	cout << endl << "Pass by value:" << endl;
	int valueExample = 20;
	cout << "Before function: " << valueExample << endl;
	incrementByValue(valueExample);
	cout << "After function: " << valueExample << endl;

	cout << endl << "Pass by reference:" << endl;
	int referenceExample = 20;
	cout << "Before function: " << referenceExample << endl;
	incrementByReference(referenceExample);
	cout << "After function: " << referenceExample << endl;

	cout << endl << "Character pass modes:" << endl;
	char valueCharacter = 'k';
	incrementCharacterByValue(valueCharacter);
	cout << "After char pass by value: " << valueCharacter << endl;

	char referenceCharacter = 'k';
	incrementCharacterByReference(referenceCharacter);
	cout << "After char pass by reference: " << referenceCharacter << endl;

	cout << endl << "String pass modes:" << endl;
	string valueString = "love";
	changeStringByValue(valueString);
	cout << "After string pass by value: " << valueString << endl;

	string referenceString = "love";
	changeStringByReference(referenceString);
	cout << "After string pass by reference: " << referenceString << endl;

	cout << endl << "Even number count:" << endl;
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int evenCount = 0;
	countEvenNumbers(numbers, 8, evenCount);
	cout << "Total even numbers: " << evenCount << endl;

	changeFirstElement(numbers);
	cout << "First array element after function: " << numbers[0] << endl;

	return 0;
}

// -----------------------------------------------------------------------------
// 5. Step-by-step dry run
// -----------------------------------------------------------------------------

// Step 1:
// int a = 5;
// A memory box is created for a and stores 5.
//
// Step 2:
// int &temp = a;
// temp becomes another name for a's existing memory box.
// No new integer memory box is created.
//
// Step 3:
// cout << temp;
// temp accesses the shared memory box, so the output is 5.
//
// Step 4:
// temp--;
// The shared value changes from 5 to 4.
// Reading a also gives 4.
//
// Step 5:
// temp = temp * 10;
// The shared value changes from 4 to 40.
// Both a and temp now give 40.
//
// Step 6:
// a++;
// The shared value changes from 40 to 41.
// Reading temp also gives 41.
//
// Final output:
// Initial value of temp: 5
// After temp--: 4
// After temp * 10: 40
// After a++: 41

// Pass-by-value dry run:
// int number = 20; creates a variable in main.
// incrementByValue(number) creates a separate parameter copy containing 20.
// The function changes its copy to 30.
// After the function returns, number in main is still 20.
//
// Pass-by-reference dry run:
// incrementByReference(number) makes the parameter an alias for number.
// The function changes the shared value from 20 to 30.
// After the function returns, number in main is 30.

// For arrays, the function receives the address of the first element.
// Therefore, changeFirstElement(numbers) changes numbers[0] in main.

// -----------------------------------------------------------------------------
// 6. Practice tasks and spoken exercises
// -----------------------------------------------------------------------------

// 1. Address verification exercise:
//    int a = 5;
//    int &temp = a;
//    cout << &a << " " << &temp << endl;
//    Verify that both addresses are the same.
//
// 2. Re-binding experiment:
//    int a = 5;
//    int b = 10;
//    int &temp = a;
//    temp = b;
//    cout << a << endl; // Prints 10.
//    cout << temp << endl; // Prints 10.
//    temp still refers to a; it did not start referring to b.
//
// 3. Uninitialized reference error:
//    int &temp; // Compilation error: reference declared but not initialized.
//
// 4. Chained reference variables:
//    int a = 5;
//    int &ref1 = a;
//    int &ref2 = ref1;
//    ref2 = 20;
//    cout << a << " " << ref1 << " " << ref2 << endl;
//    // All three names print 20 because they refer to the same value.
