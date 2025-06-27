#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n) {
    
    if (m == 0 || n == 0)
        return 0;
    
    
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    
    
    return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;
    
    int m = X.length();
    int n = Y.length();
    
    int result = lcs(X, Y, m, n);
    cout << "Length of lcs: " << result << endl;
    
    return 0;
}