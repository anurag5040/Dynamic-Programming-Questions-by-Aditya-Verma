#include <bits/stdc++.h>
using namespace std;

int LCSubstr(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = 0;

	int mx = INT_MIN;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, dp[i][j]);

	return mx;
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCSubstr(X, Y, n, m) << endl;
	return 0;
}


/*

 int solve(string &s, string &t, int n, int m, int &ans, vector<vector<int>> &dp) {
        if(n==0 || m==0)    return 0;
        if(dp[n][m]!=-1)    return dp[n][m];
        
        int temp=0;
        if(s[n-1]==t[m-1]) {
            temp= 1+solve(s, t, n-1, m-1, ans, dp);
        }
        
        solve(s, t, n-1, m, ans, dp);
        solve(s, t, n, m-1, ans, dp);
        
        ans=max(ans, temp);
        return dp[n][m]=temp;
    }
    
    int longestCommonSubstr(string s, string t, int n, int m)
    {
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        solve(s, t, n, m, ans, dp);
        return ans;
    }
    
    */
