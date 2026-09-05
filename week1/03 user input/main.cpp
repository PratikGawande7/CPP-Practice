// today we will learn how to take input from the user in C++ using cin and cout

#include <iostream>
using namespace std;

int main(){

    // declare variable
    int age;
    
    cout << "Enter your age: ";
    cin >> age; // take input from user
    cout<<"your age is : " << age << endl; // print the input value


    // but remember that  cin allow user to give any kind of input based on the datatype they have declared. but in case of boolean datatype it will only accept 0 or 1 as input. if user give any other value like true or false is enter by user then it will be considered as 0.
    

    /*
    1. cin.ignore()

    cin.ignore() removes one character from the input buffer.

    Example:
        int age;
        string name;

        cin >> age;
        cin.ignore();       // Removes the leftover Enter key
        getline(cin, name); // Reads the full name

    If the user enters:
        20
        John Smith

    cin >> age reads 20, but the Enter key remains in the buffer.
    cin.ignore() removes that Enter key so getline() can read the name.

    To remove everything left on the current line, use:
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


    2. cin.fail()

    cin.fail() checks whether the previous input operation failed.

    Example:
        int age;
        cin >> age;

        if (cin.fail()) {
            cout << "Invalid input";
        }

    If the user enters text instead of a number, cin.fail() becomes true.

    To reset cin after an input error, use:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


    3. getline(cin, variable)

    getline() reads a complete line of text, including spaces.

    Example:
        string fullName;

        cout << "Enter your full name: ";
        getline(cin, fullName);

        cout << "Hello " << fullName;

    If the user enters:
        John Smith

    getline() stores the complete text "John Smith" in fullName.

    The correct format is:
        getline(cin, variable);

    The following is incorrect:
        getline(cin, 10);

    The second argument must be a string variable, not a number.
*/

    //explaination in easy way-
//     ## What Is the Input Buffer?

// The **input buffer** is a temporary waiting area for characters that you type before your program reads them.

// Think of it like a queue:

// ```text
// Keyboard -> Input buffer -> cin
// ```

// Your program does not always receive each key directly at the exact moment you press it. The characters wait in the input buffer until a command such as `cin >> age` or `getline` reads them.

// ## Example

// Your program asks:

// ```cpp
// cout << "Enter your age: ";
// cin >> age;
// ```

// You type:

// ```text
// 25
// ```

// Then press **Enter**.

// The input buffer contains something like this:

// ```text
// +---+---+-----+
// | 2 | 5 | \n  |
// +---+---+-----+
// ```

// The characters mean:

// ```text
// '2'   the first character
// '5'   the second character
// '\n'  the newline character created by pressing Enter
// ```

// `'\n'` is pronounced **newline**. It means “move to the next line,” but in input it also represents the Enter key.

// ## What Does `cin >> age` Read?

// This code:

// ```cpp
// cin >> age;
// ```

// looks for characters that form an integer.

// It reads:

// ```text
// 2 5
// ```

// and converts them into:

// ```cpp
// 25
// ```

// But it does not consume the newline:

// ```text
// Input buffer before cin >> age:

// [ 2 ][ 5 ][ \n ]

// Input buffer after cin >> age:

// [ \n ]
// ```

// The newline is still waiting in the input buffer.

// ## Why Does `getline` Skip the Name?

// Now consider:

// ```cpp
// cin >> age;
// getline(cin, name);
// ```

// After `cin >> age`, the buffer contains:

// ```text
// [ \n ]
// ```

// Then `getline` starts reading. Its rule is:

// > Read characters until you find a newline.

// It immediately finds the leftover newline:

// ```text
// [ \n ]
//   ^
//   getline sees this immediately
// ```

// Therefore, it thinks the user entered an empty line:

// ```cpp
// name == ""
// ```

// It does not wait for you to type a name because the newline was already there.

// ## What Does `cin.ignore()` Do?

// This line:

// ```cpp
// cin.ignore();
// ```

// means:

// > Remove one character from the input buffer and throw it away.

// So the sequence becomes:

// ```cpp
// cin >> age;
// ```

// Buffer:

// ```text
// [ \n ]
// ```

// Then:

// ```cpp
// cin.ignore();
// ```

// Buffer:

// ```text
// [ empty ]
// ```

// Then:

// ```cpp
// getline(cin, name);
// ```

// Now there is no leftover newline, so `getline` waits for you to type the name.

// ## Correct Program

// ```cpp
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int age;
//     string name;

//     cout << "Enter your age: ";
//     cin >> age;

//     cin.ignore();

//     cout << "Enter your name: ";
//     getline(cin, name);

//     cout << "Age: " << age << endl;
//     cout << "Name: " << name << endl;

//     return 0;
// }
// ```

// ## Why `cout << endl` Does Not Solve It

// These are different things:

// ```cpp
// cin  // input: receives characters
// cout // output: displays characters
// ```

// This:

// ```cpp
// cout << endl;
// ```

// prints a newline on the screen. It does not remove anything from the input buffer.

// Only an input operation can deal with the input buffer, such as:

// ```cpp
// cin.ignore();
// ```

// ## Simple Timeline

// When you type:

// ```text
// 25[Enter]
// ```

// the process is:

// ```text
// 1. Keyboard creates: 2, 5, Enter
// 2. Input buffer stores: [2][5][\n]
// 3. cin >> age reads: 2 and 5
// 4. Input buffer remains: [\n]
// 5. cin.ignore removes: \n
// 6. getline waits for your name
// ```

// Without `cin.ignore()`:

// ```text
// cin >> age       // leaves \n
// getline(...)     // reads that \n and returns an empty string
// ```

// With `cin.ignore()`:

// ```text
// cin >> age       // leaves \n
// cin.ignore()     // removes \n
// getline(...)     // correctly reads the name
// ```

// The important idea is:

// > `cin >> age` reads the age but leaves the Enter key behind. `cin.ignore()` removes that leftover Enter key before `getline` reads the name.




    return 0;
}