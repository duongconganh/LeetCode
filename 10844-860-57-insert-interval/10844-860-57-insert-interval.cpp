class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int point = -1;
        int n =  intervals.size();
        int last = 2 * n;
        int i = 0;
        while(i < last){
            if(newInterval[0] <= intervals[i / 2][i % 2]){
                point = i;
                break;
            }
            i++;
        }
        if(point == -1){
            intervals.push_back(newInterval);
            return intervals;
        }
        int point1 = last;

        while(i < last){
            if(newInterval[1] < intervals[i / 2][i % 2]){
                point1 = i;
                break;
            }
            i++;
        }
        if(point1 == 0){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(point == point1 && point % 2 ==0){
            intervals.insert(intervals.begin() + point/2 , newInterval);
            return intervals;
        }

        newInterval[0] = (point % 2)?intervals[point / 2][0]:newInterval[0];
        newInterval[1] = (point1 % 2)?intervals[point1 / 2][1] :newInterval[1];

        for(int i = 0; i < n ;i ++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }else{
                break;
            }
        }
        ans.push_back(newInterval);

        for(int i = 0; i < n ;i ++){
            if(intervals[i][0] > newInterval[1]){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};