// What happens if you change return 0; to return -1;?
//
// When a C++ program ends, the value returned from main() is sent to the
// operating system as the program's exit status.
//
// return 0; means the program finished successfully.
// return -1; means the program ended with an error/failure.
//
// So if we change:
//
// int main() {
//     return 0;
// }
//
// to:
//
// int main() {
//     return -1;
// }
//
// the program still runs, but it exits with a failure code.
//
// This does NOT mean the program "crashes" automatically.
// It just tells the OS that the program did not complete successfully.
//
// A non-zero value like -1 is usually treated as an error.
// That can make the terminal show an error, or let scripts detect failure.
//
// In simple words:
// return 0; = success
// return -1; = failure
//
// Also, once return is reached, the program ends immediately,
// so any code after it will not run.
















// what a pre-processor directive (like #include) is.
// A pre-processor directive is a command that is processed before the
// actual C++ compilation starts.
//
// It begins with #, such as:
// #include <iostream>
// #define PI 3.14
//
// The compiler does not compile these lines like normal code.
// First, the pre-processor reads them and performs actions.
//
// Example:
// #include <iostream>
// This tells the compiler to include the contents of the iostream header file,
// which gives us input/output features like cout and cin.
//
// So #include is used to add code from another file into our program.
//
// In simple words:
// pre-processor directives are instructions for the compiler before compilation.
//
// They are used for:
// - including header files
// - defining constants or macros
// - conditional compilation


// Question: What are the memory sizes and value ranges of common data types like int, float, double, and char?
//
// Answer:
// In C++, data types have different sizes in memory, and each type can store
// only a certain range of values. The sizes may vary slightly depending on the
// compiler and system, but on most modern systems:
//
// char = 1 byte
// Range: -128 to 127 for signed char
// Range: 0 to 255 for unsigned char
//
// int = 4 bytes
// Range: -2,147,483,648 to 2,147,483,647
//
// float = 4 bytes
// Approximate range: ±3.4e-38 to ±3.4e38
//
// double = 8 bytes
// Approximate range: ±1.7e-308 to ±1.7e308
//
// These values are verified using sizeof() and std::numeric_limits.
//
// Example:
// #include <iostream>
// #include <limits>
//
// int main() {
//     std::cout << sizeof(char) << "\n";
//     std::cout << sizeof(int) << "\n";
//     std::cout << sizeof(float) << "\n";
//     std::cout << sizeof(double) << "\n";
//
//     std::cout << std::numeric_limits<int>::min() << " to "
//               << std::numeric_limits<int>::max() << "\n";
//
//     return 0;
// }
//
// Important:
// - char stores characters, but it is still 1 byte in memory.
// - float and double are used for decimal numbers.
// - int is used for whole numbers.
// - The exact size is implementation-defined, but these are the usual values
//   on most systems.



// Example: user gives his name as input
//
// If the program uses cin >> name;
//
// string name;
// cin >> name;
//
// User enters:
// John
//
// Then name becomes:
// "John"
//
// But if user enters:
// John Smith
//
// Then cin >> name only stores:
// "John"
//
// It stops at the space.
//
// ------------------------------------------------------------
//
// Why is this a problem?
//
// Because a person's name often has a space.
// So we need getline() to read the whole line.
//
// string name;
// getline(cin, name);
//
// User enters:
// John Smith
//
// Then name becomes:
// "John Smith"
//
// ------------------------------------------------------------
//
// What about the extra Enter key?
//
// After using cin >>, the Enter key leaves a newline in the input.
// That newline can confuse getline().
//
// Example:
// int age;
// string name;
//
// cin >> age;     // user enters 25
// getline(cin, name); // user enters John Smith
//
// This can fail because the newline from pressing Enter after 25 is still there.
//
// So we use:
// cin >> age;
// cin.ignore();   // removes the leftover newline
// getline(cin, name);
//
// Now it works correctly.
//
// ------------------------------------------------------------
//
// If user enters wrong type:
//
// User enters:
// abc
//
// int age;
// cin >> age;
//
// This fails.
// cin.fail() becomes true.
//
// Then:
//
// if (cin.fail()) {
//     cout << "Invalid input" << endl;
// }
//
// This helps us handle bad input.
//
// ------------------------------------------------------------
//
// Summary with name example:
// User input: 25
// John Smith
//
// Using cin >> age;
// cin.ignore();
// getline(cin, name);
//
// gives:
// age = 25
// name = "John Smith"


// #include<iostream>
// using namespace std;


// int main(){
// // homework question
// // question - print  1 to 100 counting
// for (int i=1;i<=100;i=i+1){
//     cout<<i<<endl;
// }


// // question- print 100 to 1 counting
// for (int i=100;i>=1;i=i-1){
//     cout<<i<<endl;
// }

// // print name 50 times
// for (int i=1;i<=50;i=i+1){
//     cout<<"Pratik"<<endl;
// }

// // print 0 to -10 counting 
// for (int i=0;i>=-10;i=i-1){
//     cout<<i<<endl;
// }


// // print table of 7
// for (int i=1;i<=10;i=i+1){
//     cout<<7*i<<endl;
// }


// // write A to Z alphabet
// for (char alphabet='A';alphabet<='Z';alphabet=alphabet+1){
//     cout<<alphabet<<endl;
// }

// // write a to z alphabet
// for (char alphabet='a';alphabet<='z';alphabet=alphabet+1){
//     cout<<alphabet<<endl;
// }









//     return 0;
// }



// homework 
#include<iostream>
using namespace std;


