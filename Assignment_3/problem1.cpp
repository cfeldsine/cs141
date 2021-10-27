#include <iostream>
#include <vector>

using namespace std;

int merge_candies(int* arr, int size){

  int smallest, nextSmallest;
  int smallestIndex, nextSmallestIndex;
  if (arr[0] < arr[1]){
    smallest = arr[0]; nextSmallest = arr[1];
    smallestIndex = 0; nextSmallestIndex = 1;
  } else {
    smallest = arr[1]; nextSmallest = arr[0];
    smallestIndex = 1; nextSmallestIndex = 0;
  }

  for (int i=2;i<size;i++){
    if (arr[i] < smallest){
      nextSmallest = smallest;
      nextSmallestIndex = smallestIndex;

      smallest = arr[i];
      smallestIndex = i;
    } else if (arr[i] < nextSmallest){
      nextSmallest = arr[i];
      nextSmallestIndex = i;
    }
  }

  arr[smallestIndex] = smallest + nextSmallest;
  arr[nextSmallestIndex] = INT_MAX;


  return smallest + nextSmallest;
}

int get_count(int* arr, int size){
  int sum=0;
  for (int i=0;i<size-1;i++){
    sum += merge_candies(arr, size);
  }

  return 2*sum;
}


int main(){
  string input = "";

  int size = -1;
  cin >> input;
  size = stoi(input);

  int arr[size];

  for (int i=0;i<size;i++){
    cin >> input;
    arr[i] = stoi(input);
  }
  int sum=0;
  cout << get_count(arr, size) << endl;

  return 0;
}
