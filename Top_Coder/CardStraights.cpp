/*

Problem Statement
    
You are playing a card game where the goal is to make straights. Each card in the deck has a number between 1 and 1000000, inclusive. A straight is a sequence of cards with consecutive values. Values do not wrap around, so 1 does not come after 1000000. In addition to regular cards, the deck also contains jokers. Each joker can be used as any valid number (between 1 and 1000000, inclusive).
You will be given a vector <int> cards containing the cards in your hand. Jokers are represented by 0s, and other cards are represented by their values. Return the number of cards in the longest straight that can be formed using one or more cards from your hand.
Definition
    
Class:
CardStraights
Method:
longestStraight
Parameters:
vector <int>
Returns:
int
Method signature:
int longestStraight(vector <int> cards)
(be sure your method is public)
    

Constraints
-
cards will contain between 1 and 50 elements, inclusive.
-
Each element of cards will be between 0 and 1000000, inclusive.
Examples
0)

    
{0,6,5,10,3,0,11}
Returns: 5
You can make 3-4-5-6-7 using one of your jokers as a 4 and the other one as a 7.
1)

    
{100,100,100,101,100,99,97,103}
Returns: 3
Not a very lucky hand.
2)

    
{0,0,0,1,2,6,8,1000}
Returns: 6
You can make 1-2-3-4-5-6 using your jokers cleverly.
3)

    
{1,9,5,7,3,4,0,0,0,10}
Returns: 10

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


class CardStraights {
public:
  int longestStraight(vector <int> cards) {
		sort(cards.begin(), cards.end());
		int numjokers = 0;
		int ans = 0;
		vector <int> mycards;

		for(int i=0; i<cards.size(); ++i){
			if (cards[i] == 0)
				++numjokers;
			else{
				if ( i==0 || (i>0 && cards[i]>cards[i-1]) )
					mycards.push_back(cards[i]);
			}
		}

		for(int i=0; i<mycards.size(); ++i){
			int k;
			int flag = numjokers;
			for(k=i; k<mycards.size()-1; ++k){
				//consume jokers
				if(flag >= mycards[k+1]-mycards[k]-1)
					flag -= mycards[k+1]-mycards[k]-1;
				else
					break;
			}
			if(flag>=0)
				ans = max(ans, mycards[k]-mycards[i]+1+flag);
		}

		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
