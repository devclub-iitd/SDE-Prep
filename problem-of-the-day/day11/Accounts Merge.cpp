// Use dsu algorithim to keep taking union of the emails belonging to the same person

class Solution {
    int findPar(int node, vector<int> &prnt) {
        if(prnt[node] == node) return node;
        return prnt[node] = findPar(prnt[node], prnt);
    }

    void unionn(int u, int v, vector<int> &rank, vector<int> &prnt) {
        u = findPar(u, prnt), v = findPar(v, prnt);

        if(rank[u] < rank[v]) prnt[u] = v;
        else if(rank[u] > rank[v]) prnt[v] = u;
        else prnt[v] = u, rank[u]++;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> rank(n, 0), prnt(n);
        for(int i=0; i<n; i++) prnt[i] = i;

        unordered_map<string, int> em;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                if(em.find(accounts[i][j]) == em.end())  em[accounts[i][j]] = i;
                else unionn(em[accounts[i][j]], i, rank, prnt);
            }
        }
        vector<set<string>> merge(n);
        for(auto i : em) merge[findPar(i.second, prnt)].insert(i.first);
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(!merge[i].size()) continue;
            
            vector<string> t;
            t.push_back(accounts[i][0]);
            for(string s : merge[i]) t.push_back(s);
            ans.push_back(t);
        }

        return ans;        
    }
};