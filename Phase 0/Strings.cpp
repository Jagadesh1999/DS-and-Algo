// 1. Way too long words

void solve() {
    string word;
    getline(cin, word);

    int length=0;
    for(int i=0; word[i]!='\0'; i++) {
        length ++;
    }

    if(length>10) {
        cout << word[0] << length-2 << word[length-1] << "\n";
    } else cout << word << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    cin.ignore();
    while(t--) solve();

    return 0;  
}

// 2. Reverse each words in the sentence

void solve() {
    string word;

    while(cin >> word) {
        int length=0;
        for(int i=0; word[i]!='\0'; i++) {
            length++;
        }

        int start=0; int end=length-1;
        while(start<end) {
            swap(word[start], word[end]);
            start++; end--;
        }

        cout << word << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;  
}

// 3. Count the Letters

void solve() {
    string text;
    getline(cin, text);

    vector<int> v(26);
    for(int i=0; text[i]!='\0'; i++) {
        v[text[i]-'a']++;
    }

    for(int i=0; i<v.size(); i++) {
        if(v[i]>0) cout << (char)(i+'a') << " : " << v[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;  
}

// 4. I love Strings

void solve() {
    string s, t;
    cin >> s >> t;

    string n;
    n.reserve(1000);

    for(int i=0; i<min(s.size(), t.size()); i++) {
        n += s[i];
        n += t[i];
    }
    
    for(int i=min(s.size(), t.size()); i<max(s.size(), t.size()); i++) {
        if(s.size()>t.size()) n += s[i];
        else if(t.size()>s.size()) n += t[i];
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    cin.ignore();

    while(t--) solve();

    return 0;  
}

// 5. String Functions

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    cin.ignore();

    string s; 
    getline(cin, s);
    int l, r; // Only the declaration part

    while (q--) {
        string type; cin >> type;
        if(type=="pop_back"){
            s.pop_back();
        }else if(type=="front"){
            cout << s.front() << endl;
        }else if(type=="back"){
            cout << s.back() << endl;
        }else if(type=="sort"){
            cin >> l >> r;
            if(l > r) {
                swap(l, r);
            }
            sort(s.begin()+l-1, s.begin()+r);
        }else if(type=="reverse") {
            cin >> l >> r;
            if (l > r) {
                swap(l, r);
            }
            reverse(s.begin()+l-1, s.begin()+r);
        }else if (type=="print") {
            int pos; cin >> pos;
            cout << s[pos-1] << endl;
        } else if (type=="substr") {
            cin >> l >> r;
            if (l > r) {
                swap(l, r);
            }
            string substr = s.substr(l-1, r-l + 1);
            cout << substr << endl;
        } else {
            char c; cin >> c;
            s.push_back(c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 6. String URL

void solve() {
    string s;
    getline(cin,s);

    int value = s.find('?');
    for(int i=value+1; i<s.size(); i++) {
        if(s[i]=='&') {
            cout << "\n";
        } else if(s[i]=='=') {
            cout << ": ";
        }
        else cout << s[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;  
}
