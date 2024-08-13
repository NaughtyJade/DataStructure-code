#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int num = 0;
	string paren;
	cin >> num;
	getline(cin, paren);
	for(int i = 0; i < num - 1; i++){
		int flag = 0;
		getline(cin, paren);
		//cout << paren << endl;
		stack<char> con;
		if(paren.empty()){flag = 1;}
		for(int j = 0; j < paren.length(); j++){
			//cout << "for in" << endl;
			if(paren[j] == '(' || paren[j] == '[' || paren[j] == '{'){
				con.push(paren[j]);
				//cout << "Lparen in" << endl;
				continue;
			}
			else if(paren[j] == ')' && con.top() != '('){
				cout << "No" << endl;
				break;;
			}
			else if(paren[j] == ']' && con.top() != '['){
				cout << "No" << endl; 
				break;
			}
			else if(paren[j] == '}' && con.top() != '{'){
				cout << "No" << endl; 
				break;
			}
			else{
				flag = 1;
				con.pop();
			}
		}
		if(flag == 1){
			cout << "Yes" << endl;
		}
		flag = 0;
	}
}
