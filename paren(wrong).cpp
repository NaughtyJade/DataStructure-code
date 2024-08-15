#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	getchar();
	while(n--){
		bool flag = true;
		string paren;
		stack<char> Lparen;
		getline(cin, paren);
		for(int i = 0; i < paren.length() && flag == true; i++){
			if(paren[i] == ')' && !Lparen.empty()){
				if(Lparen.top() == '('){
					Lparen.pop();
				}
				else{
					flag = false;
					break;
				}
			}
			else if(paren[i] == ']' && !Lparen.empty()){
				if(Lparen.top() == '['){
					Lparen.pop();
				}
				else{
					flag = false;
					break;
				}
			}
			else if(paren[i] == '}' && !Lparen.empty()){
				if(Lparen.top() == '{'){
					Lparen.pop();
				}
				else{
					flag = false;
					break;
				}
			}
			else{
				Lparen.push(paren[i]);
			}
		}
		if(Lparen.empty()){cout << "Yes" << endl;}
		else{cout << "No" << endl;}
	}
}
