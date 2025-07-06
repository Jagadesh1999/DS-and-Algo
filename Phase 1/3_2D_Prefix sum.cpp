// Prefix Sum and Difference Array Implementation

#include <bits/stdc++.h>
using namespace std;

void prefix_sum_2D() {
    int n = 3, m = 3;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> ps(n, vector<int>(m, 0));

    // Step 1: Build the 2D prefix sum matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ps[i][j] = mat[i][j];
            if(i > 0) ps[i][j] += ps[i-1][j];
            if(j > 0) ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0) ps[i][j] -= ps[i-1][j-1];
        }
    }

    // Step 2: Query submatrix sum from (x1,y1) to (x2,y2)
    int x1 = 1, y1 = 1, x2 = 2, y2 = 2; // 1-indexed based (0-based in code)

    int total = ps[x2][y2];
    if(x1 > 0) total -= ps[x1-1][y2];
    if(y1 > 0) total -= ps[x2][y1-1];
    if(x1 > 0 && y1 > 0) total += ps[x1-1][y1-1];

    cout << "Submatrix Sum (1,1 to 2,2): " << total << endl;

    // Print the full prefix sum matrix
    cout << "Prefix Sum Matrix:\n";
    for(auto& row : ps) {
        for(auto val : row) cout << val << " ";
        cout << "\n";
    }
}

