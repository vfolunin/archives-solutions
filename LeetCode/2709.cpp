struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

class Solution {
    vector<int> getPrimeDivisors(int n) {
        vector<int> primeDivisors;
        
        for (long long d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                primeDivisors.push_back(d);
                while (n % d == 0)
                    n /= d;
            }
        }
        if (n > 1)
            primeDivisors.push_back(n);

        return primeDivisors;
    }

public:
    bool canTraverseAllPairs(vector<int>& a) {
        sort(a.begin(), a.end());
        if (a[0] == 1)
            return a.size() == 1;        
        a.erase(unique(a.begin(), a.end()), a.end());
        
        vector<vector<int>> primeDivisors(a.size());
        unordered_map<int, int> primeId;
        
        for (int i = 0; i < a.size(); i++) {
            primeDivisors[i] = getPrimeDivisors(a[i]);
            for (int p : primeDivisors[i])
                if (!primeId.count(p))
                    primeId[p] = primeId.size();
        }
        
        DSU dsu(primeId.size());

        for (int i = 0; i < a.size(); i++)
            for (int p1 : primeDivisors[i])
                for (int p2 : primeDivisors[i])
                    dsu.merge(primeId[p1], primeId[p2]);  

        return dsu.cc == 1;
    }
};