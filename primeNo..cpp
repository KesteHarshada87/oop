#include<iostream>
using namespace std;

int main()
{
    int n, i, isPrime;
    
    cout << 2 << endl;  // 2 is prime
    for(n = 3; n < 100; n++) {
        isPrime = 1;  // Assume n is prime
        for(i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                isPrime = 0;  // n is not prime
                break;
            }
        }
        if(isPrime) {
            cout << n << endl;
        }
    }

    return 0;
}

