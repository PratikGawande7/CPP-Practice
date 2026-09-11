// today we will learn about operators
// An operator is a symbol that tells the computer to perform an operation on one or more values.
#include <iostream>
using namespace std;

int main() {
    // unary operator 
    // Unary operators operate on only one operand.
    // They are called unary because they work with a single variable/value.

    // 1) Increment operator (++):
    // It increases the value by 1.
    // There are two ways to use it:

    // Prefix increment( pre-increment ): ++x
    // First increase the value, then use it.
    // Example:
    int x = 5;
    cout << "Prefix increment: " << ++x << endl;  // x becomes 6 and also 6 is printed

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

    // also in loop case instead of doing updation like i=i+1 we can now just write i++ or ++i .

    // Binary operator 
    // A binary operator operates on two operands (values).
    // (1) Arithmetic operator 
    // (2) Relational operator 
    // (3) Logical operator 
    // (4) Bitwise operator 
    // (5) Assignment operator 


    // Arithmetic operator -Arithmetic operators perform mathematical calculations.
    int a=10;
    int b=5;
    cout<< a+b <<endl;
    cout<< a-b <<endl;
    cout<< a*b <<endl;
    cout<< a/b <<endl;
    cout<< a%b <<endl; // it print remainder when a is devided by b 

    cout<< 5*1.0/2<<endl; // if we do 5/2 the answer comes as 2 instead of 2.5 this is due to typecasting which will be taught after finishing operator

    // typecasting



    // Relational operator -These operators compare two values.
    // its answer is mostly in the form of true or false .
    // > → greater than
    // < → less than
    // >= → greater than or equal to
    // <= → less than or equal to
    // == → equal to
    // != → not equal to

    cout<< (5 >= 10) << endl;
    cout<< (5 == 5)  << endl;
    cout<< (5 != 10)<< endl;

    // Logical operators
    // (1) && (logical AND operator)= we know that if we have to check any condition is true or false then we just do if (cond1){} 
    // but in case if we have to check whether mutiple condition are true or not we use and operator 
    // format - if (cond1 && cond2 && cond3){}
// here we know that in case of bool we just dont do if ( cond1==true && cond2==true && cond3 == true ) we just write as above because that is better .
   // example -
   bool cond1 = true;
   bool cond2 = 1;
   bool cond3 = (5>= 5);
   if ( cond1 && cond2 && cond3){
    cout<< " all condition are true "<<endl;
   }
   else  { cout<< " all condition are not true "<<endl;
}

//  (2) || (logical OR operator )= this just work like word 'or' while we are checking condition
// example -
bool cond10 = true;
bool cond20 = 0;
bool cond30  = 5!=5;
 if (cond1 || cond2 || cond3 ){
    cout<<" atleast one condition is true "<<endl;
 }
 else {cout<<" no condition is true "<<endl;
}

// (3) ! ( logical NOT operator )= this just change the boolean value like it makes false to true and true to false 
// example -
bool isMale=true ;
cout<<!isMale<<endl;

    // Assignment operator - An assignment operator is used to assign, or store, a value in a variable
    // syntax - variable=value;

    // (1) Simple assignment operator (=)
    // It stores the value on the right inside the variable on the left.
    int number = 10;
    number = 20;
    cout << "number = " << number << endl;

    // The right side is evaluated first, then its result is assigned to the left side.
    int firstNumber = 5;
    int secondNumber = 3;
    firstNumber = secondNumber;
    cout << "firstNumber = " << firstNumber << endl;

    // (2) Compound assignment operators
    // These are shorter ways to update the value of a variable.
    // number += value means: number = number + value
    // number -= value means: number = number - value
    // number *= value means: number = number * value
    // number /= value means: number = number / value
    // number %= value means: number = number % value
    number = 10;
    // number = number+5
    number += 5;
    cout << "After += 5: " << number << endl;

   // number = number - 3;
    number -= 3;
    cout << "After -= 3: " << number << endl;
   // number = number*2;
    number *= 2;
    cout << "After *= 2: " << number << endl;
   // number = number/4;
    number /= 4;
    cout << "After /= 4: " << number << endl;
   // number = number%3;
    number %= 3;
    cout << "After %= 3: " << number << endl;

    // Remember: = assigns a value; == compares two values.

    // Bitwise operators 
    // Bitwise operators work on the individual bits of an integer.
    // Example:
    // 5 = 00000101
    // 3 = 00000011

    // (1) Bitwise AND (&)
    // A bit is 1 only when both input bits are 1.
    //   00000101  (5)
    // & 00000011  (3)
    // -----------
    //   00000001  (1)
    // 5 & 3 = 1
    cout << "5 & 3 = " << (5 & 3) << endl;

    // (2) Bitwise OR (|)
    // A bit is 1 when at least one input bit is 1. 
    //   00000101  (5)
    // | 00000011  (3)
    // -----------
    //   00000111  (7)
    // 5 | 3 = 7
    cout << "5 | 3 = " << (5 | 3) << endl;

    // (3) Bitwise XOR (^)
    // A bit is 1 when the two input bits are different.
    //   00000101  (5)
    // ^ 00000011  (3)
    // -----------
    //   00000110  (6)
    // 5 ^ 3 = 6
    cout << "5 ^ 3 = " << (5 ^ 3) << endl;

    // XOR truth table:
    // 0 ^ 0 = 0
    // 0 ^ 1 = 1
    // 1 ^ 0 = 1
    // 1 ^ 1 = 0

    // (4) Bitwise NOT (~)
    // NOT flips every bit: 0 becomes 1 and 1 becomes 0.
    // ~5 is commonly -6 for a signed int because:
    // ~n = -(n + 1), so ~5 = -(5 + 1) = -6.
    cout << "~5 = " << ~5 << endl;

    // (5) Left shift (<<)
    // Shifting left by one position usually multiplies a non-negative
    // number by 2.
    // 5      = 00000101
    // 5 << 1 = 00001010 = 10 the rightmost position is fill with 0.and the left most position is just erase
    cout << "5 << 1 = " << (5 << 1) << endl;

    // (6) Right shift (>>)
    // Shifting right by one position usually divides a non-negative
    // number by 2, dropping any remainder.
    // 20      = 00010100
    // 20 >> 1 = 00001010 = 10
    cout << "20 >> 1 = " << (20 >> 1) << endl;

    // Practical example: checking odd or even.
    // The last bit is 1 for odd numbers and 0 for even numbers.
    int value = 5;
    if ((value & 1) == 1) {
        cout << value << " is odd" << endl;
    } else {
        cout << value << " is even" << endl;
    }

    // Bitwise operators are different from logical operators:
    // &  compares integer bits; && combines conditions.
    // |  compares integer bits; || combines conditions.
    // Use parentheses when combining bitwise operators with comparisons.

// Bitwise operators work with integral data types.
// Integral data types store whole numbers.
//
// Examples:
// char
// short
// int
// long
// long long
//
// Bitwise operators also work with unsigned versions,
// such as unsigned int and unsigned long.
//
// Example:
// int a = 5;
// int b = 3;
//
// cout << (a & b);
//
// Bitwise operators work on the individual binary bits
// of whole-number values.
//
// They cannot normally be used with:
// float
// double
// string





    
    return 0;
}