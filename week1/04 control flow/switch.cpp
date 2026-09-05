// today  we will learn about using switch case instead of using if- else if/if- else if - else statement


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
// expression type- The expression used in a switch statement must be of an integral or enumerated type.
// Supported data types include:
// int
// char
// enum 
// Floating-point types such as float or double and complex data types cannot be directly used in a switch expression.Also you cannot use string.

//unique case values- dont take same case again again with diferent outputs.


//no case checking - dont make cases with condtion like case (age>12) this is not allow only cases with constant value works.( so for such cases use if else statements )



//fall through behaviour - write break after each case when fall-through is not intended 
// because unlike conditional statement it carry all cases one after the other if break is not added.



// execution order - execution starts at the matching case and continues until break or the end








    return 0;
} 



