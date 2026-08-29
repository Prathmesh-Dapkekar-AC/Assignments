#include<iostream>
using namespace std; 

int statuscode(double range){
    if(range<=0){
        return -1;
    }
    else if(range>0 && range<=29){
        return 0;
    }
    else if(range>30 && range<=44){
        return 1;
    }
    else if(range>45 && range<=59){
        return 2;
    }
    else
        return 3;
}

void printaction(int num){

    switch(num){
        case -1:
        cout<<"Status      : SENSOR_ERROR"<<endl;
        cout<<"Action      : Cooling System Triggered"<<endl;
        break;
        case 0:
        cout<<"Status      : NORMAL"<<endl;
        cout<<"Action      : No Action Required"<<endl;
        break;
        case 1:
        cout<<"Status      : WARNING"<<endl;
        cout<<"Action      : Alert Sent To Supervisor"<<endl;
        break;
        case 2:
        cout<<"Status      : CRITICAL"<<endl;
        cout<<"Action      : Cooling System Triggered"<<endl;
        break;
        default:
        cout<<"Status      : SHUTDOWN"<<endl;
        cout<<"Action      : Emergency Shutdown Initiated"<<endl;
        break;
    }
}


int main(){
    double reading;
    cout<<"Enter the reading : ";
    cin>>reading; 

    cout <<"Temperature : " << reading <<" C / " <<(reading * 9 / 5) + 32<< " F"<<endl; // Temperature to Farenheit Conversion
    int code = statuscode(reading); // Function Call for Deriving Statuscode
    printaction(code); // Function Call for Printing Action
    (reading>25)?cout<<"Reading     : Above Average":cout<<"Reading     : Below Average"; // Used Ternary Operator to check and print reading
    
    return 0;
}