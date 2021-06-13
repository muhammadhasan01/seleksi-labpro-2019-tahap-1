#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const int N = 2e4 + 5;

int n, q;
int a[N], b[N];
int l[N], r[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n);
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }
    in(q);
    for (int i = 0; i < q; i++) {
        in(l[i]), in(r[i]);
    }
    for (int i = 0; i < q; i++) {
        l[i]--, r[i]--;
        for (int j = l[i]; j <= r[i]; j++) {
            b[j] = a[j];
        }
        sort(b + l[i], b + r[i] + 1);
        int mid = (l[i] + r[i]) / 2;
        cout << b[mid] << '\n';
    }

    return 0;
}