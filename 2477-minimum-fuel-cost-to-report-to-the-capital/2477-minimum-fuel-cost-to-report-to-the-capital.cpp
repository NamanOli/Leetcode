class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const int n = 1e5 + 1 ; 
        vector<int>graph[n]; 
        for(int i = 0 ; i < roads.size() ; i++){
            graph[roads[i][0]].push_back(roads[i][1]); 
            graph[roads[i][1]].push_back(roads[i][0]); 
        }
        
        function<pair<long long,long long>(int,int)> dfs = [&](int node,int par){
            
            long long fuel = 0 , persons = 1 ; 
            for(auto x : graph[node]){
                if(x == par) continue ; 
                auto r = dfs(x, node);
                fuel += r.first ; persons += r.second ;
            }

            if(par == -1) return make_pair(fuel,persons);

            int cars = (persons / seats) + (persons%seats != 0) ; 

            return make_pair(fuel+cars,persons);            
        };
        return dfs(0,-1).first ;

    }
};