/*
Problem link:
https://lightoj.com/problem/investigation


An integer is divisible by 3 if the sum of its digits is also divisible by 3. For example, 3702 is divisible by 3 and 12 (3+7+0+2) is also divisible by 3. This property also holds for the integer 9.

In this problem, we will investigate this property for other integers.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000)>.

Output
For each case, output the case number and the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.

Sample
Input	Output
3
1 20 1
1 20 2
1 1000 4

Case 1: 20
Case 2: 5
Case 3: 64
*/

#include <bits/stdc++.h>
using namespace std;
int countValidNumbers(int r,int k){
    //the max sum of 10 digit number can be 90
    if(k>90){
        return 0;
    }
    string number=to_string(r);
    int digits=number.size();
    int validNumbers[digits+1][k][k][2]{};
    
    for(int remDigits=0;remDigits<=digits;remDigits++){
        for(int remainder=0;remainder<k;remainder++){
            for(int digitSumRemainder=0;digitSumRemainder<k;digitSumRemainder++){
                for(int tight=0;tight<2;tight++){
                    //base case
                    if(remDigits==0){
                        validNumbers[0][remainder][digitSumRemainder][tight]=(remainder==0)&&(digitSumRemainder==0);
                        continue;
                    }
                    int upperBound=tight?number[digits-remDigits]-'0':9;
                    for(int current=0;current<=upperBound;current++){
                      //everything is measured from right side in the number
                      // as we are forming the number from right to left
                        int nextRemainder=(remainder*10+current)%k;
                        int nextDigitSumRem=(digitSumRemainder+current)%k;
                        validNumbers[remDigits][remainder][digitSumRemainder][tight]+=validNumbers[remDigits-1][nextRemainder][nextDigitSumRem][tight&(current==upperBound)];
                    }
                }
            }
        }
    }
    return validNumbers[digits][0][0][1];
    //ans
}
int main() {
    int t;
    cin>>t;
    for(int testCase=1;testCase<=t;testCase++){
        int a,b,k;
        cin>>a>>b>>k;
        cout<<"Case "<<testCase<<": "<<countValidNumbers(b,k)-countValidNumbers(a-1,k)<<"\n";
    }
    return 0;
}
