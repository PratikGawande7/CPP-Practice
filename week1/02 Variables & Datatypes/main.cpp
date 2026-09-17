// today we will learn about variables and datatypes in c++


#include<iostream>
using namespace std;

int main(){
// variables meaning- jab memory block ko named dete hai fir woh memory block variable kehlata hai
// variable likhne ka tarikha- DATATYPE variablename = value;( datatype tells about type of data and size of data )
// int age =19; 
// cout<<age<<endl;

// declaration meaning-sirf variable declare karna value nahi dalna
// int age;(isse koi bhi garbage value store ho jayegi)

// cout<<age<<endl;(isse jo bhi garbage value store hogi woh print jayegi)

// definition meaning- variable ko declare karna aur value dalna dono ek sath
// int age= 19;
// cout<<age<<endl;

// manipulation or updation of variable- variable ki value ko change karna ya update karna
// age=20; (isse 19 erase hokar 20 store ho jayega)
// cout<<age<<endl;




// different datatypes (built in/primitive datatypes) in c++

// int-integer store karta hai
int count=5;

// float- decimal value store karta hai
float price=99.99;

// char- single character store karta hai
char alphabet='P';

// double- double precision decimal value store karta hai. double datatype ka size float se double hota hai  

double pi=3.141592653; 

// boolean- true ya false value store karta hai
// bool isMale=true;
// bool isChild=1;
// bool isFemale=false;
// bool isgirl=0;

// cout<<count<<endl;
// cout<<price<<endl;
// cout<<alphabet<<endl;
// cout<<pi<<endl; 
// cout<<isMale<<endl;
// cout<<isChild<<endl;
// cout<<isFemale<<endl;
// cout<<isgirl<<endl;
   
// we will learn void datatype later 

// to get the size of the variable we use sizeof() function .It tells us how many bytes a variable or datatype occupies in memory.
//cout<<sizeof(datatype);
//cout<<sizeof(variable);
int age=19;
cout<<sizeof(age)<<endl; // 4 bytes 

// for int
// signed int(let it contain n bits) =then the range of number which can be stored in it is from -2^(n-1) to 2^(n-1)-1
// unsigned int(let it contain n bits) =then the range of number which can be stored in it is from 0 to 2^(n)-1 



// also 1 byte is the smallest unit of memory and 1 byte=8 bits

// ek scope ke andar variable ko redefine nahi kar sakte hai. ek scope ke andar variable ko sirf ek bar define kar sakte hai.
// A variable declared in an outer block is visible in inner blocks.
// A variable declared inside a block is only visible inside that block.
// If you declare a new variable with the same name inside the inner block, it shadows the outer one.

return 0;   
}

/*
PRACTICAL USE OF THIS TOPIC:

Variables are named memory locations used to store information in a program.
For example:
1. int can store whole numbers such as age, count, or marks.
2. float or double can store decimal values such as price or percentage.
3. char can store one character such as a grade or initial.
4. bool can store a yes/no state and can be used directly in an if condition.

We choose a datatype according to the kind of value we need to store.
We update variables when information changes, such as increasing a count
or changing a player's score.

sizeof helps us understand how much memory a datatype or variable uses.
Scope controls where a variable can be used in the program.

Always give a local variable a value before using it. For example:
int age = 19;
An uninitialized local variable does not have a reliable value.
*/