#include <iostream>
using namespace std;

int main() {
    // unaryoperator 
    // Unary operators operate on only one operand.
    // They are called unary because they work with a single variable/value.

    // 1) Increment operator (++):
    // It increases the value by 1.
    // There are two ways to use it:

    // Prefix increment( pre-increment ): ++x
    // First increase the value, then use it.
    // Example:
    int x = 5;
    cout << "Prefix increment: " << ++x << endl;  // x becomes 6

    // Postfix increment(post-increment ): x++
    // First use the current value, then increase it.
    // Example:
    x = 5;
    cout << "Postfix increment: " << x++ << endl;  // prints 5, then x becomes 6
    cout << "After x++: " << x << endl;

    // 2) Decrement operator (--):
    // It decreases the value by 1.
    // There are two ways to use it:

    // Prefix decrement: --x
    // First decrease the value, then use it.
    int y = 10;
    cout << "Prefix decrement: " << --y << endl;  // y becomes 9

    // Postfix decrement: y--
    // First use the current value, then decrease it.
    y = 10;
    cout << "Postfix decrement: " << y-- << endl;  // prints 10, then y becomes 9
    cout << "After y--: " << y << endl;

    // Important difference:
    // ++x and x++ are not the same.
    // --x and x-- are not the same.
    // Prefix changes the value before using it.
    // Postfix uses the old value first, then changes it.

    // also in out loop case instead of doing updation like i=i+1 wecan now just write i++ or ++i .



    // Arithmetic operator
    int a=10;
    int b=5;
    cout<< a+b <<endl;
    cout<< a-b <<endl;
    cout<< a*b <<endl;
    cout<< a/b <<endl;
    cout<< a%b <<endl; // it print remainder when a is devided by b 

    cout<< 5*1.0/2<<endl;

    // typecasting



    // Relational operator
    // > → greater than
    // < → less than
    // >= → greater than or equal to
    // <= → less than or equal to
    // == → equal to
    // != → not equal to

    cout<< (5>= 10 ) << endl;
    cout<< (5 == 5)  << endl;
    cout<< ( 5 != 10)<< endl;

    return 0;
}