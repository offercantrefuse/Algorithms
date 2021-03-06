#include <iostream>
#include <queue>
using namespace std;
struct pos {
	int r, c, k;
	pos(int rr, int cc, int kk) {
		r = rr;
		c = cc;
		k = kk;
	}
	pos() {}
};

int N, M, key = 0, endr, endc, ans = 0;
bool esc = false;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
char map[50][50];
int visit[1 << 6][50][50] = { 0, };

queue<pos> q;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		for (int t = 0; t < size; t++) {
			int r = q.front().r;
			int c = q.front().c;
			int k = q.front().k;
			q.pop();
			if (map[r][c] == '1') {
				esc = true;
				return;
			}
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr<0 || nr>N - 1 || nc<0 || nc>M - 1)continue;
				if (visit[k][nr][nc] == 0) {
					if (map[nr][nc] == '.' || map[nr][nc] == '0' || map[nr][nc] == '1') {
						visit[k][nr][nc] = 1;
						q.push(pos(nr, nc, k));
					}
					else if (map[nr][nc] >= 'a'&&map[nr][nc] <= 'f') {
						int nk = (1 << (map[nr][nc] - 'a')) | k;
						visit[k][nr][nc] = 1;
						visit[nk][nr][nc] = 1;
						q.push(pos(nr, nc, nk));
					}
					else if (map[nr][nc] >= 'A' && map[nr][nc] <= 'F') {
						int have_key = (1 << (map[nr][nc] - 'A')) & k;
						if (have_key != 0) { // key 갖고있을때
							visit[k][nr][nc] = 1;
							q.push(pos(nr, nc, k));
						}
					}
				}
			}
		}
		ans++;
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				q.push(pos(i, j, key));
				visit[key][i][j] = 1;
			}
		}
	}
	bfs();
	if (esc) cout << ans << '\n';
	else cout << "-1" << '\n';
	return 0;
}