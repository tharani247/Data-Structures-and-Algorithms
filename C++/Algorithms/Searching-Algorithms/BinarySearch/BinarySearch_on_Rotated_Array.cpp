/*
 A C++ program to find an element in a sorted array which is rotated at some pivot using Binary Search algorithm
 The array is assumed to not have duplicate values
 Should output the index of the element to be searched if present and -1 otherwise
*/

#include<iostream>
using namespace std;

int search( int arr[], int n, int target){

    if(n == 0)return -1;
        
    int left = 0, right = n-1;

    //find the pivot point i.e the index where the array is rotated
    while(left < right){
            
        int mid = left + (right - left)/2;
        if ( arr[mid] > arr[right]) left = mid + 1;
        else right = mid ;
    }
        
    int pivot = left; 
    left = 0, right = n-1;
    
    //determine if the target lies to the lhs or rhs of the pivot point and change 
    //left or right variables accordingly
    if(target >= arr[pivot] && target <= arr[right] )
        left=pivot;
    else right=pivot;
        
    //standard binary search 
    while(left <= right){
            
        int mid = left + (right - left)/2;
        if(arr[mid] == target )return mid;
        else if(arr[mid] < target )left = mid+1;
        else right = mid-1;
    }

    //target not found
    return -1;

}

//Driver program to test the above 'search' function
int main(){

    int n = 8;
    int arr[n]={9, 11, 14, 0, 1, 3, 5, 8};
    int target = 5;
    int ans = search(arr, n, target);
    if(ans != -1)
        cout<<"The target = "<<target<<" is found at index "<<ans<<" in the rotated array\n";
    else 
        cout<<"The target = "<<target<<" was not found \n";

    return 0;

}