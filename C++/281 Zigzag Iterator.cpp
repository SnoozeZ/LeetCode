//extentable to k vector
class ZigzagIterator {
public:
    map<int, vector<int>> m;
    map<int, vector<int>>::iterator it; //to visit which vector
    int pos;//to visit which position
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m[0] = v1;
        m[1] = v2;
        for(auto p: m){//erase empty vector
            if(p.second.empty())
                m.erase(p.first);
        }
        it = m.begin();
        pos = 0;
    }

    int next() {
        int rlt = it->second[pos];
        if(pos == it->second.size()-1){// if the pos visit the last element of the vector
            it = m.erase(it);
        }else{
            it++;
        }
        if(it == m.end()){//if the iterator is the last one
            it = m.begin();
            pos++;
        }
        return rlt;
    }

    bool hasNext() {
        return !m.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
