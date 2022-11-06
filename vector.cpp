#include<iostream>
using namespace std;

template <typename T> class armvector{
	T* arr;
	int capacity;
	int current;
public:
	armvector(){
		arr = new T[1];
		capacity = 1;
		current = 0;
	}
	~ armvector(){
		delete [] arr;
	}
	void expend(){
		T* temp = new T[2 * capacity];
		for(int i=0;i<capacity;i++){
			temp[i] = arr[i];
		}
		delete [] arr;
		capacity*=2;
		arr = temp;
	}
	void shift(int index){
		T* temp = new T[capacity];
		int tmp_idx=0;
		for(int i=0;i<current;i++){
			if(i==index)tmp_idx++;
			temp[tmp_idx]=arr[i];
			tmp_idx++;
		}
		arr=temp;
		current++;
	}
	void update(T data, int index){
		if(index<current)arr[index]=data; 
	}
	void push_back(T data){
		if(current == capacity){
			expend();
		}
		arr[current]=data;
		current++;
	}
	void insert(T data, int index){
		if(index==current){
			push_back(data);
		}else{
			if(current == capacity){
				expend();
			}
			shift(index);
			update(data,index);
		}
	}
	void push_front(T data){
		insert(data,0);
	}
	T get(int index){
		if(index<current)return arr[index];
	}
	void erase(int index){
		if(index<current){
			T* temp=new T[capacity];
			int tmp_idx=0;
			for(int i=0;i<current;i++){
				if(i==index)continue;
				temp[tmp_idx]=arr[i];
				tmp_idx++;
			}
			arr=temp;
			current--;
		}
	}
	void pop_back(){
		current--;
	}
	void pop_front(){
		erase(0);
	}
	int size(){
		return current;
	}
	int getcapacity(){
		return capacity;
	}
	void print(){
		for(int i=0;i<current;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	armvector<int>v;
	for(int i=0;i<10;i++){
		v.push_back(i);
		v.push_front(i);
	}
	v.insert(10,10);
	for(int i=0;i<5;i++){
		v.insert(10,v.size());
		v.insert(10,0);
		v.pop_back();
		v.pop_front();
	}
	v.erase(10);
	v.erase(10);
	cout<<v.get(9)<<endl;
	v.print();
}
