maxn = 250000
maxp = 22000 + 5

# 初始化數組 fp 用來存儲質數的前幾位
fp = [0] * maxp
vis = [False] * maxn  # 記錄某數字是否被標記過

a, b = 0, 1  # 初始的 Fibonacci 數列
count_p = 1  # 質數計數器

i = 2
while count_p < maxp:
    tmp = a + b  # 計算 Fibonacci 序列
    a = b
    b = tmp
    if b > 1e10:  # 如果 b 太大，對其進行縮小處理
        b //= 10
        a //= 10

    if not vis[i]:  # 如果 i 沒有被標記為非質數
        tmp = b
        while tmp >= 1e9:  # 確保數字在合理範圍內
            tmp //= 10

        fp[count_p] = tmp  # 記錄第 count_p 個質數
        count_p += 1

        j = i * i
        while j < maxn:
            vis[j] = True  # 標記合數
            j += i

    i += 1

fp[1], fp[2] = 2, 3  # 手動設定前兩個質數

try:
    while True:
        n = int(input())  # 讀取輸入
        print(fp[n])  # 輸出第 n 個質數
except EOFError:
    pass  # 捕捉到 EOF 後退出循環