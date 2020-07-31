Problem Link https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Code
Solution 1: 
O(N) time and O(1) space complexity

class Solution {
public:
vector<int> findDisappearedNumbers(vector<int> &v) 
{
    int n=v.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int val=abs(v[i]);
        if(v[val-1]>0)
            v[val-1]*=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
            ans.push_back(i+1);
    }
    return ans;
}
};
Solution 2:
O(N) time and O(1) space complexity(IDEA IS JUST LIKE First Missing Positive)

class Solution {
public:
vector<int> findDisappearedNumbers(vector<int> &v) 
{
    int n=v.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
       while(v[i]!=i+1 && v[v[i]-1]!=v[i])
        swap(v[i],v[v[i]-1]); 
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]!=i+1)
            ans.push_back(i+1);
    }
    return ans;
}
};
