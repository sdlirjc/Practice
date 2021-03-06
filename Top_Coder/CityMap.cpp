/*

Problem Statement
    
Manao arrived to a city he's never been to. He bought a city map that depicts the city as a grid H squares high and W squares wide. Each square in this grid can either contain a street segment or a single point of interest of some type.  It was later when Manao noticed that the map lacked a legend. The map legend is the list of all types of points of interest (further referred to as POIs) present on the map. Each POI type is coupled with the corresponding symbol denoting this type on the map. For example, you might have seen an 'M' sign denoting a metro station or a fork-and-spoon sign denoting a restaurant on a city map.  Fortunately, not all is lost: the map contains a legend summary. The summary states how many POIs of each type are there on the map (for example, it could say: all in all, there are 9 restaurants and 4 metro stations on the map). Moreover, it turned out that all quantities are pairwise distinct. Manao realized that he could guess the signs using this information (for instance, if there were 4 triangle signs on the map Manao would know that triangle stands for a metro station).  You are given a vector <string> cityMap containing H elements, each of them W characters long. Each character of cityMap designates the corresponding square on Manao's city map and is '.' if there is a street segment in that square or an uppercase letter if the square contains a POI. Different types of POIs are denoted by different letters, two POIs of the same type are always denoted with the same letter. As you see, the letters just stand for the different signs on the map.  You are also given a vector <int> POIs. POIs[i] is the number of occurences of the i-th type POIs on the map. It is guaranteed that the information given is consistent, i.e. there are exactly as many different letters in cityMap as elements in POIs and there exists a valid assignment of letters to POI types.  For each POI type, determine the letter with which it is denoted on the map. Return a string of as many characters as elements in POIs, where the character at the i-th position is the letter corresponding to the i-th POI type.
Definition
    
Class:
CityMap
Method:
getLegend
Parameters:
vector <string>, vector <int>
Returns:
string
Method signature:
string getLegend(vector <string> cityMap, vector <int> POIs)
(be sure your method is public)
    

Constraints
-
cityMap will contain between 1 and 50 elements, inclusive.
-
Each element of cityMap will be between 1 and 50 characters long, inclusive.
-
The elements of cityMap will be of the same length.
-
Elements of cityMap will consist of '.' and 'A'-'Z' characters only.
-
POIs will contain between 1 and 26 elements, inclusive.
-
Each element of POIs will be between 1 and 2500, inclusive.
-
All elements of POIs will be distinct.
-
There will exist a valid assignment of letters in cityMap to POI types.
Examples
0)

    
{"M....M",
 "...R.M",
 "R..R.R"}
{3, 4}
Returns: "MR"
The city map is 3 squares high and 6 squares wide. There are 3 'M' signs and 4 'R' signs on the map. The legend summary states that there are three POIs of type 0 and four POIs of type 1 on the map. Obviously, the former are denoted with 'M' on the map and the latter are denoted with 'R'.
1)

    
{"XXXXXXXZXYYY"}
{1, 8, 3}
Returns: "ZXY"
There is a single 'Z' on the map, thus the legend should state that POIs of type 0 are denoted with 'Z'. There are three 'Y's on the map, therefore POIs of type 2 are surely denoted with 'Y'. Finally, it's now obvious that 'X's stand for the POIs of type 1.
2)

    
{"...........",
 "...........",
 "...........",
 "..........T"}
{1}
Returns: "T"
The poor city has only one point of interest in the farmost corner.
3)

    
{"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
{16,7,1,35,11,66}
Returns: "GOJIRA"

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


class CityMap {
public:
  string getLegend(vector <string> cityMap, vector <int> POIs) {
		int cnt[26] = {0};
		for(int i=0; i<cityMap.size(); ++i){
			for(int j=0; j<cityMap[i].size(); ++j){
				++cnt[cityMap[i][j]-'A'];
			}
		}
		
		string ans;
		for(int i=0; i<POIs.size(); ++i){
			for(int j=0; j<26; ++j){
				if(POIs[i]==cnt[j]){
					ans += 'A'+j;
					break;
				}
			}
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
