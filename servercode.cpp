#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"

vector<int> solve(int n, vector<vector<int>> log_data, vector<int> query, int x)
{
    vector<vector<int>> mp(n + 1);
    int m = log_data.size();

    for (auto &vec : log_data)
    {
        int serverid = vec[0];
        int hitTime = vec[1];
        mp[serverid].push_back(hitTime);
    }


    for (auto &vec : mp)
        sort(begin(vec), end(vec));

    vector<int> ans;

    for (int q : query)
    {
        int l = q - x;
        int r = q;

        // should not be in [L ____R]
        int count = 0 ;

        for (int service = 1; service <= n; service++)
        {
            auto &t = mp[service];
            int a = t.size() - (lower_bound(begin(t), end(t), l) - t.begin());
            int b = t.size() - (lower_bound(begin(t), end(t), r + 1) - t.begin());
            int inRange = b - a;
            count += (inRange == 0) ;
        }
        ans.push_back(count) ;
    }

    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // int n = 6 , m = 4 ,

    // int n = 6 ;
    // vector<vector<int>> log_data = {{3, 2}, {4, 3}, {2, 6}, {6, 3}};
    // vector<int> query = {1, 2, 3, 4, 5, 6};
    // int x = 1;

    int n = 4 ;
    vector<vector<int>> log_data = {{1, 3}, {2, 6}, {1, 5}, {3, 4}};
    vector<int> query = {10 , 6};
    int x = 5;


    auto ans = solve(n, log_data, query, x) ;
    for(auto x : ans ){
        cout <<  x << " " ;
        cout << nl ;
    }

    cout << nl ;
}
