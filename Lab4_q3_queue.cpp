#include <iostream>
#include "lab4_q1_LL.cpp"
using namespace std;



class queueLL {
    public:
    node * end ;
    linkedList l1;

    queueLL (){
        end = l1.head ;
    }

    void enqueue (int data) {
        l1.insertAt(1 , data)  ;
        
    }

    int dequeue(){
        return (l1.del()) ;

    }

    void display () {
        l1.display() ;
    }
    
    int size(){
        cout << "The size is " << l1.countItem() << endl;
    }

    bool isEmpty(){
        if (l1.head == NULL){
            return true ;
        }

        else{
            return false ;
        }
    }

    void top(){
        node * current = end;
        while ( current->next != NULL ){
            current = current -> next ;
        }
        cout<< " The top element is  " << current -> data << endl ;
    }

    
} ;

