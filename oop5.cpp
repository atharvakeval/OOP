/*
Develop an object oriented program in C++ to create a
database of the personnel information system containing the
following information: Name, Date of Birth, Blood group,
Height, Weight, Insurance Policy number, Contact address,
telephone number, driving licence no. etc Construct the database
with suitable member functions for initializing and destroying the
data viz constructor, default constructor, copy constructor,
destructor, static member functions , friend class, this pointer,
inline code and dynamic memory allocation operators-new and
delete.

*/
#include<iostream>
using namespace std;
 // class 
class information{
    

    char  *name,*add,*bg,*birth;        // pointer variable declaration

 
    public:

    int ht,wt,pn;

    // default constructor 
    information(){
        
    name  = new char;                   // allocating memory to pointer variable
    birth = new char;
    add  = new char; 
    bg  = new char; 

     ht = 99;
     wt = 99;
     pn = 999;
     name[0] = '0';
     add[0] = '0';
     bg[0] = '0';
     birth[0] = '0';
   
    }


    void accept();
    void display();
    

    void modify(){
    
    int ch =9,n;
            cout <<"record is found"<<endl;

            while(ch!=0){

             cout<<"Select the number for Which changes you want to do\n";
            cout<<"0.Exit\n";
            cout<<"1.Height\n";
            cout<<"2.Weight\n";
            cout<<"3.Address\n";
            cin >> n;
            switch(n){
                case 0:
                        ch = 0 ;
                        break;
                case 1:
                        cout<<"Enter a height";
                        cin >> ht;
                        break;
                case 2:
                        cout<<"Enter a weight";
                        cin >> wt;
                        break;
                case 3:
                        cout<<"Enter a address";
                        cin >> add;
                        break;
                default:
                    cout <<"Wrong choice Try Again!";
                    break;
            }


            }
         

    }

   


    // friend  function 

 friend  void search(information *s, int);

 //  destructor to destroy object aretate by the constructor

 ~information(){
    delete[] name;
    delete[] add;
    delete[] bg;
    delete[] birth;
 }

};


// method defination outside the class

void information ::accept(){
    cout <<"Enter the name: ";
    cin >> name;
    cout <<"Enter the date of birth: ";
    cin >> birth;
    cout <<"Enter the blood group: ";
    cin >> bg;
    cout <<"Enter the Height: ";
    cin >> ht;
    cout <<"Enter the Weight: ";
    cin >> wt;
    cout <<"Enter the policy number : ";
    cin >> pn;
    cout <<"Enter the address: ";
    cin >> add;
}


// use of inline function:

inline void information::display(){

    cout << name<<"\t "<<birth<<"\t  "<< bg <<"\t\t "<<ht<<" \t"<<wt<<"\t"<<pn<<"\t   "<<add<<endl;
}

inline void search(information *s,int p){
    

    for(int i=0;i<10;i++){

    if(p == s[i].pn){
        cout <<"record is present"; 
        break;
    }
    else    
        cout<<"record is not present";;

    }
}



    
 // class object defination outside the class
    information s[10];
   

int main(){



    int ch =2 , choice;
    int count;

    while(ch  != 0){

        cout <<"\n Menu";
        cout <<"\n 0.Exit";
        cout <<"\n 1. Accept the information";
        cout <<"\n 2. Display the record";
        cout <<"\n 3. Search for the record";
        cout <<"\n4. modify record";
        cout <<"\n5. Delete record \n";
        cin >> choice;

        switch (choice){

            case 0:
                ch = 0; 
                break;
            case 1:
            
                cout <<"Enter how many record you want to create: ";
                cin >> count;
                for(int i=0;i<count;i++){
                    s[i].accept();
                }
                break;
            case 2:

                    cout << "\nname\tdate of birth\tblood group\theight\tweight\tpolicy number\taddress" <<endl;
                     for(int i=0;i<10;i++){
                        s[i].display();
                     }
                     break;
            case 3: 
                    int p;
                    cout <<"Enter the policy number for referance: ";
                    cin >> p;
                    search(s,p);
                    break;  
            case 4:
                    int pn;
                    cout <<"Enter the policy number for modify the record";
                    cin >> pn;

                    for(int i=0;i<count;i++){

                        if(s[i].pn == pn)
                        {
                            s[i].modify();
                            break;
                        }
                    }
                    break;
            case 5:

                    int an;
                    cout <<"Enter the policy number to delete  the record";
                    cin >> an;

                    for(int i=0;i<count;i++){

                        if(s[i].pn == an)
                        {
                            while(i < count){
                                  s[i] = s[i+1];
                                  i++;

                               }
                             count--;
                             cout<<"Record deleted successfully";
                            break;
                        }
                    }
                    break;

                    

            default:
                cout << "Wrong Choice , Please Try again !"; 
                break;               

        }

    }



    return 0;
}
