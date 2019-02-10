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

    void pop(){
        l1.deleteAt(1) ;
    }
    void display(){
        l1.display() ;
    }
    void size(){
        l1.countItem() ;
    }
    void isEmpty(){
        if (l1.head == NULL){
            cout << "The linked list is empty" << endl;
        }

        else{
            cout << "The linked list is not empty" << endl;
        }
    }

    void top(){
        if (l1.head == NULL){
            cout << "The linked list is empty so no top element" << endl;
        }

        else{       
        
        cout <<"The top element of the stack is " << l1.head->data << endl ; 

        }
    }
} ; 


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

    void dequeue(){
        l1.del() ;

    }

    void display () {
        l1.display() ;
    }
    
    int size(){
        cout << "The size is " << l1.countItem() << endl;
    }

    void isEmpty(){
        if (l1.head == NULL){
            cout << "The linked list is empty" << endl ;
        }

        else{
            cout << "The linked list is not empty" << endl ;
        }
    }

    void top(){
        //node * current = end;
        while ( end -> next != NULL ){
            end = end -> next ;
        }
        cout<< " The top element is  " << end -> data << endl ;
    }

    
} ;

class stackArr {
    public:
    int array [100] ;
    int top ;

    stackArr (){
        top = -1 ;
    }

    void push (int data) {
        array[top+1] = data ;
        top ++ ;
    }

    void pop (){
        top = top - 1 ;
    }

    void display(){
        int i = 0 ;
        while (i <= top ) {
            cout << array [i] << " -> " ;
            i++ ;
        }

        cout << "NULL" << endl ;
    }

    void isEmpty(){
        if (top<0){
            cout << "The stack is empty" << endl;

        }

        else {
            cout << "The stack isn't empty" << endl;
        }

    
    }

    void topp(){
        if (top < 0){
            cout << "The stack is empty so not top element"<< endl;
        }

        else {
            cout << "THe top element is " << array[top] << endl;

        }
        
        
    }
} ;

class QueueArr {
    public:

    int Array[100] ;
    int top ;
    int end ;

    QueueArr (){
        end = -1 ;
        top = -1 ;
    }

    void enqueue (int data){
        Array[top+1] = data ;
        top ++ ;

    }

    void dequeue (){
        end ++ ;
    }

    void display (){
        int i = end + 1 ;
        while (i <= top){
            cout << Array[i] << " -> " ;
            i ++ ;            
        }

        cout << "NULL" << endl;
    }

    void size(){
        int i = end + 1 ;
        int count = 0 ;
        while (i<=top){
            count ++ ;
            i++ ;
        }

        cout << "The size of the queue is " << count << endl ;
    }

    void isEmpty() {
        if (top == end){
            cout << "The queue is empty" << endl;
            
        }


        else{
            cout << "The queue isn't empty"<< endl;
        }
    }

    void topElement() {
        if (top == end){
            cout << "The queue is empty so no top element " << endl;
        }

        else{
            cout << "The top element is " << Array[end + 1] << endl;
        }
        
        
        
    }
} ;




int main () {
    cout << "---------------------------------------QUEUE------------------------------------" << endl;
    queueLL q1 ;
    q1.enqueue(1) ;
    q1.enqueue (2) ;
    q1.enqueue (3) ;
    q1.display();
    q1.size() ;
    q1.isEmpty() ;    
    q1.dequeue();
    q1.display() ;
    q1.size() ;
    q1.dequeue();
    q1.display() ;
    q1.size() ;
    q1.dequeue();
    q1.display() ;
    q1.size() ;
    q1.isEmpty();
    q1.dequeue();
    q1.display() ;
    

    cout << "------------------------------STACK--------------------------------" << endl;

    stackLL s1;

    s1.push(1) ;
    s1.display() ;
    s1.size();
    s1.top();
    s1.push(2) ;
    s1.display();
    s1.size();
    s1.top();
    s1.push(3);
    s1.display() ;
    s1.size();
    s1.isEmpty();
    s1.top();
    s1.pop() ;
    s1.display();
    s1.size();
    s1.pop();
    s1.display();
    s1.size();
    s1.pop();
    s1.display();
    s1.size();
    s1.pop();
    s1.display();
    s1.isEmpty();
    s1.top();
    

    cout << "---------------------------STACKS--USING--ARRAY------------------------" << endl;

    stackArr s2 ;

    s2.push(1);
    s2.display();
    s2.topp() ;
    s2.push(2) ;
    s2.display();
    s2.isEmpty() ;
    s2.topp() ;
    s2.push(3);
    s2.display();
    s2.push(4) ;
    s2.display();
    s2.topp();
    s2.pop() ;
    s2.display();
    s2.topp();
    s2.isEmpty() ;
    s2.pop() ;
    s2.display();
    s2.topp() ; 
    s2.pop() ;
    s2.display();
    s2.topp() ;
    s2.pop() ;
    s2.display();
    s2.isEmpty() ;
    s2.topp() ;


    cout << "--------------------------QUEUE USING ARRAYS------------------------------" << endl;

    QueueArr q2 ;

    q2.enqueue(1) ;
    q2.display() ;
    q2.enqueue(2) ;
    q2.display() ;
    q2.size() ;
    q2.isEmpty() ;
    q2.topElement() ;
    q2.enqueue(3) ;
    q2.display() ;
    q2.enqueue(4) ;
    q2.display() ;
    q2.size() ;
    q2.isEmpty() ;  
    q2.dequeue() ;
    q2.display() ;
    q2.size() ;
    q2.topElement() ;
    q2.dequeue() ;
    q2.display() ;
    q2.dequeue() ;
    q2.display() ;
    q2.topElement() ;
    q2.size() ;
    q2.isEmpty() ;
    q2.topElement() ;
    q2.dequeue() ;
    q2.display() ;
    q2.size() ;
    q2.isEmpty() ;
    q2.topElement() ;
     
}
