#include<iostream>
#include<vector>
using namespace std ;



class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = generatePrimes(1000);
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] <= nums[i-1]) return false;
            
            if(i == 0) {
                for(int j = primes.size()-1; j >= 0; j--) {
                    if(primes[j] < nums[i]) {
                        nums[i] -= primes[j];
                        break;
                    }
                }
            } else {
                for(int j = primes.size()-1; j >= 0; j--) {
                    if(primes[j] < nums[i] && nums[i] - primes[j] > nums[i-1]) {
                        nums[i] -= primes[j];
                        break;
                    }
                }
            }
        }
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
private:
vector<int> generatePrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false;
        
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n; i++) {
            if(isPrime[i]) primes.push_back(i);
        }
        return primes;
    }
};


int main(){
    Solution s ;
    vector<int> nums ={4,9,6,10} ;
    cout << s.primeSubOperation(nums) <<endl ;
}