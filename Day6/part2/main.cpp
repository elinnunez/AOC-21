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

    long long int school[8] = {0};

    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
       
        school[stoi(token)]+=1;

        line.erase(0, pos + delimiter.length());
    }
    school[stoi(line)]+=1;

    //group the fishes by day = i;
    for (int i = 0; i < 256; i++)
    {   
        long long int temp = school[0];
        //move each val down 1 index since subtract 1 from their life cycle
        for(int i = 0; i < 8; i++) {
            school[i] = school[i+1];
        }
        school[6]+=temp;
        school[8] =temp;
    }

    long long total = 0;
    for(int i = 0; i < 9; i++) {
        // cout << "Index " << i << " : ";
        // cout << school[i] << endl;

        total+= school[i];
    }

    cout << total << endl;

    ofstream outfile("p2out6.txt");

    outfile << total << endl;

    return 0;
}