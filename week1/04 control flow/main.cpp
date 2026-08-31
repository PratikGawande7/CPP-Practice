// today we will learn how to write code for conditions

#include<iostream>
using namespace std ;


int main(){

//int budget;
//cout<<"enter your budget :";
//cin>>budget;

// if condition- it is used to check the condition and if the condition is true then it will execute the code inside the if block otherwise it will not execute the code inside the if block.
// if(budget>2000000)
// { 
//     cout<<"you can buy scorpio "<<endl;
// }








// if-else condition- it is used to check the condition and if the condition is true then it will execute the code inside the if block otherwise it will execute the code inside the else block.
// example 1-
//  if(budget>2000000)
// { 
//     cout<<"you can buy scorpio "<<endl;
// }
// else {
//     cout<<"you cannot buy scorpio"<<endl;
// }



// example 2-
// int age=100;
// if(age>18){
// cout<<"you are eligible for voting"<<endl;
// }
// else{
//     cout<<"you are not eligible for voting"<<endl;
// }









// if-else if ladder- it is used to check multiple conditions and if the condition is true then it will execute the code inside the if block otherwise it will check the next condition and so on until it finds a true condition or reaches the end of the ladder.
// int marks=65;
// if (marks>90){
// cout<<"you got A grade"<<endl; 
// }
// else if(marks>80){
//     cout<<"you got B grade"<<endl;
// }
// else if(marks>70){
//     cout<<"you got C grade"<<endl;
// }
// else if(marks>60){
//     cout<<"you got D grade"<<endl;
// }







// if -else if-else ladder- it is used to check multiple conditions and if the condition is true then it will execute the code inside the if block otherwise it will check the next condition and so on until it finds a true condition or reaches the end of the ladder. If none of the conditions are true then it will execute the code inside the else block.

// int marks=55;
// if (marks>90){
//     cout<<"you got A grade"<<endl;
// }

// else if(marks>80){
//     cout<<"you got B grade"<<endl;
// }

// else if (marks>70){
//     cout<<"you got C grade"<<endl;
// }

// else if(marks>60){
//     cout<<"you got D grade"<<endl;
// }
// else{
//     cout<<"you failed"<<endl;
// }








// nested if-else condition- it is used to check the condition and if the condition is true then it will execute the code inside the if block otherwise it will execute the code inside the else block. Inside the if block we can write another if-else condition and so on.
int height;
cout<<"enter your height in feet : ";
cin>>height;

int weight;
cout<<"enter your weight in kg :";
cin>>weight;


if (height>5)
{
   if (weight>50)
   {
      cout<<"your height and weight is fine"<<endl;;
   }
   else{
      cout<<"your height is fine but you are underweight"<<endl;

   }
}
else{

cout<<"your height is short"<<endl;

}



   return 0;
}