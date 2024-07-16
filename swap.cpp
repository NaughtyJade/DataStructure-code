#include <iostream>
using namespace std;

void swap(int *arr, int a, int b){
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main(){
	int m, n;
	cin >> m >> n;
	int *arr = new int[m];
	for(int i = 0; i < m; i++){
		cin >> arr[i];
	}
	int a, b;
	for(int j = 0; j < n; j++){
		cin >> a >> b;
		swap(arr, a, b);
	}
	for(int k = 0; k < m; k++){
		if(k == m - 1){
			cout << arr[k] << endl;
		}
		else{
			cout << arr[k] << ' ';
		}
	}
}
