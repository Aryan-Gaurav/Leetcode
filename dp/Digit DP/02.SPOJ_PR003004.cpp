/*
Link to problem: https://www.spoj.com/problems/PR003004/

Statement:
For a pair of integers a and b, the digit sum of the interval [a,b] is defined as the sum of all digits occurring in all numbers between (and including) a and b. For example, the digit sum of [28, 31] can be calculated as:

               2+8  +  2+9  +  3+0  +  3+1 = 28
Given the numbers a and b, calculate the digit sum of [a,b].

Input
On the first line one positive number: the number of test cases, at most 100.

After that per test case:

one line with two space-separated integers, a and b (0 <= a <= b <= 10^15).
Output
Per test case:

one line with an integer: the digit sum of [a,b];
Example
Input:
3
0 10
28 31
1234 56789

Output:
46
28
1128600
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Digit DP:
Source:
https://codeforces.com/blog/entry/84928
https://codeforces.com/blog/entry/53960
*/
ll sumOfDigits(ll r){
string number=to_string(r);
int digits=number.size();
ll totalNumbers[digits+1][10][2]{},sumOfDigits[digits+1][10][2]{};
	for(int remDigits=0;remDigits<=digits;remDigits++){
		for(int current=0;current<10;current++){
			for(int tight=0;tight<2;tight++){
				if(remDigits==0){
					totalNumbers[0][current][tight]=current==0;
					continue;
				}
				int upperBound=tight?number[digits-remDigits]-'0':9;
				if(current>upperBound){
					continue;
				}
				for(int next=0;next<10;next++){
					totalNumbers[remDigits][current][tight]+=totalNumbers[remDigits-1][next][tight&(current==upperBound)];
					sumOfDigits[remDigits][current][tight]+=sumOfDigits[remDigits-1][next][tight&(current==upperBound)];
				}
				sumOfDigits[remDigits][current][tight]+=current*totalNumbers[remDigits][current][tight];
			}
		}
	}
	ll sumOfAllDigits=0,leftMost=number[0]-'0';
	for(int current=0;current<=leftMost;current++){
		sumOfAllDigits+=sumOfDigits[digits][current][current==leftMost];
	}
	return sumOfAllDigits;
}

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		cout<<sumOfDigits(b)-sumOfDigits(a-1)<<"\n";
	}
	return 0;
}
