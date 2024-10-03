/******************************************************************************

Create a class named weather report that holds a daily weather report
with data member’s day_of_month, hightemp, lowtemp, amount_rain
and amount_snow. The constructor initializes the fields with default
values: 99 for day_of_month, 999 for hightemp,-999 for low emp and 0
for amount_rain and amount_snow. Include a function that prompts the
user and sets values for each field so that you can override the default
values. Write a C++ program that creates a monthly report. a) Menu driven program with options to Enter data and Display report
b) Report Format
Day High_ Temp Low_Temp Amt_snow Amt_Rain
Av
*******************************************************************************/
#include <iostream>
using namespace std;
int n;
class weather_report

{
public:
    int day_of_month,hightemp,lowtemp,amount_rain,amount_snow;

    
/*weather_report(int day = 99, int high = 999, int low = 999, int rain = 0, int snow = 0) 
     {
        day_of_month = day;
        hightemp = high;
        lowtemp = low;
        amount_rain = rain;
        amount_snow = snow;
    }
  */  
    weather_report() 
     {
        day_of_month = 99;
        hightemp = 999;
        lowtemp = -999;
        amount_rain = 0;
        amount_snow = 0;
    }
    void enter_report(){
        
        
        cout << "Enter the date:";
        cin >> day_of_month;
        cout << "Enter the Highest Temp. :";
        cin >> hightemp;
        cout << "Enter the Lowest Temp. :";
        cin >> lowtemp;
        cout << "Enter the amount of snow:";
        cin >> amount_snow;
        cout << "Enter the amount of rain:";
        cin >> amount_rain;

    }
    void Display(){
        cout <<"\t\t" <<  day_of_month << "\t\t" << hightemp <<"\t\t" << lowtemp <<"\t\t" <<amount_snow <<"\t\t" << amount_rain <<"\t"<<endl;
        
    }
    
    ~weather_report()
    {
        cout<<"\n object is destroyed";
    }
    

}m[10];

void Avg(){
        int htemp=0,ltemp=0,snow=0,rain=0;
       for(int i=0;i<n;i++){
         htemp += m[i].hightemp;
         ltemp += m[i].lowtemp;
         snow += m[i].amount_snow;
         rain += m[i].amount_rain;
        }
        
        float a_htemp,a_ltemp,a_snow,a_rain;
        
        a_htemp = htemp/n;
        a_ltemp = ltemp/n;
        a_snow = snow/n;
        a_rain = rain/n;
        
        cout <<"\t\tAvg:\t\t"<<a_htemp<<"\t\t"<<a_ltemp<<"\t\t"<<a_snow<<"\t\t"<<a_rain;

    
}


int main()
{
    int ch=1,choice;
    while(ch != 3){
        
        cout << "\n1.Enter the Report of weather" << endl;
        cout << "\n2.Display weather Report" << endl;
        cout << "\n3.Exit" << endl;
        cout << "enter the choice:";
        cin >> choice;
        
        switch(choice){
            
            case 1:
                    cout << "how many days report you want to insert:";
                    cin >> n;
                    for(int i=0;i<n;i++){
                        m[i].enter_report();
                    }
                    break;
            case 2:
                    cout << "\t\tDay\t" <<"     High Temp\t" <<"     Low Temp\t" <<"     Amt_snow\t" <<"     Amt_rain\n"<<endl;
                    for(int i=0;i<10;i++){
                        m[i].Display();
                    }
                    cout <<"\n\n";
                        Avg();
                    cout <<"\n";
                    break;
            case 3:
                    ch =3;
                    break;
            default:
                    cout <<"wrong choice";
                    break;
                
        }
    }

    return 0;
}