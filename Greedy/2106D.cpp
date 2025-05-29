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

    int t; cin >> t; 

    while(t--) {

        int n,m; 
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];

        vector<ll> prefix(m, n);

        // compute prefix 
        ll i = 0, j = 0;
        while(i<n && j<m) {
            if(a[i] >= b[j]) {prefix[j] = i; j++; i++;}
            else { i++;}
        }

        if(j==m) {
            cout << 0 << endl;
            continue;
        }

        vector<ll> suffix(m+1, -1);
        i = n-1; j = m-1;
        
        // compute suffix
        while(i >=0 && j >=0) {
            if(a[i] >= b[j]) {suffix[j] = i;i--; j--;}
            else {i--;}
        }

        ll ans = 1e12;

        for(int i=0;i<m;i++) {
            ll front = (i==0 ? -1 : prefix[i-1]);
            ll back = (i == (m-1) ? n : suffix[i+1]);
            if(front < back) ans = min(ans, b[i]);
        }

        if(ans == 1e12) ans = -1;

        cout << ans << endl;
    }

    return 0;
}