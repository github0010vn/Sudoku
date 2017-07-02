#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

int arr[9][9];
pair<int, int> c[81];
int n;
bool row[9][9];
bool col[9][9];
bool sqr[9][9];

int findSqr(int i, int j) {
	int x, y;

	if (i >= 0 && i <= 2) x = 1;
	else if (i >= 3 && i <= 5) x = 2;
	else x = 3;
	if (j >= 0 && j <= 2) y = 1;
	else if (j >= 3 && j <= 5) y = 2;
	else y = 3;

	return 3*(x - 1) + (y - 1);
}

void solve(int m) {
	if (m == 0) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}
		return;
	}

	int i, j;

	i = c[m - 1].first;
	j = c[m - 1].second;
	for (int k = 1; k <= 9; ++k) {
		if (!row[i][k - 1] && !col[j][k - 1] && !sqr[findSqr(i , j)][k - 1]) {
			row[i][k - 1] = true;
			col[j][k - 1] = true;
			sqr[findSqr(i , j)][k - 1] = true;
			arr[i][j] = k;
			solve(m - 1);
			row[i][k - 1] = false;
			col[j][k - 1] = false;
			sqr[findSqr(i , j)][k - 1] = false;
			arr[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("stdin.in", "r", stdin);
	// freopen("stdout.out", "w", stdout);

	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(sqr, false, sizeof(sqr));

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				c[n++] = make_pair(i, j);
			}
			else {
				row[i][arr[i][j] - 1] = true;
				col[j][arr[i][j] - 1] = true;
				sqr[findSqr(i, j)][arr[i][j] - 1] = true;
			}
		}
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "--------------------------------------------------" << endl;

	solve(n);

	return 0;
}