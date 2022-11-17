#include<iostream>
using namespace std;

template <typename T> class sortedArr{
private:
    int len=1;
    T *arr = new T[len];
public:
    sortedArr(T *arr, int len){
        this->len = len;
        this->arr = new T[len];
        this->arr=arr;
    }
    void bubble_sort(){
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(arr[i]>arr[j])swap(arr[i],arr[j]);
            }
        }
    }
    void counting_sort(){
        if(len<=0)return;
        T mn=arr[0];
        T mx=arr[0];
        for(int i=0;i<len;i++){
            mn=(arr[i]<mn)?arr[i]:mn;
            mx=(arr[i]>mx)?arr[i]:mx;
        }
        int shift=mn;
        int dif=mx-mn+1;
        T *tmp = new T[dif];
        for(int i=0;i<dif;i++){
            tmp[i]=0;
        }
        for(int i=0;i<len;i++){
            tmp[arr[i]-shift]++;
        }
        int idx=0;
        for(int i=0;i<dif;i++){
            T ct=tmp[i];
            T num=i+shift;
            while(ct--){
                arr[idx]=num;
                idx++;
            }
        }
        if(tmp!=NULL)delete [] tmp;
    }
    void merge(int l, int mid, int r){
        int i=l; //left arr index
        int j=mid+1; //right arr index
        int k=0; //tmp arr index
        int siz=r-l+1;
        T *tmp = new T[siz];
        while(i<=mid&&j<=r){
            if(arr[i]<arr[j]){
                tmp[k]=arr[i];
                k++;
                i++;
            }else{
                tmp[k]=arr[j];
                k++;
                j++;
            }
        }
        while(i<=mid){
            tmp[k]=arr[i];
            k++;
            i++;
        }
        while(j<=r){
            tmp[k]=arr[j];
            k++;
            j++;
        }
        for(int idx_arr=l,idx_tmp=0;idx_arr<=r;idx_arr++,idx_tmp++){
            arr[idx_arr]=tmp[idx_tmp];
        }
        if(tmp!=NULL)delete [] tmp;
    }
    void merge_sort(int l=-1, int r=-1){
        if(l==-1&&r==-1){ //init
            l=0,r=len-1;
        }
        if(l<r){
            int mid = l+(r-l)/2;
            merge_sort(l,mid);
            merge_sort(mid+1,r);
            merge(l,mid,r);
        }
    }
    int size(){
        return len;
    }
    T val(int idx){
        if(idx<len)return arr[idx];
        else return 0;
    }
    void render(T *arr){
        arr = new T[len];
        arr=this->arr;
    }
};

int main(){
    int arr[]={2,4,3,5,-6,4,2,-4,5,23,2};
    int len= *(&arr + 1) - arr;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortedArr<int>sa(arr,len);
    len=sa.size();
    cout<<len<<endl;
    //sa.bubble_sort();
    //sa.counting_sort();
    sa.merge_sort();
    for(int i=0;i<len;i++){
        cout<<sa.val(i)<<" ";
    }
    cout<<endl;
    sa.render(arr);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}