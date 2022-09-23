class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order, bool &hasCycle) {
        visited[v] = 1;

        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, order, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }

        visited[v] = 2;
        order.push_back(v);
    }

public:
    vector<int> sortItems(int itemCount, int groupCount, vector<int> &groupOf, vector<vector<int>> &prevItems) {
        for (int &group : groupOf)
            if (group == -1)
                group = groupCount++;

        vector<vector<int>> itemGraph(itemCount), groupGraph(groupCount);
        for (int itemB = 0; itemB < prevItems.size(); itemB++) {
            for (int itemA : prevItems[itemB]) {
                itemGraph[itemA].push_back(itemB);
                if (groupOf[itemA] != groupOf[itemB])
                    groupGraph[groupOf[itemA]].push_back(groupOf[itemB]);
            }
        }

        vector<int> visited(itemCount);
        vector<int> itemOrder;
        bool hasCycle = 0;

        for (int item = 0; item < itemCount; item++)
            if (!visited[item])
                dfs(itemGraph, item, visited, itemOrder, hasCycle);

        if (hasCycle)
            return {};

        reverse(itemOrder.begin(), itemOrder.end());

        vector<vector<int>> orderedGroups(groupCount);
        for (int item : itemOrder)
            orderedGroups[groupOf[item]].push_back(item);

        visited.assign(groupCount, 0);
        vector<int> groupOrder;

        for (int group = 0; group < groupCount; group++)
            if (!visited[group])
                dfs(groupGraph, group, visited, groupOrder, hasCycle);

        if (hasCycle)
            return {};

        reverse(groupOrder.begin(), groupOrder.end());

        vector<int> res;
        for (int group : groupOrder)
            res.insert(res.end(), orderedGroups[group].begin(), orderedGroups[group].end());
        return res;
    }
};