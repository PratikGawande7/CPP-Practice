// Today we will learn how to print something.

// iostream gives us input and output tools such as cout.
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
