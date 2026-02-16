class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            bitset<32> x(nums[i]);
            string s = x.to_string();
            int pos = s.find('1');
            if (pos == string::npos)
                pos = 31;
            s = s.substr(pos);
            reverse(s.begin(), s.end());
            int revNum = stoul(s, nullptr, 2);
            pq.push_back({revNum, nums[i]});
        }
        for (auto it : pq) {
            cout << it.first << " " << it.second << endl;
        }

        sort(pq.begin(), pq.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });
        vector<int> res;
        for (int i = 0; i < n; i++) {
            auto it = pq[i];
            res.push_back(it.second);
        }
        return res;
    }
};