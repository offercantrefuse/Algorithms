#include <iostream>

using namespace std;

struct _Node {
	char word;
	int left;
	int right;
} node[101];

int N, addr;
char str[10];

// ������ȸ
void solve(int v) {
	if (node[v].left > 0)
		solve(node[v].left);
	cout << node[v].word;
	if (node[v].right > 0)
		solve(node[v].right);
}

// �Է°�
void input() {
	int i;
	for (i = 0; i < N; i++) {
		cin >> addr;
		cin >> str;

		node[addr].word = str[0];
		node[addr].left = 0;
		node[addr].right = 0;
		// N������ ������ ����
		// �Է� ������ �ܸ� ��带 üũ
		if (addr * 2 <= N) {
			cin >> node[addr].left;
			if (addr * 2 + 1 <= N)
				cin >> node[addr].right;
		}
	}
}

int main() {
	int testcase;
	for (testcase = 1; testcase <= 2; testcase++) {
		cin >> N;
		input();
		solve(1);
		cout << endl;
	}
	return 0;
}