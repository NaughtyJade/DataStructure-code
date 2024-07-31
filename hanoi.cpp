#include <iostream>
using namespace std;
int steps = 0;
void H(int n,char A, char B, char C){
    if(n == 1){
        cout << A << " to " << C << endl;
        steps++;
    }
    else{
        H(n - 1, A, C, B);
        H(1, A, B, C);
        H(n - 1, B, A, C);
    }
}

int main(){
    int n = 0;
    while(cin >> n){
        H(n, 'A', 'B', 'C');
        cout << "steps:" << steps << endl;
        steps = 0;
    }
    
}
