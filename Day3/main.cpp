#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readFile(string filename, int one[], int zero[], int index) {
    string line;

    ifstream mf(filename);

    while (!mf.eof())
    {
        getline(mf, line);

        // cout << "line: " << line << endl;

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

void outputFun(string filename, string of, char c, int index, vector<int>& bag)
{
    ofstream outfile(of);

    string line;

    ifstream mf(filename);

    int count = 0;

    string prev;

    while (!mf.eof())
    {
        getline(mf, line);

        // cout << "line: " << line << endl;

        if (line == "")
        {
            continue;
        }

        if(line[index] == c) {
            outfile << line << endl;
            count+=1;
            prev = line;
        }
    }

    outfile.close();
    mf.close();

    if(count == 1) {
        cout << "final: " << prev << endl;
        bag.push_back(std::stoi(prev, nullptr, 2));
    }

    // return mf;
}

int main()
{

    ifstream myfile("input3.txt");

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

        if (line[0] == '1')
        {
            oneArr[0] += 1;
        }
        else
        {
            zeroArr[0] += 1;
        }
    }

    vector<int> bag;

    int oneArr2[12];
    int zeroArr2[12];

    oneArr2[0] = oneArr[0];
    zeroArr2[0] = zeroArr[0];

    for(int i = 1; i < 12; i++) {
        oneArr2[i] = 0;
        zeroArr2[i] = 0;
    }


    myfile.close();

    if(oneArr[0] >= zeroArr[0]) {
        outputFun("input3.txt", "filter" + to_string(1) + ".txt", '1', 0, bag);
        outputFun("input3.txt", "f" + to_string(1) + ".txt", '0', 0, bag);
    } else {
        outputFun("input3.txt", "filter" + to_string(1) + ".txt", '0', 0, bag);
        outputFun("input3.txt", "f" + to_string(1) + ".txt", '1', 0, bag);
    }


    for(int i = 1; i < 12; i++) {
        readFile("filter"+ to_string(i) +".txt", oneArr, zeroArr, i);

        if(oneArr[i] >= zeroArr[i]) {
            outputFun("filter"+ to_string(i) + ".txt", "filter" + to_string(i+1) + ".txt", '1', i, bag);
        } else {
            outputFun("filter"+ to_string(i) + ".txt", "filter" + to_string(i+1) + ".txt", '0', i, bag);
        }
    }

    for(int i = 1; i < 12; i++) {
        readFile("f" + to_string(i) + ".txt", oneArr2, zeroArr2, i);

        if(oneArr2[i] >= zeroArr2[i]) {
            outputFun("f"+ to_string(i) + ".txt", "f" + to_string(i+1) + ".txt", '0', i, bag);
        } else {
            outputFun("f"+ to_string(i) + ".txt", "f" + to_string(i+1) + ".txt", '1', i, bag);
        }
    }

    int final = 1;

    for(int i = 0; i < bag.size(); i++) {
        final *= bag[i];
        cout << "bag: " << bag[i] << endl;
    }


    ofstream outfile("p2out3.txt");
    cout << "Final: " << final << endl;
    outfile << final << endl;

    return 0;
}