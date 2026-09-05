// today we will learn about variables and datatypes in c++


#include<iostream>
using namespace std;

int main(){
// variables meaning- jab memory block ko named dete hai fir woh memory block variable kehlata hai
// variable likhne ka tarikha- DATATYPE variablename = value;( datatype tells about type of data and size of data )
// int age =19; 
// cout<<age<<endl;

// declaration meaning-sirf variable declare karna value nahi dalna
// int age;
// cout<<age<<endl;(isse koi bhi garbage value store ho jayegi)

// definition meaning- variable ko declare karna aur value dalna dono ek sath
// int age= 19;
// cout<<age<<endl;

// manipulation or updation of variable- variable ki value ko change karna ya update karna
// age=20;
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
   


// to get the size of the variable we use sizeof() function

int age=19;
cout<<sizeof(age)<<endl; // 4 bytes 

// for int
// signed int(let it contain n bits) =then the range of number which can be stored in it is from -2^(n-1) to 2^(n-1)-1
// unsigned int(let it contain n bits) =then the range of number which can be stored in it is from 0 to 2^(n)-1 



//also 1 byte is the smallest unit of memory and 1 byte=8 bits

// ek scope ke andar variable ko redefine nahi kar sakte hai. ek scope ke andar variable ko sirf ek bar define kar sakte hai.
// A variable declared in an outer block is visible in inner blocks.
// A variable declared inside a block is only visible inside that block.
// If you declare a new variable with the same name inside the inner block, it shadows the outer one.

return 0;   
}