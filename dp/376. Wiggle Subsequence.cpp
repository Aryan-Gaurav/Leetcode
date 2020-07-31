Problem Link https://leetcode.com/problems/wiggle-subsequence/

Code
Solution 1: O(N^2)

class Solution {
public:
int wiggleMaxLength(vector<int> &v) 
{
    int n=v.size();
    if(n<=1)
        return n;
    int inc[n],dec[n];
    inc[0]=1,dec[0]=1;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        inc[i]=1,dec[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i] && inc[i]<dec[j]+1)
                inc[i]=dec[j]+1;
            if(v[j]>v[i] && dec[i]<inc[j]+1)
                dec[i]=inc[j]+1;
        }
        ans=max({ans,inc[i],dec[i]});
    }
    return ans;       
}
};
Solution 2: O(N)
