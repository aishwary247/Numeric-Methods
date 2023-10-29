#include<bits/stdc++.h>
using namespace std;

float Error(vector<float>&v1, vector<float>&v2){
    float error = 0;
    for(int i = 0; i < v1.size(); i++){
        error += pow((v1[i]-v2[i]),2);
    }
    return sqrt(error);
}

void GaussSidel(){
    ifstream in("Input1.txt");
    ofstream out("Output2.txt");

    int n;
    in >> n ;
    vector <vector <float> > A (n , vector<float>(n,0));
    for(int i = 0; i < n ; i++){
    out << "Coeffecients of equation " << i+1 << " - " << endl;
    for(int j = 0; j<n; j++){
        in  >> A[i][j];
        out << A[i][j] << endl;
        }
    }
    vector<float> B(n,0);
    for(int i = 0; i<n ; i++){
        in >> B[i];
    }
    vector<float> X0 (n);
    out << "Initial guess - ";
    for(int i = 0; i<n ; i++){
        in >> X0[i];
        out << X0[i]<< " " ;
    }
    out << endl ;
    vector <vector <float> > kmat ;
    kmat.push_back(X0);
    float error = 1;
    int k = 0;
    vector<float> Errorlst ;
    while(error >= 1e-06){
        vector<float> sol(n,0) ;
        kmat.push_back(sol);
        for(int i = 0; i<n ; i++){
        // xi = bi - Sigma aijxi
            
            float sum  = 0;
            for(int j = 0; j<n ; j++){
                if(j == i){
                    continue;
                }
                else if(j<i){
                    sum += A[i][j]*kmat[k+1][j];
                }
                else if(j>i){
                    sum += A[i][j]*kmat[k][j];
                }
            }
            float x = (B[i]-sum)/A[i][i];
            kmat[k+1][i] = x;
        }
        k++;
        error = Error(kmat[k],kmat[k-1]);
        Errorlst.push_back(error);
    }
    for(int j = 1; j< k+1; j++){
        out << "Output of iteration "<< j << ": ";
        for(int i = 0; i< n ;i++){
            out << kmat[j][i] << " " ;
        }
        out << endl;
    }
    out << "Error after each iteration- " << endl ;
    for(auto x: Errorlst){
        out << x << endl ;
    }
}

int main() {
    GaussSidel();

}

