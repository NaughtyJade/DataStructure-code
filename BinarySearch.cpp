#include <iostream>
#include <algorithm>

// 可以使用 std::sort() 排序陣列。
// sort(arr, arr + n);

using namespace std;

int BinarySearch(int *arr, int length, int target){
	int left = 0, right = length - 1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(arr[mid] > target){right = mid - 1;}
		else if(arr[mid] < target){left = mid + 1;}
		else if(left > right){return 0;}
		else{return mid;}
	}
}

int main() {
	int n = 0;
	cin >> n;
	for(;n > 0; n--){
		int l = 0, index = 0;
		cin >> l;
		int *arr = new int[l];
		for(int i = 0; i < l; i++){
			cin >> arr[i];
		}
		sort(arr, arr + l);
		int target = 0;
		cin >> target;
		//cout << BinarySearch(arr, l, target) << endl;
		if(arr[BinarySearch(arr, l, target)] != target){cout << "Not Found" << endl;}
		else{cout << BinarySearch(arr, l, target) << endl;}
		/*while(index < l){
			if(arr[index] == target){cout << index << endl;break;}
			else{index++;}
		}
		if(index == l){
			cout << "Not Found" << endl;
		}*/
	}
}
