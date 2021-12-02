#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream myfile ("input2.txt");

    if(!myfile.is_open()) {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;

    int horizontal = 0;
    int depth = 0;

    while(!myfile.eof()) {
        getline(myfile, line);

        if(line == "") {
            continue;
        }

        if(line[0] == 'f') {
            horizontal+= line[8] - '0';
        } else if (line[0] == 'd') {
            depth+= line[5] - '0';
        } else {
            depth-= line[3] - '0';
        }

    }

    int total = horizontal * depth;

    ofstream outfile ("part1output2.txt");
    outfile << total << endl;

    myfile.close();
    outfile.close();

    return 0;
}