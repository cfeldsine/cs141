#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack (int maxWeight, int weights[], int values[], int size){
  int curBest = 0;
  // cout << "knapSack(" << maxWeight << ")" << endl;
  for (int i=0;i<size;i++){
    if (maxWeight >= weights[i]){
      curBest = max(curBest, knapSack(maxWeight-weights[i], weights, values, size-1) + values[i]);
      // cout << curBest << endl;
    }
  }
  return curBest;
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
