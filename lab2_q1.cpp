//including libraries
#include <iostream>
using namespace std;

//defining a class node
class node {
    public: //public access to the class

    int data ; //data section of the node
    node * next ; //a pointer next pointing to a node

    node (){
        next = NULL ; //constructor node where next point to NULL by default
    }
} ;

//Defining a class linked list

class linkedList {
    public:
    node * head ; //head is a pointer and only variable in the linked list

    linkedList (){
        head = NULL ; //Head pointing to NULL by default
    }

//defining a insert function

    void insert (int a){
        node * temp = new node ; //a new node is created whenever this function is called
        temp->data = a ; //assigning value to the data section of the node ;

        if (head == NULL) {
            head = temp ; //if linked list is empty then the head hold the address of temp

        }

        else {
            node*current = head ; //if linked list is not empty we have to use loop to reach the end of the linked list
            while (current->next != NULL){
                current = current->next ;
            }
            current->next = temp ;
        }
    }

//Defining insertAt function

    void insertAt (int pos, int data){
        node * current = head ; //current is a pointer pointing to the head

        int i = 1 ; //initiating i

        while (i<pos-1){
            current = current -> next ; //looping till i<position - 1
            i++ ;
        }

        node * temp = new node ; //forming a new node 
        temp->data = data ;

        if (head == NULL) {
            head = temp ; //if linked list is empty then the head hold the address of temp

        }

        else {
            temp -> next = current -> next ;
            current -> next = temp ;
        }


        
    }

//defining delete function

    void del(){
        node * current = head ; //current pointer pointing to head
        node * temp ; //temp pointer

        if (head==NULL){
                    //if head is already pointing to null so all is well brrooooo
        }

        if (head->next == NULL){ 
            head = NULL ;
        }

        else{
            while (current -> next -> next != NULL){ //looping to get to the right pos
                current = current -> next ;
            }
        }

        temp = current -> next ;
        current -> next = NULL ;
        delete temp; 
    }


// defining deleteAt function

    void deleteAt(int pos){
        node * current = head ;
        node * temp ;

        if (head==NULL){
                   //if head is already pointing to null so all is well brrooooo
        }

        if (head->next == NULL){
            head = NULL ;

        }

        else {
            int i=1 ;
            while ( i < pos-1){
                current = current -> next ;// looping to get the right pos
                i++ ;
            }
        }

        temp = current -> next ; //deleting link between current and the node to be  deleted
        current -> next = temp -> next ; //making link between the current and node succeeding the to-be-deleted node
        temp -> next = NULL ; //making the to-be-deleted node point to NULL
        delete temp ;


    }

//defining function count items

    void countItem(){
        int count = 0 ;
        node * current = head; 

        while (current!=NULL) {
            count ++ ;
            current = current -> next ;
        }

        cout << "No. of nodes in the linked list is " << count << endl ;
    }

//defining print function

    void display (){
        node * current ;
        current = head ; //node current 

        while (current != NULL){
            cout << current->data << " -> " ;
            current = current -> next ;
        }
        cout << "NULL" << endl ;
    }

};



int main(){
    linkedList l1 ;
    cout << "Adding nodes in the linked list with values" << endl ;
    l1.insert(1);
    l1.insert(2);
    l1.insert(7);
    l1.insert(9);
    l1.insert(2);
    l1.insert(5);
    l1.display();
    cout << "Inserting value 3 at position 2 and value 4 and position 3" << endl;
    l1.insertAt(2,3) ;
    l1.insertAt(3,4) ;
    l1.display();
    cout << "Deleting last element of the list " << endl ;
    l1.del() ;
    l1.display();
    cout << "Deleting elememnt at position 4 " << endl ;
    l1.deleteAt(4);
    l1.display();
    l1.countItem();
 
    return 0;
} 
