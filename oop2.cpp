/*A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a 

customer wants a book,the sales person inputs the title and author and the system searches the list and displays whether it is available or not. If it is not, an appropriate message 

is displayed.If it is, then the system displays the book details and requests for the number of copies required. If the requested copies book details and requests for the number of 

copies required.If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message “Required copies not in stock” is displayed. Design 

a system using a class called books with suitable member functions and Constructors. Use new operator in constructors to allocate memory space required. Implement C++ program for the
system.
*/
#include <iostream>
#include<cstring>
int n;
using namespace std;

class books{
public:
	int copies;
	double cost;
	char *tt,*aut,*pub;
	void add_stock();
//	void sale_book();
	void display_stock();

}b[100];

// method defination;
 void books:: add_stock(){
     
    tt = aut = pub = new char;
	
	cout << "Enter the title of the book: ";
	cin >> tt; 
	cout << "Enter the author of the book: ";
	cin >> aut;
	cout << "Enter the publisher name: ";
	cin >> pub;
	cout << " enter the price of the book: ";
	cin >> cost;
	cout << "Enter the copies of the book: ";
	cin >> copies;
 
 }
 
// display stock
void books::display_stock(){
	
	
	cout<<"\t "<<tt<<"\t "<<aut<<"\t   "<<pub<<"\t\t"<<cost<<"\t "<<copies<<"\t"<<endl;
	

} 
 // sale book
void sale_book(){
     string title;
     string author;
     bool f = false;
     int requestedcopies,k;
     
    cout << "enter the title and author name :";
    cin >> title >> author;
    cout << "\tTitle\tAuthor\tPublisher\tCost\tCopies" << endl;
    
    for(int i=0;i<n;i++){
        if(b[i].tt == title && b[i].aut == author){
             k = i;
            b[i].display_stock();
            f = true;
            break;
        }
    }
    if(!f){
        cout << "book is not available";
        return ;
    }
    
    cout << "Enter how many copies you want to buy:";
    cin >> requestedcopies;
    
    if(requestedcopies <= b[k].copies){
        
        cout << "total price of books is : " << b[k].cost * b[k].copies;
        b[k].copies -= requestedcopies;
        
    }
    else{
        cout <<"Required copies not in stock";
    }

    
}
 
 
 
 int main(){

	int ch=1,choice;
	while(ch != 4){
	    
	    
	    cout<<"\nMenu:";
	    cout<<"\n1.Enter a books in stock";
	    cout<<"\n2. display total books available in stock";
	    cout<<"\n3.Buy books";
	    cout<<"\n4.Exit";
	    cout<<"\nEnter the choice:";
	    cin>>choice;
	    
	    switch(choice){
	
	        case 1:
	                cout << " How many book stock you want to add ?:";
 	                cin >> n;
 	                for(int i=0;i<n;i++){
 		                  b[i].add_stock();
 	                }
 	                break;
 	       case 2:
 	                cout << "\tTitle\tAuthor\tPublisher\tCost\tCopies" << endl;
	                for (int i=0;i<n;i++){
                            b[i].display_stock();
	                }
	                break;
	                
	       case 3:
	               sale_book();
	               break;
	               
	       case 4:
	                ch=4;
	                break;
	       default:
	                cout<<"wrong choice.";
	                break;
 	  }
	}
 
 
	return 0;
 }