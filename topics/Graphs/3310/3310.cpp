class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &ele: invocations){
            adj[ele[0]].push_back(ele[1]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int u=q.front();q.pop();
            visited[u]=true;
            for(auto &v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                for(int &v: adj[i]){
                    if(visited[v]==true){
                        flag=true; 
                        break;
                    } 
                }
            }
        }
        vector<int> ans;
        if(!flag){
            for(int i=0;i<n;i++){
                if(!visited[i]) ans.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};