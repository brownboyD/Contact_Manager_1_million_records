#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Phonebook
{
    public:
    vector<string> firstNames;
    vector<string> lastNames;
    vector<string> mobileNumber;

    void add(string firstName, string lastName, string phone)
    {
        transform(firstName.begin(),firstName.end(),firstName.begin(),::tolower);
        transform(lastName.begin(),lastName.end(),lastName.begin(),::tolower);
        transform(phone.begin(),phone.end(),phone.begin(),::tolower);
        firstNames.push_back(firstName);
        lastNames.push_back(lastName);
        mobileNumber.push_back(phone);
    }    
};