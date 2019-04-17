#include <iostream>
using namespace std;

class node {
    public:
    int data ;
    node * left ;
    node * right ;

    node (int value){
        data = value ;
        left = NULL ;
        right = NULL ;

    }
} ;

class BST {
    public:

    node * root ;
    

    BST (){
        root = NULL ;
        

    }

    void insert (int data){
        insertHelp (root, data) ;
    }

    void insertHelp (node * current , int value) {
        if (current == NULL){
            current = new node(value) ;
            if (root == NULL){
                root = current ;
            }
        }

        else if (value < current -> data){
            if (current -> left == NULL){
                current -> left = new node(value) ;
            }

            else {
                insertHelp (current -> left, value) ;
            }
        }

        else {
            if (current -> right == NULL){
                current -> right = new node(value) ;
            }

            else {
                insertHelp(current -> right, value) ;
            }
        }

    }

    int display(){
        displayHelp(root) ;
    }

    int displayHelp(node * current){
        if (current == NULL) {
            return 0 ;
        }

        else {
            displayHelp(current -> left) ;
            cout << current -> data << " " ;
            displayHelp(current -> right) ;
        }

    }

    int countItem (node * current){
        int count = 0 ;
        if (current == NULL){
            
        }
        
        else {
            count = countItem (current->left) + countItem(current -> right) + 1;
        }

        return count ;
    }

    int rangeSearch (int k1 , int k2){
        rangeSearchHelp(root , k1, k2) ;

    }

    int rangeSearchHelp(node * current , int k1 , int k2){
        
        if (current == NULL){
            return 0 ;
        }

        if (k1 < current -> data){
            rangeSearchHelp (current -> left , k1, k2) ;
        }

        if (current-> data >= k1 && current -> data <= k2){
            cout << current -> data << " "  ;
            

        }

        if (k2 > current -> data){
            rangeSearchHelp(current -> right , k1, k2) ;
        }

        
    }

    int countinRange (int k1 , int k2){
        countinRangeHelp(root , k1 , k2) ;
    }

    int countinRangeHelp(node * current , int k1 , int k2){
        

        if (current == NULL){
            return 0 ;
        }

        if (current -> data >= k1 && current -> data <= k2){
            return countinRangeHelp(current -> left , k1 , k2) + countinRangeHelp (current -> right , k1, k2) + 1 ;
            
        }

        else if (k1 < current-> data){
            return (countinRangeHelp(current -> left , k1 , k2)) ;
        }

        
        
        else {
            return (countinRangeHelp(current -> right , k1 , k2)) ;
        }

        
    }

    int height (){
        heightHelp(root) ;
    
    }
    int heightHelp(node * current){
        if (current == NULL){
            return 0 ;
        }

        else {
            int lheight = heightHelp(current->left) ;
            int rheight = heightHelp(current->right) ;

            if (lheight > rheight){
                return lheight + 1 ;
            }

            else {
                return rheight + 1 ;
            }
        }

    
        
    }

    void print2D (){
        print2DHelp (root , 0) ;
    }

    void print2DHelp (node * current , int space) {
        if (current){
            print2DHelp(current -> right , ++space) ;
            cout << endl ;
            for (int i = 1; i < space ; i++) {
                cout << "       " ;
            }    
                cout << current -> data << endl ;
            
            print2DHelp(current -> left , space) ;
        
        }
    }
    
} ;

int main (){
    BST b1 ;
    
    cout << "No. of nodes are " << b1.countItem(b1.root)  << endl ;
    b1.insert(6) ;
    b1.display() ;
    cout << endl ;
    b1.insert(8) ;
    b1.display() ;
    cout << endl ;
    cout << "No. of nodes are " << b1.countItem(b1.root)  << endl ;
    b1.insert(2) ;
    b1.display() ;
    cout << endl ;
    cout << "No. of nodes are " << b1.countItem(b1.root)  << endl ;
    b1.insert(5) ;
    b1.display() ;
    cout << endl ;
    b1.insert(9) ;
    b1.display() ;
    cout << endl ;
    b1.insert(1) ;
    b1.display() ;
    cout << endl ;
    cout << "No. of nodes are " << b1.countItem(b1.root)  << endl ;
    b1.insert(3) ;
    b1.display() ;
    cout << endl ;
    b1.insert(4) ;
    b1.display() ;
    cout << endl ;
    b1.insert(10) ;
    b1.display() ;
    cout << endl ;
    b1.insert(11) ;
    b1.display() ;
    cout << endl ;
    b1.insert(7) ;
    b1.display() ;
    cout << endl ;
    cout << "No. of nodes are " << b1.countItem(b1.root)  << endl ;
    cout << "Elements between 2 and 7 are " ;
    b1.rangeSearch(2 , 7) ;
    cout << endl ;
    cout << "No of elements between 2 and 7 is " << b1.countinRange(2 , 7) << endl ;
    cout << "Height of the bst is " << b1.height() << endl ;
    cout << "*******************************************************" << endl ;

    b1.print2D() ;

    cout << "********************************************************" << endl ;
    
}