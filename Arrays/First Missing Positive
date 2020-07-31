problem link https://leetcode.com/problems/first-missing-positive/

code
Solution 1:
O(N) time and O(N) space complexity

class Solution {
public:
int firstMissingPositive(vector<int> &v) 
{
    int n=v.size();
    if(n==0) return 1;
    bool vis[n];
    memset(vis,0,sizeof(vis));
    for(auto x:v)
        if(x>0 && x<=n)
            vis[x-1]=1;
            
    for(int i=0;i<n;i++)
        if(!vis[i])
            return i+1;
    return n+1;
}
};

Solution 2:
O(N) time and O(1) space complexity
We can use idea of hashing using the same array by making the terms negatives which are already present but it will fail if the elements in array are 
already negative.So we come up with a similar idea,so we try to shift 1 to 1st pos, 2 to 2nd pos and so on.We ignore values larger than n and -ve values.
The inner while loop runs till every number is at its correct place.O(N)+O(N)=O(N)
class Solution {
public:
int firstMissingPositive(vector<int> &v) 
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(v[i]>0 && v[i]<=n)
        {
            while(v[i]>0 && v[i]<=n && v[v[i]-1]!=v[i])
            {
                swap(v[i],v[v[i]-1]);
            }
        }
    }
    for(int i=0;i<n;i++)
        if(v[i]!=i+1)
            return i+1;
    return n+1;
}
};
