// For this we already might need some kind of algorithm to solve it, though for the constraints given you might use almost any approach. 
// If you just have a directed graph then in order to check whether you can reach all nodes from all other nodes you can do different things — 
// you can dfs/bfs from all nodes, two dfs/bfs from the single node to check that every other node has both paths to and from that node, 
// or you can employ different "min distance between all pairs of nodes" algorithm.
// All of these seem to work fine for this problem.

// But we shouldn't ignore here that the input graph has a special configuration — it's a grid of vertical and horizontal directed lines.
//  For this graph all you need is to check whether four outer streets form a cycle or not.
//  If they form a cycle then the answer is "YES", otherwise "NO". 

// Here is an explanation for such short solution:

// If outer streets (top, bottom, rightmost and leftmost) form a cycle (clockwise or counter-clockwise), then
// by following that cycle, one can reach any junction on that cycle from any other junction on the same cycle.
// moreover, independent of the directions of inner streets you can also reach all "inner" junctions from any "outer" junction.
//  Therefore, if the outer streets form a cycle, then the answer is "YES".
// If outer streets do not form a cycle, then

// there is at least one "corner" junction, for which both horizontal and vertical streets have directions towards that junction 
// (otherwise, there it would be a cycle). Since one can not move out from such "corner" junction to anywhere else, the answer is "NO". 


#include <iostream>
#include <string>

using namespace std;

int main() {
	int x; cin >> x >> x;
	
	string s1; cin >> s1;
	string s2; cin >> s2;
	
	string s3 = { s1.front() , s1.back() , s2.front() , s2.back() };
	
	cout << (s3 == "<>v^" || s3 == "><^v" ? "YES" : "NO");
}