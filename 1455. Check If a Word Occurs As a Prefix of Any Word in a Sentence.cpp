#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
		return BFS(sentence, searchWord) ;
		
    }
private:
	int BFS (string sentence, string searchWord) {
		int res = 0 ;
		int i = 0 ;
		while(i < sentence.size()) {
			if(sentence[i] == ' ') {
				i++ ;
				continue ;
			}
			string word = "" ;
			while(i < sentence.size() && sentence[i] != ' ') {
				word += sentence[i] ;
				i++ ;
			}
			res++ ;
			if(word.size() >= searchWord.size() && word.substr(0, searchWord.size()) == searchWord) {
				return res ;
			}
		}
		return -1 ;
	}
};
 int main(){
	 Solution s ;
	 string sentence = "i love eating burger" ;
	 string searchWord = "burg" ;
	 cout << s.isPrefixOfWord(sentence, searchWord) << endl ;
	 return 0 ;
 }