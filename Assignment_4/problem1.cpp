#include <iostream>

using namespace std;

void print(int arr[], int size) {
  cout << "Array:";
  for (int i=0;i<size;i++){
    cout << " " << arr[i];
  }
  cout << endl;
}

int LDS(int arr[], int size) {
  int ans[size];
  ans[0] = 1;

  for (int i=0;i<size; i++){
    int maxVal = 0;
    for (int j=0; j<i;j++){
      if (arr[j] > arr[i] && ans[j] > maxVal){
        maxVal = ans[j];
      }
    }
    ans[i] = ++maxVal;
    // print(ans, size);
  }


  int returnVal = ans[0];
  for (int i=1;i<size;i++){
    if (returnVal < ans[i]){
      returnVal = ans[i];
    }
  }
  return returnVal;

}

int main(){
  string input = "";
  getline(cin, input);

  int size = stoi(input);

  int arr[size];

  getline(cin, input);
  input += " ";
  for (int i=0;i<size;i++){
    int split = input.find(' ');
    arr[i] = stoi(input.substr(0, split));
    input = input.substr(split+1);
  }

  // print(arr, size);

  cout << LDS(arr, size);

  return 0;
}
