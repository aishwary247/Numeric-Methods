// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    int ans = 1;
    for(int i = 1; i < n+1; i++){
        ans = ans * i;
    }
    return ans;
}

int Que1( double x){
    double ans = 1;
    double target = cos(x);
    bool req = true ;
    int n = 2;
    int terms = 1;
    while(abs(target-ans) > 1e-7 ){
        // cout << abs(target-ans) << " " ;
        double val = pow(x,n)/fact(n);
        // cout << val << " ";
        // cout << req << " ";
        if (req == true){
        ans = ans - val;
        req = false;
        }
        else{
            ans = ans + val;
            req = true;
        }
        // cout << ans << endl ;
        n = n+2;
        terms ++ ;
        cout << ans << endl ;

    }
    return terms ;
}
int main() {
    cout.precision(8);
    cout << "value of cos(x) = " << cos(0.3*M_PI) << endl;
    cout << Que1(0.3*M_PI);
    return 0;
}

