#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include "./TrieNode.h"
using namespace std;
class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word, int i)
    {
        transform(word.begin(), word.end(), word.begin(),::tolower);
        if(word.size() == 0)
        {
            root -> isEnd = true;
            root -> index.insert(i);
            return;
        }
        int ind = word[0]-'a';
        TrieNode* child;

        if(root -> children[ind] != NULL)
        {
            child = root -> children[ind];
        }
        else 
        {
            child = new TrieNode(word[0]);
            root -> children[ind] = child;
        }
        insertUtil(child, word.substr(1),i);
    }

    void insertWord(string word, int i)
    {
        insertUtil(root,word,i);
    }
    bool isLastNode(TrieNode* root)
    {
	    for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return 0;
            }			
        }
	    return 1;
    }
    void suggestions(TrieNode* root, string prefix, set<int> &results)
    {
        if(root -> isEnd)
        {
            for(auto it:root -> index)
            {
                results.insert(it);
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(root -> children[i])
            {
                char child = 'a' + i;

                suggestions(root -> children[i], prefix+child, results);
            }
        }
    }
    int autoSuggestion(TrieNode* root, const string input,set<int> &results)
    {
        TrieNode* current = root;
        for(auto ch: input)
        {
            int ind = ch-'a';
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


