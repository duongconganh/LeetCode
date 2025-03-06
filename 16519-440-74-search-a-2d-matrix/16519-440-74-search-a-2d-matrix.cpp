class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n*m - 1;
        int ans;
        while(l <= r){
            ans = (l + r)/2;
            if(matrix[ans/m][ans%m] == target){
                return true;
            }else if(matrix[ans/m][ans%m] < target){
                l = ans + 1;
            }else{
                r = ans - 1;
            }
        }

        return false;
    }
};