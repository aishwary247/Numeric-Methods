#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
float fn(float x){
    float ans=x-exp(x)/3;
    return ans;
}
float solve(float xl, float xr ,float tol,float del){
    float x2; 
    int itr = 0;
    x2 = (xl+xr)/2;
    while(abs(x2-xl)>tol ){
        
        if(fn(x2)*fn(xl)<0){
            xr=x2;
        }
        else{
            xl=x2;
        }
        x2=(xl+xr)/2;

        itr ++ ;
    }
    cout << itr << endl;
    return x2;
}
int main(){
    float xl,xr;
    cout<<"Entetr guess value"<<endl;
    cin>>xl>>xr;
    float tol = 1e-04;
    
    float del = 1e-04;
    
    cout<<solve(xl,xr,tol,del)<<endl;
    
    return 0;
}