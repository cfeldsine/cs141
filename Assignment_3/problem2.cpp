#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

// void sort(int weights[], int values[], int size){
// 	for (int i=0;i<size;i++){
// 		int min = values[i];
// 		int minIndex = i;
// 		for (int j=i;j<size;j++){
// 			if (values[j] < min){
// 				min = values[j];
// 				minIndex = j;
// 			}
// 		}
// 		int temp = values[i], temp2 = weights[i];
// 		values[i] = min; weights[i] = weights[minIndex];
// 		values[minIndex] = temp; weights[minIndex] = temp2;
//
// 	}
// }

int knapSack (int maxWeight, int size, int weights[], int values[]){
  //maxWeight = k
  //size =
  int ans[size+1][maxWeight+1];
  for (int i=0;i<=size;i++){
    // cout << "Weight: " << weights[i-1] << " Value: " << values[i-1] << endl;
    for (int j=0;j<=maxWeight;j++){
      // cout << "Column: " << j << endl;
      if (j == 0 || i == 0){
        // cout << "option 1" << endl;
        ans[i][j] = 0;
      } else if (weights[i-1] <= j){
        // cout << "option 2: " << ans[i-1][j] << " " <<  values[i-1] << " " << ans[i-1][j-weights[i-1]]<< endl;
        ans[i][j] = max(ans[i-1][j], values[i-1] + ans[i-1][j-weights[i-1]]);
      } else {
        // cout << "option 3" << endl;
        ans[i][j] = ans[i-1][j];
      }
    }
  }

  // cout << "Array: " << endl;
  // for (int i=0;i<=size;i++){
  //   for (int j=0;j<=maxWeight;j++){
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return ans[size][maxWeight];
}

int main()
{
    string input = "";
    getline(cin, input);

    int split = input.find(' ');
    int maxWeight = stoi(input.substr(0, split));
    int size = stoi(input.substr(split+1));

    int weights[size];
    int values[size];

    for (int i=0;i<size;i++){
      getline(cin, input);
      split = input.find(' ');
      weights[i] = stoi(input.substr(0, split));
      values[i] = stoi(input.substr(split+1, input.length()-split));
    }

    // cout << "Weights: ";
    // for (int i=0;i<size;i++){
    //   cout << weights[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "Values: ";
    // for (int i=0;i<size;i++){
    //   cout << values[i] << " ";
    // }
    // cout << endl;


    cout << knapSack(maxWeight, size, weights, values) << endl;
    return 0;
}
