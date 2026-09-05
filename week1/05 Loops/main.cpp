// today we will learn about loops 
// Loop – simple definition
// A loop is a programming structure that repeats a block of code again and again until a certain condition becomes false.

// It is used to avoid writing the same code many times.
#include<iostream>
using namespace std;


int main(){
// for loop
// for (initialization; condition ;updation ){
// code to be executed in each iteration 
//}


 for (int i= 1; i<=5;i=i+1){
    cout<<"Pratik"<<endl;
 }
 // how it works- 
 //(1)initially value of i is 1
 //(2) then condition is check whether i<=5 which is true
 //(3) then code inside the scope start to run 
 //(4) then again value of i is updated i=i+1
//(5) then again it is check whether condition still fulfill or not that is i becomes 2 then it is check whether condition is still true or not 2<=5 true so again code inside scope start to run
// so the flow is initialization--> condition--> code execution-->  value updation --> condition--> code execution
// this happen until condition become false and then it exit the loop



// another example 
// for counting 1 to 10
for (int i =1;i<=10;i=i+1){
    cout<< i << endl;
}

// another example 
//for counting 51 to 69
for (int i =51;i<=69;i=i+1){
    cout<< i <<endl;
}
// in the above example we took the condition as i<=69 instead of this condition we could have use i<70

// break keyword- let suppose mene loop banate time condition banayi hai ki i<=10 but muze sirf tabtak code ko execute karna hai jab tak i< 5 hai toh mai uske liye bina condition ko badle bhi break keyword ka use karke ye kar sakta hu
// example 
for (int i=1;i<=10;i=i+1){
    if(i == 5){
        break;
    }
    cout<<i<<endl;

}
// above example mein  jabtak i<5 hai tabtak inside wala loop execute he nahi hoga direct cout<<i hoga lekin jab i=5 ho jayega tab inside wala loop execute hone lagega aur fir uske hesaab se direct break karna hai so sirf 1 2 3 4 hoga agar 5 bhi karna hai toh inside wale if ki condition me i==6 likho 
// break keyword ko use karne ka aur ek tarikha hai 
//another example
 for  (int i =1;i<=10;i=i+1){
    cout<<i<<endl;
    if (i==5){
        break;
    }
}


// iteration-In your code, each time the loop body runs once, that is one iteration.
// i=1, prints 1 - this is first iteration
// i=2, prints 2 - this is second iteration
// i=3, prints 3 - this is third iteration 
// continue keyword- it skip a specific iteration
// the basic difference between break and continue keyword is that break directly exit the for loop but continue just skip specific iteration and continue the for loop 

//example
for (int i=1;i<=10;i=i+1){
    if (i==3){
        continue;
    }
    cout<<i<<endl;
}
  
// while loop- it is also loop but its format is different from for loop
// initialization
// while (condition){
// code to be executed in each iteration  
// 
// updation ;
// }

//example 
int i=1;
while (i<=5){

cout<<i<<endl;

i=i+1;

}


return 0;

}