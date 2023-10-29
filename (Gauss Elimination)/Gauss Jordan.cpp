// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

float power(int x){
    float ans = 1 ;
    int i = 0;
    while(i<4){
        ans = ans / x ;
        i++;
    }
    return ans ;
}
float func(){
    float ans = 0 ;
    for (int i = 1; i< 10000+1;i++ ){
        ans = ans + power(i);
    }
    setprecision(7);
    return ans ;
}
float func2(){
    float ans = 0 ;
    for (int i = 10000; i> 0; i-- ){
        ans = ans + power(i);
    }
    return ans ;
}
int main() {
    
    
    cout.precision(8);
    cout << func() << endl ;
    cout << func2()<< endl;
    float actual = pow(M_PI,4)/90 ;
    cout<< actual<<endl ;
    cout << "Percent error from 1 to 10k  = " << ((actual-func())/actual)*100 << endl;
    cout << "Percent error from 10k to 1 = " << ((actual-func2())/actual)*100;

    return 0;
}

