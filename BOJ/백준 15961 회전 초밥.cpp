#include <iostream>
using namespace std;
 
int N, d, k, c;
int sushi[3000000] = { 0, };
int visit[3001] = { 0, };
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }
    int cnt = 0, ans = 0;
    for (int j = 0; j < k; j++) {
        if (visit[sushi[j % N]] == 0) { // ó�� ��
            cnt++;
            visit[sushi[j % N]]++;
        }
        else {
            visit[sushi[j % N]]++;
        }
    }
    if (visit[c] == 0)
        ans = ans < cnt + 1 ? cnt + 1 : ans;
    else
        ans = ans < cnt ? cnt : ans;
 
    for (int i = 1; i < N; i++) {
        visit[sushi[i - 1]]--;
        if (visit[sushi[i - 1]] == 0) // ���� sushi �ߺ� x
            cnt--;
        if (visit[sushi[(i + k - 1) % N]] > 0) { // ���� �����Ѱ� �ߺ�
            visit[sushi[(i + k - 1) % N]]++;
        }
        else { // ���ο� �ʹ� ����
            visit[sushi[(i + k - 1) % N]]++;
            cnt++;
        }
        if (visit[c] == 0)
            ans = ans < cnt + 1 ? cnt + 1 : ans;
        else
            ans = ans < cnt ? cnt : ans;
    }
    cout << ans << '\n';
    return 0;
}