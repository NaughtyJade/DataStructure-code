#include <iostream>
using namespace std;
int main(){
    int a, sum;
    while(cin >> a){
        int sum = a;
        while(true){
            sum += a / 3;
            if(a < 3){
            	 break;
           	}
           	else{
            	a=(a/3+a%3);
            }
        }
        if(a == 2){
            sum+=1;
        }
        	cout<<sum<<endl;
    }
}
