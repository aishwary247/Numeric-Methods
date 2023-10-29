// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return x - exp(x)/3 ;
}
float f1(float x){
    return 1- exp(x)/3 ;
}
void NR(){
    float x0 ;
    cout << "What is the initial guess- "  ;
    cin >> x0 ;
    float xi;
    float error ;
    int itr = 0;
   
    
        while(true){
            xi = x0 - f(x0)/f1(x0);
            if(abs(x0-xi)<1e-04){
                cout << "The solution comes out to be- " << xi << endl ;
                cout << "Number of iterations required- " << itr << endl<< endl;
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
        NR();
        
    }
}
