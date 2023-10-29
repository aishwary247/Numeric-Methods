// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return x - exp(x)/3 ;
}

void RegularFalsi(){
    float xl, xr ;
    cout << "What are the initial guesses- "  ;
    cin >> xl >> xr ;
    float xi;
    float error ;
    int itr = 0;
    if(f(xl)*f(xr)> 0){
        cout << "Initial guesses incorrect for Bisection Method (f(xl)*f(xr)> 0)";
    }
    else{
        while(true){
            xi = xl - f(xl)*((xr-xl)/(f(xr)-f(xl))) ;
            if(abs(xl-xi)<1e-04){
                cout << "The solution comes out to be- " << xl << endl ;
                cout << "Number of iterations required- " << itr << endl << endl ;
                return ;
            }
            else{
                if(f(xl)*f(xi)< 0){
                    xr = xi;
                }
                else{
                    xl = xi ;
                }
                itr ++;
            }
        }
    }

}

int main() {
    int i =2;
    while(i--){
        RegularFalsi();
        
    }
}