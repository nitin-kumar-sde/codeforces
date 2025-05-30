#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/codeforces/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/codeforces/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;

    string s, t; cin >> s >> t;

    int i = 0, j = 0;

    vector<int> prefix(m, n);
    vector<int> suffix(m, -1);
    while(i < n && j < m) {
        if(s[i] == t[j]) {prefix[j] = i; i++; j++;}
        else {i++;}
    }
    i = n-1, j = m-1;
    while( i >=0 && j >= 0) {
        if(s[i] == t[j]) {suffix[j] = i; i--; j--;}
        else {i--;}
    }

    int ans = 1;
    for(int i=0;i<m-1;i++) {
        ans = max(ans, suffix[i+1] - prefix[i]);
    }

    cout << ans << endl;
    return 0;
}