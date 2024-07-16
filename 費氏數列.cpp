#include <iostream>
using namespace std;

int fab(int a){
	 if(a == 0){
	 	return 1;
	 }
	 else if (a == 1){
	 	return 1;
	 }
	 else
	 	return fab(a-1) + fab(a-2);

}

int main(){
	int num = 0;
	while(cin >> num){
		cout << fab(num) << endl;
	}
}
