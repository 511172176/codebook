// Nim 遊戲 SG 函數
#define maxn 20+5
#define maxs 100+5
int sg[maxn];

void SG() {
    int mex[maxs] = {}; // MEX表初始化
    sg[0] = 0;          // 初始化SG值
    for (int i = 1; i < maxn; i++) {
        memset(mex, 0, sizeof(mex));  // 清空MEX數組
        for (int j = 0; j < i; j++) {
            mex[sg[j] ^ sg[i - j - 1]] = 1;  // Nim遊戲狀態轉移
        }
        int g = 0;
        while (mex[g]) g++;  // 找到最小的MEX
        sg[i] = g;  // 設置SG值
    }
}
