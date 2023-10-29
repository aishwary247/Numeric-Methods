// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return x - exp(x)/3 ;
}

void Secant(){
    float xl, xr ;
    cout << "What are the initial guesses- "  ;
    cin >> xl >> xr ;
    float xi;
    float error ;
    int itr = 0;
    
        while(true){
            xi = xl - f(xl)*((xr-xl)/(f(xr)-f(xl))) ;
            if(abs(xl-xi)<1e-04){
                cout << "The solution comes out to be- " << xl << endl ;
                cout << "Number of iterations required- " << itr << endl << endl;
                return ;
            }
            else{
                xl = xr ;
                xr = xi;
                itr ++;
            }
        }
    

}

int main() {
    int i =2;
    while(i--){
        Secant();
        
    }
}