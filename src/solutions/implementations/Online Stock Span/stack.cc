class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top()[0] <= price) {
            vector<int> t = s.top();
            s.pop();
            res += t[1];
        }
        s.push(vector<int>{price, res});
        return res;
    }
private:
    stack<vector<int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */