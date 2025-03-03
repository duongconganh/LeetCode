#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> pivotArray(vector<int>& n, int pivot) {
        int small = 0;
        int size = n.size();
        int big = size;
        int sum = 0;
        vector<int> ans(big ,pivot);
        for(int i = 0; i < size;i ++){
            if(n[i] < pivot){
                ans[small ++] = n[i];
            }
            if(n[size - 1 - i] > pivot){
                ans[--big] = n[size - 1 - i];
            }
        }

        return ans;
    }
};