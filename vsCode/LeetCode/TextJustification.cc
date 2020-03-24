/*
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include<bits/stdc++.h>
#include "map"
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> output;
    string s = "";
    for(int i = 0; i < words.size(); i++)
    {
        s += words[i];
        if((s.length() < maxWidth) && ((i+1) < words.size()))
        {
            //check for next words
            int j = i+1, len = s.length();
            bool single = true;
            while(j < words.size())
            {
                if((len + words[j].length() + 1)<= maxWidth)
                {
                    single = false;
                    len += (words[j].length() + 1);
                    j++;
                }
                else
                {
                    break;
                }
            }
            bool padding = true;
            if(j == words.size())
            {
                //padding is not tolerated
                padding = false;
            }
            if(!single)
                j--;
            int spaces_per_word = (maxWidth - len) / (j - i);
            int left_spaces_to_cover =  (maxWidth - len) % (j - i);
            if(single)
            {
                s+=" ";
                j--;
                padding = false;
            }
            if(padding)
            {
                //space filling zone
                for(int k = i+1; k <=j; k++)
                {
                    s = s + " ";
                    for(int l = 0; l < spaces_per_word; l++)
                        s +=" ";
                    if(left_spaces_to_cover > 0)
                    {
                        s+=" ";
                        left_spaces_to_cover--;
                    }
                    s += words[k];
                }
            }
            else
            {
                //space filling zone
                for(int k = i+1; k <=j; k++)
                {
                    s = s + " "+words[k];
                }  
                cout<<" diff : "<<(maxWidth - s.size())<<" "<<s<<endl;
                int tmp = maxWidth - s.size();
                for(int l = 0; l < tmp; l++)
                    s += " ";
            }
            i = j;
        }
        else if(i == (words.size() - 1))
        {
            for(int l = 0; l < (maxWidth - words[i].size()); l++)
                s+=" ";
        }
        output.push_back(s);
        s = "";
    }
    return output;
}

int main()
{
    vector<string> input = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    vector<string> output = fullJustify(input, maxWidth);
    for(auto s : output)
    {
        cout<<":"<<s<<":"<<endl;
    }
}