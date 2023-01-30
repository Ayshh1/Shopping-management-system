#include<iostream>

#include<string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"queue1.h"
#include"stackk.h"

using namespace std;


int search(int);
int Display();
string check(int);      


struct node
 {
 	int quantity;
	int ID;
	string Name;
	double Price;
	
    struct    node* next;
};

struct node *head=NULL;


 void AddProd()
{
	system("cls");
	int id,quantityy;           
	string name;
	double pr;            //  pr for price
	struct node *t=new node;
	struct node *p=head;

	cout<<"ENTER PRODUCT ID  "<<endl;
	cin>>id;
	t->ID=id;
	cout<<"ENTER PRODUCT NAME  "<<endl;
	cin>>name;
	t->Name=name;
	cout<<"ENTER PRODUCT PRICE  "<<endl;
	cin>>pr;
	t->Price=pr;
	cout<<"ENTER PRODUCT QUANTITY  "<<endl;
	cin>>quantityy;
	t->quantity=quantityy;
	
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	else
	{
		while(p->next!=NULL)
    {
		p=p->next;
                        }
        p->next=t;
        t->next=NULL;
		
	}	
	
	system("cls");
    cout<<"THIS PRODUCT IS ADDED ";

	}


	int search(int id)                     //    for search item in list
 {
 	int i=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			i++;
 			p=p->next;
	}
 	return i;
 }


	void Delete_Product()
	{
		system("cls");
		Display();
		int id;
		struct node *cur=head;
		struct node *pre=head;
		cout<<"ENTER THE ID OF THE PRODUCT YOU WANT TO DELETE"<<endl;
		cin>>id;
		 if (head == NULL)
    {
    	system("cls");
        cout<<"THE LIST IS NOW EMPTY"<<endl;
    }
	int pos=0;
	int n=Display();               //   to load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=n){

		while(cur->ID!=id){                //  for delete middle area products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"ITEM IS DELETED"<<endl;
	}else{
		cout<<"ITEM NOT FOUND"<<endl;
	}
	}

  //To modify the price of the product
	void modify()
	{
		int id;
		double pr;        //    pr for price
		string N_ame;
		int iD; int Q;     //   N_ame for new name
		if (head == NULL)
    {
    	system("cls");
        cout<<"LIST IS EMPTY"<<endl;
    }
         else
	{    
	    Display();
		cout<<"ENTER ID OF THE PRODUCT OF WHICH THE PRICE YOU WANT TO MODIFY"<<endl;
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=Display();               //   for load no of nodes
	    pos=search(id);
	                            //   for check whether the desire node exists or not
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"OLD ID : "<<cur->ID<<endl;
		cout<<"OLD NAME: "<<cur->Name<<endl;
		cout<<"OLD PRICE: "<<cur->Price<<endl;
		cout<<"OLD QUANTITY: "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"ENTER A NEW ID:"<<endl;
		cin>>iD;
		cur->ID=iD;
		cout<<"ENTER THE NEW NAME:"<<endl;
		cin>>N_ame;
		cur->Name=N_ame;
		cout<<"ENTER NEW PRICE:"<<endl;
		cin>>pr;
		cur->Price=pr;
		cout<<"ENTER THE NEW QUANTITY:"<<endl;
		cin>>Q;
		cur->quantity=Q;
	}

	    
    {
		cout<<id<<" NOT FOUND";
	}
	}
}



