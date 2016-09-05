/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
// https://discuss.leetcode.com/topic/42042/simple-java-solution-using-a-stack-with-explanation/2
class NestedIterator {
public:
    stack<NestedInteger> cache;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; i--) {
            cache.push(nestedList[i]);
        }
    }

    int next() {
        int res = cache.top().getInteger();
        cache.pop();
        return res;
    }

    bool hasNext() {
        if (cache.empty()) {
            return false;
        } else if (cache.top().isInteger()) {
            return true;
        } else {
            NestedInteger top = cache.top();
            cache.pop();
            for(int i = top.getList().size()-1; i >= 0; i--) {
                cache.push(top.getList()[i]);
            }
            // Recursive flatten (Tail Recursion).
            if(hasNext()) {
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
