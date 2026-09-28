class OrderManagementSystem {
    unordered_map<int, string> typeOf;
    unordered_map<int, int> priceOf;
    unordered_map<string, unordered_map<int, unordered_set<int>>> orders;

public:    
    void addOrder(int id, const string &type, int price) {
        typeOf[id] = type;
        priceOf[id] = price;
        orders[type][price].insert(id);
    }
    
    void modifyOrder(int id, int newPrice) {
        string type = typeOf[id];
        cancelOrder(id);
        addOrder(id, type, newPrice);
    }
    
    void cancelOrder(int id) {
        orders[typeOf[id]][priceOf[id]].erase(id);
        typeOf.erase(id);
        priceOf.erase(id);
    }
    
    vector<int> getOrdersAtPrice(const string &type, int price) {
        unordered_set<int> &res = orders[type][price];
        return { res.begin(), res.end() };
    }
};