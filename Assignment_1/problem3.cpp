
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v){
	cout << "Vector:";
	for (auto x:v){
		cout << " " << x;
	}
	cout << endl;
}

void sort(vector<int> &v){
	for (int i=0;i<v.size();i++){
		int min = v[i];
		int minIndex = i;
		for (int j=i;j<v.size();j++){
			if (v[j] > min){
				min = v[j];
				minIndex = j;
			}
		}
		int temp = v[i];
		v[i] = min;
		v[minIndex] = temp;
	}
}

int main() {
	string size;
	cin >> size;
	cin.ignore();

	string scores;
	vector<int> scoreVect;
	getline(cin, scores);
	scores += ' ';

	int s;

  int firstIndex = 0;
	for (int i=0;i<scores.length();i++){
		if (scores[i] == ' '){
			s = stoi(scores.substr(firstIndex, i));
      firstIndex = i;

      bool repeat = false;
      for (auto x:scoreVect){
        if (x == s){
          repeat = true;
        }
      }
      if (!repeat){
			  scoreVect.push_back(s);
      }
		}
	}
	sort(scoreVect);

	string queries;

	cin >> queries;

	int numQueries = stoi(queries);
	vector<int> rankVect;

	string rank;
	for (int i=0;i<numQueries;i++){
		cin >> rank;
		rankVect.push_back(stoi(rank));
	}

	for (int i=0; i<rankVect.size(); i++){
		cout << scoreVect[rankVect[i]-1] << endl;
	}

	return 0;
}
