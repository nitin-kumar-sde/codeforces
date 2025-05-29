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

bool isPossible(vector<ll> cities, vector<ll> towers, int n, 
    int m , ll r) {
    int i = 0, j=0;
    while(i < n && j < m) {
         ll rightEnd = towers[j] + r; 
         ll leftEnd = towers[j] - r;

         if(cities[i] < leftEnd) return false;
         while(i < n && cities[i] <= rightEnd) i++;
         j++;
    }
    return (i == n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/codeforces/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/codeforces/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;

    vector<ll> cities(n);
    vector<ll> towers(m);

    for(int i=0;i<n;i++) 
    cin >> cities[i];

    for(int i=0;i<m;i++) 
    cin >> towers[i];

    ll low = 0, high = 2e9;
    ll ans = high;
    // binary search on radius(r)
    while(low <=high) {

        ll mid = (low + high)/2;
        if(isPossible(cities,towers,n, m, mid )) {
            high = mid-1;
            ans = mid;
        }
        else 
        low = mid + 1;
    }

    // low to points to min of solution space.
    cout << low << endl;

    return 0;
}