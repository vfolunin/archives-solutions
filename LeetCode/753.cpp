class Solution {    
    void makeGraph(int width, int digits, unordered_map<string, unordered_set<string>> &graph, string &v) {
        if (v.size() == width - 1) {
            for (int digit = 0; digit < digits; digit++) {
                string to = v.substr(1) + string(1, '0' + digit);
                graph[v].insert(to);
            }
            return;
        }
        
        for (int digit = 0; digit < digits; digit++) {
            v.push_back(digit + '0');
            makeGraph(width, digits, graph, v);
            v.pop_back();
        }
    }
    
    vector<string> euler(unordered_map<string, unordered_set<string>> &graph) {
        vector<string> stack = { graph.begin()->first }, cycle;
        
        while (!stack.empty()) {
            string v = stack.back();
            
            if (!graph[v].empty()) {
                string to = *graph[v].begin();                
                graph[v].erase(to);                
                stack.push_back(to);
            } else {
                stack.pop_back();
                cycle.push_back(v);
            }
        }
        
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
    
public:
    string crackSafe(int width, int digits) {
        if (width == 1) {
            string res;
            for (int digit = 0; digit < digits; digit++)
                res += digit + '0';
            return res;
        }
        
        unordered_map<string, unordered_set<string>> graph;
        string v;
        makeGraph(width, digits, graph, v);
        
        vector<string> cycle = euler(graph);
        
        string res = cycle[0];
        for (int i = 1; i < cycle.size(); i++)
            res += cycle[i].back();
        
        return res;
    }
};