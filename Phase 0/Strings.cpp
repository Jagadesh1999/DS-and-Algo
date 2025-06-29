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

