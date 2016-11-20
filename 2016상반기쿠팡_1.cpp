#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<string> strArr;
vector<pair<int, pair<int, int> > > ans;
char res[130][130];
bool resFlag[130][130];

void Lower(char& c) {
	c = tolower(c);
}
bool pairCompare(pair<int, pair<int, int> > t1, pair<int, pair<int, int> > t2) {
	return t1.first < t2.first;
}
int main() {
	string str;
	getline(cin, str);
	stringstream ss(str);

	while (ss >> str) {
		strArr.push_back(str);
	}

	while (!strArr.empty()) {
		string temp = strArr.back();
		strArr.pop_back();
		int firstIdx = 0;
		int lastIdx = temp.size() - 1;

		//소문자 변환
		for_each(temp.begin(), temp.end(), Lower);

		//첫글자, 마지막글자 추출
		while (temp.at(firstIdx) == '.' || temp.at(firstIdx) == ',') {
			firstIdx++;
		}
		while (lastIdx > 0 && temp.at(lastIdx) == '.' || temp.at(lastIdx) == ',') {
			lastIdx--;
		}

		res[temp.at(firstIdx)][temp.at(lastIdx)]++;
		resFlag[temp.at(firstIdx)][temp.at(lastIdx)] = true;
	}

	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			if (resFlag[i][j]) {
				ans.push_back(make_pair(res[i][j], make_pair(i, j)));
			}
		}
	}

	sort(ans.begin(), ans.end(), pairCompare);

	while (!ans.empty()) {
		pair<int, pair<int, int> >  nowAns = ans.back();
		ans.pop_back();

		printf("%c%c , %d\n", nowAns.second.first, nowAns.second.second, nowAns.first);
	}

	return 0;
}