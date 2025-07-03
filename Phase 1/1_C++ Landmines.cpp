// 1. Odd One Out
void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int count=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(v[i]==v[j]) {
                count++;
            }
        }
        if(count%2!=0) {
            cout << v[i] << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;  
}

// 2. IO Problem 
void solve() {
    int x;
    cin>>x;

    string m;
    cin>>m;

    string y;
    string z;

    int count=0;
    for(int i=0; m[i]!='.'; i++) {
        y.push_back(m[i]);
        count++;
    }

    for(int i=count+1; m[i]!='\0'; i++) {
        z.push_back(m[i]);
    }

    int f = stoi(z)+x;
    int l = stoi(y)+x;

    cout << f << "." << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) solve();
    return 0;  
}

// 3. Contiguous subarray with the same difference between elements that has the maximum length

// Algorithm :
// -- Initialise 3 variables (currLen, maxLen, previous diff)
// -- Run loop from i=2 to i<n
// -- Find diff by performing A[i]-A[i-1]
// -- If previous diff==diff, 
//    Increment currLen by 1;
//    maxLen = max(maxLen, currLen);
// -- Else, 
//    previous diff=diff;
//    currLen = 2;
//    
void solve() {
    int n; cin>>n;
    vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];

    int maxLen = 2;
    int currLen = 2;
    int prev_diff = v[1]-v[0];

    for(int i=2; i<n; i++) {
        if(v[i]-v[i-1]==prev_diff) {
            currLen++;
            maxLen=max(maxLen, currLen);
        } else {
            prev_diff=v[i]-v[i-1];
            currLen=2;
        }
    }
    cout << maxLen << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;  
}

// 4. Sum of digits of a number (Number can be upto 10^6)

void solve() {
    string s;
    cin>>s;

    int sum=0;

    for(int i=0; s[i]!='\0'; i++) {
        sum = sum + (int)(s[i]-'0');
    }

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;  
}

// 5. Minimum operations to built the increasing Array/non - decreasing array
void solve() {
    int n; cin>>n;

    vector<int> v(n); 
    for(int i=0; i<n; i++) cin>>v[i];

    long long count=0;

    for(int i=1; i<n; i++) {
        if(v[i]<v[i-1]) {
            count += v[i-1]-v[i];
            v[i]=v[i-1];
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;  
}



