#include <iostream>

using namespace std;

int win;
char com[30];
int cnt = 0;
void sol(int xNum, int oNum, int game) {
	if (xNum >= win) return;
	if (oNum == win) {
		for (int i = 0; i < game; i++) {
			printf("%c", com[i]);
		}
		printf("\n");
		cnt++;
		return;
	}
		                    
	com[game] = 'o';
	sol(xNum, oNum + 1, game + 1);
	com[game] = 'x';
	sol(xNum+1, oNum, game + 1);
	
}
int main() {
	cin >> win;
	sol(0,0,0);
	printf("total %d case(s)", cnt);
	return 0;
}