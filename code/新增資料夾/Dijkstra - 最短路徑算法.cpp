// Dijkstra 最短路徑算法
Dijkstra(G) {
   for each v in V {
      d[v] = infinity;  // 初始化所有點的距離
   }
   d[s] = 0;  // 起點距離為0
   S = {};  // 空集合S
   Q = V;   // 未處理的節點集合

   while (Q is not empty) {
      u = ExtractMin(Q);  // 選擇距離最小的節點u
      S = S U {u};        // 將u加入集合S
      for each v in u->Adj[] {
         if (d[v] > d[u] + w(u,v)) {
            d[v] = d[u] + w(u,v);  // 更新距離
         }
      }
   }
}
