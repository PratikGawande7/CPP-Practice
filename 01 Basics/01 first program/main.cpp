// Today we will learn how to print something.

// iostream gives us input and output tools such as cout.
// It is called a header file.
#include<iostream>

// This lets us write cout instead of std::cout.
using namespace std;

// Program execution starts from the main function.
int main() {

// cout means character output: it prints text on the screen.
cout<<"namaste dunia"<<endl;

// endl moves the cursor to the next line.
cout<<"namaste dunia \n";

// \n also moves the cursor to the next line.
cout<<"namaste dunia"<<"\n";
cout<<"namaste dunia"<<'\n';

// A semicolon ends a statement. It is not printed on the screen.
// return 0 means that the program finished successfully.
    return 0;
}


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

/*
In simple words:

#include <iostream> is like bringing a toolbox
that provides tools such as cout, cin, and endl.

std is like a label or brand name
used to identify standard C++ tools.

using namespace std; means:
"Use the tools identified by std directly,
without writing std:: every time."
*/

/*
PRACTICAL USE OF THIS TOPIC:

We use cout to show information to the user on the screen.
For example, we can use it to:
1. Display instructions or messages.
2. Show the result of a calculation.
3. Create a simple menu in a console program.
4. Print values while testing and debugging our code.

We use endl or \n when we want the next output to appear on a new line.
In future programs, cout will help us display user input, calculations,
conditions, loops, and other results.
*/
