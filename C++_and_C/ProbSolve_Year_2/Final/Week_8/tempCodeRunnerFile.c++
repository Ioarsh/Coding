#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX_N 00000

int n, c, k;
int power_A[MAX_N];
int power_B[MAX_N];
int Best[MAX_N];

void read_input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> power_A[i] >> power_B[i];
        Best[i] = -1;
    }
}

int choose(int i, int numA, int numB) {
    if (i == n - 1) {
        Best[i] = min(power_A[i], power_B[i]);
        return Best[i];
    }
    if (Best[i] != -1) {
        return Best[i];
    }
    int diffA = power_A[i], diffB = power_B[i];
    int c_A = choose(i + 1, numA + 1, numB) + diffA;
    int c_B = choose(i + 1, numA, numB + 1) + diffB;
    if (numA > numB) {
        if (abs(numA - numB) < k)
            Best[i] = min(c_A, c_B);
        else
            Best[i] = c_B;
    }
    else if (numB > numA) {
        if (abs(numB - numA) < k)
            Best[i] = min(c_A, c_B);
        else
            Best[i] = c_A;
    }
    else {
        Best[i] = min(c_A, c_B);
    }
    return Best[i];
}

int main() {
    cin >> c;
    vector<int> answer(c);
    for (int i = 0; i < c; i++) {
        read_input();
        answer[i] = choose(0, 0, 0);
    }
    for (auto i : answer) {
        cout << i << '\n';
    }
    return 0;
}