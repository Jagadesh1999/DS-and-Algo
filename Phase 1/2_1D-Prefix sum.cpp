// 1. Prefix Sum and Difference Array Implementation

#include <bits/stdc++.h>
using namespace std;

void prefix_sum() {
    int n, q;
    cin>>n>>q;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
        v[i] = ((v[i]%MOD)+MOD)%MOD;
    }

    vector<int> ps(n);
    ps[0]=v[0];

    for(int i=1; i<n; i++) {
        ps[i]=(ps[i-1]+v[i])%MOD;
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        l-=1;
        r-=1;

        if(l!=0)
            cout << ((ps[r]-ps[l-1])+MOD)%MOD << "\n";
        else cout << ps[r] << "\n";
    }
}


void difference_array() {
    int n = 5; 
    vector<int> diff(n + 1, 0); 
  
    diff[1] += 5;
    diff[4] -= 5;

    diff[2] += 2;
    diff[5] -= 2;

    diff[0] += 3;
    diff[3] -= 3;

    vector<int> result(n);
    result[0] = diff[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + diff[i];
    }

    for (int val : result) {
        cout << val << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    prefix_sum();
    difference_array();
}

// 2. LR Sum Query

void solve() {
    int n, q;
    cin>>n>>q;

    const int mod = 1e9 + 7; 
    
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
        v[i] = ((v[i]%mod)+mod)%mod;
    }

    vector<int> ps(n);
    ps[0]=v[0];

    for(int i=1; i<n; i++) {
        ps[i]=(ps[i-1]+v[i])%mod;
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        l-=1;
        r-=1;

        if(l!=0)
            cout << ((ps[r]-ps[l-1])+mod)%mod << "\n";
        else cout << ps[r] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;  
}

// 3. Good Numbers

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    const int max = 1e6 + 2;
    vector<int> v(max,0);

    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;

        v[l]+=1;
        v[r+1]-=1;
    }

    vector<int> ps(max);
    ps[0]=v[0];
    for(int i=1; i<max; i++) {
        ps[i]=ps[i-1]+v[i];
    }

    vector<int> good(max, 0);
    for(int i=1; i<max; i++) {
        good[i]=(ps[i]>=k?1:0);
    }

    vector<int> ps_2(max, 0);
    for(int i=1; i<max; i++) {
        ps_2[i]=ps_2[i-1]+good[i];
    }

    while(q--) {
        int l, r;
        cin>>l>>r;

        cout << ps_2[r]-ps_2[l-1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;  
}



