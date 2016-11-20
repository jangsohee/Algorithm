#include <iostream>
//-1:����or���۹������, -2: ��ֹ� 
int n, b, max;
char maze[120][120];
int map[120][120];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } }; //�����Ͽ�


void dfs(int x, int y, int step, int d) {
	//��������: ����������
	if (map[x][y] == -1) {
		if (max < step-1) max = step-1;
		return;
	}

	int xTemp = x + dir[d][0];
	int yTemp = y + dir[d][1];
	
	//1. ���� ���� ��
	if (xTemp < 0 || yTemp < 0 || yTemp >= n || xTemp >= n || maze[xTemp][yTemp] == '*') {
		for (int i = 0; i < 4; i++) {
			xTemp = x + dir[i][0];
			yTemp = y + dir[i][1];
			//�ȵǴ� ����	
			//1. �ȉ�� ��
			if (i == d)
				continue;
			//2. ���� ���� �� 
			if (xTemp < 0 || yTemp < 0 || yTemp >= n || xTemp >= n)
				continue;
			//3. ��ֹ� ������ ��
			if (maze[xTemp][yTemp] == '*')
				continue;
			
			//dfs ��
			map[x][y] = -1;
			dfs(xTemp, yTemp, step + 1, i);
			map[x][y] = 0;
		}
	}
	else {
		//�Դ� �������� �� ��
		map[x][y] = -1;
		dfs(xTemp, yTemp, step + 1, d);
		map[x][y] = 0;
	}
	
}
int main() {
	scanf("%d %d", &n, &b);
	for (int i = 0; i < b; i++) {
		char alpha = NULL;
		int no = 0;
		scanf("\n%c%d", &alpha, &no);
		maze[no - 1][alpha - 'A'] = '*';
	}
	
	dfs(0, 0, 1, 3); //������
	dfs(0, 0, 1, 2); //�Ʒ���
	printf("%d\n", max);
	return 0;
}