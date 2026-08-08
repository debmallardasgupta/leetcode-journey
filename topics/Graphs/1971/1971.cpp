class Solution {
public:
    bool dfs(int u, int dest, vector<vector<int>>& g, vector<int>& vis) {
        if (u == dest) return true;
        vis[u] = 1;
        for (int child : g[u]) {
            if (!vis[child]) {
                if (dfs(child, dest, g, vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        return dfs(source, destination, g, vis);
    }
};