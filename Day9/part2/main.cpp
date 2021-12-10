//prob an island/graph problem


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

void parseInput(string textfile, vector<vector<int>> &adjL)
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

        vector<int> curV;

        if (line == "")
        {
            continue;
        }

        line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1"); // removes leading, trailing and extra spacing;

        for (int i = 0; i < line.size(); i++)
        {
            curV.push_back((line[i] - '0'));
        }

        adjL.push_back(curV);
    }
}

int main()
{

    vector<vector<int>> matrix;

    vector<int> lowpoints;
    vector<int> basin;

    parseInput("test9.txt", matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> cur = matrix[i];
        std::cout << "Row " << i << ": ";

        for (int j = 0; j < cur.size(); j++)
        {
            std::cout << cur[j] << " ";
            int temp = cur[j];
            int count = 0;
            if (i == 0)
            {
                if (j == 0)
                {

                    if (temp < cur[j + 1] && temp < matrix[1][0])
                    {
                        lowpoints.push_back(temp);
                        int k = 0;
                        while (cur[j + k] != 9 && k < cur.size())
                        {
                            k++;
                            count += 1;
                        }
                        k = 1;
                        while (matrix[i + k][0] != 9 && k < matrix.size())
                        {
                            k++;
                            count += 1;
                        }
                        basin.push_back(count);
                    }
                }
                else if (j == cur.size() - 1)
                {
                    if (temp < cur[j - 1] && temp < matrix[1][cur.size() - 1])
                    {
                        lowpoints.push_back(temp);
                        int k = 0;
                        while(cur[j-k] != 9 && k < cur.size()) {
                            k++;
                            count++;
                        }

                        k = 1;
                        while(matrix[i+k][j] != 9 && k < matrix.size()) {
                            k++;
                            count++;
                        }
                        basin.push_back(count);
                    }
                }
                else
                {
                    if (temp < cur[j - 1] && temp < cur[j + 1] && temp < matrix[1][j])
                    {
                        lowpoints.push_back(temp);
                        int k = 0;

                        while(cur[j-k] != 9 && j-k > -1) {
                            k++;
                            count++;
                        }
                        
                        k = 1;
                        while(cur[j+k] != 9 && j+k < cur.size()) {
                            k++;
                            count++;
                        }

                        k = 1;

                        while(matrix[i+k][j] != 9 && k < matrix.size()) {
                            k++;
                            count++;
                        }

                        basin.push_back(count);
                    }
                }
            }
            else if (i == matrix.size() - 1)
            {
                if (j == 0)
                {
                    if (temp < cur[j + 1] && temp < matrix[i - 1][0])
                    {
                        lowpoints.push_back(temp);
                    }
                }
                else if (j == cur.size() - 1)
                {
                    if (temp < cur[j - 1] && temp < matrix[i - 1][j])
                    {
                        lowpoints.push_back(temp);
                    }
                }
                else
                {
                    if (temp < cur[j - 1] && temp < cur[j + 1] && temp < matrix[i - 1][j])
                    {
                        lowpoints.push_back(temp);
                    }
                }
            }
            else
            {
                if (j == 0)
                {
                    if (temp < cur[j + 1] && temp < matrix[i - 1][0] && temp < matrix[i + 1][0])
                    {
                        lowpoints.push_back(temp);
                    }
                }
                else if (j == cur.size() - 1)
                {
                    if (temp < cur[j - 1] && temp < matrix[i - 1][j] && temp < matrix[i + 1][j])
                    {
                        lowpoints.push_back(temp);
                    }
                }
                else
                {
                    if (temp < cur[j - 1] && temp < cur[j + 1] && temp < matrix[i - 1][j] && temp < matrix[i + 1][j])
                    {
                        lowpoints.push_back(temp);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int final = lowpoints.size();

    std::cout << "Low Points: ";
    for (int i = 0; i < lowpoints.size(); i++)
    {
        std::cout << lowpoints[i] << " ";
        final += lowpoints[i];
    }
    std::cout << std::endl;

    std::cout << "Basin: ";
    for (int i = 0; i < basin.size(); i++)
    {
        std::cout << "Row " << i << ": ";
        std::cout << basin[i] << std::endl;
    }
    std::cout << std::endl;

    ofstream outfile("p2outtest9.txt");

    outfile << final << endl;
    cout << "Sum: " << final << endl;

    return 0;
}