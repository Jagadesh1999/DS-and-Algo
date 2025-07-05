#include <bits/stdc++.h>
using namespace std;

void explainStrings() {
    string s;
    // string s="";
    // string s="Casuals";
    
    getline(cin, s);
    // s.pushback(6);
    
    cout << s[i] << s.front() << " " << s.back << " ";
    
    s.pop_back();
    
    s.size();
    sort(s.begin(), s.end()); // sort(s.begin()+l-1, s.begin()+r);
    reverse (s.begin(), s.end()); // reverse(s.begin()+l-1, s.begin()+r);
    string s2 = s.substr(l,r-l+1);
    
    cout << s << " " << s2 << "\n";
}

void explainVector() {
    vector<int> v;
    // vector<int> 
    // vector <int> v(n, 4); 
    
    for(int i=0; i<n; i++) {
        cin>>v.push_back(i);
        // O(1) for a single push_back
        // O(n) for the complete push_back for n elements
    }
    v.insert(v.begin()+2, 10);
    
    cout << v[i] << " " << v.front() << " " << v.back() << "\n"; // O(1)
    
    v.pop_back();
    v.erase(v.begin()+2);
    // O(1)
    
    v.size() // O(1)
    v.swap(v1) // O(1)
    v.clear // O(1)
    
    for(auto it: v) {
        cout << it << " ";
    } // O(n)
}

void explainStack() {
    int n; 
    cin>>n;
    
    stack<int> st;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        st.push(x);
    }
    // O(n) for n pushes
    
    cout << st.top() << " "; // O(1)
    st.pop(); // Removes the top element
     
    if(!st.empty()) {
        cout << st.size() << "\n";
    } // O(1)
    
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    // O(n)
}

void explainQueue() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    // O(n) for n pushes

    cout << q.front() << " "; // O(1)
    q.pop(); // Removes the front element

    if (!q.empty()) {
        cout << q.size() << "\n"; // O(1)
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    // O(n)
}

void explainMap() {
    map<int, string> mp;
    
    map<int, string> mp = {{101, "apple"}, {102, banana}};
    // mp[101] = "apple";
    // mp[102] = "banana";
    // O(nlogn)
    
    // int n; cin >> n;
    // map<int, string> mp;
    
    // for(int i=0; i<n; i++) {
    //     int key; 
    //     cin >> key;
    //     string value;
    //     cin >> value;
        
    //     mp[key]=value;
    // }
    // O(logn) per insertion
    
    if(mp.find(101)!=mp.end())
        cout << mp[101] << "\n"; // O(log n) for accessing
        
    cout << mp.size() << "\n";
    
    for(auto it : mp) {
        cout << mp.first << " " << mp.second << "\n";
    } // O(n)
}

void explainMultimap() {
    multimap<int, string> mm;

    multimap<int, string> mm = {{101, "apple"}, {102, "banana"}, {101, "avocado"}};
    // mm.insert({101, "apple"});
    // mm.insert({102, "banana"});
    // mm.insert({101, "avocado"});
    // O(n log n)

    // int n; cin >> n;
    // multimap<int, string> mm;
    
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;
    //     string value;
    //     cin >> value;

    //     mm.insert({key, value});
    // }
    // O(log n) per insertion

    if (mm.find(101)!=mm.end()) {
        // prints first value with key 101
        cout << mm.find(101)->second << "\n"; // O(log n)
    }

    cout << mm.size() << "\n";

    for (auto it : mm) {
        cout << it.first << " " << it.second << "\n";
    } // O(n)
}

void explainPriorityQueue() {
    // vector<int> initList = {3, 1, 4, 1, 5, 9, 2, 6};
    // priority_queue<int> taskPriorityQueue(initList.begin(), initList.end());

    priority_queue<int> pq;

    priority_queue<int> pq2;
    pq2.push(30);
    pq2.push(10);
    pq2.push(40);
    // Equivalent to:
    // priority_queue<int> pq2 = {30, 10, 40}; // Not allowed in C++
    // Must use push()
    // O(log n) per insertion

    // int n; cin >> n;
    // priority_queue<int> pq;
    // for (int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     pq.push(x);
    // }
    // O(log n) per insertion

    if (!pq2.empty()) {
        // prints largest element
        cout << pq2.top() << "\n"; // O(1)
    }

    cout << pq2.size() << "\n";

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    } // O(n log n)
}

void explainSet() {
    set<int> st;

    set<int> st = {101, 102, 105, 103};
    // st.insert(101);
    // st.insert(102);
    // st.insert(105);
    // st.insert(103);
    // O(n log n) for initialization (heap + balancing during insertion)

    // int n; cin >> n;
    // set<int> st;
    
    // for(int i = 0; i < n; i++) {
    //     int value;
    //     cin >> value;
    //     st.insert(value);
    // }
    // O(log n) per insertion

    if (st.find(101)!=st.end())
        cout << "101 is present\n";  // O(log n) for find

    cout << st.size() << "\n"; // O(1)
    cout << st.count(1) << "\n"; 

    for (auto it : st) {
        cout << it << " ";
    } // O(n) – prints in **sorted order**

    cout << "\n";
}

void explainMultiset() {
    multiset<int> ms;

    multiset<int> ms = {101, 102, 101, 103};
    // ms.insert(101);
    // ms.insert(102);
    // ms.insert(101);
    // ms.insert(103);
    // O(n log n) for initialization (with duplicates allowed)

    // int n; cin >> n;
    // multiset<int> ms;
    
    // for(int i = 0; i < n; i++) {
    //     int value;
    //     cin >> value;
    //     ms.insert(value);
    // }
    // O(log n) per insertion

    if (ms.find(101) != ms.end())
        cout << "101 is present\n";  // O(log n) for find (returns iterator to any one occurrence)

    cout << ms.size() << "\n"; // O(1)
    cout << ms.count(1) << "\n";

    for (auto it : ms) {
        cout << it << " ";
    } // O(n) – prints in **sorted order**, including duplicates

    cout << "\n";

    // Erasing a single instance of 101 (only one, not all)
    auto it = ms.find(101);
    if (it != ms.end()) ms.erase(it); // O(log n)

    // Erasing all instances of 101
    ms.erase(101); // O(log n) * number of instances
}

void explainDeque() {
    deque<int> dq;

    deque<int> dq = {10, 20, 30};
    // dq.push_back(10);
    // dq.push_back(20);
    // dq.push_back(30);
    // O(n) for initialization (copying all elements)

    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int x; cin >> x;
    //     dq.push_back(x);
    // }
    // O(1) amortized for push_back
    // O(1) amortized for push_front

    dq.push_front(5);  // Adds to front – O(1)
    dq.push_back(40);  // Adds to back – O(1)

    dq.pop_front();    // Removes front – O(1)
    dq.pop_back();     // Removes back – O(1)

    cout << "Front: " << dq.front() << "\n"; // O(1)
    cout << "Back: " << dq.back() << "\n";   // O(1)

    cout << "Size: " << dq.size() << "\n";   // O(1)

    for (auto it : dq) {
        cout << it << " ";
    } // O(n) – prints in order from front to back

    cout << "\n";

    // Access by index
    cout << "Element at index 1: " << dq[1] << "\n"; // O(1) random access
}



int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    
    explainStrings();
    explainVector();
    explainStack();
    explainQueue();
    explainMap();
    explainMultimap();
    explainPriorityQueue();
    explainSet();
    explainMultiset();
    explainDequeue();
    
    return 0;
}
