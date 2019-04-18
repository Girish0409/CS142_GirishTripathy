#include <iostream>
using namespace std;

class heap{
    public:

    int *arr ;
    int max_size ;
    int csize ;

    heap (int msize){
        arr = new int[msize] ;
        this->max_size = max_size ;
        csize = 0 ;
    }

    void swap (int *a , int *b){
        int temp = *a ;
        *a = *b ;
        *b = temp ;
    }

    int parent (int i){
        return (i - 1)/2 ;
    }

    int leftchild(int i){
        return 2*i + 1 ;
    }

    int rightchild(int i){
        return 2*i + 2 ;
    }

    int getmin(){
        return arr[0] ;
    }

    void insert(int value){
        if (csize==max_size){
            cout << "heap overflow" << endl ;
        }      
        int i = csize ++ ;
        arr[i] = value ;
        

        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(&arr[i] , &arr[parent(i)]) ;
            i = parent (i) ;
        }
    }

    void display(){
        for (int i = 0 ; i < csize ; i++){
            cout<< arr[i] << "  " ; 

        }
        cout << endl ;
    }

    void minHeapify(int i){
        int l = leftchild(i) ;
        int r = rightchild(i) ;

        int smallest = i ;

        if (l < csize && arr[l] < arr[i]){
            smallest = l ;
        }

        if (r < csize && arr[r] < arr[smallest]){
            smallest = r ;
        }

        if (smallest != i) {
            swap (&arr[i] , &arr[smallest]) ;
            minHeapify(smallest) ;
        }
    }

    int extractMin(){
        if (csize <= 0){
            return __INT_MAX__ ;
        }

        else if (csize == 1){
            csize-- ;
            return arr[0] ;
        }

        else {
            int root = arr[0] ;
            arr[0] = arr[csize -1] ;
            minHeapify(0) ;
            csize -- ;
            return root ;
            
        }

        
    }

    void decreaseKey(int i, int new_val){
        arr[i] = new_val ;

        while (i != 0 && arr[parent(i)]>arr[i]){
            swap(&arr[parent(i)], &arr[i]) ;
            i = parent(i) ;
        }
    }
} ;

int main (){

    heap h1(100) ;
    h1.insert(4) ;
    h1.display() ;
    h1.insert(2) ;
    h1.display() ;
    h1.insert(3) ;
    h1.display() ;
    h1.insert(5) ;
    h1.display() ;
    h1.insert(9) ;
    h1.display() ;
    h1.insert(11) ;
    h1.display() ;
    cout << h1.extractMin() << endl ;
    h1.display() ;
    h1.decreaseKey(3 , 1) ;
    h1.display() ;
    
    
}