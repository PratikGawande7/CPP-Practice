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






