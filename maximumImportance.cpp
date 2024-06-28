#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads){
        long long ans = 0;
        vector<int> degree (n, 0);
        vector<pair<int, int>> cities;
        for(const auto &road : roads){
            ++degree[road[0]];
            ++degree[road[1]];
        }
        for(int i=0; i<n; ++i){
            cities.emplace_back(degree[i], i);
        }
        sort(cities.rbegin(), cities.rend());
        for(int i=0; i<n; ++i){
            ans += (long long)(n - i) * cities[i].first;
        }
        return ans;
    }
};