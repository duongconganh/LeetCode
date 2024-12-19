class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int value = 0;
        int maxi = 0;

        int count = 0; 
        int  j = 0;
        int k = 0; 

        for(int i=0;i<arr.size();i++)
        {
            maxi = max(maxi,arr[i]);
            if(arr[i]==value){
                k=1;
            }
            if(k==1 && maxi-j == (i-j)){
                count++;
                value = maxi+1;
                maxi = 0;
                k=0;
                j = i;
            }
        }
        return count;
    }
}; 