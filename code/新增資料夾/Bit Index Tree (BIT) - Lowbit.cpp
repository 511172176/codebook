// Bit Index Tree (BIT) - Lowbit
#define lowbit(x) ((x) & (-(x)))
int bit[2 * maxn] = {0};  // 宣告並初始化 bit 陣列

void add(int p, int v) {
    while (p < 2 * maxn) {
        bit[p] += v;    // 更新當前節點的值
        p += lowbit(p); // 跳到下一個需要更新的節點
    }
}

int sum(int p) {
    int ret = 0;
    while (p > 0) {
        ret += bit[p];  // 累加前綴和
        p -= lowbit(p); // 跳到上一個節點
    }
    return ret;
}
