#include <bits/stdc++.h> 
using namespace std; 
 

struct bucket
 { 
	int data; 
   bucket* next; 
   };
    
struct bucket* top; 
 
void push(int data) 
{  
	struct bucket* temp; 
	temp = new bucket(); 

	if (!temp) { 
		cout << "STACK OVERFLOW"<<endl; 
		exit(1); 
	} 

	temp->data = data; 

	temp->next= top; 

	top = temp; 
} 
 // To check if the stack is empty
int isEmpty() 
{ 
	return top == NULL; 
} 
 // To get the bucket on the top
int peek() 
{ 
	 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 

// To pop a bucket on top
void bpop() 
{ 
	struct bucket* temp; 

	
	if (top == NULL) { 
		cout << "STACK UNDERFLOW" << endl; 
		exit(1); 
	} 
	else { 
		
		temp = top; 
		top = top->next;  
		temp->next = NULL; 
		
		
		
	}
		cout<<"Your Trolly Number is :"<<top->data<<endl; 
    	cout<<"              ___"<<endl;
	    cout<<"             /  |"<<endl;
	    cout<<"  __________/--"<<endl;
	    cout<<" |__/___/__|     "<<endl;     
	    cout<<" |_/___/___|     "<<endl;     
	    cout<<"    ______/         "<<endl;
	    cout<<"     O   O           "<<endl;


} 

void display() 
{ 
	struct bucket* temp; 

	 
	if (top == NULL) { 
		cout << "\nStack Underflow"; 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL)
 { 
	cout << temp->data << " ";  
			temp = temp->next; 
		} 
	} 
} 