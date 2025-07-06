// Prefix Sum and Difference Array Implementation

#include <bits/stdc++.h>
using namespace std;

void prefix_sum_2D() {
    int n, m;
    cin >> n >> m;

    int mat[n][m], ps[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
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

    int diff[n+2][m+2] = {0};
    int ps[n][m], result[n][m];

    int u;
    cin >> u;
    for(int i = 0; i < u; i++) {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;

        diff[x1][y1] += val;
        diff[x2+1][y1] -= val;
        diff[x1][y2+1] -= val;
        diff[x2+1][y2+1] += val;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ps[i][j] = diff[i][j];
            if(i > 0) ps[i][j] += ps[i-1][j];
            if(j > 0) ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0) ps[i][j] -= ps[i-1][j-1];
        }
    }

    for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cout << ps[i][j] << " ";
    }
    cout << "\n";
}

int main() {
    prefix_sum_2D();
    difference_array_2D();
    return 0;
}


// 2. Rectangle Sum Query

#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    int mat[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>mat[i][j];
            mat[i][j]=((mat[i][j]%mod)+mod)%mod;
        }
    }

    int ps[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ps[i][j]=mat[i][j];
            if(i>0) ps[i][j]=(ps[i][j]+ps[i-1][j])%mod;
            if(j>0) ps[i][j]=(ps[i][j]+ps[i][j-1])%mod;
            if(i>0 && j>0) ps[i][j]=((ps[i][j]-ps[i-1][j-1])+mod)%mod;
        }
    }

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1-=1; y1-=1; x2-=1; y2-=1;

        int total = ps[x2][y2];
        if(x1>0) total=((total-ps[x1-1][y2])+mod)%mod;
        if(y1>0) total=((total-ps[x2][y1-1])+mod)%mod;
        if(x1>0 && y1>0) total=(total+ps[x1-1][y1-1])%mod;

        cout << total << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;  
}

// 2. Max Value in the Rectangle

#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
long long mat[N][N]; // difference array
long long ps[N][N];  // prefix sum

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    // Apply all updates
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        x1--, y1--, x2--, y2--; // convert to 0-based indexing

        mat[x1][y1] += c;
        mat[x1][y2 + 1] -= c;
        mat[x2 + 1][y1] -= c;
        mat[x2 + 1][y2 + 1] += c;
    }

    long long maxVal = LLONG_MIN;
    int count = 0;

    // Build prefix sum and count max value cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ps[i][j] = mat[i][j];
            if (i > 0) ps[i][j] += ps[i - 1][j];
            if (j > 0) ps[i][j] += ps[i][j - 1];
            if (i > 0 && j > 0) ps[i][j] -= ps[i - 1][j - 1];

            if (ps[i][j] > maxVal) {
                maxVal = ps[i][j];
                count = 1;
            } else if (ps[i][j] == maxVal) {
                count++;
            }
        }
    }

    cout << maxVal << " " << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
