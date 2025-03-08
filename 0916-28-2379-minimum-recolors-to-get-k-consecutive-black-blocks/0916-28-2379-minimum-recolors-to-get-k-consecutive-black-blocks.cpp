class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n;
        int check = 0;
        for(int i = 0;i < n;i ++){
            if(i < k){
                if(blocks[i] == 'W'){
                    check++;
                }
            }else{
                ans = min(ans, check);
                if(blocks[i] == 'W' && blocks[i - k] == 'B'){
                    check++;
                }else if(blocks[i] == 'B' && blocks[i - k] == 'W'){
                    check--;
                }
            }
        }

        return ans = min(ans, check);;
    }
};