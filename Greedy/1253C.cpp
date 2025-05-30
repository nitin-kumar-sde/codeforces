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

    vector<ll> input(n);

    for(int i=0;i<n;i++)
    cin >> input[i];

    sort(input.begin(), input.end());

    for(int i=0;i<n;i++) {
        if(i+m < n)
        input[i+m] += input[i];
        
        if(i>0)
        input[i] += input[i-1];
    }

    for(int i=0;i<n;i++) {
       cout << input[i] << " ";
    }


    return 0;
}