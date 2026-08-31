// do-while loop - it work differently then for loop and while loop .In do-while loop first iteration is done withouut considering whether it follow condition or not.even if it is false and dont follow condition still first iteration  will happen
// format of do-while loop
// initialization;
// do{
// code to be executed in each iteration
// updation;
//} while(updation);

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



// nested loop
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