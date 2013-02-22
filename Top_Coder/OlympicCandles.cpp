/*

Problem Statement
    
To celebrate the upcoming Thought Challenge Olympics, you are going to follow tradition and light candles. On the first night of the event, you will light one candle. At the end of the night, you will extinguish the candle. On each subsequent night, you will light one more candle than you did on the previous night, so that on the n-th night (indexed from 1) you will light n candles (and extinguish them all in the morning). Each night that you light a candle, its height will decrease by 1 inch; once its height reaches 0 inches, you cannot use it anymore.
You are given a vector <int> candles, the i-th element of which is the height of the i-th candle that you own. Return the maximum number of nights you can celebrate the event without going to the store to get more candles. For example, if you have three candles of height 2, you can light one the first night, the other two on the second night, and then all three candles on the third night.
Definition
    
Class:
OlympicCandles
Method:
numberOfNights
Parameters:
vector <int>
Returns:
int
Method signature:
int numberOfNights(vector <int> candles)
(be sure your method is public)
    

Constraints
-
candles will contain between 1 and 50 elements, inclusive.
-
Each element of candles will be between 1 and 100, inclusive.
Examples
0)

    
{2, 2, 2}
Returns: 3
The example from the statement.
1)

    
{2, 2, 2, 4}
Returns: 4
With an extra candle we are able to use the candles for four nights.
2)

    
{5, 2, 2, 1}
Returns: 3

3)

    
{1, 2, 3, 4, 5, 6}
Returns: 6

4)

    
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Returns: 4

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


class OlympicCandles {
public:
  int numberOfNights(vector <int> candles) {
		int ans = 0;
		bool flag = true;
		while(flag && ans<=candles.size()){
			sort(candles.begin(), candles.end());
			for(int i=candles.size()-1; i>int(candles.size())-1-ans; --i){
				--candles[i];
				if(candles[i]<0){
					flag = false;
					break;
				}
			}
			if(flag)
				++ans;
		}
		return ans-1;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
