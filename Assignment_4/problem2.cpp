#include <iostream>

using namespace std;



void print(int arr[], int size) {
  cout << "Array:";
  for (int i=0;i<size;i++){
    cout << " " << arr[i];
  }
  cout << endl;
}

int weightedEditDistance (int arr1[], int arr2[], int size1, int size2){
  int ans[size1+1][size2+1];

  for (int x=0;x<=size1;x++){
    for (int y=0;y<=size2;y++){
      ans[x][y] = 0;
    }
  }

  ans[0][0] = 0;
  for (int i=1;i<=size1;i++){
    ans[i][0] = ans[i-1][0] + arr1[i-1];
  }
  for (int j=1;j<=size2;j++){
    ans[0][j] = ans[0][j-1] + arr2[j-1];
  }

  // cout << "2D Array: " << endl;
  // for (int x=0;x<=size1;x++){
  //   for (int y=0;y<=size2;y++){
  //     cout << ans[x][y] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  for (int i=1;i<=size1;i++){
    for (int j=1;j<=size2;j++){
      int del = ans[i-1][j] + arr1[i-1];
      int ins = ans[i][j-1] + arr2[j-1];
      int rep = ans[i-1][j-1] + abs(arr1[i-1] - arr2[j-1]);
      // cout << "Del: " << del << endl;
      // cout << "Ins: " << ins << endl;
      // cout << "Rep: " << rep << endl;

      ans[i][j] = min(min(del, ins), rep);

      // cout << "2D Array: " << endl;
      // for (int x=0;x<=size1;x++){
      //   for (int y=0;y<=size2;y++){
      //     cout << ans[x][y] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
  }

  return ans[size1][size2];
}

int main()
{
    string input = "";
    getline(cin, input);

    int split = input.find(' ');
    int size1 = stoi(input.substr(0, split));
    int size2 = stoi(input.substr(split+1));

    int arr1[size1];
    int arr2[size2];

    getline(cin, input);
    input += " ";
    for (int i=0;i<size1;i++){
      int split = input.find(' ');
      arr1[i] = stoi(input.substr(0, split));
      // cout << "Parsed: " << arr1[i] << endl;
      input = input.substr(split+1);
      // cout << "Input: " << input << endl;
    }

    getline(cin, input);
    input += " ";
    for (int i=0;i<size2;i++){
      int split = input.find(' ');
      arr2[i] = stoi(input.substr(0, split));
      input = input.substr(split+1);
    }

    // print(arr1, size1);
    // print(arr2, size2);


    cout << weightedEditDistance(arr1, arr2, size1, size2);
    return 0;
}
