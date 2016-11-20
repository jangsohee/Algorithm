#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char word[1000001];
char del[37];
int wSize, dSize;
bool flag = true;
stack<pair<int, int> > st;

int main() {
	
	cin >> word;
	cin >> del;

	wSize = strlen(word);
	dSize = strlen(del);

	if (dSize == 1) {
		for (int i = 0; i < wSize; i++) {
			if (word[i] == del[0]) {
				word[i] = '@';
			}
		}
	}
	else {
		for (int i = 0; i < wSize; i++) {
			if (word[i] == del[0]) {
				st.push(make_pair(i, 0));
			}
			else if (!st.empty()) {
				pair<int, int> temp = st.top();
				int dIdx = temp.second;

				if (word[i] == del[dIdx + 1]) {
					st.push(make_pair(i, dIdx + 1));
					if (dIdx + 1 == dSize - 1) {
						for (int j = 0; j < dSize; j++) {
							word[st.top().first] = '@';
							st.pop();
						}
					}
				}
				else {
					while (!st.empty()) {
						st.pop();
					}
				}
			}
		}
	}
	
	for (int i = 0; i < wSize; i++) {
		if (word[i] != '@') {
			printf("%c", word[i]);
			flag = false;
		}
	}
	if (flag) {
		printf("FRULA\n");
	}
	return 0;
}