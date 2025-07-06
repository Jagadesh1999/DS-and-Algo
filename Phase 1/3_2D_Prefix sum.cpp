#include <bits/stdc++.h>
using namespace std;

const int max = 105;
int mat[max][max], diff[max][max], ps[max][max], result[max][max];

void prefix_sum_2D() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ps[i][j] = mat[i][j];
            if(i > 0) ps[i][j] += ps[i-1][j];
            if(j > 0) ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0) ps[i][j] -= ps[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int total = ps[x2][y2];
        if(x1 > 0) total -= ps[x1-1][y2];
        if(y1 > 0) total -= ps[x2][y1-1];
        if(x1 > 0 && y1 > 0) total += ps[x1-1][y1-1];
        cout << total << "\n";
    }
}

void difference_array_2D() {
    int n, m;
    cin >> n >> m;

    int u;
    cin >> u;
    for(int i=0; i<u; i++) {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        diff[x1][y1] += val;
        diff[x2+1][y1] -= val;
        diff[x1][y2+1] -= val;
        diff[x2+1][y2+1] += val;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ps[i][j] = diff[i][j];
            if(i > 0) ps[i][j] += ps[i-1][j];
            if(j > 0) ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0) ps[i][j] -= ps[i-1][j-1];
            result[i][j] = ps[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    prefix_sum_2D();
    difference_array_2D();
    return 0;
}
