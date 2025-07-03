// 1. Perform the Linear Search in a 2D Array

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int x; cin >> x;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]==x) {
                cout << "will not take number\n";
                return;
            }
        }
    }

    cout << "will take number\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 2. Absolute difference between the diagonals in the matrix

void solve() {
    int n; cin >> n;

    int arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int sum_1=0; int sum_2=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) sum_1 = sum_1 + arr[i][j];
            else if(i+j==n-1) sum_2 = sum_2 + arr[i][j];
        }
    }

    if(sum_1>sum_2) cout << sum_1 - sum_2 << "\n";
    else cout << sum_2 - sum_1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 3. 8 Neighbours

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    char arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];   
        }
    }

    int x, y;
    cin >> x >> y;
    x = x-1; y = y-1; // 0-based indexing

    int row_1, row_2, col_1, col_2;

    // Defining x-1 and x+1
    if(x-1>=0 && x+1<=n-1) {
        row_1 = x-1;
        row_2 = x+1;
    } else if(x-1>=0 && x+1>n-1) {
        row_1 = x-1;
        row_2 = x;
    } else if(x-1<0 && x+1<=n-1) {
        row_1 = x;
        row_2 = x+1;
    } else {
        row_1 = x;
        row_2 = x;
    }

    // Defining y-1 and y+1
    if(y-1>=0 && y+1<=m-1) {
        col_1 = y-1;
        col_2 = y+1;
    } else if(y-1>=0 && y+1>m-1) {
        col_1 = y-1;
        col_2 = y;
    } else if(y-1<0 && y+1<=m-1) {
        col_1 = y;
        col_2 = y+1;
    } else {
        col_1 = y;
        col_2 = y;
    }

    for(int i=row_1; i<=row_2; i++) {
        for(int j=col_1; j<=col_2; j++) {
            if(i==x && j==y) continue;
            if(arr[i][j]!='x') {
                cout << "no\n";
                return;
            }
        }
    }
    cout << "yes\n";
}

// Optimised method of defining rows_1, rows_2, col_1, col_2
// int row_1 = max(0, x - 1);
// int row_2   = min(n - 1, x + 1);
// int col_1 = max(0, y - 1);
// int col_2   = min(m - 1, y + 1);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 4. Mirror Array

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        int start = 0;
        int end = m-1;
        while(start<end) {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 5. Matrix multiplication

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    
    int arr1[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr1[i][j];
        }
    }
    
    int arr2[m][p];
    for(int i=0; i<m; i++) {
        for(int j=0; j<p; j++) {
            cin >> arr2[i][j];
        }
    }
    
    int res[n][p];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            res[i][j] = 0;
            for(int k=0; k<m; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            cout << res[i][j] << " ";
        }
    }
    
}

int main() {
    solve();
    
    return 0;
}
