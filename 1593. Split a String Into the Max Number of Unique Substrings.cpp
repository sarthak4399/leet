#include<iostream>
#include<string>
#include<unordered_set>
using namespace std ;


class Solution {

public:
    int maxUniqueSplit(string s) {
        int unique_count ;
        unordered_set<string> unique_set;
        unique_count = 0;
        for (int i = 0 ; i < s.size(); i++){
            string temp = "";
            for (int j = i ; j < s.size(); j++){
                temp += s[j];
                if (unique_set.find(temp) == unique_set.end()){
                    unique_set.insert(temp);
                    unique_count++;
                    i = j;
                    break;
                }
            }
        }
        return unique_count;
    }
};


int main () {
    Solution s;
    string str = "ababccc";
    std::cout<<s.maxUniqueSplit(str)<<std::endl;
    return 0;
}