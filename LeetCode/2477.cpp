class Solution {
    tuple<long long, int, int> dfs(vector<vector<int>> &graph, int v, int p, int seats) {
        long long cost = 0;
        int cars = 0, size = 1;
        
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            auto [childCost, childCars, childSize] = dfs(graph, to, v, seats);
            cost += childCost + childCars;
            size += childSize;
        }
        
        return { cost, (size + seats - 1) / seats, size };
    }
    
public:
    long long minimumFuelCost(vector<vector<int>> &edges, int seats) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        auto [cost, cars, size] = dfs(graph, 0, -1, seats);
        return cost;
    }
};