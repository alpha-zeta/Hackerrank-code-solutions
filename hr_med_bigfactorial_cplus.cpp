#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> BigInt;
#define EL printf("\n");
// Complete the extraLongFactorials function below.
void Set(BigInt &a)
{
    while (a.size() > 1 && a.front() == 0)
        a.erase(a.begin());
}

BigInt init(int a)
{
    int d = 0, b = 0;
    BigInt res;
    while (a != 0)
    {
        d = a % 10;
        a = a / 10;
        res.insert(res.begin(), d);
    }
    Set(res);
    return (res);
}
BigInt dec(BigInt n)
{
    int carry = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        int val = n[i] - carry;
        carry = 0;
        if (val < 0)
        {
            val = val + 10;
            carry++;
        }
        n[i] = val;
        if (carry == 0)
        {
            break;
        }
    }
    return (n);
}
BigInt add(BigInt n, BigInt m)
{
    int carry = 0;
    int s1 = n.size(), s2 = m.size();
    BigInt res;
    for (int i = 0; i < m.size(); i++)
    {
        int val1 = n[s1 - i - 1], val2 = m[s2 - i - 1];
        int sum = val1 + val2 + carry;
        carry = 0;
        if (sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        res.insert(res.begin(), sum);
    }
    if (carry != 0)
    {
        if (s1 == s2)
        {
            res.insert(res.begin(), carry);
        }
        else if (s1 > s2)
        {
            for (int i = (n.size() - m.size() - 1); i >= 0; i--)
            {
                int val = n[i] + carry;
                carry = 0;
                if (val > 10)
                {
                    carry = val / 10;
                    val = val % 10;
                }
                res.insert(res.begin(), val);
                n[i] = val;
            }
        }
    }
    else
    {
        for (int i = (n.size() - m.size() - 1); i >= 0; i--)
        {
            res.insert(res.begin(), n[i]);
        }
    }
    Set(res);
    return (res);
}
BigInt multInt(BigInt n, int m)
{
    int carry = 0;
    Set(n);
    BigInt res;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        int val = (n[i] * m) + carry;
        carry = 0;
        if (val >= 10)
        {
            carry = val / 10;
            val = val % 10;
        }
        res.insert(res.begin(), val);
    }
    if (carry != 0)
    {
        res.insert(res.begin(), carry);
    }
    return (res);
}
BigInt mult(BigInt n, BigInt m)
{
    BigInt res;
    res = {0};
    for (int i = m.size() - 1; i >= 0; i--)
    {
        BigInt val = multInt(n, m[i]);

        for (int j = 0; j < m.size() - i - 1; j++)
        {
            val.push_back(0);
        }
        res = add(val, res);
    }
    return (res);
}
BigInt fact(BigInt n, int m)
{

    BigInt res = {1}, tmp = n;
    for (int i = m; i >= 1; i--)
    {
        Set(tmp);
        Set(res);
        res = mult(res, tmp);
        tmp = dec(tmp);
    }
    return (res);
}
void extraLongFactorials(int n)
{
    BigInt fac;
    if (n == 0 || n == 1)
    {
        fac = {1};
    }
    else
    {
        BigInt m = init(n);
        fac = fact(m, n);
    }

    for (int i = 0; i < fac.size(); i++)
    {
        cout << fac[i];
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);
    return 0;
}
