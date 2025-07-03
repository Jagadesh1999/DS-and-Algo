#include <bits/stdc++.h> // Includes all the C++ libraries
using namespace std; // Imported to make use of cin, cout usage with less complexity

// C++ STL is classified into four parts :
// -- Algorithms
// -- Containers
// -- Functions
// -- Iterators

// Pairs -> To store 2 variables
void explainPair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << "\n";
    
    // What if, I need to store more than 2 variables?
    // Sol -> Use nested property of pairs
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << "\n";
    
    // Till now, we would have declared integer array, char array etc. 
    // Can we use a pair array?
    pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
    cout << arr[1].second << "\n";
}

// Lets learn the containers in STL :

// Vector - Dynamic Memory
void explainVector() {
    vector<int> v1;
    v1.size();
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(10);
    v1.push_back(20);
    v1.emblace_back(8); // Generally faster
    
    vector<pair<int, int>> v2;
    v2.push_back({2,3});
    v2.emblace_back(2,3);
    
    vector<int> v3(5, 100);
    vector<int> v4(v3); // Copy of the vector v3 is vector v4
    
    // Accessing the elements 
    cout << v1[0] << "\n";
    
    // Iterators in Vector :
    v1.begin(); // Points to the memory location of the element at 0th index
    v1.end(); // Points to the memory location that is after the element at the last index
    
    cout << v1.front() << "\n";
    cout << v1.back() << "\n";
    
    sort(v1.begin(), v1.end()); 
    reverse(v1.begin(), v1.end());
    
    // When l and r (0-based indices) are given
    sort(v1.begin()+l, v1.begin()+r+1);
    reverse(v1.begin()+l, v1.end()+r+1);
    
    v1.erase(v1.begin()+2); // Erase element at position 2 
    v1.erase(v1.begin()+2, v1.begin()+4) // Erase elemets from position 2 to position 3
    
    v1.insert(v1.begin(),300);
    
    v1.pop_back();
    
    v1.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    explainPair();
    explainVector();
}
