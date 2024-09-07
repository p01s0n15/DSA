#include<iostream>
using namespace std;
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int mini = i;
        for(int j=i+1; j<=n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(&arr[mini], &arr[i]);

    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selection(arr,n);
    print(arr,n);
}