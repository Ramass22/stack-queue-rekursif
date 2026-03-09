#include <iostream>
using namespace std;

int fibinaci(int n){
    if(n <=1){
        return n;
    }
    else {
        return fibinaci(n-2) + fibinaci(n-1);
    }
}
int main() {
    int jumlah;
    cout << "masukan jumalah = ";
    cin >> jumlah;
    cout << "deret fibonacci :";
    for (int i = 0; i < jumlah; i++){
        cout << fibinaci(i) << "  ";
    }
    cout << endl;
    return 0;
    
}