int main(){
// what happpen if put ; after for()
// for (int i=1;i<=10;i=i+1);
// {
//     cout<<i<<endl;
// } 
// this code dont work

// what if we take input instead of giving condition
// int i;
// if (cin>>i){
//     cout<<"Pratik"<<endl;
// }
// this code work

// what if we gave any output instead of giving condition
// if (cout << "Hi") {
//     cout << "Pratik" << endl;
// }
// this also works because cout << "Hi" prints the text and returns the cout stream.
// In a condition, C++ checks whether the stream is valid (not failed).
// Since cout is working normally, the condition is true, so Pratik is printed.



    return 0;
}



// can we apply modulus operator (%) on float type value
// answer-The % operator works only with integers because it calculates the whole-number remainder
// Floating-point numbers can contain decimal fractions, so C++ uses fmod() to calculate their remainder
// // For integers:
// 10 % 3;              // modulus operator

//  For float or double:
// fmod(10.5, 3.2);     // fmod() function



// ==================== BINARY AND NUMBER SYSTEMS ====================
// A number system is a way of representing numbers using a set of symbols
// and a base.
//
// The base tells us how many different digits are available in that system.
//
// Decimal number system:
// - Base 10
// - Uses the digits 0 to 9
// - This is the number system people normally use.
// Example: 538
//
// Binary number system:
// - Base 2
// - Uses only the digits 0 and 1
// - Computers use binary to represent and process data.
// Example: 1011 (binary)
//
// Octal number system:
// - Base 8
// - Uses the digits 0 to 7
// Example: 27 (octal)
//
// Hexadecimal number system:
// - Base 16
// - Uses 0 to 9 and A to F
// - A means 10, B means 11, C means 12, D means 13,
//   E means 14, and F means 15.
// Example: 2F (hexadecimal)

// PLACE VALUE IN A NUMBER SYSTEM
// In every number system, the value of a digit depends on its position.
// The positions start from the right side with power 0.
//
// Decimal example:
// 538 = (5 * 10^2) + (3 * 10^1) + (8 * 10^0)
//     = 500 + 30 + 8
//     = 538
//
// Binary example:
// 1011 = (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0)
//      = 8 + 0 + 2 + 1
//      = 11 in decimal

// CONVERTING DECIMAL TO BINARY
// To convert a decimal number to binary:
// 1. Divide the number by 2.
// 2. Write down the remainder, which is always 0 or 1.
// 3. Divide the quotient by 2 again.
// 4. Continue until the quotient becomes 0.
// 5. Read the remainders from bottom to top.
//
// Example: convert decimal 13 to binary
// 13 / 2 = 6 remainder 1
//  6 / 2 = 3 remainder 0
//  3 / 2 = 1 remainder 1
//  1 / 2 = 0 remainder 1
//
// Reading the remainders from bottom to top:
// 13 in decimal = 1101 in binary

// CONVERTING BINARY TO DECIMAL
// Multiply each binary digit by its power of 2 and add the results.
//
// Example:
// 1101 = (1 * 2^3) + (1 * 2^2) + (0 * 2^1) + (1 * 2^0)
//      = 8 + 4 + 0 + 1
//      = 13 in decimal

// In C++, an integer literal can be written in different number systems:
// int decimalNumber = 13;      // decimal
// int binaryNumber = 0b1101;   // binary
// int octalNumber = 015;       // octal
// int hexadecimalNumber = 0xD; // hexadecimal
//
// The prefix tells C++ which number system is being used:
// 0b or 0B = binary
// 0        = octal
// 0x or 0X = hexadecimal


// ==================== TYPECASTING ====================
// Typecasting means converting a value from one data type to another data type.
// It is useful when we want an operation to use a different data type.

// IMPLICIT TYPECASTING
// Implicit typecasting happens automatically when C++ converts a value
// to another compatible type.
// It usually converts a smaller type into a larger type to avoid data loss.
//
// Example:
// int number = 10;
// double result = number;
//
// The int value 10 is automatically converted to the double value 10.0.

// Another example:
// int wholeNumber = 5;
// double decimalNumber = 2.5;
// double answer = wholeNumber + decimalNumber;
//
// wholeNumber is automatically converted to double before addition.

// INTEGER DIVISION
// The type of the operands affects the type of the result.
// If both operands are int, C++ performs integer division.
// Integer division keeps only the whole-number part and removes the remainder.
//
// int result = 5 / 2;
// result becomes 2, not 2.5.
// Both 5 and 2 are int values, so the result is calculated as an int.
//
// To get a decimal answer, at least one operand must be a floating-point value:
// double result1 = 5.0 / 2;                    // 2.5
// double result2 = static_cast<double>(5) / 2; // 2.5
//
// In simple words:
// int / int = integer result
// double / int = decimal result
// int / double = decimal result

// EXPLICIT TYPECASTING
// Explicit typecasting happens when the programmer manually asks C++
// to convert a value to another type.
//
// Syntax:
// dataType(value)
//
// Example:
// int a = 5;
// int b = 2;
// double answer = double(a) / b;
//
// Without typecasting, a / b performs integer division and gives 2.
// With double(a), the division gives 2.5.

// C++ style explicit typecasting can also be written using static_cast:
// int a = 5;
// int b = 2;
// double answer = static_cast<double>(a) / b;

// TYPECASTING A DECIMAL TO AN INTEGER
// When a decimal value is converted to int, the fractional part is removed.
// It does not round the value.
//
// double price = 9.75;
// int wholePrice = static_cast<int>(price);
// wholePrice becomes 9.

// POSSIBLE DATA LOSS
// Converting a larger or more precise type to a smaller type can lose data.
//
// double value = 12.89;
// int result = static_cast<int>(value);
// result becomes 12, so .89 is lost.

// Summary:
// - Implicit typecasting is performed automatically by C++.
// - Explicit typecasting is performed manually by the programmer.
// - Typecasting can be used to control the result of an operation.
// - Converting from double to int removes the decimal part.