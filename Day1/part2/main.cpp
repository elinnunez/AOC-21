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

    string line1;
    string line2;
    string line3;

    getline(myfile, line1);
    getline(myfile, line2);
    getline(myfile, line3);

    prev = stoi(line1) + stoi(line2) + stoi(line3);

    string curt;

    while(!myfile.eof()) {
        getline(myfile, curt);

        if(curt == "") {
            break;
        }

        curr = stoi(curt) + stoi(line2) + stoi(line3);

        if(curr > prev) {
            // cout << curr << " > " << prev << endl;
            ltp++;
        }

        line2 = line3;
        line3 = curt;

        prev = curr;
    }

    ofstream outfile ("part2output.txt");

    outfile << ltp << endl;

    return 0;
}