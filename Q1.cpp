#include <iostream>
using namespace std;

  struct node // structure having variable for data section and a pointer
  {
    int data;
    node *next;
  };

   class linkedList //  class  containing the functions to handle the nodes
  {
    private:
    node *head, *tail; //Declaring two pointers head and tail
    public:
    linkedList() // constructor initialize the value of the function into NULL
    {
      head=NULL;
      tail=NULL;
    }
    void insert(int value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {
        tail->next=temp;
        tail=temp;
      }
    }
    void insertAt(int pos,int value)//  insert element at certain position
    {
    node *cur=new node;
    node *prev=new node;
    node *temp= new node;
    cur= head;
    temp->data=value;
    if(pos<=countItems()) //count the number of elements
    {
    for(int i=1;i<pos;i++)
    { prev= cur;
     cur=cur->next;
    }
    prev->next=temp;
    temp->next=cur;}
    else
    cout<<"Linked list does not have that many elements.\n";

    }

    void Delete()// delete element at the end of list
    {
    	node*cur=new node;
    	node*prev=new node;
    	cur=head;
    	while(cur->next!=NULL)
    	{
    	prev=cur;
    	cur=cur->next;
    	}
    	tail=prev;
    	prev->next=NULL;
    	delete cur;
    }

    void deleteAt(int pos)// delete element at a certain position
    {
     node *cur=new node;
     node *prev=new node;
     node *after=new node;
     cur=head;
     if(pos<=countItems()) //To check if the list has that many elements
     {
     for(int i=1;i<pos; i++)
     {prev=cur;
      cur=cur->next;
      after=cur->next;
     }
     prev->next=after;
     delete cur;
     }
     else
     cout<<"Linkedlist does not have that many elements\n.";
    }

    int countItems() //To count the number of elements in the list
    {       int count=0;
    	node *temp=new node;
    	temp= head;
    	while(temp!=NULL)
    	{ temp=temp->next;
    	count++;
    	}
    	return count;
    }
   void display()// to display the elements
    {
    	node*temp= new node;
    	temp=head;
    	cout<<"The list is:";
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<"->";

    		temp=temp->next;
    	}
    cout<<"NULL"<<endl;
   }

  };
int main() {
 linkedList l; // Declaring object of class linkedList
 l.insert(1);
 l.insert(2);
 l.display();
 cout<<"The total number of elements in the list is "<<l.countItems()<<endl;
 l.insertAt(2,3);
 l.display();
 l.Delete();
 l.display();
 l.insertAt(2,4);
 l.display();
  cout<<"The total number of elements in the list is "<<l.countItems()<<endl;
 l.deleteAt(2);
 l.display();
 l.insertAt(5,4);
 l.deleteAt(3);
	return 0;
}
