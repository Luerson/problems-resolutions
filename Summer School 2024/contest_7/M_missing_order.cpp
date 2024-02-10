#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


vector<int> vec;
int dp[1001][1001];


int solve(int index, int target) {
    if (index == target)
        return 0;
    else if (dp[index][target] != -1)
        return dp[index][target];
    
    return dp[index][target] = solve(vec[index], target)+1;
}


long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 



int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ////////////////////////
    int n;

    
    cin >> n;
    
    vec.resize(n+10);
    memset(dp, -1, sizeof(dp));
    
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }
    
    set<int> vals;
    for (int i = 1; i <= n; i++)
    {
        // cout << "vec[" << i << "] = " << vec[i] << endl;
        vals.insert(solve(vec[i], i)+1);
    }

    int mmc = *vals.begin();
    for (int val : vals)
    {
        // cout << "mmc = " << mmc << "; val = " << val << endl;
        mmc = lcm(mmc, val);
    }
    cout << mmc << endl;
    // cout << "UOU" << endl;    
    // cout << ans << endl;
    

    return 0;
}