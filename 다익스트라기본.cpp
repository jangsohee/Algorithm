#include <cstdio>

using namespace std; 

struct VERTEX {
	bool chk; //�湮 üũ 
	int dist; //�Ÿ�
	int preV; //���� ����
};

VERTEX v[101];
int g[101][101];

int main() {

	int n = 0;
	int v1 = 0, v2 = 0, d = 0;

	//�Է�
	scanf("%d", &n);
	while (scanf("%d %d %d", &v1, &v2, &d) == 3) {
		g[v1][v2] = d;
	}

	//�ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		v[i].chk = false;
		v[i].dist = 0x7fffffff; //�ʱⰪ���� �ִ밪
		v[i].preV = 0;
	}

	//�����
	v[1].dist = 0;

	//��� ������ ����, �ִ� �Ÿ� ������ �ϳ��� ����
	int minV = 0;
	for (int i = 1; i <= n; i++) {
		
		int minDist = 0x7fffffff;
		for (int j = 1; j <= n; j++) {
			if (v[j].chk == false && minDist > v[j].dist) {
				minDist = v[j].dist;
				minV = j;
			}
		}

		v[minV].chk = true;

		for (int j = 1; j <= n; j++) {
			if (g[minV][j] != 0 && v[j].dist > g[minV][j] + v[minV].dist) {
				v[j].dist = g[minV][j] + v[minV].dist;
				v[j].preV = minV;
			}
		}
	}

	//��º�

	return 0;
}