#include <iostream>
using namespace std;

class BTnode {
    public:
    int data ;
    BTnode * left ;
    BTnode * right ;
    BTnode * parent ;

    BTnode (int value){
        data = value ;
        left = NULL ;
        right = NULL ;
        parent = NULL ;
    }
} ;

class BT{
    public:

    BTnode* root ;

    BT(){
        root = NULL ;
    }

    void insert(int data){
        insertHelp(root , data) ;
    }

    void insertHelp(BTnode * current , int data){
        if (current == NULL){
            current = new BTnode(data) ;
            if (root == NULL){
                root = current ;
            }
            return ;
        }

        else if (data < current->data){
            if (current -> left == NULL){
                current -> left = new BTnode(data) ;
                current -> left -> parent = current ;
            }

            else {
                insertHelp(current -> left , data) ;
            }
        }

        else {
            if (current -> right == NULL){
                current -> right = new BTnode (data) ;
                current -> right -> parent = current ;
            }

            else {
                insertHelp(current -> right , data) ;
            }
        }

        
    }

    int display(){
        if (root == NULL) {
            cout << "Nothing to display" << endl ;
        }

        else {
            displayHelp(root) ;

        }
        
        
    }


    int displayHelp(BTnode* current){
        if (current == NULL){
            
            return 0 ;
        }

        else {
            displayHelp(current -> left) ;
            cout << current -> data << " " ;
            displayHelp(current -> right) ;
        }
    }

    BTnode * getMin(BTnode * current){
        while (current -> left != NULL){
            current = current -> left ;

        }

        return current ;
    }

    void replace_with_parent (BTnode * A , BTnode * B){
        if (A->parent){
            if (A->parent -> left == A){
                A -> parent -> left = B ;
            }

            else if (A->parent-> right == A){
                A -> parent -> right = B ;
            }

        }

        if (B){
            B -> parent = A -> parent ;
        }
    }


    void deleteNode (int value){
               
        deleteHelp (root , value) ;
    }

    void deleteHelp (BTnode * current , int value){
        //search for the value to be deleted

                
        if (value < current -> data) {
            deleteHelp (current -> left, value) ;
            return ;
        }

        else if (value > current -> data){
            deleteHelp (current -> right, value);
            return ;
        }

        else if (value == current -> data){
            cout << "Value " << value << " found!! Now deleting it" << endl ;

            if (current -> left == NULL && current -> right == NULL){
                cout << " Its a leaf node" << endl ;
                BTnode * temp = current ;
                replace_with_parent(current , NULL) ;
                delete temp ;

            } 

            else if(current -> left == NULL || current -> right == NULL){
                cout << " Its a one child node " << endl ;
                if (current -> parent -> left == current){
                    
                    replace_with_parent(current , current -> left) ;
                }

                else if(current -> parent -> right == current){
                    replace_with_parent(current, current -> right) ;
                }
            }

            else if (current -> left != NULL && current -> right != NULL){
                cout << "Its a node with 2 childrens" << endl ;

                BTnode * temp = getMin(current -> right) ;
                current -> data = temp -> data ;
                deleteHelp(temp , temp -> data) ;
               
            }       
            
        }

        
    }




} ;

int main(){
    BT b1 ;

    b1.display() ;
    b1.insert(50) ;
    b1.display() ;
    cout << endl ;
    b1.insert(40) ;
    b1.display() ;
    cout << endl ;
    b1.insert(90) ;
    b1.display() ;
    cout << endl ;
    b1.insert(20) ;
    b1.display() ;
    cout << endl ;
    b1.insert(70) ;
    b1.display() ;
    cout << endl ;
    b1.insert(10) ;
    b1.display() ;
    cout << endl ;
    b1.insert(30) ;
    b1.display() ;
    cout << endl ;
    b1.insert(60) ;
    b1.display() ;
    cout << endl ;
    b1.insert(80) ;
    b1.display() ;
    cout << endl ;
    b1.insert(100) ;
    b1.display() ;
    cout << endl ;
    b1.insert(120) ;
    b1.display() ;
    cout << endl ;
    b1.insert(110) ;
    b1.display() ;
    cout << endl ;
    b1.insert(130) ;
    b1.display() ;
    cout << endl ;
    b1.insert(75) ;
    b1.display() ;
    cout << endl ;
    b1.insert(82) ;
    b1.display() ;
    cout << endl ;

    cout << "The minimum element is " << b1.getMin(b1.root) ->data << endl ;
    b1.deleteNode(30) ;
    b1.display() ;
    cout << endl ;
    b1.deleteNode(100) ;
    b1.display() ;
    cout << endl ;
    b1.deleteNode(70) ;
    b1.display() ;
    cout << endl ;
    
}
