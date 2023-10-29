#include<bits/stdc++.h>
using namespace std;

double func(int a){
    double x = 0.005 ;
    double tol = x;
    while ( tol >= 1e-6){
    double x0 = x ;
    x = (x+ a/x)/2 ;
    tol = abs(x0-x);
    }
    return x ;
}    
void truePercentRelativeError (int n, int a){
    
    double x = 0.005;
    double xt = sqrt(a);
    
    while(n--){
        double x0 = x;
        x = (x+ a/x)/2 ; 
        cout << (abs(xt-x)/xt)*100<< endl ;
    }    
}    
void approximatePercentRelativeError(int n, int a){
    
    double x = 0.005;
    while(n--){
        double x0 = x;
        x = (x+ a/x)/2 ; 
        cout << (abs(x-x0)/x0)*100 << endl ;
    }
}   


int main() {
    
    cout << func(5) << endl ;
    cout << endl;
    truePercentRelativeError (4, 5);
    cout << endl ;
    approximatePercentRelativeError(4,5);

}

