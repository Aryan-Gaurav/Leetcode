Problem Link
https://leetcode.com/problems/sqrtx/
https://www.interviewbit.com/problems/square-root-of-integer/

Implement int sqrt(int x)

Code:
int Solution::sqrt(int n) 
{
    int low=0,high=1e5;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if((long long)mid*mid>n)
            high=mid-1;
        else low=mid+1;
    }
    return high;
}
