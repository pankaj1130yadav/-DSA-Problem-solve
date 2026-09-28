class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val)) return false;

        mp[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;

        int idx = mp[val];
        int last = arr.back();

        arr[idx] = last;
        mp[last] = idx;

        arr.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};