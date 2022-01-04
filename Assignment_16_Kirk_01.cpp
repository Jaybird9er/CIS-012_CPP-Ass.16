#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main ()
{
    // file initiation
    ifstream inData;
    inData.open("Data.txt");

    // variables
    int val = 0;
    int index = 0;
    int numArray[26];
    int countArray[26];
    int row = 0;

    // body
    // copy data from file to array
    while (! inData.eof())
    {
        inData >> val;
        numArray[index] = val;
        index++;
    }

    // count student ranges
    index = 0;
    for (int rangeEval = 0; rangeEval <= 200; rangeEval)
    {
        int sum = 0;
        for (int student = 0; student < 26; student++)
        {
            int rangeEnd = 0;
            if (rangeEval == 175)
            {
                rangeEnd += 1;
            }
            if (numArray[student] >= rangeEval && numArray[student] < rangeEval + 25 + rangeEnd)
            {
                sum += 1;
            }
        countArray[index] = sum;
        }
        index++;
        rangeEval += 25;
    }

    cout << setw(8) << "Range" << setw(18)<< "# of Students" << endl;

    // arrange and print table
    for (int range = 0; range < 200; range++)
    {
        cout << setw(3) << right << range << " - " << setw(3) << right;
        if (range + 24 == 199)
        {
            range = 200;
        }
        else
        {
            range = range + 24;
        }
        cout << range << setw(13) << countArray[row] << endl;
        row++;
    }

    // close file
    inData.close();

    return 0;
}
