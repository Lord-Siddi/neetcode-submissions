class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        vector<int>res;
        while(k--&&(!pq.empty())){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
