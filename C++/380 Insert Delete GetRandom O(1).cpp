// Use map to record the position of a number, use vector to random access.
// Each deleting, move the last element in vector to the deleted position.

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> map;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.count(val)) return false;    // Exist.
        map[val] = (int)nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!map.count(val)) return false;
        int pos = map[val];
        nums[pos] = nums.back();
        map[nums.back()] = pos;
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randPos = rand() % nums.size();
        return nums[randPos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
