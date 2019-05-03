#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct pos {
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos() {}
};

int N, M, target = 0, res;
int map[50][50];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
bool visit[10];
int arr[10];
bool check[50][50];
vector<pos> virus;

int spread() {
	int cnt = 0, tmp = 0;
	queue<pos> q;
	for (int i = 0; i < M; i++) {
		q.push(virus[arr[i]]);
		check[virus[arr[i]].r][virus[arr[i]].c] = true;
	}
	while (!q.empty() && target > cnt) {  // �� ��Ʈ���ų� ���̻� ��Ʈ�� �� ���� �� ����
		int qSize = q.size();
		for (int t = 0; t < qSize; t++) {
			int rr = q.front().r;
			int cc = q.front().c;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1 || check[nr][nc]) continue;
				if (map[nr][nc] == 0) {  // map�� �� �����̸� ��Ʈ�����ϴ� ���̹Ƿ� cnt ����
					check[nr][nc] = true;
					q.push(pos(nr, nc));
					cnt++;
				}
				else if (map[nr][nc] == 2) {  // map�� �̹� virus�̸� cnt�� ���� ����
					check[nr][nc] = true;
					q.push(pos(nr, nc));
				}
			}
		}
		tmp++;
	}
	if (target <= cnt) return tmp;
	else return -1;
}

void comb(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < 50; i++) {    // check �迭 �ʱ�ȭ
			for (int j = 0; j < 50; j++) {
				check[i][j] = false;
			}
		}
		int ans = spread();    // ���̷��� ��Ʈ����
		if (ans == -1) return;
		res = ans > res ? res : ans;
		return;
	}
	for (int i = idx; i < virus.size(); i++) {  // ���̷��� �ĺ��� �� M��ŭ ����
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			comb(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) { // ���̷��� �ĺ�  
				virus.push_back(pos(i, j));
				target++;
			}
			else if (map[i][j] == 1) {
				target++;
			}
		}
	}
	target = N * N - target;   // ���̷����� ��Ʈ�����ϴ� ĭ �� �̸� ����س���
	res = 10000;
	comb(0, 0);  // ����
	if (res == 10000) cout << "-1\n";
	else cout << res << '\n';
	return 0;
}