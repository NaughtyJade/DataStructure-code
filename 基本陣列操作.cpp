#include <iostream>
using namespace std;

int main(){
	int line = 0, count = 0, i;
	cin >> line;
	while(line--){
		cin >> count;
		i = 0;
		int num[10];
		while(count--){
			cin >> num[i];
			i++;
		}
		while(i--){
			if(i == 0){
				cout << num[i];
			}
			else{
				cout << num[i] << " ";
			}
		}
		cout << endl;
	}
}
