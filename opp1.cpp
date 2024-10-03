#include <iostream>
#include <cstring>
int n,i=0;
using namespace std;

class IPPB {
private:
    double balance;
    int age;
    char name[25];
    int  pin;

public:
       int accno;
       IPPB()
       {
       balance=0.0;
       age=0;
       strcpy(name,"MYbank");
       pin=100;
       }
    

    void Create();

    void Deposit() {
        int amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void CheckBalance() {
        int enterpin;
        cout <<"Enter the pin";
        cin >> enterpin;
        if(enterpin != pin){
        cout << "Invalid PIN." << endl;
	return;
        }
        cout << "Balance: " << balance << endl;
    }

    void Withdraw() {
        int amount, enteredPin;
        cout << "Enter the amount to Withdrawal: ";
        cin >> amount;
        
           cout << "Enter your PIN: ";
        cin >> enteredPin;
        if (enteredPin != pin) {
            cout << "Invalid PIN." << endl;
            return;
        }  
        
        if(balance <=0){
            cout << "Invalid Balance to withdraw";
        }
        
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
            return;
        }
     
        balance -= amount;
        cout << "Withdrawal successful. remaining balance: " << balance << endl;
    }

    void DisplayAccountDetails()  {
    
        	cout << "\t"<< name << "\t" << age << "\t" << accno << "\t" << balance << endl;
}


}m[100];	//  array of object ;



// function defination outside the class ;

void IPPB ::Create(){
	cout << "Enter the bank holder name: ";
        cin.ignore(); // Ignore any newline left in the input buffer
        cin >> name;
        cout << "Enter the age: ";
        cin >> age;
        cout << "Enter the initial deposit amount: ";
        cin >> balance;
        cout << "Enter the bank account number: ";
        cin >> accno;
        cout << "Enter the 4-digit PIN number: ";
        cin >> pin;
}



int main() {
    int ch,choice=1;
    bool found = false;
    cout << "enter how many account you want to create:";
    cin >> n;
    
    for(i=0;i<n;i++){
    			
    		cout <<"enter the details of "<< i+1 <<" person."<<endl;	
    		m[i].Create();
    
    } 
    
    cout << "Enter the account number to operate on: ";
        IPPB* currentacc = nullptr;
        int accnumber;
        cin >> accnumber;
    
for(int i=0;i<n;i++){
    	
if(m[i].accno == accnumber)
{
        currentacc = &m[i];
        break;
}
}

if( currentacc == nullptr){
    		cout << "account is not found" << endl;
    		return 0;
}
    	
    while(choice != 6){
    		//found = true;
    		//break;
    		
    		cout << "\n Menu:";
    		cout << "\n 1.Deposit the amount";
    		cout << "\n 2.Check balance";
    		cout << "\n 3.Withdraw";
    		cout << "\n 4.Display Account Details";
    		cout << "\n 5.Display All Account Details";
    		cout << "\n 6.Exit";
    		cout << "\nEnter the choice:";
    		cin >> ch;
    	
    			switch(ch){
    				case 1:
    					currentacc->Deposit();
    					break;
    				case 2:
    					currentacc->CheckBalance();
    					break;
    				case 3:
    					currentacc->Withdraw();
    					break;
    				case 4:
    					cout <<"\t" <<"Name" <<"\t" <<"Age" <<"\t" <<"Acc.number"<<"\t" <<"Balance" << endl;
    					currentacc->DisplayAccountDetails();
    					break;
    				case 5:
    					cout <<"\t" <<"Name" <<"\t" <<"Age" <<"\t" <<"Acc.number"<<"\t" <<"Balance" << endl;
    					for(int i=0;i<n;i++){
    					    m[i].DisplayAccountDetails();
    					}
    					break;
    				case 6 :
    					    choice =6;
    					    break;
    				default :
    					cout << "invalid choice";
   					break;
    				
    		}
    		
    		}
    

    return 0;
}

