class Cashier {
    int counter = 0, mod, discount;
    unordered_map<int, int> price;
    
public:
    Cashier(int mod, int discount, vector<int> &products, vector<int> &prices) : mod(mod), discount(discount) {
        for (int i = 0; i < products.size(); i++)
            price[products[i]] = prices[i];
    }
    
    double getBill(const vector<int> &products, const vector<int> &amounts) {
        double cost = 0;
        for (int i = 0; i < products.size(); i++)
            cost += price[products[i]] * amounts[i];
        
        if (++counter % mod == 0)
            cost *= (100 - discount) / 100.0;
        
        return cost;
    }
};