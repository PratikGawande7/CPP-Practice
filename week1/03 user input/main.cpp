//today we will learn how to take input from the user in C++ using cin and cout

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

    




    return 0;
}