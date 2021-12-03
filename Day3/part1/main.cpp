#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream myfile ("input3.txt");

    if(!myfile.is_open()) {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;

    int oneArr[12];
    int zeroArr[12];

    for(int i = 0; i < 12; i++) {
        oneArr[i] = 0;
        zeroArr[i] = 0;
    }


    while(!myfile.eof()) {
        getline(myfile, line);

        // cout << "line: " << line << endl;

        if(line == "") {
            continue;
        }

        for(int i = 0; i < line.length(); i++) {
            if(line[i] == '1') {
                oneArr[i]+=1;
            } else {
                zeroArr[i]+=1;
            }
        }

    }

    string bingamma;
    string binepsilon;

    for(int i = 0; i < 12; i++) {
        if(oneArr[i] > zeroArr[i]) {
            bingamma+="1";
            binepsilon+="0";
        } else {
            bingamma+="0";
            binepsilon+="1";
        }
    }

    ofstream outfile ("pt1output3.txt");

    int decgamma = std::stoi(bingamma, nullptr, 2);
    int decepsilon = std::stoi(binepsilon, nullptr, 2);

    int total = decgamma * decepsilon;

    outfile << total << endl;

    cout << bingamma << endl;
    cout << binepsilon << endl;

    myfile.close();
    outfile.close();

    return 0;
}