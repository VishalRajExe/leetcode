class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int M = 1500;
        int cnt[M + 1] = {0}, mult[M + 1] = {0};
        int pmin = INT_MAX;

        for (auto& it : items) {
            cnt[it[0]]++;
            pmin = min(pmin, it[1]);
        }
        // mult[f] = number of items whose factor is a multiple of f
        for (int f = 1; f <= M; ++f)
            for (int m = f; m <= M; m += f)
                mult[f] += cnt[m];

        vector<int> dp(budget + 1, 0);

        // First copy of each item: 0/1 knapsack, value = 1 purchased + free copies
        for (auto& it : items) {
            int p = it[1], v = mult[it[0]];
            for (int b = budget; b >= p; --b)
                dp[b] = max(dp[b], dp[b - p] + v);
        }
        // Extra copies are worth 1 each, so only the cheapest price matters
        for (int b = pmin; b <= budget; ++b)
            dp[b] = max(dp[b], dp[b - pmin] + 1);

        return dp[budget];
    }
};