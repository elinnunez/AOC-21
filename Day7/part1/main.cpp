#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ifstream myfile("input7.txt");

    if (!myfile.is_open())
    {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;
    getline(myfile, line);

    vector<int> ship;

    string delimiter = ",";
    size_t pos = 0;
    string token;

    int maxH = 0;
    int minH = 0;

    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);

        ship.push_back(stoi(token));

        maxH = max(stoi(token), maxH);
        minH = min(stoi(token), minH);

        line.erase(0, pos + delimiter.length());
    }
    ship.push_back(stoi(line));
    maxH = max(stoi(line), maxH);
    minH = min(stoi(line), minH);

    // cout << "Max Horizontal: " << maxH << endl;
    // cout << "Min Horizontal: " << minH << endl;

    int minFuel = 0;

    for (int j = minH; j <= maxH; j++)
    {
        if (std::find(ship.begin(), ship.end(), j) != ship.end())
        {
            // cout << "Found: " << j << endl;
            int curMin = 0;
            for (int i = 0; i < ship.size(); i++)
            {
                // cout << ship[i] << " -> ";
                if (ship[i] > j)
                {
                    curMin += (ship[i] - j);
                    // cout << ship[i] - j << " ";
                }
                else if (ship[i] < j)
                {
                    curMin += (j - ship[i]);
                    // cout << j - ship[i];
                }
            }

            // cout << "curMin: " << curMin << endl;
            if (j == minH)
            {
                minFuel = curMin;
            }
            else
            {
                minFuel = min(curMin, minFuel);
            }
        }
    }

    cout << minFuel << endl;

    ofstream outfile("p1out7.txt");

    outfile << minFuel << endl;

    return 0;
}