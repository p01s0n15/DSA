#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int lp = low;
    int rp = mid+1;
    while(lp<=mid && rp<=high){
        if(arr[lp]<=arr[rp]){
            temp.push_back(arr[lp]);
            lp++;
        }else{
            temp.push_back(arr[rp]);
            rp++;
        }
    }
    while(lp<=mid){
        temp.push_back(arr[lp]);
        lp++;
    }
    while(rp<=high){
        temp.push_back(arr[rp]);
        rp++;
    }
    for(int i=low; i<=high; i++){
        arr[i]= temp[i-low];
    }
}

void mergesort(int arr[],int low,int high){
    if(low>=high){return;}
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n]; // array input
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    print(arr,n);
}