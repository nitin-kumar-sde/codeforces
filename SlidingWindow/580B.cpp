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

    ll n,d; cin >> n >> d;

    vector<pair<ll,ll> > input(n);

    for(int i=0;i<n;i++) {
        cin >> input[i].first;
        cin >> input[i].second;
    }

    // sort in order of money 
    sort(input.begin(), input.end());

    ll maxSum = 0;
    int i=0, j=0;
    ll currentSum = 0;

    while(j<n) {
        currentSum += input[j].second;
        ll diff = input[j].first - input[i].first;
        // move to valid window
        while(diff >= d) {
            currentSum -= input[i].second;
            i++;
            diff = input[j].first - input[i].first;
        }
        maxSum = max(maxSum, currentSum);
        j++;
    }

    cout << maxSum << endl;
    return 0;
}