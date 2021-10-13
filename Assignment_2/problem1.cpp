#include <iostream>

using namespace std;


int merge(int arr[], int begin, int middle, int end){
  int sum = 0;

  int i1 = begin, i2 = middle + 1;
  int new_array[end-begin+1];

  int new_array_index = 0;
  while (i1 <= middle && i2 <= end){
    if (arr[i1] < arr[i2]){
      new_array[new_array_index++] = arr[i1++];
    } else {
      new_array[new_array_index++] = arr[i2++];
    }
  }

  while (i1 <= middle){
    new_array[new_array_index++] = arr[i1++];
  }
  while (i2 <= end){
    new_array[new_array_index++] = arr[i2++];
  }

  sum += new_array[new_array_index-1] - new_array[0];
  i1 = begin;
  for (new_array_index = 0; new_array_index <= end-begin; new_array_index++){
    arr[i1++] = new_array[new_array_index];
  }
  return sum;


}

int merge_sort(int arr[], int begin, int end){
  int sum = 0;
  int middle = (begin + end)/2;
  if (begin < middle){
    sum += merge_sort(arr, begin, middle);
  }
  if (middle+1 < end){
    sum += merge_sort(arr, middle+1, end);
  }
  sum += merge(arr, begin, middle, end);

  return sum;
}

int sort(int arr[], int size){
   return merge_sort(arr, 0, size-1);
}

int main() {
  string input;
	cin >> input;
	cin.ignore();
  int size = stoi(input);

	int scoreVect[size];

	for (int i=0;i<size;i++){
    cin >> input;
    cin.ignore();
    scoreVect[i] = stoi(input);
	}

  cout << sort(scoreVect, size) << endl;

  return 0;

}