int Display()
{
		system("cls");
		int i=0;             //   i for product count
		struct node *p=head;
		cout<<"EXISTING PRODUCTS ARE"<<endl;
	
		cout<<"ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
		cout<<"=================================================================|\n";
		
	ofstream new_file;
	new_file.open("new_file",ios::out);
	if (!new_file)
	{
		cout<<"FILE NOT CREATED"<<endl;
	}
	
	else
	{
		while(p!=NULL)
		{
	       
			new_file<<p->ID<<"\t\t"<<p->Name<<"\t\t\t"<<p->Price<<"\t\t\t"<<p->quantity<<"\n";
			cout<<p->ID<<"\t\t"<<p->Name<<"\t\t\t"<<p->Price<<"\t\t\t"<<p->quantity<<"\n"; //    call   
			p=p->next;
			i=i+1;
		}
		new_file.close();
		cout<<"TOTAL PRODUCTS IN OUR STORE RIGHT NOW:"<<i<<endl;
		
	    }
}
	  

	void buy()
	{
        system("cls");
        Display();
		string products[20];
		   //   To display items sold
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"THERE ARE NO ITEMS TO BUY"<<endl;
        }
	    else
        {
		cout<<"HOW MANY ITEMS DO YOU WANT TO BUY"<<endl;
		cin>>no; 
        int count=Display();           //   to store no. of nodes
		while (i<=no)
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"ENTER THE ID OF THE ITEM YOU WANT TO BUY"<<endl;
            int id,pos=0;
            cin>>id;
            if(id==-1){system("cls"); return;	}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"HOW MUCH QUANTITY OF THIS PRODUCT DO YOU WANT TO PURCHASE"<<endl;
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"THE QUANTITY YOU ENTERED IS NOT AVAILABLE"<<endl;
               cout<<"TO GO BACK TO THE MAIN MENU , PRESS -1"<<endl;
               goto a;
               
           }
           products[c]=cur->Name;   // this will contain the names of the items bought  in array; 
		   c++;   
		   
	       pay=pay+(cur->Price*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {    
             
		cout<<"THIS ITEM IS NOT AVAILABLE IN OUR STORE AT THIS TIME"<<endl;
		
	    }
}
        string customer;
        cout<<"ENTER YOUR NAME :"; cin>>customer;
        enqueue(customer);
	    system("cls");
        cout<<"YOU HAVE BOUGHT : ";
        for(int i=0;i<no;i++)
      {              //    show the item you have bought
        cout<<products[i]<<",";
       }
                  
	    cout<<" PRICE: "<<pay;
       cout<< "THANKYOU FOR SHOPPING FROM OUR STORE"<<endl;

         

         
          }
            }


 
    void administator()
	{
		system("cls");
			int ch;

 
	do {

                



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|        ADMINISTRATOR PORTAL            |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     1. ADD A NEW PRODUCT    "<<endl;
	cout<<"\t\t     2. DISPLAY ALL PRODUCTS   "<<endl;
	cout<<"\t\t     3. MODIFY EXISTING PRODUCT"<<endl;
	cout<<"\t\t     4. DELETE A SPECIFIC ITEM"<<endl;
	cout<<"\t\t     5. DISPLAY THE CUSTOMERS LIST "<<endl;
	cout<<"\t\t     6. DEQUEUE CUSTOMER"<<endl;
	cout<<"\t\t     ENTER 0 FOR MAIN MENU "<<endl;


	cout<<"ENTER YOUR CHOICE";   cin>>ch;
	switch(ch){
	case 1:
	AddProd();
	break;
case 2:
	system("cls");
    Display();
    break;
case 3:
	modify();
	system("cls");
	break;
case 4:
	Delete_Product();
cout<<"PRODUCT IS REMOVED FROM THE STORE";
	break;
case 5:
	  system("cls");
      cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  displayQueue();
	   break;
case 6:
	   system("cls");
	  cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  dequeue();
      displayQueue();
	break;


default: system("cls");

	}
}
while(ch!=0)	;
}



	                        //        Main function
int main()
{
    //adding trolleys
     for(int i=0;i<=51;i++)
     {
     
     	push(i);
	 }

        system("color f1");  //for console color
		system("color 5");     //  for console color
	cout<<"--------------------------------------------------"<<endl;
	cout<<"           SHOPPING STORE MANAGEMENT SYSTEM        "<<endl;
	cout<<"--------------------------------------------------"<<endl;
   	cout<<"|Submitted to : SIR ATIF -- |"<<endl;
   	

   	cout<< "            NAME : AYESHA SHAHZAD "<<endl;
   	cout<<"             ROLL NO : 210680"<<endl;
   	cout<<"             DSA FINAL SEMESTER PROJECT"<<endl<<endl;
    
	system("pause");
	system("cls");

    int ch;
	while(ch!=3){
	
	                     //            choice for below message

    cout<<"|--------MAIN MENU-----------|"<<endl<<endl;
	cout<<" 1.ADMINISTRATOR OF THE STORE"<<endl;
	cout<<" 2.CUSTOMER               "<<endl;
	cout<<" 3.EXIT PROGRAM                  "<<endl<<endl;



	cout<<"\ENTER YOUR CHOICE"<<endl;
	cin>>ch;
	switch(ch){
	case 1:


		administator();
		break;

	case 2:
		cout<<endl<<endl;
		bpop();
		system("pause");
	    buy();
	    break;

    case 3:
    	cout<<"    THANKYOU FOR VISITING OUR STORE!";
    	break;
   
	}
}
return 0;	

}






