// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;

// k = km*c^2 / (cs+c^2)
// (1/k) = (cs/km)(1/c^2)+ (1/km)
// Y = a1*X + a0

void lstf(vector<int> v){
    for(int i= 0;i< v.size();i++){
        cout << v[i]<< " ";
    }
}
vector<double> summation1reg(vector<double>x , vector<double>y){

    //y_pred = a1*x + a0
    //a1 = (N*SIGMA(xi*yi)-SIGMA(xi)*SIGMA(yi))/N*SIGMA(xi^2)-(SIGMA(xi))^2
    //a0 = SIGMA(yi)/N - (SIGMA(xi)/N)*a1

    int N = x.size();

    double sum_xi = 0;
    for(int i= 0; i<N;i++){
        sum_xi += x[i];
    }
    // cout <<"sum_xi = " <<sum_xi ;
    double sum_yi = 0;
    for(int i= 0; i<N;i++){
        sum_yi += y[i];
    }
    //cout <<"sum_yi = " <<sum_yi ;

    double sum_xi_sq = 0;
    for(int i= 0; i<N;i++){
        sum_xi_sq += (x[i])*(x[i]);
    }
    //cout <<"sum_xi_sq = " <<sum_xi_sq;

    double sum_xi_yi = 0;
    for(int i= 0; i<N;i++){
        sum_xi_yi += (x[i])*(y[i]);
    }
    //cout <<"sum_xi_yi = " <<sum_xi_yi ;


    double a1 = ((N*sum_xi_yi)-(sum_xi*sum_yi))/((N*sum_xi_sq)-(sum_xi*sum_xi));
    double a0 = ((sum_yi/N)-(sum_xi/N)*a1);

    cout << "y_pred = "<< a1 << "x + "<< a0 << endl ;
    

    vector<double> params = {a0,a1} ;
    return params ;
}

vector<double> y_prediction (double a0, double a1, vector<double> x) {
    vector<double> y_pred ;
    for(auto val : x ){
        double value = a1*val + a0 ;
        y_pred.push_back(value);
        cout<< value << endl;
    }
    return y_pred;
}

int main() {
    // taking values of c 
    ifstream in("Input-1.txt");
    // 5 values of c
    double c ;
    vector<double> X;
    for(int i = 0; i<5; i++){
        in >> c;
        X.push_back(1/(c*c));
    }
    double k ;
    vector<double> y ;
    for(int i = 0; i<5; i++){
        in >> k ;
        y.push_back(1/k);
    }
    double a0 , a1;
    vector<double> params = summation1reg(X,y);   
    a0 = params[0] ;   a1= params[1] ;

    double kmax , cs ;
    // a0 = 1/kmax 
    // a1 = cs/kmax 
    kmax = 1/a0 ; 
    cs = a1*kmax ;

    cout << "kmax = " << kmax << endl ;
    cout << "cs = " << cs << endl  ;

    // Given c = 2 mg/L

    double x = 0.25 ;
    double yg = a1*x + a0 ;
    //k = 1/y ;
    double k_pred = 1 / yg ;
    cout << "Growth rate at c = 2mg/L = " << k_pred ;

}

