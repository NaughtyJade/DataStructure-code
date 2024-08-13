#include <iostream>
using namespace std;
int cun = 0;
int fib(int n)
{
    cun++;
    if(n <= 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(){
	int num = 0;
	while(cin >> num){
		cout << fab(num) << endl;
	}
}
