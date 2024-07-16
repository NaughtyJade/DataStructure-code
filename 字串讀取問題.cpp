#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		if(s[0] == '0'){
			return 0;
		}
		else{
			cout << s[5] <<"\n";
		}
	}
}
