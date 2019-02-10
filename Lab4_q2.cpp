#include <iostream>
#include "Lab4_q2_Stack.cpp"
using namespace std;

class queueUsingStack {
    public:

    stackLL s1, s2 ;

    void enqueue (int x){
        s1.push(x) ;
    }

    void dequeue(){
        
        if (s1.isEmpty() && s2.isEmpty()){
            cout << "The queue is empty" << endl;
        }

        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.top()); 
                s1.pop(); 
                
            }
        }

        s2.pop() ;

        if(s1.isEmpty()){
            while(!s2.isEmpty()){
                s1.push(s2.top()) ;
                s2.pop() ;
            }
        }

          
    }

    void display(){
        s1.display() ;
    }

    int top(){
        cout << "The top element is " << s1.top() << endl ;

    }

    void isEmpty(){
        if (s1.isEmpty() && s2.isEmpty()){
            cout << "The queue is empty" << endl ;
        }

        else {
            cout << "The queue is not empty" << endl ;
        }
    }

    int count () {
       return ( s1.size() );
    }

    
} ;

int main (){
    queueUsingStack qs1 ;

    qs1.enqueue(1) ;
    qs1.display() ;    
    qs1.enqueue(2) ;
    qs1.display() ;
    qs1.enqueue(3) ;
    qs1.display() ;
    qs1.top() ;
    qs1.dequeue() ;
    qs1.display();
    qs1.enqueue(4) ;
    qs1.display() ;
    qs1.top() ;
    qs1.enqueue(5) ;
    
    qs1.display() ;
    cout << "The size of the queue is " << qs1.count() << endl;
    qs1.isEmpty() ;
    qs1.dequeue() ;
    qs1.display() ;
    qs1.top() ;
    qs1.dequeue() ;
    qs1.display() ;
    qs1.top() ;
    qs1.dequeue() ;
    qs1.display() ;
    qs1.top() ;
    qs1.dequeue() ;
    qs1.display() ;   
    qs1.isEmpty() ;
    
    
}