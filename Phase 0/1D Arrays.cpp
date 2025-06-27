// 1. Perform the Linear Search.

void solve() {
    int n; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int x; cin >> x;

    for(int i=0; i<n; i++) {
        if(arr[i]==x) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 2. Replace every positive number in the array with 1 and every negative number with 2 and Zeroes remain unchanged.

void solve() {
    int n; cin >> n;

    int arr[n]; 
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        if(arr[i]>0) arr[i]=1;
        else if(arr[i]<0) arr[i]=2;
    }

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 3. Print the positions of the array that store a value less than or equal to 10.

void solve() {
    int n; cin >> n;

    int arr[n]; 
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        if(arr[i]<=10) 
            cout << "A[" << i << "] = " << arr[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t; 
    while(t--) solve();

    return 0;
}

// 4. Perform Array Reversal (2-pointer technique)

void solve() {
    int n; cin >> n;

    int arr[n]; 
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = n-1;

    while(start<end) {
        swap(arr[start],arr[end]);
        start ++;
        end --;
    }

    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

// 5. Bubble Sort Algorithm

// Bubble Sort :
// Total passes -> n-1;
// Total comparisons in each pass -> n-1;
// If no swap after each pass, array is sorted
// Use j<n-1-i to not compare the sorted portion

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i++) {
        bool performSwap = false;
        for(int j=0; j<n-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                if(!performSwap) performSwap = true;
            }
        }
        if(!performSwap) {
            for(int i=0; i<n; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
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

// 6. Maximum value of all the subarrays in the array

// Approach :
// For each element 'i'in the array, consider all the subarrays that can be formed with 'i' as the first number
// For each subarray possible, store the max in a vector
// Sort and print the vector.

void solve() {
    int n; 
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> maxList;

    for(int i=0; i<n; i++) {
        int maximum = arr[i];
        for(int j=i; j<n; j++) {
            maximum = max(maximum, arr[j]);
            maxList.push_back(maximum);
        }
    }

    sort(maxList.begin(), maxList.end());

    for(int i=0; i<maxList.size(); i++) {
        cout << maxList[i] << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 7. Replace minmax in the array

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int min, max;
    min = max = v[0];

    int minIndex, maxIndex;
    minIndex = maxIndex = 0;

    for(int i=1; i<n; i++) {
        if(v[i]<min) {
            min=v[i];
            minIndex=i;
        }
        else if(v[i]>max) {
            max=v[i];
            maxIndex=i;
        }
    }

    swap(v[minIndex], v[maxIndex]);

    for(int i=0; i<n; i++) cout << v[i] << " ";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 8. Is B a Permutation of A

// Approach :
// 1. Sort both the arrays
// 2. Check if they are equal

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++) {
        if(a[i]!=b[i]) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 9. Is B a subsequence of A?

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> b(m);
    for(int i=0; i<m; i++) cin >> b[i];

    int count=0;
    int j=0;

    for(int i=0; i<n; i++) {
        if(a[i]==b[j]) {
            count ++;
            j++;
            continue;
        }else continue;
    }

    if(count==m) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}

// 10. Frequency Array

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> fv(m+1);

    // for(int i=1; i<=m; i++) {
    //     for(int j=0; j<n; j++) {
    //         if(i==v[j]) fv[i]++;
    //     }  
    // }

    for(int i=0; i<n; i++) {
        fv[v[i]]++;
    }

    for(int i=1; i<=m; i++) cout << fv[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

// 11. Palindrome Array Check

void solve() {
    int n; cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int start=0; int end=n-1;

    while(start<end) {
        if(v[start]!=v[end]) {
            cout << "NO\n";
            return;
        }
        start ++;
        end --;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

// 12. Lucky Array

void solve() {
    int n; cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int min = v[0];
    for(int i=0; i<n; i++) {
        if(v[i]<min) min = v[i];
    }

    int count=0;
    for(int i=0; i<n; i++) {
        if(v[i]==min) count ++;
    }

    if(count%2==0) cout << "Unlucky\n";
    else cout << "Lucky\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;  
}


















