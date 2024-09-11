// Kruskal 算法 - 最小生成樹
Kruskal() {
   T = {};  // 初始化空生成樹
   for each v in V {
      MakeSet(v);  // 初始化每個節點為單獨的集合
   }
   sort E by increasing edge weight w;  // 按邊權重排序
   for each (u,v) in E (in sorted order) {
      if FindSet(u) != FindSet(v) {
         T = T U {{u,v}};  // 將邊加入生成樹
         Union(FindSet(u), FindSet(v));  // 合併集合
      }
   }
}
