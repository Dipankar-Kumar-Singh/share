#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 1e5 +10 ;

vector<int> seg[4*N] ;
vector<int> v ; 

void build(int n ,int s , int e)
{
    if(s==e)
    {
        seg[n].push_back(v[s]) ; 
        return ;
    }

    int mid = (s+e)/2 ;

    build(2 * n + 1, s, mid);
    build(2 * n + 2, mid + 1, e);

    merge(all(seg[2*n+1]),all(seg[2*n+2]),back_inserter(seg[n])) ;
}


int query(int n ,int s, int e, int l , int r , int val)
{

    if( s > r or e < l  )
    {
        return 0 ;
    }

    if( l <= s and e <= r)
    {
        int ans = (seg[n].size() - (lower_bound(all(seg[n]),val) - seg[n].begin())) ;
        return  ans;
    }

    int mid = (s+e)/2 ;
    return (query(2 * n + 1, s, mid , l, r, val) + query(2 * n + 2, mid + 1, e, l, r, val));

}


void print_ans(int t_c, vector<int> vec)
{
    cout << "Case #" << t_c << ": " ;
    for(auto &x : vec) cout << x << " " ;
    cout << "\n" ;
}

void solve(int tc)
{
    int n ; cin >> n ;

    v.clear() ; v.resize(n) ; for(auto &x : v) cin >> x ; 
    for(int i = 0 ; i < 4*N ; i++) seg[i].clear() ;

    build(0,0,n-1) ;
    vector<int> ans ; 

    for(int i = 0 ; i < n ; i++)
    {
        int l = 0 , r = i + 2  ; 
        while (r-l>1)
        {
            int mid = (l+r)/2 ;
            if(query(0,0,n-1,0,i,mid)>=mid)  l = mid ;
            else r = mid ;
        }
        ans.push_back(l) ;
    }
    print_ans(tc,ans) ;
}


signed main()
{
    FAST 

    int test_case ;     cin >> test_case ;

    for(int tc = 1 ; tc <= test_case ; tc++)
    {
            solve(tc) ;
    }
}

