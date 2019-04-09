#include <iostream>

using namespace std;

int ExecuteAckerman(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0 && m > 0)
        return ExecuteAckerman(m - 1, 1);
    else if (n > 0 && m > 0)
        return ExecuteAckerman(m - 1, ExecuteAckerman(m, n - 1));

    return 0;
}

int main()
{
    int m, n;

    cin >> m >> n;

    cout << ExecuteAckerman(m, n);
}