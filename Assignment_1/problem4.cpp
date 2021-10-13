#include <iostream>
#include <vector>

using namespace std;

void print(int arr[], unsigned char size){
	cout << "Array:";
	for (int i=0;i<size;i++){
		cout << " " << arr[i];
	}
	cout << endl;
}

int merge(int arr[], unsigned char begin, unsigned char middle, unsigned char end){

  cout << "Merge:" << endl;

  unsigned char i1 = begin, i2 = middle + 1;

  unsigned short sum = 0;

  int new_array[end-begin+1];

  unsigned char new_array_index = 0;
  while (i1 <= middle && i2 <= end){
    if (arr[i1] > arr[i2]){
      new_array[new_array_index] = arr[i1++];
      sum += (middle-i1+1);
    } else {
      new_array[new_array_index] = arr[i2++];
    }
  }

  while (i1 <= middle){
    new_array[new_array_index++] = arr[i1++];
  }
  while (i2 <= end){
    new_array[new_array_index++] = arr[i2++];
  }

  i1 = begin;
  for (new_array_index = begin; new_array_index <= end-begin; new_array_index++){
    arr[i1++] = new_array[new_array_index];
    cout << " " << new_array[new_array_index];
  }
  cout << endl;


  return sum;
}

int merge_sort(int arr[], unsigned char begin, unsigned char end){
  if (begin > end){
    return 0;
  }
  int middle = (begin + end)/2;
  int inversions = merge_sort(arr, begin, middle);
  inversions += merge_sort(arr, middle+1, end);

  inversions += merge(arr, begin, middle, end);
  return inversions;
}

int sort(int arr[], unsigned char size){
  return merge_sort(arr, 0, size-1);
}

int main() {
  // string input;
	// cin >> input;
	// cin.ignore();
  // unsigned char size = stoi(input);
  //
	// int scoreVect[size];
	// getline(cin, input);
	// string scores = input + ' ';
  //
	// int s;
  //
	// unsigned char firstIndex = 0;
  // unsigned char arrIndex = 0;
	// for (int i=0;i<scores.length();i++){
	// 	if (scores[i] == ' '){
	// 		scoreVect[arrIndex++] = stoi(scores.substr(firstIndex, i));
  //     firstIndex = i;
	// 	}
	// }
  //
  // print(scoreVect, size);

  int scoreVect[] = {3, 1, 5, 2, 4};
  unsigned char size = 5;

  cout << sort(scoreVect, size) << endl;

  print(scoreVect, size);

}
