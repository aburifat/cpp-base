#include<iostream>
using namespace std;

// include custom cpp files start
#include "algorithm/sorting/tim_sort.h"
#include "algorithm/sorting/counting_sort.h"

//include custom cpp files end

int main(){
    int arr[]={4,3,5,7,6,3,4,5};
    int arr2[]={4,3,5,2,6,3,4,7};
    tim_sort(arr,0,7);
    counting_sort(arr2,1,6);
    for(int i=0;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=7;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}