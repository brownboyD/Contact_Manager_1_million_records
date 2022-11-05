#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <vector>
#include<set>
#include"Trie.h"
#include"Phonebook.h"
#include"./TrieForNumber.h"
#include"ExactSearch.h"
using namespace std;
signed main()
{
    Trie* t = new Trie;
    TrieForNumber* m = new TrieForNumber;
    int i = -1;
    Phonebook book;
    ifstream inputFile;
    string myFilePath = "./phonebook.csv";
    inputFile.open(myFilePath);
    string line = "";
    while (getline(inputFile, line)) {
        i++;  
        stringstream inputString(line);
        string lastName, firstName, phone;   
        getline(inputString, firstName, ',');
        getline(inputString, lastName, ',');
        getline(inputString, phone, ',');
        book.firstNames.push_back(firstName);
        book.lastNames.push_back(lastName);
        book.mobileNumber.push_back(phone);
        t -> insertWord(firstName,i);       
        t -> insertWord(lastName,i);  
        m -> insertWord(phone, i);   
        line = "";
    }
    cout << "\n\n File is read and data is Stored Successfully :) \n\n";
    bool flag = false;
    while(true)
    {
        int choice;
        if(!flag)
        {
            cout<<"--------------------WELCOME TO CONTACT MANAGER-------------------"<<"\n";
            cout << "\t MENU \n\n";
        }
        flag = true;
        cout << "1. Add Contact \n\n";
        cout << "2. Search \n\n";
        cout << "Choose a number to do operation.... \n\n";
        cin >> choice;
        if(choice == 1)
        {
            string firstName,lastName, mobileNumber;
            cout << "Enter First Name \n";
            cin >> firstName;
            cout << "Enter Last Name \n";
            cin >> lastName;
            cout << "Enter Mobile Number \n";
            cin >> mobileNumber;
            transform(firstName.begin(),firstName.end(),firstName.begin(),::tolower);
            transform(lastName.begin(),lastName.end(),lastName.begin(),::tolower);
            book.add(firstName,lastName,mobileNumber);
            i++;
            t -> insertWord(firstName,i);       
            t -> insertWord(lastName,i);
            cout << "Contact added Succesfully :) \n";
        }
        else if(choice == 2)
        {
            cout << "1.Search for Exact First Name \n\n";
            cout << "2.Search for Exact Last Name \n\n";
            cout << "3.Search for Exact Mobile Num \n\n";
            cout << "4.Direct Search with Prefix string \n\n";
            cout << "Enter Choice......... \n";
            int further;
            cin >> further;
            cout<<"Input the string to be searched  \n\n";
            string input;
            cout << "Waiting for Input..... \n";
            cin >> input;
            set<int> results;
            if(input[0] - '0' >= 0 && input[0] - '0' <= 9)
            {
                m->search(input,results);
            }
            else 
            {
                t->search(input,results);
            }
            exactSearch(further,input,results,book);
            cout << "\n\n\n";
        }
        else 
        {
            cout << "invalid Input!\n\n";
            break;
        }

    }
    
}