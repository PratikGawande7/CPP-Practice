// we will study ternary operator


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
//instead of doing this you can uuse ternary operator

int x=12;
int y= 10;

int result= x>y ? x : y;
// in this way we can use ternary operator where we have true or false like statement and can be use instead of if-else statement.
cout<<result;
    return 0;
}


