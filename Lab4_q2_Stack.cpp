#include <iostream>
#include "lab4_q1_LL.cpp"
using namespace std;

class stackLL {
    public:
    node * end ;
    linkedList l1;
    stackLL (){
        end = l1.head;
    }

    void push (int data){
        l1.insertAt(1,data) ;
    }

    int pop(){
        l1.deleteAt(1) ;
    }
    void display(){
        l1.display() ;
    }
    int size(){
        l1.countItem() ;
    }
    bool isEmpty(){
        if (l1.head == NULL){
            return true ;
        }

        else{
            return false ;
        }
    }

    int top(){
        if (l1.head == NULL){
            cout << "The linked list is empty so no top element" << endl;
        }

        else{       
        
        return (l1.head->data) ;

        }
    }
} ; 






