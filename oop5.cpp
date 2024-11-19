#include<iostream>

using namespace std;
int rno;

class parent
{
public:
string des,name;
int id,sal;
virtual void accept()=0;
virtual void display()=0;  
};

class doctor: public parent
{
public:
void accept();
void display();
};

class staff: public parent
{
public:
void accept();
void display();
};

class patient:public parent
{
public:
int bill;
void accept();
void display();
};

void doctor::accept()
{
    cout<<"\n enter the Id,Name, Designation And Salary";
    cin>>id>>name>>des>>sal;
}

void staff::accept()
{
    cout<<"\n enter the Id,Name, Designation And Salary";
    cin>>id>>name>>des>>sal;
}

void patient::accept()
{
    cout<<"\n enter the Id,Name, Designation And bill";
    cin>>id>>name>>des>>bill;
    
}

void doctor::display()
{
    cout<<id<<"\n"<<name<<"\n"<<des<<"\n"<<sal<<"\n";
}

void staff::display()
{
    cout<<id<<"\n"<<name<<"\n"<<des<<"\n"<<sal<<"\n";
}

void patient::display()
{
    cout<<id<<"\n"<<name<<"\n"<<des<<"\n"<<bill<<"\n";
}

int main()
{
    doctor d;
    patient p;
    staff s;

    d.accept();
    d.display();

    s.accept();
    s.display();

    p.accept();
    p.display();

    return 0;
 }