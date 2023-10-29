// Header files and namespaces
#include<bits/stdc++.h>
using namespace std;


void lstf(vector<int> v){
    for(int i= 0;i< v.size();i++){
        cout << v[i]<< " ";
    }
}
//Summation method for 1 independent variable (x,y)
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
    cout << "y_pred values : " << endl ;

    vector<double> y_pred ;
    for(auto val : x ){
        double value = a1*val + a0 ;
        y_pred.push_back(value);
        cout<< value << endl;
    }
    return y_pred;
}

double y_avg(vector<double>y){
    double sum = 0;
    for(int i = 0; i<y.size();i++){
        sum += y[i];
    }
    return sum/y.size() ;
}

double S_r(vector<double>y, vector<double>y_pred){
    double Sr = 0 ;
    for(int i = 0; i<y.size();i++){
        Sr += pow((y[i]-y_pred[i]),2) ;
    }
    return Sr ;
}    
double S_t(vector<double>y, double y_avg){
    double St = 0 ;
    for(int i = 0; i<y.size();i++){
        St += pow((y[i]-y_avg),2) ;
    }
    return St ;
}

int main(){
    vector<double> y = {1,2,3,4,5,6,7};
    vector<double> x = {0.5,2.5,2.0,4.0,3.5,6.0,5.5};

    vector<double>y_pred = summation1reg(x,y);
    double yavg = y_avg(y);
    double St = S_t(y,yavg);
    double Sr = S_r(y,y_pred);

    double r2 = (St-Sr)/St ;
    // cout << St << " " << Sr << " " << r2;
    cout << "Correlation coefficient is: "<< sqrt(r2);
}

