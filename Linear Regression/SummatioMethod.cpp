// summation menthod for 2 independent variables
#include<bits/stdc++.h>
using namespace std;

// printing matrix
void lstf(vector<vector<double>>arr){
for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0; j< arr[0].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }
} 
void pivot(vector <vector<double> >& v , int k ){
    // k --> arr[k][k]
    int n = v.size() ;
    double big = v[k][k] ;
    int p = k ;
    for(int i = k+1 ; i< n; i++){
        if(v[i][k] > big){
            big = v[i][k];
            p = i ;
        }
    }
    if(p != k ){
        swap(v[p],v[k]);
        }
}

vector<double> GaussElimination(vector<vector<double>>AugMatrix){
    int n = AugMatrix.size();
    for (int k = 0 ; k < n ; k++){
        pivot(AugMatrix,k);
        
        for (int i = k+1 ; i < n; i++){
            
            double factor = AugMatrix[i][k]/AugMatrix[k][k];
            
            for(int j = 0; j<n+1; j++){
                AugMatrix[i][j] = AugMatrix[i][j]- factor* AugMatrix[k][j];
                if (abs(AugMatrix[i][j]) < 1e-05){
                    AugMatrix[i][j] = 0 ;
                }
            }
        }
        
    }
    vector<double> sol(n);
    double xn = AugMatrix[n-1][n]/ AugMatrix[n-1][n-1];
    sol[n-1] = xn ;

    for(int i = n-2; i >= 0; i--){
        double bi = AugMatrix[i][n];
        double Xi = 0;
        for(int j = i+1 ; j< n ; j++){
            Xi =  Xi + AugMatrix[i][j]*sol[j];
        }
        double xi =  (bi-Xi)/AugMatrix[i][i];
        sol[i]= xi;
    }

    return sol ;
}

void fns(vector<double>x, vector<double>u, vector<double>y){
    int n = x.size();
    cout << "n = " << n << endl;
    double sum_xi = 0;
    for(int i= 0; i<n ; i++){
        sum_xi += x[i];
        //cout << sum_xi << " ";
    }
    //cout << endl ;
    double sum_ui = 0;
    for(int i= 0; i<n ; i++){
        sum_ui += u[i];
        
    }
    double sum_xi_xi = 0;
    for(int i= 0; i<n ; i++){
        sum_xi_xi += x[i]*x[i];
    }
    double sum_ui_ui = 0;
    for(int i= 0; i<n ; i++){
        sum_ui_ui += u[i]*u[i];
    }
    double sum_ui_xi = 0;
    for(int i= 0; i<n ; i++){
        sum_ui_xi += u[i]*x[i];
    }
    double sum_yi_xi = 0;
    for(int i= 0; i<n ; i++){
        sum_yi_xi += y[i]*x[i];
    }
    double sum_yi_ui = 0;
    for(int i= 0; i<n ; i++){
        sum_yi_ui += y[i]*u[i];
    }
    double sum_yi = 0;
    for(int i= 0; i<n ; i++){
        sum_yi += y[i];
    }
    //Augumented Matrix
    vector<vector<double>> A = {{  double(n),     sum_xi,    sum_ui, sum_yi},
                                {sum_xi, sum_xi_xi,sum_ui_xi,sum_yi_xi},
                                {sum_ui,sum_ui_xi, sum_ui_ui,sum_yi_ui}};
    //lstf(A);   
    vector<double> coefficients = GaussElimination(A) ;
    cout << "The coefficients are (ao- a3): "  << endl ;                      
    for (auto x: coefficients){
        cout << x << endl ;
    }
}

int main(){
    ifstream in("Input-4.txt");
    int m ;
    //cout << "No. of rows in data- ";
    in >> m ;
    //cout << m << endl ;
    vector<double> y(m) ;
    for(int i =0; i<m; i++){
        in >> y[i];
        // cout << y[i] << " ";
    }
    // cout << endl ;
    
    vector<double> x(m);
    for(int i = 0; i<m ;i++){
            in >> x[i];
            // cout << x[i] << " ";
        }
        // cout << endl;
    vector<double> u(m);
    for(int i = 0; i<m ;i++){
            in >> u[i];
            // cout << u[i] << " ";

        }  
    fns(x,u,y) ;     
}


