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

int freq[2] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/codeforces/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/codeforces/output.txt", "w", stdout);
    #endif

    int n,k; cin >> n >> k;
    string s; cin >> s;

    int i=0, j=0;
    int maxLength = 0;

    while(j<n) {
        freq[s[j] - 'a']++;

        // move to valid segment
        while(min(freq[0], freq[1]) >k) {
            freq[s[i] - 'a']--;
            i++;
        }
        maxLength = max(maxLength, j-i+1);
        j++;
    }

    cout << maxLength << endl;
    return 0;
}