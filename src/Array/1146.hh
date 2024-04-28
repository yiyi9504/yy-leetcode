#include "../../include/common.hh"

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {

    }
    
    void set(int index, int val) {
        store_[index][snapid_+1] = val;
    }
    
    int snap() {
        return ++snapid_;
    }
    
    int get(int index, int snap_id) {
        auto& store_index = store_[index];
        auto it = store_index.lower_bound(snap_id);
        if (it == store_index.end()) {
            for (auto it = store_index.rbegin(); it != store_index.rend(); ++it) {
                if(it->first <= snap_id) {
                    return it->second; 
                }
            }
        } else {
            while (true) {
                if(it->first <= snap_id) {
                    return it->second; 
                }
                if (it == store_index.begin()) break;
                it--;
            }            
        }
        return 0;
    }

private:
    map<int, map<int, int> > store_;
    int snapid_ = -1;
};

