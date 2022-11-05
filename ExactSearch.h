#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include"Phonebook.h"
#include<set>
using namespace std;
void exactSearch(int further, string input, set<int> &results, Phonebook &book)
{
    bool flag = false;
    transform(input.begin(),input.end(), input.begin(),::tolower);
    if(further == 1)
    {
        for(auto val: results)
        {
            if(book.firstNames[val] == input)
            {
                cout << book.firstNames[val] <<  " " << book.lastNames[val] << " " << book.mobileNumber[val] << "\n";
                flag = true;
            }
        }
        if(!flag)cout << "NOT FOUND \n";
    }
    else if(further == 2)
    {
       for(auto val: results)
        {
            if(book.lastNames[val] == input)
            {
                cout << book.firstNames[val] <<  " " << book.lastNames[val] << " " << book.mobileNumber[val] << "\n";
                flag = true;
            }
        } 
        if(!flag)cout << "NOT FOUND \n";
    }
    else if(further == 3)
    {
       for(auto val: results)
        {
            if(book.mobileNumber[val] == input)
            {
                cout << book.firstNames[val] <<  " " << book.lastNames[val] << " " << book.mobileNumber[val] << "\n";
                return;
            }
        } 
        cout << "NOT FOUND \n";
    }
    else if(further == 4)
    {
        for(auto val: results)
        {
            cout << book.firstNames[val] <<  " " << book.lastNames[val] << " " << book.mobileNumber[val] << "\n";
        }
        cout << "Total matched records :-  " << results.size() << "\n\n";
        
    } 
}
