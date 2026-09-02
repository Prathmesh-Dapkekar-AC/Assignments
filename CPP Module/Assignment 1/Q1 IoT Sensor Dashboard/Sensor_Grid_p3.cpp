#include<iostream>
#include<cmath>
using namespace std; 

void hottestroom(double arr[][3], int i, int j){ 
    double maxroom=arr[0][0];
     int f,r; 
       for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
        if(maxroom<arr[i][j]){
                maxroom=arr[i][j];       // Finding and printing the hottest room details.
                f=i;
                r=j;
         }
        }
      }
        cout<<"Hottest Room  : Floor "<<f+1<<", Room "<<r+1<<"  ->  "<<maxroom<<" C"<<endl;
}

void hottestfloor(double arr[][3], int i,int j){
     double maxavg=0;
     int f1;
     for(i=0;i<=2;i++){
        double sum=0;
        for(j=0;j<=2;j++){
            sum += arr[i][j];         // Finding the average of each floor and printing the details of highest floor average temp
        }
        double avgf = sum/3;
        if(maxavg<avgf){
            maxavg=avgf;
            f1=i;
        }
     }
     cout<<"Hottest Floor : Floor "<<f1+1<<"  (avg "<<round(maxavg*100.0) / 100.0<<" C)"<<endl;
}


int main(){
    double arr[3][3];
    int i=0;
    int j=0;
    cout<<"Enter Readings of Temperature : "<<endl;

    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            cin >> arr[i][j];    // Reading temperatures for all 9 rooms into a 2D array
        } 
    } 

    cout<<"\t\tRoom1\tRoom2\tRoom3"<<endl; 
    int count=0;
    for(i=0;i<=2;i++){
        cout<<"Floor "<<i+1<<"  : \t";
        for(j=0;j<=2;j++){
            cout<<arr[i][j] <<"\t";          // display the readings in a formatted table

            if(arr[i][j]>=30.0){
                count++;                    // Counting total rooms at or above the WARNING threshold (30°C)
            }
            }
            cout<<endl;
        } 

    hottestroom(arr,3,3);     // Function call 
    hottestfloor(arr,3,3);    // Function call 
    cout<<"Rooms at WARNING or above : "<<count<<endl;     // printing total room at or above the warning threshold
    return 0;
    
}