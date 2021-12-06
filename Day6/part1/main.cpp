#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ifstream myfile("input6.txt");

    if (!myfile.is_open())
    {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;
    getline(myfile, line);
    vector<int> inputs;

    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
        inputs.push_back(stoi(token));
        line.erase(0, pos + delimiter.length());
    }
    inputs.push_back(stoi(line));

    int currTotal = 0;

    for (int i = 0; i <= 80; i++)
    {   
        int count = 0;
        // cout << "Day " << i << ": ";
        for (int j = 0; j < inputs.size(); j++)
        {
            // cout << inputs[j] << " ";
            inputs[j] = inputs[j] - 1;
            if(inputs[j] == -1) {
                inputs[j] = 6;
                count++;
            }
        }

        currTotal = inputs.size();
        
        for(int i = 0; i < count; i++) {
            inputs.push_back(8);
        }
        // cout << endl;
    }

    ofstream outfile("p1out6.txt");

    cout << currTotal << endl;

    outfile << currTotal << endl;

    return 0;
}