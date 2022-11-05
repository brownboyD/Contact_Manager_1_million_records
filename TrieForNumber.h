#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include "./TrieNodeForNumber.h"
using namespace std;
class TrieForNumber
{
    public:
    TrieNodeForNumber* root;
    TrieForNumber()
    {
        root = new TrieNodeForNumber('\0');
    }
    void insertUtil(TrieNodeForNumber* root, string word, int i)
    {
        if(word.size() == 0)
        {
            root -> isEnd = true;
            root -> index.insert(i);
            return;
        }
        int ind = word[0]-'0';
        TrieNodeForNumber* child;

        if(root -> children[ind] != NULL)
        {
            child = root -> children[ind];
        }
        else 
        {
            child = new TrieNodeForNumber(word[0]);
            root -> children[ind] = child;
        }
        insertUtil(child, word.substr(1),i);
    }

    void insertWord(string word, int i)
    {
        string temp = "";
        for(auto ch: word)
        {
            if(ch-'0' >= 0 && ch-'0' <= 9)temp.push_back(ch);
        }
        word = temp;
        insertUtil(root,word,i);
    }
    bool isLastNode(TrieNodeForNumber* root)
    {
	    for (int i = 0; i < 10; i++)
        {
            if (root->children[i])
            {
                return 0;
            }			
        }
	    return 1;
    }
    void suggestions(TrieNodeForNumber* root, string prefix, set<int> &results)
    {
        if(root -> isEnd)
        {
            for(auto it:root -> index)
            {
                results.insert(it);
            }
        }
        for(int i = 0; i < 10; i++)
        {
            if(root -> children[i])
            {
                char child = '0' + i;

                suggestions(root -> children[i], prefix+child, results);
            }
        }
    }
    int autoSuggestion(TrieNodeForNumber* root, const string input,set<int> &results)
    {
        TrieNodeForNumber* current = root;
        for(auto ch: input)
        {
            int ind = ch-'0';
            if(!current -> children[ind])
            {
                return 0;
            }
            current = current -> children[ind];
        }
            if(isLastNode(current))
            {
                results.insert(*((current->index).begin()));
                return -1;
                
            }
            suggestions(current,input,results);
            return 1;
    }
    
    int search(string input, set<int> &results)
    {
        transform(input.begin(),input.end(),input.begin(),::tolower);
        autoSuggestion(root, input, results);
        return 1;
    }

};


