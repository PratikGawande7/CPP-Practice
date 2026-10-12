// today we will learn about using switch case instead of using if- else if/if- else if - else statement


#include<iostream>
using namespace std;



int main(){

char grade;
cout<<"enter your grade : ";
cin>>grade;

// if (grade== 'A'){
//     cout<<"your marks is in the range 90-100"<<endl;
// }

// else if (grade == 'B')
// {
//     cout<<"your marks is in the range 80-90"<<endl;
// }
// else if (grade == 'C')
// {
//     cout<<"your marks is in the range 70-80"<<endl;
// }
// else if (grade == 'D')
// {
//     cout<<"your marks is in the range 60-70"<<endl;
// }
// else {
//     cout<<"your marks is below 60"<<endl;
// }





// switch case statement-
//format- switch(expression){
// case value1:code to be executed if expression equal value1
// break;
// case value2:code to be executed if expression equal value2
// break;
// case value3: code to be  executed if expression equal value3
// default:code to be executed if none of the case match 
// }
switch(grade){
    case 'A': cout<<"your marks is in range 90-100"<<endl;
    break;
    case 'B': cout<<"your marks is in range 80- 90"<<endl;
    break;
    case 'C':cout<<"your marks is in range 70-80 "<<endl;
    break;
    case 'D':cout<<"your marks is in range of 60-70"<<endl;
    break;
    default:cout<<"your marks is below 60 "<<endl;

}

// rule of switch (expression) 
// expression type - The expression's resulting type must be an integral or
// enumerated type (after integral promotions). Common examples include int,
// char, and bool, as well as enum types. char is integral, so a character such
// as 'A' can be matched with a case label such as case 'A'.
// It is not true that only float and double are disallowed: floating-point
// types, pointers, strings, and class types such as std::complex cannot be
// used directly as the switch expression. The expression itself can be more
// than a single variable, as long as its resulting type meets this rule.

// unique case values- dont take same case again again with diferent outputs.


// no case checking - dont make cases with condtion like case (age>12) this is not allow only cases with constant value works.( so for such cases use if else statements )



// fall through behaviour - write break after each case when fall-through is not intended 
// because unlike conditional statement it carry all cases one after the other if break is not added.



// execution order - execution starts at the matching case and continues until break or the end

// bool can be used because it converts to an integral value:
// false = 0, true = 1 
// bool isLoggedIn = true;

// switch (isLoggedIn) {
//     case true:
//         cout << "Logged in";
//         break;
//     case false:
//         cout << "Not logged in";
//         break;
// }





    return 0;
} 

/*
PRACTICAL USE OF THIS TOPIC:

switch is useful when one value must be compared with several fixed choices.
For example, it can be used for:
1. Handling menu choices such as 1 = add and 2 = subtract.
2. Handling commands in a small console program.
3. Checking a grade, day number, or menu option.
4. Selecting an action based on an enum value.

Each case represents one possible value. The matching case runs, and break
stops the switch so that the next cases do not run accidentally.
default handles values that do not match any case.

Use switch for exact fixed values. Use if-else when you need ranges,
comparisons, or more complex conditions such as marks > 90.
*/

