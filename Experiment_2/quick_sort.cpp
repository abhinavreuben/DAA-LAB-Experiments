/*
Roll No: 25/DA/002
Name: Abhinav Reuben Topno
*/

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
        int p = partition(arr,low,high);
        quickSort(arr, low, p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

