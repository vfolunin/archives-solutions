class MovieRentingSystem {
    map<pair<int, int>, int> price;
    unordered_map<int, set<pair<int, int>>> unrented;
    set<vector<int>> rented;
    
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries) {
        for (vector<int> &entry : entries) {
            price[{ entry[0], entry[1] }] = entry[2];
            unrented[entry[1]].insert({ entry[2], entry[0] });
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto [price, shop] : unrented[movie]) {
            res.push_back(shop);
            if (res.size() == 5)
                break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        unrented[movie].erase({ price[{ shop, movie }], shop });
        rented.insert({ price[{ shop, movie }], shop, movie });
    }
    
    void drop(int shop, int movie) {
        unrented[movie].insert({ price[{ shop, movie }], shop });
        rented.erase({ price[{ shop, movie }], shop, movie });
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (const vector<int> &entry : rented) {
            res.push_back({ entry[1], entry[2] });
            if (res.size() == 5)
                break;
        }
        return res;
    }
};