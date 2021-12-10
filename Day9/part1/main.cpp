#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

void parseInput(string textfile, vector<vector<int>>& adjL) {
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

        vector<int> curV;

        if (line == "")
        {
            continue;
        }

        line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1"); // removes leading, trailing and extra spacing;

        for(int i = 0; i < line.size(); i++) {
            curV.push_back((line[i] - '0'));
        }

        adjL.push_back(curV);
    }

}

int main()
{

    vector<vector<int>> matrix;

    parseInput("test9.txt", matrix);

    for(int i = 0; i < matrix.size(); i++) {
        vector<int> cur = matrix[i];
        std::cout << "Row " << i << ": ";

        for(int j = 0; j < cur.size(); j++) {
            std::cout << cur[j] << " ";
        }
        std::cout << std::endl;
    }

    int final;

    ofstream outfile("p1outtest9.txt");

    // outfile << final << endl;
    // cout << final << endl;


    return 0;
}