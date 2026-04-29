class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n=len(text1)
        m=len(text2)

        tab=[[0 for x in range(n+1)] for x in range(m+1)]

        for i in range(m+1):
            for j in range(n+1):
                if i==0 or j==0:
                    tab[i][j]=0
                elif text2[i-1]==text1[j-1]:
                    tab[i][j]=tab[i-1][j-1]+1
                else:
                    tab[i][j]=max(tab[i-1][j],tab[i][j-1])
        return tab[m][n]