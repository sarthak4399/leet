#include <iostream>
#include <vector>
using namespace std ;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == ' '){
                s1[i] = ' ' ;
            }
        }
        for(int i = 0 ; i < s2.size() ; i++){
            if(s2[i] == ' '){
                s2[i] = ' ' ;
            }
        }
        vector<string> res ;
        string temp = "" ;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == ' '){
                res.push_back(temp) ;
                temp = "" ;
            }else{
                temp += s1[i] ;
            }
        }
        res.push_back(temp) ;
        temp = "" ;
        for(int i = 0 ; i < s2.size() ; i++){
            if(s2[i] == ' '){
                res.push_back(temp) ;
                temp = "" ;
            }else{
                temp += s2[i] ;
            }
        }
        res.push_back(temp) ;
        vector<string> ans ;

        for(int i = 0 ; i < res.size() ; i++){
            int count = 0 ;
            for(int j = 0 ; j < res.size() ; j++){
                if(res[i] == res[j]){
                    count++ ;
                }
            }
            if(count == 1){
                ans.push_back(res[i]) ;
            }
        }
        return ans ;
        
    }
};
int main(){
    Solution s ;
    vector<string> res = s.uncommonFromSentences("this apple is sweet", "this apple is sour") ;
    for(auto i : res){
        cout << i << " " ;
    }
    return 0 ;  
}