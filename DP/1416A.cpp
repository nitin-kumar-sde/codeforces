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
        int n; cin >> n;
        vector<int> input(n+1);

        for(int i=1;i<=n;i++)
        cin >> input[i];

        vector<int> lastIndex(n+1,0);
        vector<int> maxGap(n+1,-1);
        vector<int> minK(n+1,-1);

        for(int i=1;i<=n;i++) {
            maxGap[input[i]] = max(maxGap[input[i]], i-lastIndex[input[i]]);
            lastIndex[input[i]] = i;
        }

        for(int i=1;i<=n;i++) {
            maxGap[input[i]] = max(maxGap[input[i]], n-lastIndex[input[i]] +1);
        }

        for(int i=1;i<=n;i++) {
            for(int j = maxGap[i]; j<=n;j++)  {
                if(minK[j] != -1 || maxGap[i] == -1) break;
                minK[j] = i;
            }
        }
        for(int i=1;i<=n;i++) {
            cout << minK[i] << " ";
        }
        cout << endl;

    }

    return 0;
}