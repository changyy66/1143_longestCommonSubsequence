// 1143_longestCommonSubsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;
inline int max(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}
int longestCommonSubsequence(string text1, string text2) {
	int n1 = text1.size();
	int n2 = text2.size();
	if (n1 == 0 || n2 == 0)return 0;
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
	for (int i = 1; i < n1 + 1; i++)
	{
		for (int j = 1; j < n2 + 1; j++)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n1][n2];
}

int main()
{
    return 0;
}

