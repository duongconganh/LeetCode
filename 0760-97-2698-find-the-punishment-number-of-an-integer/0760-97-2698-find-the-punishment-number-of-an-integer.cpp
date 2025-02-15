bool check =  false;
int arr[1001] = {0};
class Solution {
public:
    int punishmentNumber(int n) {       
        int ans = 0;;
        for(int i = 1; i <= n;i ++){
            if(arr[i] == 0){
                checksum(i * i, i, 0);
                if(check == true){
                    ans += i * i;
                    check = false;
                    arr[i] = 1;
                }else{
                    arr[i] = 2;
                }
            }else if(arr[i] == 1){
                ans += i * i;
                check = false;
                arr[i] = 1;
            }else{
                arr[i] = 2;
            }

        }
        return ans;
    }
    void checksum(int dot, int n, int sum){
        if(check == 1)return;
        if(sum == n && dot == 0){
            check = true;
            return;
        }
        if(dot == 0) return;
        if(sum > n)return;
        for(int i = 10; dot % i <= i && i < 100000;i *= 10){
            checksum(dot / i,n,sum + dot % i);
        }


    }
};