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
    cout << "the inverse matrix: "    << endl ;
    lstf(Iden);
    return Iden ;    
}



// Matrix Multipication  
vector<vector<double>> matrixMultiply( vector<vector<double>>& A, vector<vector<double>>& B) {
    int m = A.size();    // Number of rows in A
    int n = A[0].size(); // Number of columns in A
    int p = B[0].size(); // Number of columns in B

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
// Transpose of matrix
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
int main(){
    ifstream in("Input-4.txt");

    //vector < vector<double> > test = {{2,-1,0,1},{0,1,2,3},{0,1,1,2},{2,5,1,4}};
    //inverseMatrix(test);
    int m , n;
    //cout << "No. of rows in data- ";
    in >> m ;
    //cout << "No. of independent variables- ";
    in >> n ;
    //cout << " y1 - ym: ";
    // cout << m << " " << n ;
    vector<vector<double>> Y(m,vector<double>(1,0)) ;
    for(int i =0; i<m; i++){
        in >> Y[i][0];
    }
    vector<vector<double>> X(m,vector<double>(n+1,1));
    for(int i = 1; i<n+1 ;i++){
        //cout << "Feature "<< i<<" from 1-m";
        for(int j = 0; j<m ; j++){
            in >> X[j][i];
        }
    }
    //vector<vector<double>> X = {{1,1,1,1,1,1,1},{1,2,3,4,5,6,7}};
    //vector<vector<double>> Y = {{0.5},{2.5},{2.0},{4.0},{3.5},{6.0},{5.5}};
    cout << " X: " << endl ;
    lstf(X);
    cout << "Y: " << endl ;
    lstf(Y);
    vector<vector<double>>transpose_X = transpose(X);
    cout << "transpose(X) : "<< endl ;
    lstf(transpose_X);
    vector<vector<double>>XTcrsX = matrixMultiply(transpose_X,X);
    cout << "XTcross X : "<< endl ;
    lstf(XTcrsX);
    vector<vector<double>> XTcrsX_inv = inverseMatrix(XTcrsX);
    cout << " Xt x X inverse" << endl ;
    lstf(XTcrsX_inv);
    vector<vector<double>>XTcrsY = matrixMultiply(transpose_X,Y) ;
    vector<vector<double>> phiVector = matrixMultiply(XTcrsX_inv,XTcrsY);

    cout << "The parameters (a0-an): " << endl ;
    lstf(phiVector);
}