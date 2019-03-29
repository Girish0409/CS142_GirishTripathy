#include <iostream>
using namespace std;

class node {
    public:
    int data ;
    node* left ;
    node* right ;

    node (int value){
        data = value ;
        left = NULL ;
        right == NULL ;
    }
} ;

class BT {
    public:
    node* root ;
    BT (){
        root = NULL ;
    }

    void insert (int data){
        insertHelp(root,data) ;

    }

    void insertHelp(node* current , int data){
        if (current == NULL){
            current = new node (data) ;
            if (root == NULL){
                root = current ;
            }
            return ;
        }

        else if (data < current -> data){
            if (current -> left == NULL){
                current -> left = new node (data) ;
            }

            else {
                insertHelp(current->left , data) ;
            }
        }

        else {
            if (current -> right == NULL){
                current->right = new node (data) ;
            }

            else {
                insertHelp(current -> right , data) ;
            }
        }
    }

    int display(){
        display2(root) ;
    }

    int display2(node * current){
        if (current == NULL){
                        
            return 0;
        }     
            display2(current -> left) ;
            
            cout << current -> data << " "   ;
            display2(current -> right) ;
        
        
    }

    node * search (node * current , int value){
        if (current == NULL || current -> data == value ) {
                      
            return current ;
        }
               
        else if (value < current -> data){
            return search(current -> left , value) ;
        }

        else {
            return search(current -> right , value) ;
        }
    }
} ;

int main (){
    
    BT b1 ;
    b1.display() ;
    cout << endl ;
    b1.insert(4) ;
    b1.display() ;
    cout << endl ;
    b1.insert(1) ;
    b1.display() ;
    cout << endl ;
    b1.insert(2) ;
    b1.display() ;
    cout << endl ;
    b1.insert(3) ;
    b1.display() ;
    cout << endl ;
    b1.insert(6) ;
    b1.display() ;
    cout << endl ;
    b1.insert(5) ;
    b1.display() ;
    cout << endl ;
    b1.insert(7) ;
    b1.display() ;
    cout << endl ;
    if (b1.search(b1.root, 2) != NULL ) {
        cout << "FOUND" << endl ;

    }

    else {
        cout << "NOT FOUND" << endl ;
    }

    if (b1.search(b1.root, 9) != NULL ) {
        cout << "FOUND" << endl ;

    }

    else {
        cout << "NOT FOUND" << endl ;
    }
    

    
}