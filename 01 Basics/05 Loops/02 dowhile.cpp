// do-while loop - it work differently then for loop and while loop .In do-while loop first iteration is done without considering whether it follow condition or not.even if it is false and dont follow condition still first iteration  will happen
// format of do-while loop
// initialization;
// do{
// code to be executed in each iteration
// updation;
//} while(condition);

#include<iostream>
using namespace std;
int main(){
 // example   
// int i=1;
// do{
//     cout<<i<<endl;
//     i=i+1;
// } while(i<=5);


//example
// int count=20;

// int i=1;
// do{
//     cout<<i<<endl;
//     i=i+1;
// } while(i<=count);



// nested loop- A nested loop is a loop placed inside another loop. The inner loop runs completely for each iteration of the outer loop.
for (int i=1;i<=3;i=i+1){
    for (int j=1;j<=3;j=j+1){
        cout<<i<<j<<endl;
    }
}

for(int i=1;i<=2;i=i+1){
    for(int j=1;j<=2;j=j+1){
        cout<<i*j<<endl;
    }
}


return 0;
}

/*
PRACTICAL USE OF THIS TOPIC:

Use a do-while loop when the code must run at least once before the condition
is checked. This is useful for:
1. Showing a menu before asking whether the user wants to continue.
2. Asking for input at least once and repeating until it is valid.
3. Repeating a game or task until the user chooses to stop.

The main difference is:
while checks the condition first, so it may run zero times.
do-while runs the code first, so it always runs at least once.

A nested loop is useful when one repeated task is inside another repeated task.
For example, nested loops can print rows and columns, create a table, display
a pattern, or compare every item with other items.

The inner loop completes all of its iterations for each one iteration of the
outer loop.
*/