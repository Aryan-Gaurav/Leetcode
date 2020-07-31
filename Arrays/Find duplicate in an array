problem link https://leetcode.com/problems/find-the-duplicate-number/
Statement:Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one(it may occur more than once).

Normal solution in O(n) time and O(n) space complexity using hash map,O(nlogn) using binary search and O(1) space.In interviewbit O(n) and O(sqrt(n)) space.
O(1) space:
Solution 1:

Idea is to use the given array as a hashmap.The values which are ecounterd before,its index has -ve values.If we ecounter a value which is already -ve then we got 
the duplicate.

class Solution {
public:
int findDuplicate(vector<int>& v) 
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        int val=abs(v[i]);
        if(v[val]<0)
            return val;
        else v[val]*=-1;
    }
    return -1;    
}
};
Solution 2:
O(1) space
If the array is read only(immutable).
Same idea as linked list cycle detection.
int findDuplicate(const vector<int>& v) //could also do by subtracting 1 for better understanding
{
    int fast=v[v[0]],slow=v[0];
    while(fast!=slow)
    {
        fast=v[v[fast]];
        slow=v[slow];
    }
    fast=0;
    while(fast!=slow)
    {
        fast=v[fast];
        slow=v[slow];
    }
    return slow;   
}
ALITER:
suppose the array is

index: 0 1 2 3 4 5

value: 2 5 1 1 4 3

first subtract 1 from each element in the array, so it is much easy to understand.
use the value as pointer. the array becomes:

index: 0 1 2 3 4 5

value: 1 4 0 0 3 2

![enter image description here][1]

Second if the array is

index: 0 1 2 3 4 5

value: 0 1 2 4 2 3

we must choose the last element as the head of the linked list. If we choose 0, we can not detect the cycle.
int findDuplicate(const vector<int>& v) 
{
    int n=v.size();
    int fast=v[v[n-1]-1],slow=v[n-1];
    while(fast!=slow)
    {
        fast=v[v[fast-1]-1];
        slow=v[slow-1];
    } 
    fast=n;
    while(fast!=slow)
    {
        slow=v[slow-1];
        fast=v[fast-1];
    }
    return fast;   
}
