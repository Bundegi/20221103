#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"

using namespace std;
int S;
int N;
int Ary = 0;
int sum = 0;
int room[21] = { 0, };
vector<int> Array;
void Back(int depth,int start) {
	if (sum == S && depth >= 1) Ary++;
	for (int i = start; i < N; i++) {
		if (!room[i]){
			room[i] = true;
			sum += Array[i];
			Back(depth + 1, i);
			room[i] = false;
			sum -= Array[i];
		}
	}
}
int main() {
	fast;
	cin >> N >> S;
	int Su;
	for (int i = 0; i < N; i++) {
		cin >> Su;
		Array.push_back(Su);
	}
	Back(0, 0);
	cout << Ary;
}