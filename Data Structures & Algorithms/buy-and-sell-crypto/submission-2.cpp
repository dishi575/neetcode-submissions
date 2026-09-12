class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=prices[0];
        for(int& sell:prices){
            maxi=max(maxi,sell-mini);
            mini=min(mini,sell);
        }
        return maxi;
    }
};
