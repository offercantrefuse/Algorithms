#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> answer;
vector<string> solution(vector<string> record) {
	vector<pair<pair<string, string>, int>> user;
	for (int i = 0; i < record.size(); i++) {  // vector( (id, �г�), inout)   //   Enter =1 , leave = 2
		if (record[i] == "\"Enter") {
			bool flag = true;
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					flag = false;
					user[j].first.second = record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1);
				}
			}
			if (flag) {
				user.push_back(make_pair(make_pair(record[i + 1], record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1)), 1));
			}
			i += 2;
		}
		else if (record[i] == "\"Change") {
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					user[j].first.second = record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1);
				}
			}
			i += 2;
		}
		else if (record[i] == "\"Leave") {
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					user.push_back(make_pair(make_pair(record[i + 1], record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1)), 2));
				}
			}
			i += 2;

		}
	}
	for (int i = 0; i < user.size(); i++) {
		if (user[i].second == 1) {
			if (i != user.size() - 1) {
				answer.push_back(user[i].first.second);
				answer.push_back("���� ���Խ��ϴ�.\",");
			}
			else {
				answer.push_back(user[i].first.second);
				answer.push_back("���� ���Խ��ϴ�.\"");
			}
		}
		if (user[i].second == 2) {
			if (i != user.size() - 1) {
				answer.push_back(user[i].first.second);
				answer.push_back("���� �������ϴ�.\",");
			}
			else {
				answer.push_back(user[i].first.second);
				answer.push_back("���� �������ϴ�.\"");
			}
		}
	}
	return answer;
}
int main() {
	string s, w;
	vector<string> word;
	getline(cin, s);                     /// ������ ������ ���ڿ� �Է�
	for (stringstream sts(s); (sts >> w);) {  /// ���ڿ� s�� ������� ���ڿ� ��Ʈ�� sts����
											  /// ���ڿ� ��Ʈ�� sts�� �̿��Ͽ� �� �ܾ w�� �Է�
											  /// sts�� ���� �ܾ ���ٸ� NULL ��ȯ
		word.push_back(w);               /// �ܾ� w�� word�� �߰�
	}


	solution(word);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}