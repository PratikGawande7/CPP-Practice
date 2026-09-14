// Today we will learn about reference variables.

#include <iostream>
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
// 3. Lecture example
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

	return 0;
}

// -----------------------------------------------------------------------------
// 4. Step-by-step dry run
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

// -----------------------------------------------------------------------------
// 5. Practice tasks and spoken exercises
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
