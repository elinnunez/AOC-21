#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{

    ifstream myfile("input4.txt");

    if (!myfile.is_open())
    {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string input;
    getline(myfile, input);

    vector<int> inputs;
    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        inputs.push_back(stoi(token));
        // cout << inputs[inputs.size() - 1] << endl;
        // std::cout << token << std::endl;
        input.erase(0, pos + delimiter.length());
    }
    inputs.push_back(stoi(input));
    // cout << inputs[inputs.size() - 1] << endl;

    // cout << "Inputs size: " << inputs.size() << endl;

    string line;

    vector<vector<int>> dino(100);
    int curdI = -1;

    while (!myfile.eof())
    {
        getline(myfile, line);

        if (line == "")
        {
            curdI += 1;
            // cout << "New Grid: " << curdI << endl;
            continue;
        }

        line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1"); // removes leading, trailing and extra spacing;

        // cout << line << endl;

        delimiter = " ";
        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            dino[curdI].push_back(stoi(token));

            // std::cout << token << "-" << std::endl;
            // cout << dino[curdI][dino[curdI].size() - 1] << endl;
            line.erase(0, pos + delimiter.length());
        }
        dino[curdI].push_back(stoi(line));
        // cout << dino[curdI][dino[curdI].size() - 1] << endl;
        // cout << line << "-" << endl;
    }

    dino.resize(curdI);

    // cout << "Dino af size: " << dino.size() << endl;

    bool bingo = false;
    int F = 0;

    int finalCall;
    int winningCard;

    int lastCard = dino.size();
    int lastCI;

    vector<bool> curwins(dino.size(), false);

    while (lastCard > 0)
    {
        // cout << "input cur: " << inputs[F] << endl;
        for (int i = 0; i < dino.size(); i++)
        {
            // cout << "Dino " << i << " size: " << dino[i].size() << endl;
            vector<int> curt = dino[i];

            for (int j = 0; j < curt.size(); j++)
            {
                if (curt[j] == inputs[F])
                {
                    dino[i][j] = -1;
                    // cout << inputs[F] << " found" << endl;
                }
            }
        }

        for (int f = 0; f < dino.size(); f++)
        {
            vector<int> cur = dino[f];

            if(curwins[f] == true) {
                continue;
            }

            for (int k = 0; k < 5; k++)
            {
                if ((cur[0 + k] + cur[5 + k] + cur[10 + k] + cur[15 + k] + cur[20 + k]) == -5)
                {
                    bingo = true;
                    finalCall = inputs[F];
                    // cout << "final num: " << finalCall << endl;
                    winningCard = f;
                    // cout << "Horizontal Bingo on card index: " << f << endl;
                    lastCI = f;

                    curwins[f] = true;
                }
            }

            for (int k = 0; k < cur.size(); k += 5)
            {
                if ((cur[0 + k] + cur[1 + k] + cur[2 + k] + cur[3 + k] + cur[4 + k]) == -5)
                {
                    bingo = true;
                    finalCall = inputs[F];
                    // cout << "final num...: " << finalCall << endl;
                    winningCard = f;
                    // cout << "Vertical Bingo on card index: " << f << endl;
                    lastCI = f;

                    curwins[f] = true;
                }
            }

            if(curwins[f] == true) {
                lastCard -=1;
            }
        }
        F++;
    }

    int sum = 0;

    for(int i = 0; i < dino[lastCI].size(); i++) {
        if(dino[lastCI][i] != -1) {
            sum+= dino[lastCI][i];
        }
    }

    cout << "Final Num: " << finalCall << endl;
    cout << "Final Card Sum: " << sum << endl;
    cout << "Final Card Index: " << lastCI << endl;
    int final = sum * finalCall;

    ofstream outfile("p2out4.txt");

    outfile << final << endl;
    cout << "Final Total: " << final << endl;


    //for testing

    // for (int i = 0; i < dino[lastCI].size(); i++)
    // {
    //     cout << dino[lastCI][i] << " ";
    //     if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24)
    //     {
    //         cout << endl;
    //     }
    // }

    return 0;
}