// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

float g(float x){
    return exp(x)/3 ;
}
// f(x)= x - e^x/3;  x = g(x);
void FP(){
    float x0 ;
    cout << "What is the initial guess- "  ;
    cin >> x0 ;
    float xi;
    float error ;
    int itr = 0;
   
    
        while(true){
            xi = g(x0);
            if(abs(x0-xi)<1e-04){
                cout << "The solution comes out to be- " << xi << endl ;
                cout << "Number of iterations required- " << itr << endl << endl ;
                return ;
            }
            else{
                x0 = xi ;
                itr ++;
            }
        }
    

}

int main() {
    int i =2;
    while(i--){
        FP();
        
    }
}