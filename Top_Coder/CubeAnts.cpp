/*

Problem Statement
    
NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Fox Ciel is observing the behavior of ants. She has a cube whose vertices are indexed from 0 to 7 as follows.
 
You are given a vector <int> pos containing the initial locations of the ants. The i-th element of pos is the index of the vertex where the i-th ant is located. In an attempt to observe their moves, Ciel puts honey on the 0-th vertex. The ants notice it immediately and start moving toward the honey. In a single turn, each ant will either move to an adjacent vertex along an edge of the cube or stay in its current vertex. All moves in a turn happen simultaneously, and at all times, it is legal for multiple ants to be at the same location of the cube.

Ciel observes the ants until they all move to the 0-th vertex. In order to determine how clever they were, she wants to know the minimal number of turns that were required for this to happen. Return this minimal number.
Definition
    
Class:
CubeAnts
Method:
getMinimumSteps
Parameters:
vector <int>
Returns:
int
Method signature:
int getMinimumSteps(vector <int> pos)
(be sure your method is public)
    

Constraints
-
pos will contain between 1 and 50 elements, inclusive.
-
Each element of pos will be between 0 and 7, inclusive.
Examples
0)

    
{0,1,1}
Returns: 1

1)

    
{5,4}
Returns: 2

2)

    
{0}
Returns: 0
There is only one ant, and it is already on the 0-th vertex, so the minimum number of turns required is 0.
3)

    
{6,1,6}
Returns: 3

4)

    
{7,7,3,3,7,7,3,3}
Returns: 2

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


class CubeAnts {
public:
  int getMinimumSteps(vector <int> pos) {
		int minMoves[8];
		minMoves[0] = 0;
		minMoves[1] = 1;
		minMoves[2] = 2;
		minMoves[3] = 1;
		minMoves[4] = 1;
		minMoves[5] = 2;
		minMoves[6] = 3;
		minMoves[7] = 2;
		
		int ans = 0;
		for(int i=0; i<pos.size(); ++i){
			ans = max(ans, minMoves[pos[i]]);
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
