#include "../../include/common.hh"
#include "../../include/SegmentTree.hh"

using namespace std;

#define IDX(x) x+1

class NumArray {
public:
    NumArray(vector<int>& nums) {
        Num = nums.size();
        for(int i=0; i<Num;i++) w[i+1]=nums[i];
        build(1,1,Num);
    }
    
    void update(int index, int val) {
        int id = IDX(index);
        change(1,id,id,val-w[id]);
        w[id] = val;
    }
    
    int sumRange(int left, int right) {
        return query(1,IDX(left),IDX(right));
    }
private:
    int Num;
};
