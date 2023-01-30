#include <iostream>
#include<conio.h>
using namespace std;

// Structure of Node.
struct Node
{
string data;
Node *next;
};

Node *front = NULL;
Node *rear = NULL;

//Function to check if queue is empty or not
bool isempty()
{
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}

//function to enter elements in queue
void enqueue ( string name )
{
 Node *ptr = new Node();
 ptr->data= name;
 ptr->next = NULL;

 //If inserting the first element/node
 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->next = ptr;
  rear = ptr;
 }
}

//function to delete/remove element from queue
void dequeue ( )
{
 if( isempty() )
 cout<<"QUEUE IS EMPTY"	<<endl;
 else
 //only one node in queue.
 if( front == rear)
 {
  
  front = rear = NULL;
 }
 else
 {
  Node *ptr = front;
  front = front->next;
  
 }
}




//function to display queue
void displayQueue()
{  
 if (isempty())
  cout<<"QUEUE IS EMPTY"<<endl;
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
   cout<<"\t"<<ptr->data<<"\t  "<<endl;
   ptr= ptr->next;
  
  }
 }
 
}
//function to show the element at front
void showfront( )
{
 if( isempty())
 cout<<"QUEUE IS EMPTY"<<endl;
 else
 cout<<"ELEMENT AT FRONT IS:"<<front->data<<endl;
}

