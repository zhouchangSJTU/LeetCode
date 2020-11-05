#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> used;
        used.insert(beginWord);
        unordered_map<string,int> mem;
        int res;
        res = find(beginWord,endWord,wordList,used,mem)+1;
        if(res>=999999){
            return 0;
        }
        else{
            return res;
        }
    }

    int find(string beginWord, string endWord, vector<string>& wordList, unordered_set<string> used, unordered_map<string,int> & mem){
        if(mem.find(beginWord)!=mem.end()){
            return mem[beginWord];
        }
        int tempSove=0;
        int minres=999999;
        string tempKey;
        for(auto str: wordList){
            if(beginWord==endWord){
                return 0;
            }
            else if(used.find(str)!=used.end()){
                continue;
            }
            else{
                if(trans(beginWord,str)){
                    used.insert(str);
                    tempSove=tempSove+1;
                    // if(minres>(find(str,endWord,wordList,used)+1)){
                    //     minres=find(str,endWord,wordList,used)+1;
                    //     tempKey=str;
                    // }
                    minres=min(minres,find(str,endWord,wordList,used,mem)+1);
                    used.erase(str);
                }
            }
        }
        if(tempSove){
            mem.insert({beginWord,minres});
            return minres;
        }
        else{
            mem.insert({beginWord,999999});
            return 999999;
        }
    }

    bool trans(string beginWord, string endWord){
        int len = beginWord.size();
        int count = 0;
        for(int i=0;i<=len-1;i++){
            if(beginWord[i]!=endWord[i]){
                count=count+1;
            }
        }
        if(count==1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Solution sl;
    string beginWord="a";
    string endWord="c";
    vector<string> wordList={"a","b","c"};
    int res;
    res = sl.ladderLength(beginWord,endWord,wordList);
    cout<<res<<endl;
    return 0;
}
