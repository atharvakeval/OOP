#include <iostream>
#include <cmath> 
using namespace std;
int n;
class student
{
    public:
    int rno;
    string name,prn,branch;
    void basic_details();
    void display();
};

void student::basic_details()
{
    cout<<"Enter Name and Department: ";
    cin>>name>>branch;
    cout<<"Enter Roll No and Prn:";
    cin>>rno>>prn;
}

void student::display()
{
    cout<<"Name"<<"\t"<<"Department"<<"\t"<<"Roll No"<<"\t"<<"PRN NO"<<endl;
    cout<<name<<branch<<rno<<prn;
}

class test: virtual public student
{
    public:
    string sub[5];
    int C1[5],C2[5],C3[5],end[5];
    void accept_marks();
    void display();
};

void test::accept_marks()
{
    for(int i=0;i<5;i++)
    {
    cout<<"Enter the  subject name :";
    cin>>sub[i];
    cout<<"Enter CIA-1 marks: ";
    cin>>C1[i];
    cout<<"Enter CIA-2 marks:";
    cin>>C2[i];
    cout<<"Enter CIA-3 marks:";
    cin>>C3[i];
    cout<<"Enter the End-Sem examination marks:";
    cin>>end[i];
    }
}

void test::display()
{
     for(int i=0;i<5;i++)
     {
        cout<<"Subject"<<"\t"<<"CIA-1 Marks"<<"\t"<<"CIA-2"<<"\t"<<"CIA-3"<<"\t"<<"End-Sem Marks";
         cout<<"\n"<<sub[i]<<"\t"<<C1[i]<<"\t"<<C2[i]<<"\t"<<C3<<"\t"<<"\t"<<end[i];
     }
}

class sport: virtual public student{
    public:
    string sport;
    int S_marks;
    void accept_sport();
    void display();
};

void sport::accept_sport()
{
    cout<<"Enter the Sport name:";
    cin>>sport;
    cout<<"Enter the marks of Sport:";
    cin>>S_marks;
}

void sport::display()
{
    cout<<"Sport name"<<"\t"<<"\t"<<"marks";
    cout<<sport<<S_marks;
}

class result:public test, public sport
{
    public:
    int tot[5],C[5],C_tot[5];
    int overall=0;
    int per;
    void percent();
    void total();
    void display_all();
   
}a[100];

void  result::total()
{
    for(int i=0;i<5;i++)
    {
        C[i]= C1[i]+C2[i]+C3[i] ;
        C_tot[i]=C[i]/1.5;
        tot[i]=C_tot[i]+end[i];
        overall+=tot[i];
    }
    overall+=S_marks;
}

void result::percent()
 {
    for(int i=0;i<5;i++)
    {
     per=(float(overall)/600)*100;
    }
}

void result::display_all()
    {
        cout<<"Name"<<"\t"<<"Branch"<<"\t"<<"PRN no"<<"\t"<<"Roll No\n";
        cout<<name<<"t"<<branch<<"\t"<<rno<<"\t"<<prn<<"\n";
        cout<<"Subject"<<"\t"<<"CIA-1 Marks"<<"\t"<<"CIA-2"<<"\t"<<"CIA-3"<<"\t"<<"End-Sem Marks"<<"\t"<<"Total\n";
        for(int i=0;i<5;i++)
        {
            cout<<sub[i]<<"\t"<<C1[i]<<"\t"<<C2[i]<<"\t"<<C3[i]<<"\t"<<end[i]<<"\t"<<tot[i]<<"\t"<<"\n";
        }
        cout<<sport<<"\t"<<"0"<<"\t"<<"0"<<"\t"<<"0"<<"\t"<<S_marks<<"\t"<<S_marks<<"\n";
        cout<<"Total percentage is"<<per<<"%";
    }


int main()
{
    cout<<"Enter the number of students record you want to store:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the"<<n<<"number student record:"<<endl;
        a[i].basic_details();
        a[i].accept_marks();
        a[i].accept_sport();
        a[i].total();
        a[i].percent();
        a[i].display_all();
    }
    return 0;
}