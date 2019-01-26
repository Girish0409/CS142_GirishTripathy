//include libraries
#include <iostream>
using namespace std;


//definning a node
class node {
    public:
    int data ;
    node * next ;

    node (int a){
        next = NULL ;
        data = a ;
    }
} ;

//defining a linked list circular 
class CircularLinkedList {
    public:
    node * head ;

    CircularLinkedList (){
        head = NULL ;
    } 

//Defining insert function

    void insert (int a){
        node * temp = new node(a) ;
        
        if (head == NULL){
            head = temp ;
        }

        else {
            node * current = head ;
            while (current -> next != head) 
                current = current -> next ;
                current -> next = temp ;
        
        }
            temp -> next = head ;
        
    }

//defining insertAt function

    void insertAT(int pos, int a) {
        node * current = head ; 
        int i = 1 ; 

        while (i<pos-1){
            current = current -> next ; 
            i++ ;
        }

        node * temp = new node(a) ; 
        

        if (head == NULL) {
            head = temp ; 

        }

        else {
            temp -> next = current -> next ;
            current -> next = temp ;
        }

    }

//defining delete function
    
    void del(){
        node * current = head ; 
        node * temp ; 

        if (head==NULL){
                    
        }

        if (head->next == head){ 
            head = NULL ;
        }

        else{
            while (current -> next -> next != head){ 
                current = current -> next ;
            }
        }

        temp = current -> next ;
        current -> next = head ;
        delete temp; 
    }

//defining deleteAt function

    void deleteAt(int pos){
        node * current = head ;
        node * temp ;

        if (head==NULL){
                   
        }

        if (head->next == head){
            head = NULL ;

        }

        else {
            int i=1 ;
            while ( i < pos-1){
                current = current -> next ;
                i++ ;
            }
        }

        temp = current -> next ; 
        current -> next = temp -> next ; 
        temp -> next = NULL ; 
        delete temp ;


    }


//defining print function

    void print (){
        node * current = head ;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while (current -> next != head){
            cout << current -> data << " -> " ;
            current = current -> next ;
        }

        cout << current -> data << endl ;
    }

//defining function count items

    void countItem(){
        int count = 0 ;
        node * current = head; 

        while (current->next !=head) {
            count ++ ;
            current = current -> next ;
        }
        count = count + 1 ;

        cout << "No. of nodes in the linked list is " << count << endl ;
    }



 };

 int main(){
    CircularLinkedList c1 ;
    cout << "Inserting nodes in the circular linked list" << endl ;
    c1.insert (1) ;
    c1.insert(2) ;
    c1.insert(3);
    c1.insert(4) ;
    c1.insert(5) ;
    c1.insert(6) ;
    c1.print() ;
    cout << "Inserting node in the 2nd position" << endl ;
    c1.insertAT(2,8) ;
    c1.print () ;
    cout << "Deleting the last element of the linked list" << endl ;
    c1.del() ;
    c1.print() ;
    cout << "Deleting th 3rd elementof the linked list" << endl ;
    c1.deleteAt(3);
    c1.print();
    c1.countItem() ;
    
 }