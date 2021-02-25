#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m)
{
    string one[] = {"", "one", "two", "three", "four",
                    "five", "six", "seven", "eight",
                    "nine", "ten", "eleven", "twelve",
                    "thirteen", "fourteen", "fifteen",
                    "sixteen", "seventeen", "eighteen",
                    "nineteen"};
    string hours[] = {"", "one", "two", "three", "four",
                      "five", "six", "seven", "eight",
                      "nine", "ten", "eleven", "twelve",
                      "one"};
    string ten[] = {"", "", "twenty"};
    int tmp = 0;
    if (m > 30)
    {
        tmp = 60 - tmp;
    }
    string hour = "", minute = "", mid = "", res = "";
    if (hour == "")
    {
        hour = "twelve";
    }
    if (m == 0)
    {
        hour = hours[h];
        res = hour + " o' clock";
    }
    else if (m <= 19)
    {
        minute = one[m];
        hour = hours[h];
        if (m == 15)
        {
            res = "quarter past " + hour;
        }
        else if (m == 1)
        {
            res = minute + " minute past " + hour;
        }
        else
        {
            res = minute + " minutes past " + hour;
        }
    }
    else if (m > 19 && m <= 30)
    {
        hour = hours[h];
        if (m == 30)
        {
            res = "half past " + hour;
        }
        else
        {
            int ones = m % 10;
            minute = "twenty " + one[ones];
            res = minute + " minutes past " + hour;
        }
    }
    else if (m > 30)
    {
        if (m == 45)
        {
            res = "quarter to " + hours[h + 1];
        }
        else
        {
            int tmp = 60 - m;
            if (tmp <= 19)
            {
                minute = one[tmp];
            }
            else
            {
                int ones = tmp % 10;
                minute = "twenty " + one[ones];
            }
            res = minute + " minutes to " + hours[h + 1];
        }
    }
    return (res);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
