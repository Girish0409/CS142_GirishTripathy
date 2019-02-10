#include <iostream>
#include "Lab4_q3_queue.cpp" 
using namespace std;

class stackUsingQueue {
    public:

    queueLL q1 , q2 ; 

    void push(int x) {
        q1.enqueue(x) ;
    }

    /*void pop() {
        if (q1.isEmpty() && q2.isEmpty()){
            cout << "The stacks are empty" << endl ;
        }

        if (q2.isEmpty()){
            q2.enqueue(q1.dequeue()) ;              -----DOUBT-----
            q1.dequeue() ;
        }

        q2.dequeue() ;

        if(q1.isEmpty()){
            q1.enqueue(q2.dequeue()) ;
            q2.dequeue() ;
        }

    }
     */

    void display() {
        q1.display() ;
    }

    int size(){
        q1.size() ;
    }

    int isEmpty(){
        if (q1.isEmpty() && q2.isEmpty()){
            cout << "The stack is empty" << endl;

        }

        else{
            cout << "The stack isn't empty" << endl;
        }
    }

    /*int top(){
        q1.top() ;                --------DOUBT HERE----------
    }
    */
} ;

int main() {
    stackUsingQueue sq1 ;

    sq1.push(1) ;
    sq1.display() ;
    sq1.push(2) ;
    sq1.display() ;
    sq1.push(3) ;
    sq1.display() ;
    sq1.push(4) ;
    sq1.display() ;
    sq1.push(5) ;
    sq1.display() ;
    /*
    sq1.pop() ;
    sq1.display() ;             ------------DOUBT HERE-------------
    sq1.pop() ;
    sq1.display() ;
    */

    sq1.size() ;
    sq1.isEmpty() ;
    //sq1.top() ;

    cout << "Sir, I have doubts in other two function that i will be clearing with you" << endl;
    
    
}