class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(),prices.end());
        double sum = 0;
        sort(discounts.begin(),discounts.end());
        int it1 = n-1;
        int it2 = m-1;
        while(it1 >=0 && it2 >=0){
            // double x = (prices[it1]/100.0);
            sum += ((100-discounts[it2])/100.0)*prices[it1];
            it1--;
            it2--;
        }
        if(it1 >=0){
            while(it1 >=0){
                sum += prices[it1];
                it1--;
            }
        }
        return sum;
    }
};