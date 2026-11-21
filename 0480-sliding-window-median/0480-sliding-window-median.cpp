class Solution {
public:
    multiset<int> lo, hi;

    void balance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }

        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void add(int x) {
        if (lo.empty() || x <= *prev(lo.end())) {
            lo.insert(x);
        } else {
            hi.insert(x);
        }

        balance();
    }

    void remove(int x) {
        auto it = lo.find(x);

        if (it != lo.end()) {
            lo.erase(it);
        } else {
            it = hi.find(x);
            if (it != hi.end()) {
                hi.erase(it);
            }
        }

        balance();
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k) {
                remove(nums[i - k]);
            }

            if (i >= k - 1) {
                if (k % 2 == 1) {
                    ans.push_back((double)*prev(lo.end()));
                } else {
                    double a = *prev(lo.end());
                    double b = *hi.begin();

                    ans.push_back((a + b) / 2.0);
                }
            }
        }

        return ans;
    }
};