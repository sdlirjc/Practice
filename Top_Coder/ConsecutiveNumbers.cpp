/*

Problem Statement
    
Your little son has written some consecutive positive integers on a piece of paper, in no particular order. Each integer was written exactly once. He then erased one of the integers and showed you the remaining ones. Do you know which number your son erased?
Formally, a list of positive integers is said to be consecutive if there are two positive integers a and b such that every integer between a and b, inclusive, appears in the list exactly once.
For example, if the remaining numbers are (10,7,12,8,11), the only possible missing number is 9. If the remaining numbers are (2,3), the missing number could be either 1 or 4. If the remaining numbers are (3,6), your son must have made a mistake.
You are given the remaining numbers in a vector <int> numbers. Return a vector <int> containing all the possible numbers your son might have erased. The numbers should be sorted in ascending order, and there should be no duplicates. If your son made a mistake, return an empty vector <int>.
Definition
    
Class:
ConsecutiveNumbers
Method:
missingNumber
Parameters:
vector <int>
Returns:
vector <int>
Method signature:
vector <int> missingNumber(vector <int> numbers)
(be sure your method is public)
    

Constraints
-
numbers will contain between 1 and 50 elements, inclusive.
-
Each element of numbers will be between 1 and 1000000000, inclusive.
Examples
0)

    
{10,7,12,8,11}
Returns: {9 }
The first example in the problem statement.
1)

    
{3,6}
Returns: { }
The third example in the problem statement.
2)

    
{5,6,7,8}
Returns: {4, 9 }
There original list might be {4,5,6,7,8} or {5,6,7,8,9}.
3)

    
{1000000000}
Returns: {999999999, 1000000001 }

4)

    
{1,6,9,3,8,12,7,4,11,5,10}
Returns: {2 }

5)

    
{1}
Returns: {2 }
Only positive integers are allowed.
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


class ConsecutiveNumbers {
public:
  vector <int> missingNumber(vector <int> numbers) {
		vector <int> ans;
		if (numbers.size()==0)
			return ans;
		if (numbers.size()==1){
			if (numbers[0]-1 > 0) ans.push_back(numbers[0]-1);
			if (numbers[0]+1 > 0) ans.push_back(numbers[0]+1);
			return ans;
		}
		
		sort(numbers.begin(), numbers.end(), less<int>());
		
		for(int i=1; i<numbers.size(); ++i){
			if(numbers[i]-numbers[i-1]==1){
				//pass
			}
			if(numbers[i]-numbers[i-1]==2){
				ans.push_back(numbers[i]-1);
			}
		}
		
		if (ans.size()==0 && numbers.size()==numbers[numbers.size()-1]-numbers[0]+1){
			if (numbers[0]-1 > 0) ans.push_back(numbers[0]-1);
			if (numbers[numbers.size()-1]+1 > 0) ans.push_back(numbers[numbers.size()-1]+1);
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
