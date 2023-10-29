#include<bits/stdc++.h>
using namespace std;

void lstf(vector<vector<double>>arr){
for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0; j< arr[0].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }
    cout << endl ;
} 

void lstf1D(vector<double> v){
    for(int i = 0 ; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl ;
}



vector<vector<double>> transpose( vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Initialize the transpose matrix with dimensions cols x rows
    vector<vector<double>> transpose(cols, vector<double>(rows, 0));

    // Fill in the transpose matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

vector<vector<double>> matrixMultiply( vector<vector<double>>& A, vector<vector<double>>& B) {
    int m = A.size();    // Number of rows in A
    int n = A[0].size(); // Number of columns in A
    int k = B.size();  // Number of rows in B
    int p = B[0].size(); // Number of columns in B
    if(n != k){
        cout << "matrix multiply dimension error" << endl ;
        exit(1);
    }

    // Initialize the result matrix C with dimensions mxp
    vector<vector<double>> C(m, vector<double>(p, 0));

    // Perform matrix multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
void pivot(vector < vector<double> >& v , vector < vector<double> >& I, int k ){
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
        swap(I[p],I[k]);
        }
}
vector<vector<double>> inverseMatrix( vector<vector<double>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    if (n != m){
        cout << "Dimension error" << endl ;
        exit(1);
    }
    vector<vector<double>>Iden(n,vector<double>(n,0));
    for(int i = 0 ; i< n; i++){
        Iden[i][i] = 1 ;
    }
    for(int k = 0; k<n ; k++){
            pivot(mat,Iden,k);
            double div = mat[k][k];
            if(abs(div) < 1e-05 ){
                cout << "Not invertible";
                exit(1);
            }
            for(int j = k ; j< n ; j++){
                mat[k][j]= mat[k][j]/div;
            }
            for(int j = 0 ; j< n ; j++){
                Iden[k][j]= Iden[k][j]/div;
            }
            for(int l = 0; l< n; l++){
                if(l == k){
                    continue;
                }
                else{
                    double factor = mat[l][k];
                    for(int j = k ; j<n; j++ ){

                        mat[l][j] = mat[l][j] -factor*mat[k][j];
                        if(abs(mat[l][j])<1e-05){
                            mat[l][j] = 0;
                        }
                    }
                    for(int j = 0 ; j<n; j++ ){

                        Iden[l][j] = Iden[l][j] -factor*Iden[k][j];
                        if(abs(Iden[l][j])<1e-05){
                            Iden[l][j] = 0;
                        }
                    }
                }
            }
        }
    return Iden ;    
}
double fns(double a4, double b4, double x){
        return a4*x*exp(b4*x);
    }


double Diff_a4 (double a4, double b4, double x ){
    double del = 1.0e-8;
    double a = (fns(a4+del,b4,x)-fns(a4,b4,x))/del ;
    return a;
   }
double Diff_b4 (double a4, double b4, double x ){
    double del = 1.0e-8;
    double a = (fns(a4,b4+del,x)-fns(a4,b4,x))/del ;
    return a;
   }
int main(){
    
    ifstream in("Input-2.txt");
    int m ; // no. of training examples
    in >>  m ;
    //cout << m << endl ;

    vector<double> Yi(m) ; 
    
    vector<double> Xi(m) ;
     
    
    for(int i=0 ; i< m; i++){
        in >> Xi[i] ;
    }
    for(int i=0 ; i< m; i++){
        in >> Yi[i] ;
    }
    //lstf1D(Xi);
    //lstf1D(Yi);


    // matrix D 
    double a4 = 1.0 ; double  b4 = 1.0 ;
    while(true){
        vector<vector<double>> D(m) ;
        for(int i = 0 ; i< m; i++){
            vector<double> ele = {Yi[i]-fns(a4,b4,Xi[i])} ;
            D[i]=ele;
        }
        //cout << "D: ";
        //lstf(D);

        vector<vector<double>> Zj(m) ;
        for(int i = 0 ; i< m; i++){
            vector<double> ele = {Diff_a4(a4,b4,Xi[i]), Diff_b4(a4,b4,Xi[i])} ;
            Zj[i] = ele;
        }
        //lstf(Zj);

        
        vector<vector<double>> Zj_T = transpose(Zj);
        //lstf(Zj_T);
        vector<vector<double>> Zj_T_Zj = matrixMultiply(Zj_T,Zj);
        //lstf(Zj_T_Zj);
        vector<vector<double>> Zj_T_Zj_inverse = inverseMatrix(Zj_T_Zj);
        vector<vector<double>> Zj_T_D = matrixMultiply(Zj_T,D);
        
        vector<vector<double>> Del_A = matrixMultiply(Zj_T_Zj_inverse, Zj_T_D);
        cout << "Del_A : " << endl ;
        lstf(Del_A);

        double error = max(abs(Del_A[0][0]/a4 ), abs(Del_A[0][0]/b4) ) ;
        cout << "Error: " << error << endl ;
        if(error < 1e-05){
            break ;
        }
        a4 = a4 + Del_A[0][0];
        b4 = b4 + Del_A[1][0];
        

    }
    cout << "Alpha4 = " << a4 << endl ;
    cout << "Beta4 = " << b4 << endl ;


}