#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int N) {
    vector<int> dp(N+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // cong thuc F(n)
    }
    return dp[N];
}

int Balo(int W, vector<int>& w, vector<int>& v, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    //i la do vat thu i
    //j la gioi han trong luong hien tai
    //dp[i][j] la tong gia tri lon nhat cua cac do vat lay duoc khi chon trong cac do vat tu 1 toi i va j la gioi han tong trong luong cua chung
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(w[i-1] <= j) { //co the chon do vat i - 1
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i-1]]); //neu chon vat i
            } else {
                dp[i][j] = dp[i-1][j]; //neu khong chon vat i
            }
        }
    }
    return dp[n][W];
}

int main() {
    int N = 10;
    cout << "F(" << N << ") = " << Fibonacci(N) << endl;

    vector<int> w = {2, 3, 4, 5};
    vector<int> v = {3, 4, 5, 6};
    int n = w.size();
    int W = 5;
    cout << "Max value = " << Balo(W, w, v, n) << endl;

    return 0;
}

