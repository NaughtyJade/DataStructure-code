#include <iostream>
using namespace std;

void copy(int *a, int *b, int size){
	while(size--){
		b[size] = a[size];
	}
}
int main(){
	int size;
	int before[100], after[100];
	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> before[i];
	}
	copy(before, after, size);
	for(int j = 0; j < size; j++){
		if(j  == size - 1){
			cout << after[j] << endl;
		}
		else{
			cout << after[j] << ' ';
		}
	}
}
