/*

Problem Statement
    
Fox Ciel lives in a beautiful countryside. She loves climbing mountains. Yesterday, she went hiking in the mountains.   Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[n]. These values represent altitudes visited by Fox Ciel during the trip, in order. Fox Ciel does not remember the precise sequence, but she remembers the following:
for each i, h[i] >= 0
h[0] = h0
h[n] = hn
for each i, abs(h[i+1]-h[i]) = 1
   The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1. We will call the two types of steps "steps up" and "steps down", respectively. Steps up will be denoted 'U' and steps down will be denoted 'D'.   You are given the ints n, h0, and hn: the length of the trip, the altitude at the beginning, and the altitude at the end. In addition to these, Fox Ciel remembers some contiguous segment of her trip. You are given this segment as a string history. Each character of history is either 'U' or 'D'.   Check whether there is a valid trip that matches everything Fox Ciel remembers. Return "YES" (quotes for clarity) if there is at least one such trip, or "NO" if there is none.
Definition
    
Class:
FoxAndMountainEasy
Method:
possible
Parameters:
int, int, int, string
Returns:
string
Method signature:
string possible(int n, int h0, int hn, string history)
(be sure your method is public)
    

Constraints
-
n will be between 1 and 100,000, inclusive.
-
history will contain between 1 and min(50,n) characters, inclusive.
-
Each character in history will be either 'U' or 'D'.
-
h0 will be between 0 and 100,000, inclusive.
-
hn will be between 0 and 100,000, inclusive.
Examples
0)

    
4
0
4
"UU"
Returns: "YES"
The only solution is: h[] = {0, 1, 2, 3, 4}, the history of the entire trip will be "UUUU".
1)

    
4
0
4
"D"
Returns: "NO"
Based on n, h0 and hn, the history of the entire trip must be "UUUU". There is no 'D' in this history.
2)

    
4
100000
100000
"DDU"
Returns: "YES"
We have the following solution: h[] = {100000, 100001, 100000, 99999, 100000}, the history of the entire trip is "UDDU".
3)

    
4
0
0
"DDU"
Returns: "NO"

4)

    
20
20
20
"UDUDUDUDUD"
Returns: "YES"

5)

    
20
0
0
"UUUUUUUUUU"
Returns: "YES"

6)

    
20
0
0
"UUUUUUUUUUU"
Returns: "NO"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class FoxAndMountainEasy {
public:
  string possible(int n, int h0, int hn, string history) {
		int nD=0, nU=0;
		if (h0 == hn){
			nD=nU=n/2;
		}
		else{
			//uphill and downhill
			nD = (n+h0-hn)/2;
			nU = (n+hn-h0)/2;
		}
		
		//two simple checks
		//1. in history, numbers of 'D' and 'U' cannot exceed those in all
		//2. h cannot below zero
		int cD=0, cU=0, start=h0;
		for (int i=0; i<history.size(); ++i){
			if (history[i] == 'U'){
				++cU;
				++start;
			}
			else if (history[i] == 'D'){
				++cD;
				--start;
			}
			
			if (start<0)
				return "NO";
		}
		if (cU>nU || cD>nD)
			return "NO";
		
		return "YES";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
