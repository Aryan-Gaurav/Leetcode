/*
Problem Link:
https://codeforces.com/contest/1036/problem/C
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
ll countClassyNumbers(ll r){
	string number=to_string(r);
	int digits=number.size();
	ll totalNumbers[digits+1][4][2]{};
	for(int remDigits=0;remDigits<=digits;remDigits++){
		for(int nonZero=0;nonZero<=3;nonZero++){
			for(int tight=0;tight<2;tight++){
				if(remDigits==0){
					//here nonZero means maximum allowed non-zero didgits
					totalNumbers[0][nonZero][tight]=1;
					continue;
				}
				int upperBound=tight?number[digits-remDigits]-'0':9;
				for(int current=0;current<=upperBound;current++){
					int remNonZero=nonZero-(current>0);
					if(remNonZero>=0){
						totalNumbers[remDigits][nonZero][tight]+=totalNumbers[remDigits-1][remNonZero][tight&(current==upperBound)];
					}
				}
			}
		}
	}
	return totalNumbers[digits][3][1];
}

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		cout<<countClassyNumbers(b)-countClassyNumbers(a-1)<<"\n";
	}
	return 0;
}
