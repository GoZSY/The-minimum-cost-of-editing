/*************************************************************************************
/*
    当A=="" 或者B==""时，cost是删除或插入的代价
    当A!="" 且 B!= ""时
    A[i] == B[j] D[i][j] = D[i-1][j-1]
    A[i] != B[j] D[i][j] = MIN{D[i-1][j-1]+c2(修改一个值)，D[i-1][j]+c1(删除一个值)，D[i][j-1]+c0(插入一个值)}
*/
**************************************************************************************/
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) 
    {
        // write code here
        if(n==0 && m == 0)
            return 0;
        int dp[n+1][m+1];
        dp[0][0] = 0;
         
   
        for(int i = 1; i <= m; ++i)
            dp[0][i] = dp[0][i-1] + c0;
        
        for(int i = 1; i <= n; ++i)
            dp[i][0] = dp[i-1][0] + c1;
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
		{
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = t_min(dp[i-1][j-1]+c2,dp[i-1][j]+c1,dp[i][j-1]+c0);
        }
        return dp[n][m];
    }
private:
    int t_min(int a, int b, int c)
    {
        int m = (a < b) ? a : b;
        return (m < c) ? m : c;
    }
};
