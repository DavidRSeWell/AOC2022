#include <fstream>
#include <istream>
#include <iostream>
#include <string>

using namespace std;

int convertToInt(char act)
{
    if (act == 'X' | act == 'A')
    {
        return 1;
    }
    else if (act == 'Y' | act == 'B')
    {
        return 2;
    }
    else 
    {
        return 3;
    }
    
}

int getTotalScore(char opp, char our)
{
    int opp_val = convertToInt(opp);
    int our_val = convertToInt(our);

    if (opp_val == our_val)
    {
        return our_val + 3;
    }

    if (opp_val == 1)
    {
        if (our_val == 2)
        {
            return 6 + our_val;
        }
        else{
            return our_val;
        }
    }
 
    if (opp_val == 2)
    {
        if (our_val == 3)
        {
            return 6 + our_val;
        }
        else{
            return our_val;
        }
    }
    
    if (opp_val == 3)
    {
        if (our_val == 1)
        {
            return 6 + our_val;
        }
        else{
            return our_val;
        }
    }

    return -1;
}

int day2_1(string path)
{
    ifstream dataInput(path);

    string line;

    int totalScore = 0;
    if(dataInput.is_open())
    {
        while(getline(dataInput, line))
        {
            cout << "Line: " << line << endl;
            char opp = line[0];
            char our = line[2];
            totalScore += getTotalScore(opp, our);
        }
    }
    else
    {
        cout << "Could not open the file!!" << endl;
        return -1;
    }

    cout << "Total Score is " << totalScore << endl;

    return totalScore;
}

int getTotalScore2(int opp, char outcome)
{
    if (outcome == 'Y')
    {
        return opp + 3;
    }
    else if (outcome == 'X')
    {
        switch (opp)
        {
            case (1):
                return 3;
            case (2):
                return 1;
            case (3):
                return 2;
        }
    }
    else // We want to win
    {

        switch (opp)
        {
            case (1):
                return 2 + 6;
            case (2):
                return 3 + 6;
            case (3):
                return 1 + 6;
        }
    }

    return -1;
}

int day2_2(string path)
{
    ifstream dataInput(path);

    string line;

    int totalScore = 0;
    if(dataInput.is_open())
    {
        while(getline(dataInput, line))
        {
            cout << "Line: " << line << endl;
            char opp = line[0];
            char our = line[2];
            int opp_val = convertToInt(opp);
            int score = getTotalScore2(opp_val, our);
            totalScore += score;
        }
    }
    else
    {
        cout << "Could not open the file!!" << endl;
        return -1;
    }

    cout << "Total Score is " << totalScore << endl;

    return totalScore;
}

int main()
{
    cout << "Running day 2 " << endl;

    string path = "../data/day2.txt";

    day2_2(path);

    return 0;

}