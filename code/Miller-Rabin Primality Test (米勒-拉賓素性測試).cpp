// 米勒-拉賓素數測試演算法：一種高效的隨機化素數判定方法。
// 利用快速冪與模數運算來測試一個數是否為素數。

typedef long long ll;

// 快速模數乘法，防止溢出
ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;  // 如果b的最低位為1，則加上a
        a = (a + a) % mod;  // a * 2
        b >>= 1;  // 右移 b
    }
    return res;
}

// 快速冪演算法，計算 base^exp % mod
ll powmod(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = mulmod(res, base, mod);  // 如果exp的最低位為1，乘上base
        base = mulmod(base, base, mod);  // base * base
        exp >>= 1;  // 右移 exp
    }
    return res;
}

// 米勒-拉賓測試演算法
bool miller_rabin(ll n, int k) {
    if (n < 2) return false;  // 如果 n < 2 不是素數
    if (n != 2 && n % 2 == 0) return false;  // 偶數不是素數

    ll d = n - 1;
    while (d % 2 == 0) d /= 2;  // 分解 d 使得 n-1 = d * 2^r

    // 重複測試 k 次
    while (k--) {
        ll a = 2 + rand() % (n - 3);  // 隨機選擇一個測試基數 a
        ll x = powmod(a, d, n);  // 計算 a^d % n

        if (x == 1 || x == n - 1) continue;  // 可能是素數

        while (d != n - 1) {
            x = mulmod(x, x, n);  // 平方，計算 x^2 % n
            d *= 2;

            if (x == 1) return false;  // 合數
            if (x == n - 1) break;  // 可能是素數
        }

        if (x != n - 1) return false;  // 如果 x 最終不等於 n-1 則為合數
    }

    return true;  // 通過所有測試，n 可能是素數
}
