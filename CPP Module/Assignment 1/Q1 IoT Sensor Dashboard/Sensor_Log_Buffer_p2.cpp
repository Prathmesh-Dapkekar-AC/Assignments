#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    int skip=0;

    cout<<"Enter Number of readings you want : ";  // Accepting n from the user
    cin>>n;
    double arr[n];
    cout<<"Enter Readings : "<<endl;     // then reading n temperature values into an array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

      cout<<"\nReadings Entered : "<<n<<endl;   
      cout<<"Valid readings   : ";

    for(int i=0;i<n;i++){ 
        if(arr[i]==0){ 
          skip++;  
          continue;       // skipping values below 0 (sensor error) using continue
        }
        else 
        cout<<arr[i]<<" ";        //  printing all valid readings 
    }
    cout<<"\nSkipped (errors) : "<<skip<<endl;

     for(int i=0;i<n;i++){         // Scanning for the first reading at or above 45°C
        if(arr[i]>=45){ 
          cout<<"First CRITICAL   : Index "<<i+1<<"  ->  "<<arr[i]<<" C"<<endl;   // printing its index and first critical value
          break;        // stopped scanning using break
        } 
    }
     double min,max;
     double sum=0,avg=0;
     double first_valid;

     for(int i=0;i<n;i++){
        if(arr[i]!=0){
          first_valid = arr[i];        // calculating first valid reading to avoid error for assigning 0 value to min and max
          break;
        }
     } 

     min=first_valid;
     max=first_valid;

    for(int i=0;i<n;i++){ 
         if(arr[i]==0){ 
          continue;            // skipping zero elements out of min,max and avg calcualtion 
        }
        else {
        if(min>arr[i]){ 
            min=arr[i];
        }
        if(max<arr[i]){
            max=arr[i];
        }
        sum=sum+arr[i];
        avg=sum/(n-skip);         // Computing min, max, and average in one single loop pass
    }
    }
    cout<<"Min : "<<min<<" C    Max : "<<max<<" C    Avg : "<<round(avg)<<" C"<<endl;

    int normal=0;
    int warning=0;
    int critical=0;
    int shutdown=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=0.0){
            continue;
        }
        else if(arr[i]>0.0 && arr[i]<=29.0){
            normal++;
            continue;
        }
        else if(arr[i]>=30.0 && arr[i]<=44.0){
            warning++;
            continue;
        }
        else if(arr[i]>=45.0 && arr[i]<=59.0){
            critical++;
            continue;
        }
        else if(arr[i]>=60.0){
            shutdown++;
            continue;           // counting readings per category by using different count varaible
        }
    }

    cout<< "Normal : "<<normal << "\t Warning : " << warning << "\tCritical : "<<critical << "\t Shutdown : " << shutdown<< endl;
  
  return 0;
}