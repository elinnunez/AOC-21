#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(string filename, int one[], int zero[], int index) {
    string line;

    ifstream mf(filename);

    while (!mf.eof())
    {
        getline(mf, line);

        cout << "line: " << line << endl;

        if (line == "")
        {
            continue;
        }

        if(line[index] == '1') {
            one[index]+=1;
        } else {
            zero[index]+=1;
        }
    }

    mf.close();
}

void outputFun(string filename, string of, char c, int index)
{
    ofstream outfile(of);

    string line;

    ifstream mf(filename);

    while (!mf.eof())
    {
        getline(mf, line);

        cout << "line: " << line << endl;

        if (line == "")
        {
            continue;
        }

        // for(int i = 0; i < line.length(); i++) {
        //     if(line[i] == '1') {
        //         oneArr[i]+=1;
        //     } else {
        //         zeroArr[i]+=1;
        //     }
        // }

        if(line[index] == c) {
            outfile << line << endl;
        }
    }

    outfile.close();
    mf.close();

    // return mf;
}

int main()
{

    ifstream myfile("test3.txt");

    if (!myfile.is_open())
    {
        cout << "Can't Open File" << endl;
        return 1;
    }

    string line;

    int oneArr[12];
    int zeroArr[12];

    for (int i = 0; i < 12; i++)
    {
        oneArr[i] = 0;
        zeroArr[i] = 0;
    }

    while (!myfile.eof())
    {
        getline(myfile, line);

        // cout << "line: " << line << endl;

        if (line == "")
        {
            continue;
        }

        // for(int i = 0; i < line.length(); i++) {
        //     if(line[i] == '1') {
        //         oneArr[i]+=1;
        //     } else {
        //         zeroArr[i]+=1;
        //     }
        // }

        if (line[0] == '1')
        {
            oneArr[0] += 1;
        }
        else
        {
            zeroArr[0] += 1;
        }
    }


    myfile.close();

    if(oneArr[0] >= zeroArr[0]) {
        outputFun("test3.txt", "filter" + to_string(1) + ".txt", '1', 0);
    } else {
        outputFun("test3.txt", "filter" + to_string(1) + ".txt", '0', 0);
    }

    for(int i = 1; i < 5; i++) {
        readFile("filter"+ to_string(i) +".txt", oneArr, zeroArr, i);

        if(oneArr[i] >= zeroArr[i]) {
            outputFun("filter"+ to_string(i) + ".txt", "filter" + to_string(i+1) + ".txt", '1', i);
        } else {
            outputFun("filter"+ to_string(i) + ".txt", "filter" + to_string(i+1) + ".txt", '0', i);
        }
    }



    // string bingamma;
    // string binepsilon;

    // for (int i = 0; i < 12; i++)
    // {
    //     if (oneArr[i] > zeroArr[i])
    //     {
    //         bingamma += "1";
    //         binepsilon += "0";
    //     }
    //     else
    //     {
    //         bingamma += "0";
    //         binepsilon += "1";
    //     }
    // }

    // ofstream outfile("pt1output3.txt");

    // int decgamma = std::stoi(bingamma, nullptr, 2);
    // int decepsilon = std::stoi(binepsilon, nullptr, 2);

    // int total = decgamma * decepsilon;

    // outfile << total << endl;

    // cout << bingamma << endl;
    // cout << binepsilon << endl;

    // cout << "oneArr: " << endl;
    // for(int i = 0; i < 12; i++) {
    //     cout << oneArr[i] << endl;
    // }

    // cout << endl;
    // cout << "zeroArr: " << endl;
    // for (int i = 0; i < 12; i++) {
    //     cout << zeroArr[i] << endl;
    // }

    // outfile.close();

    return 0;
}