#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <stack>
#include <valarray>

using namespace std;

int day1(string path, int numRemeber)
{
    //stack<int> maxCal; // FILO
    int maxCal[numRemeber];

    for (int i = 0; i < numRemeber; i ++){
        maxCal[i] = i;
    }

    string line;

    ifstream dataInput(path);

    int len = sizeof(maxCal) / sizeof(maxCal[0]);

    if (dataInput.is_open())
    {

        int curr_count = 0;
        while (getline(dataInput, line))
        {
            cout << line << "\n";
            if (line.size() == 0)
            {
                if (curr_count > maxCal[0])
                {
                    maxCal[0] = curr_count;
                    sort(maxCal, maxCal + len); // Keep sorted since this is not guarunteed
                }
                curr_count = 0;
            }
            else
            {
                curr_count += stoi(line);
            }

        }
        dataInput.close();
    }

    int totalMax = 0;

    for (int i = 0; i < numRemeber; i++)
    {
        cout << "The ith total is " << maxCal[i] << "\n";
        totalMax += maxCal[i];
    }

    cout << "The sum total is " << totalMax << "\n";
    return totalMax;

}

int main()
{
    string path = "../data/day1.txt";
    day1(path, 3);
    return 0;
}