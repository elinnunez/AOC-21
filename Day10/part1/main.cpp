#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <stack>

using namespace std;

void parseInput(string textfile, vector<string> &adjL)
{
    ifstream mf(textfile);

    if (!mf.is_open())
    {
        cout << "Can't Open File" << endl;
        return;
    }

    string line;

    while (!mf.eof())
    {
        getline(mf, line);

        if (line == "")
        {
            continue;
        }

        line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1"); // removes leading, trailing and extra spacing;

        adjL.push_back(line);
    }
}

int main() {
    vector<string> phrases;

    parseInput("input10.txt", phrases);

    // std::cout << "Phrases Len: " << phrases.size() << std::endl;

    vector<char> broken;
    for(int i = 0; i < phrases.size(); i++) {
        string str = phrases[i];
        // cout << str << ": ";
        stack<char> bag;

        int j = 0;
        bool flag = false;
        while(j < str.length() && flag != true) {
            char cur = str[j];
            if(bag.empty()) {
                if(cur == ']' || cur == ')' || cur == '}' || cur == '>') {
                    // cout << "Broken: " << cur << endl;
                    broken.push_back(cur);
                    flag = true;
                } else {
                    bag.push(cur);
                }
            } else if (cur == '[' || cur == '(' || cur == '{' || cur == '<') {
                bag.push(cur);
            } else {
                if(bag.top() == '[' && cur == ']' || bag.top() == '(' && cur == ')' || bag.top() == '{' && cur == '}' || bag.top() == '<' && cur == '>') {
                    bag.pop();
                } else {
                    broken.push_back(cur);
                    // cout << "broken: " << cur << endl;
                    flag = true;
                }
            }
            j++;
        }
    }

    int total = 0;
    
    // std::cout << "Broken Chars: " << std::endl;
    for(int i = 0; i < broken.size(); i++) {
        char cur = broken[i];
        // std::cout << cur << std::endl;
        if(cur == ')') {
            total+= 3;
        } else if (cur == ']') {
            total+= 57;
        } else if (cur == '}') {
            total+= 1197;
        } else if (cur == '>') {
            total+= 25137;
        }
    }

    std::cout << "Corrupted Total: " << total << std::endl;

    ofstream outfile("p1out10.txt");

    outfile << total << endl;

    return 0;
}