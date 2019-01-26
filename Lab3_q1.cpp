//including libraries
#include <iostream>
using namespace std;

//creating a node class
class node {
    public: //accessibke to public
    int data ; //data section of the node
    node * next ; // next link of the node
    node * prev ; //previous link of the node

    node (){
        next = NULL ; //by default both pointers pointing to null
        prev = NULL ;
    }
} ;

//defining a class doubly linked list

class DoubleLinkedList {
    public:
    node * head ; //head pointer of the DLL

    DoubleLinkedList (){
        head = NULL ; //by default head pointing to NULL
    }

//defining insert function with parameter data

    int insert(int a){
        node*temp = new node ;
        temp -> data = a ;
        if (head == NULL) {
            head = temp ;
        }

        else {
            node * current = head ;
            while (current -> next != NULL) {
                current = current -> next ;
            }

            current -> next = temp ;
            temp -> prev = current ;
        }
    }

//defining insertAt funtion with position and data as parameter

    int insertAt(int pos , int a){
        node * current = head ; 
        int i = 1 ; 

        while (i < pos-1){
            current = current -> next ;
            i++ ;
        }
        
            node * temp = new node ;
            temp -> data = a ;

            if (head == NULL) {
                head = temp;
            }

            else {
            
            temp -> next = current -> next ;
            current -> next = temp ;
            temp -> prev = current ;

            current = current -> next ;

            current -> prev = temp ;
            }
            
        

    }

//defining delete function

    int del () {
        node * current = head ; 

        if (head==NULL){
                    
        }

        if (head->next == NULL){ 
            head = NULL ;
        }

        else {
            node * current = head ;
            node * temp ;

            while ( current -> next -> next != NULL ) {
                current = current -> next ;
            }

            temp = current -> next ;
            current -> next = NULL ;
            delete temp ;
        }
    }

//Defining deleteAT funtion with positon as parameter

    int deleteAT (int pos){
        node * current = head ;
        node * temp ;

        if (head == NULL){

        }

        if (head->next == NULL){
            head = NULL ;
        }

        else {
            node * current = head ;
            int i = 1 ;

            while (i<pos-1){
                current = current -> next ;
                i++ ;
            }

            temp = current -> next ;
            current -> next = temp -> next ;
            temp -> next = NULL ; 
            current -> next -> prev = current ;
            temp -> prev = NULL ;
          
            delete temp ; 

        }
    }

//Defining count items function

    int countItems(){
        node * current = head ;
        int count = 0 ;
        while (current != NULL) {
            current = current -> next ;
            count ++ ;
        }

        return count ;
    }



//defining print function

    void print (){
        node * current ;
        current = head;
        while (current != NULL ){
            cout << current -> data << " -> "  ;
            current = current -> next ;
        }

        cout << "NULL" << endl ;
    }

} ;



    

int main (){
    DoubleLinkedList d1 ;
    cout << "Inserting data nodes in the Double Linked lists" << endl ;
    d1.insert (1) ;
    d1.insert (2) ;
    d1.insert (6) ;
    d1.insert (8) ;
    d1.insert (9) ;
    d1.insert (2) ;
    d1.insert (3) ;
    d1.insert(4) ;
    d1.print () ;
    cout << "Inserting data node in the 3rd position" << endl ;
    d1.insertAt(3 , 7) ;
    d1.print () ;
    cout << "Deleting last node"<< endl ;
    d1.del() ;
    d1.print();
    cout << "Deleting node in the second position" << endl ;
    d1.deleteAT(2) ;
    d1.print() ;

    cout << "Number of nodes in the double Linked list is " << d1.countItems() << endl ;
    
    
}