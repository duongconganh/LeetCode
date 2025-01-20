typedef pair<int, int> p;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // from map make a mapping of the value with it's {row, col}
        vector<p> mp(m*n + 1); // coz we need till index m*n

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowColorCount(m), colColorCount(n);

        for(int i = 0; i < arr.size(); i++){
            int value = arr[i];
            int row = mp[value].first, col = mp[value].second;
            
            if(++rowColorCount[row] == n || ++colColorCount[col] == m) return i;
        }

        return -1;
        
    }
};