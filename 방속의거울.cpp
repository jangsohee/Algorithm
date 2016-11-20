#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int map[1001][1001];
int chk[1001][1001];

int main() {
	//int argc, char** argv
	//setbuf(stdout, NULL);
	int TC;
	int test_case;
	int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };//��, ��, ��, �� 

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		//char map[1024][1024] = { 0, };

		int N = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("\n%c", &map[i][j]);
			}
		}
		// 1 = / 2 = `
		int cnt = 0;
		int nowR = 0;
		int nowC = -1;
		int prevD = 3;

		while (1) {
			if (nowR >= 0 && nowC >= 0 && nowR < N && nowC) chk[nowR][nowC] = -1;

			int nextR = nowR + dir[prevD][0];
			int nextC = nowC + dir[prevD][1]; //��0 ��2 ��1  ��3

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) break;

			//�׳ɱ�
			if (map[nextR][nextC] == '0') {
				nowR = nextR;
				nowC = nextC;
			}
			else if (map[nextR][nextC] == '1') {
				if (chk[nextR][nextC] != -1) cnt++;
				if (prevD == 0) {
					//�� ->������
					prevD = 3;
				}
				else if (prevD == 1) {
					//��-> �Ʒ���
					prevD = 2;
				}
				else if (prevD == 2) {
					//�� -> ����
					prevD = 1;
				}
				else if (prevD == 3) {
					//�� -> ����
					prevD = 0;
				}
				nowR = nextR;
				nowC = nextC;
			}
			else if (map[nextR][nextC] == '2') {
				if (chk[nextR][nextC] != -1) cnt++;
				if (prevD == 0) {
					//��-> ����
					prevD = 1;
				}
				else if (prevD == 1) {
					//��-> ����
					prevD = 0;
				}
				else if (prevD == 2) {
					//��-> ������
					prevD = 3;
				}
				else if (prevD == 3) {
					//��-> �Ʒ�
					prevD = 2;
				}
				nowR = nextR;
				nowC = nextC;
			}

		}
		printf("Case #%d\n", test_case);
		printf("%d\n", cnt);
		memset(chk, 0, sizeof(chk));
		memset(map, 0, sizeof(map));
	}

	return 0;
}