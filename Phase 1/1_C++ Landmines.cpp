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



