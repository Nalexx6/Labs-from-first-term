#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){

    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    for (int i = 5; i < sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;

}

int main ()
{
    int n,k, b,m;
    int ar[1000]={0};
    int pr[1000]={0};
    cin >> n;
    cin >> k;
    for (int p=2;p<=n;p++)
        if (prime(p))
            pr[p]++;

    m=0;
    for (int i = k+1; i <= n; i++) {

        b = i;

        for (int j = 2; j <= i && b != 1; j++)
            if (pr[j])
                while(b % j == 0) {
                    ar[j]++;
                    b /= j;
                    m = max(m, j);

                }

    }
    for (int i = 2; i <= (n-k); i++) {

        b = i;

        for (int j = 2; j <= i && b != 1; j++)
            if (prime(j))
                while(b % j == 0) {
                    ar[j]--;
                    b /= j;


                }

    }
    for (int i = 2; i < m; i++)
        if (ar[i]!=0)
            cout << i << "," << ar[i] << '\n';
    if (ar[m]>0)
        cout << m << "," << ar[m] << '\n';
}
