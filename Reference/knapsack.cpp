#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack (int maxWeight, int weights[], int values[], int size, int ans[]){
  // cout << "knapSack(" << maxWeight << ")" << endl;
  // cout << "Stored value: " << ans[maxWeight] << endl;
  if (ans[maxWeight] != -1) {
    return ans[maxWeight];
  }
  int curBest = 0;
  for (int i=0;i<size;i++){
    if (maxWeight >= weights[i]){
      curBest = max(curBest, knapSack(maxWeight-weights[i], weights, values, size-1, ans) + values[i]);
      // cout << "Branch " << i << ": " << curBest << endl;
    }
  }
  return ans[maxWeight] = curBest;
}

int main()
{
    int val[] = { 150, 100, 10 };
    int wt[] = { 5, 4, 2 };
    int W = 8;
    int ans[W + 1];
    fill_n (ans, W + 1, -1);
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n, ans);
    return 0;
}
