#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    // return the immidiate next possible words
    vector<string> findNext(string curr, vector<string>& wlist)
    {
        vector<string> nexts;
        for(string s : wlist)
        {
            int k = 0;
            for(int i = 0; (i < s.size()) && (k < 2) ; i++)
            {
                if(curr[i] != s[i])
                    k++;
            }
            if(k < 2)
                nexts.push_back(s);
        }
        return nexts;
    }
    bool remove(vector<string>& list, string word)
    {
        for(auto elem = list.begin(); elem  != list.end(); elem++)
        {
            if( word == *elem)
            {
                list.erase(elem);
                return true;
            }
        }
        return false;
    }
    
    void solve(string begin, string end, vector<string>& wlist, vector<vector<string>>& papaSol, vector<string>& babySol, int& min)
    {
        if(babySol.size() > min)
            return;
        if(begin == end)
        {
                if(min == babySol.size())
                {
                    papaSol.push_back(babySol);
                }
                else if(min > babySol.size())
                {
                    for(auto vec : papaSol)
                        vec.clear();
                    papaSol.clear();
                    papaSol.push_back(babySol);
                    min = babySol.size();
                }
        }
        else if(wlist.size() == 0)
        {
            return;
        }
        else
        {
            vector<string> words = findNext(begin, wlist);
            for(string word : words)
            {
                remove(wlist, word);
                babySol.push_back(word);
                solve(word, end, wlist, papaSol, babySol, min);
                wlist.push_back(word);
                remove(babySol, word);
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> solution;
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return solution;
        else
        {
            vector<string> babySol;
            int min = INT_MAX;
            babySol.push_back(beginWord);
            remove(wordList, beginWord);
            solve(beginWord, endWord, wordList, solution, babySol, min);
            return solution;
        }
    }
};