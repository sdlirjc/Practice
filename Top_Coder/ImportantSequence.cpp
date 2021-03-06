/*

Problem Statement
    
This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet. 
 Little Rudolph had an important sequence of positive integers. The sequence consisted of N positive integers a0, a1, .., aN-1.  Rudolph wrote the sequence onto the blackboard in the classroom. While Rudolph had gone out, little Arthur came into the classroom and saw the sequence. Arthur likes to play with numbers as much as he likes to give his friends puzzles. So he did the following:
First, he wrote a '+' or a '-' between each pair of consecutive numbers (possibly using different signs for different pairs of numbers).
Next, for each sign he computed the result of the corresponding operation and wrote it under the sign. I.e., if he used the '+' sign between ai and ai+1, he would write the sum ai+ai+1 under this '+' sign. Similarly, if he used the '-' sign between ai and ai+1, he would write the difference ai-ai+1. In this way he obtained a new sequence of N-1 numbers b0, b1, .., bN-2.
Finally, he erased the original sequence. Now there was only the operator sequence o0, o1, .., oN-2 and the resulting number sequence b0, b2, .., bN-2 left on the blackboard.
For example, if the original sequence was {1, 2, 3, 4}, and Arthur wrote operators {+, -, +}, then the content of the blackboard changed like this:  
1   2   3   4    ->    1 + 2 - 3 + 4    ->    1 + 2 - 3 + 4    ->     +  -  +
                                                3  -1   7             3 -1  7
 When Rudolph returned, he was shocked as his important sequence had disappeared. Arthur quickly told him what operations he had performed and that Rudolph has to simply reconstruct the orginal sequence.  Unfortunately, little Arthur did not realize that it is not necessarily possible to determine the original sequence uniquely. For example, both original sequences {1, 2, 3, 4} and {2, 1, 2, 5} lead to the same sequence {3, -1, 7} when operator sequence is {+, -, +}.  The only thing Rudolph remembers about his original sequence is that all the integers were positive. Rudolph now wants to count all sequences of positive integers that match the blackboard. You are given vector <int> B and string operators both containing N-1 elements. The i-th element of B is the number bi and i-th element of operators will be '+' or '-', meaning that the i-th operator is + or -, respectively. Return the number of different positive integer sequences A that lead to sequence B when operators operators are used in the way described. If there are infinitely many such sequences, return -1. Note that there may be test cases where no valid sequence A exists. For such test cases the correct return value is 0.
Definition
    
Class:
ImportantSequence
Method:
getCount
Parameters:
vector <int>, string
Returns:
int
Method signature:
int getCount(vector <int> B, string operators)
(be sure your method is public)
    

Notes
-
It is guaranteed that the correct answer will always fit into the 32-bit signed integer type.
-
The integer 0 (zero) is not positive. It may not occur in Rudolph's original sequence.
Constraints
-
B will contain between 1 and 50 elements, inclusive.
-
operators will contain the same number of characters as the number of elements in B.
-
Each element of B will be between -1000000000 (-109) and 1000000000 (109), inclusive.
-
Each character in operators will be either '+' or '-' (quotes for clarity).
Examples
0)

    
{3, -1, 7}
"+-+"
Returns: 2
From the problem statement.
1)

    
{1}
"-"
Returns: -1
There are infinitely many pairs of positive integers that differ by one.
2)

    
{1}
"+"
Returns: 0
Note that all numbers ai have to be positive integers.
3)

    
{10}
"+"
Returns: 9

4)

    
{540, 2012, 540, 2012, 540, 2012, 540}
"-+-+-+-"
Returns: 1471

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


class ImportantSequence {
public:
  int getCount(vector <int> B, string operators) {
  		int N = (int)B.size()+1;
    	long long mn = 1 ;
    	long long mx = 1LL<<60;

	    for ( int i=0; i<N-1; i++)
	    {
	        long long pmn = mn;
	        long long pmx = mx;
	        
	        if (operators [i] == '-'){
	            mn = pmn-B[i];
	            mx = pmx-B[i];
	        }
	        else{
	            mx = B[i]-pmn;
	            mn = B[i]-pmx;
	        }
	        mx = max (0LL, mx);
	        mn = max (1LL, mn);
	    }
   		return mx-mn+1<(1LL<<32) ? (mx-mn+1) : -1;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
