#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <numeric> 
 
using namespace std;
 
#define ll long long
 
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007
 
bool isPenaltyPossible(vector<ll> input, ll n , ll k, string s, ll panelty) {
    ll count = 0;
    bool isStarted = false;
 
    for(int i=0; i<n;i++) {
        if(input[i] > panelty && !isStarted && s[i] == 'B') {
            isStarted = true;
            count++;
        }
        if(input[i] > panelty && isStarted && s[i] == 'R') {
            isStarted = false;
        }
    }
    return count <= k;
}
 
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

        ll n; cin >> n; ll k; cin >> k;
        string s; cin >> s;
 
        vector<ll> input(n);
        for(int i=0;i<n;i++) 
        cin >> input[i];
 
        ll low = 0;
        ll high = 0;
        // find bounds for answer  
        for(int i=0;i<s.length();i++) {
            if(s[i] == 'B') {
                high = max(high, input[i]);
            }
        }
       
        ll minPanelty = high;
 
        while(low <= high) {          
            ll mid = (low + high)/2;
            if(isPenaltyPossible(input, n, k, s, mid)){
                minPanelty = mid;
                high = mid-1;
            }
            else 
            low = mid+1;
        }
 
        cout << minPanelty << endl;
    } 
 
    return 0;
}