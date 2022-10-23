#include<bits/stdc++.h>
using namespace std;

struct Audience {
	string name;
	int score[4];
	string O = "";
};

bool compare(Audience a, Audience b) {
	for (auto it : a.O) {
		switch (it) {
		case 'H':
			if (a.score[0] != b.score[0])
				return a.score[0] > b.score[0];
			break;
		case 'W':
			if (a.score[1] != b.score[1])
				return a.score[1] > b.score[1];
			break;
		case 'I':
			if (a.score[2] != b.score[2])
				return a.score[2] > b.score[2];
			break;
		case 'E':
			if (a.score[3] != b.score[3])
				return a.score[3] > b.score[3];
			break;
		}
	}
	return a.name < b.name;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<Audience> groupA, groupB, groupC, groupD;
	string str[4];
	int n;
	cin >> n >> str[0] >> str[1] >> str[2] >> str[3];
	for (int i = 0; i < n; i++) {
		int max = 0, group;
		Audience temp;
		cin >> temp.name >> temp.score[0] >> temp.score[1] >> temp.score[2] >> temp.score[3];
		for (int j = 0; j < 4; j++) {
			if (max < temp.score[j]) {
				max = temp.score[j];
				group = j + 1;
			}
		}
		switch (group) {
		case 1:
			temp.O = str[0];
			groupA.emplace_back(temp);
			break;
		case 2:
			temp.O = str[1];
			groupB.emplace_back(temp);
			break;
		case 3:
			temp.O = str[2];
			groupC.emplace_back(temp);
			break;
		case 4:
			temp.O = str[3];
			groupD.emplace_back(temp);
			break;
		}
	}
	sort(groupA.begin(), groupA.end(), compare);
	sort(groupB.begin(), groupB.end(), compare);
	sort(groupC.begin(), groupC.end(), compare);
	sort(groupD.begin(), groupD.end(), compare);
	cout << "Group A:";
	if (groupA.empty())
		cout << " No Audience\n";
	else {
		cout << "\n";
		for (auto it : groupA)
			cout << it.name << "\n";
	}
	cout << "Group B:";
	if (groupB.empty())
		cout << " No Audience\n";
	else {
		cout << "\n";
		for (auto it : groupB)
			cout << it.name << "\n";
	}
	cout << "Group C:";
	if (groupC.empty())
		cout << " No Audience\n";
	else {
		cout << "\n";
		for (auto it : groupC)
			cout << it.name << "\n";
	}
	cout << "Group D:";
	if (groupD.empty())
		cout << " No Audience\n";
	else {
		cout << "\n";
		for (auto it : groupD)
			cout << it.name << "\n";
	}
}
