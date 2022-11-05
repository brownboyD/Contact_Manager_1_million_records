#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class TrieNodeForNumber
{
    public:
    char data;
    TrieNodeForNumber* children[10];
    bool isEnd;
    set<int> index;

    TrieNodeForNumber(char ch)
    {
        data = ch;
        for(int i = 0; i < 10; i++)children[i] = NULL;
        isEnd = false;
    }
};