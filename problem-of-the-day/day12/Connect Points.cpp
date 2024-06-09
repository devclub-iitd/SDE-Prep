// We will use Prim's Algorithm (is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.) 
// and min-heap data structure(is a tree-like data structure that always stores the minimum 
// valued element (edge weight here) at the root) to solve this problem.

// In this apporach we will pick any random node then select the lowest weight node that connect a node present in MST to a node
//  that is not present in MST and will keep it in min-heap and we use one boolean vector to record which node is already present
//  in the MST

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; //creating heap to store minimum weight
        vector<bool> arr(n);
        heap.push({ 0, 0 });
        int mincost = 0;
        int remaning = 0;
        while (remaning < n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            if (arr[currNode]) {
                continue;
            }
            
            arr[currNode] = true;
            mincost += weight;
            remaning++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!arr[nextNode]) {
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + 
                                     abs(points[currNode][1] - points[nextNode][1]);
                    
                    heap.push({ nextWeight, nextNode });
                }
            }
        }
        
        return mincost;
    }
};