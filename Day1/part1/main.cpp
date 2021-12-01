#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream myfile ("input.txt");

    int ltp = 0;

    int prev, curr;

    if(!myfile.is_open()) {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;
    getline(myfile, line);

    prev = stoi(line);

    while(!myfile.eof()) {
        getline(myfile, line);

        if(line == "") {
            continue;
        }
        curr = stoi(line);
        if(curr > prev) {
            ltp++;
        }
        prev = curr;
    }

    ofstream outfile ("part1output.txt");

    outfile << ltp << endl;

    return 0;
}