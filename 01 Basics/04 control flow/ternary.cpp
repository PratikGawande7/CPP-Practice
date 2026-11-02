// we will study ternary operator
// we will study how to use ternary operator instead of using simple if-else statement for true or false expressions.

#include<iostream>
using namespace std;


int main(){

int age=12;

// if(age>18){  
//     cout<<"you are elgible to vote "<<endl;
// }
// else{
//     cout<<"you are not eligible to vote "<<endl;

// ternary operator
// format- condition ? expression_if_true: expression_if_false; 
// example -1
// (age>18) ? cout<<"you are eligible to vote ":cout<<"you are not eligible to vote ";
//example -2
// int x=12;
// int y=10;
// int result;

// if (x>y)
// {
//     result=x;
// }


// else 
// {
// result = y;
// }

// cout<<result;
//instead of doing this you can use ternary operator

int x=12;
int y= 10;

int result= x>y ? x : y;
// in this way we can use ternary operator where we have true or false like statement and can be use instead of if-else statement.
cout<<result;
    return 0;
}

/*
PRACTICAL USE OF THIS TOPIC:

The ternary operator is a short way to choose between two values.

condition ? value_if_true : value_if_false;

Read it in English as:
"If the condition is true, use the first value; otherwise, use the second value."

It is useful when:
1. There are only two possible results.
2. We want to assign a value, such as the larger of two numbers.
3. We want to display one of two short messages.

For example, x > y ? x : y stores x when x is greater; otherwise it stores y.

Use a normal if-else statement when the logic has multiple steps or becomes
long and difficult to read. The ternary operator should keep simple choices
short, not replace every if-else statement.
*/


