//inlcuding libraries

#include <iostream>
using namespace std;

//defining partition function that takes array start and end as arguments
int partition (int *MyArr , int start ,int end) {
    int pivot = MyArr[end] ;
    int pIndex = start ;
//looping till we get the pivot at the right position
    int i = start ;
    while (i < end){
        if (MyArr[i] <= pivot) {
            swap(MyArr[i] , MyArr[pIndex]) ;            
            pIndex ++ ;                        
        }
        
        i++ ;
}
        swap (MyArr[pIndex] , MyArr[end]) ;
//return index no of the pivot
        return pIndex ;
} ;

//defining quicksort function that takes the array, start and end as arguments
void quickSort(int *MyArr , int start , int end) {
    if ( start >= end) {
        return ; //exiting statement else looping and looping and looping
    }

//recursively calling the function
    else {  int pIndex = partition (MyArr,start,end) ;            
            quickSort(MyArr,start,pIndex-1) ;
            quickSort(MyArr,pIndex+1,end) ;
    }   
} ;

//defining main function

int main(){
    int MyArr [9] = { 5 , 6 , 8 , 9 , 7 , 2 , 3 , 1 , 4 } ;
    cout << "The array before sorting is " << endl ;
    int i = 0 ;
    while(i < 9) {
        cout << MyArr[i] << "  " ;
        i++ ;
    }
    cout << endl ;

    quickSort(MyArr , 0 , 8) ;

    cout << "The array after sorting is " << endl ;
    int j = 0 ;
    while(j < 9) {
        cout << MyArr[j] << "  " ;
        j++ ;
    }
    cout << endl ;

}

