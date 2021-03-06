#include <iostream>
using namespace std;

int h[10][10];
int r[10][10];
int tc, T;
int N, M, C;

int getPSum(int m, int y, int x, int sum, int psum) {
	if (m >= M) return psum;
	int nextSum;
	int maxi = 0;
	for (int i = m; i < M; i++) {
		if (sum + h[y][x + i] <= C) {
			nextSum = getPSum(i + 1, y, x, sum + h[y][x + i], psum + h[y][x + i] * h[y][x + i]);
			if (maxi < nextSum) maxi = nextSum;
		}
		nextSum = getPSum(i + 1, y, x, sum, psum);
		if (maxi < nextSum) maxi = nextSum;
	}
	return maxi;
}

int getMaxPair(int y, int x) {
	int maxR = 0;
	for (int j = x + M; j <= N - M; j++) {
		if (maxR, r[y][j]) maxR = r[y][j];
	}
	for (int i = y + 1; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (maxR < r[i][j]) maxR = r[i][j];
		}
	}
	return maxR;
}

int solve(void) {
	int i, j;
	int sum;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			r[i][j] = getPSum(0, i, j, 0, 0);
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j <= N; j++) {
			sum = r[i][j] + getMaxPair(i, j);
			if (ans < sum) ans = sum;
		}
	}
	return ans;
}

int main(void) {
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				r[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> h[i][j];
			}
		}
		cout << "#" << tc << ' ' << solve() << endl;
	}
	return 0;
}