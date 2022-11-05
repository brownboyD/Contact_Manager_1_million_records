#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isEnd;
    set<int> index;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)children[i] = NULL;
        isEnd = false;
    }
};