#include <stdio.h>

int n, k;
int count; //����� �� ����
int arr[12][12][12]; //���� ���� 3���� �迭

int mv[] = { 0, -1, 1 }; //x,y,z �ึ�� �̵� ����

void init()
{
	count = 0;
}

void print()
{
	for (int z = 1; z <= n; ++z)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int x = 1; x <= n; ++x)
			{
				//���� �ִ��ڸ��� ���
				if (arr[z][y][x] == 1)
				{
					printf("%d ", x);
					break;
				}
			}
		}
		printf("\n");
	}
}

void no_result()
{
	for (int z = 1; z <= n; ++z)
	{
		for (int y = 1; y <= n; ++y)
		{
			printf("-1 ");
		}
		printf("\n");
	}
}

int check(int px, int py, int pz)
{
	//z, y, x ������ ��� �������� �̵������� ����
	//(0, 0, 0), (0, 0, -1), (0, 0, 1) ~ (1, 1, 1)
	for (int move_z = 0; move_z < 3; ++move_z)
	{
		for (int move_y = 0; move_y < 3; ++move_y)
		{
			for (int move_x = 0; move_x < 3; ++move_x)
			{

				//x, y, z ��� �̵����� ������(���ڸ�) ����
				if (move_z == 0 && move_y == 0 && move_x == 0) continue;

				//�˻��ϰ��� �ϴ� ��ġ ����
				int x = px;
				int y = py;
				int z = pz;

				while (1)
				{
					//�ش��ϴ� �������� ��ĭ�� �̵��ϸ� �˻��Ѵ�
					x += mv[move_x];
					y += mv[move_y];
					z += mv[move_z];

					//1~n �� �ƴ� ������ ���
					if (x < 1 || x > n) break;
					if (y < 1 || y > n) break;
					if (z < 1 || z > n) break;

					//�ش� �������� �̵��غ� ��� ���� �־ �Ұ����� ���
					if (arr[z][y][x] == 1) return 0;
				}
			}
		}
	}

	//�ش� ��ġ�� �� ���� �� ����
	return 1;
}

void dfs(int y, int z, int queen)
{
	//�̹� ����� ���� ��� �������� �ʴ´� (����ġ��)
	if (count == k) return;

	//y�� n�� ���� ��� 
	//�� ����� n���� ������ ���� z�� ����� n���� �ϼ��Ѵ�
	if (y > n)
	{
		y = 1; //y���� �ʱ�ȭ �ϰ�
		z = z + 1; //z���� 1 �ø���
	}

	//���� n*n�� ���� ���
	if (queen == n * n)
	{
		count = count + 1; //����� ���� 1 ������Ų��
		if (count == k) print(); //k��°�� ��� ������ ����Ѵ�
		return;
	}

	//�ش� y�࿡ ���� ���� �� �ִ� x���� ã�´�
	for (int x = 1; x <= n; ++x)
	{
		if (check(x, y, z) == 1) //���� �� �ִ� ��ġ�̸�
		{
			arr[z][y][x] = 1; //���� ���´�
			dfs(y + 1, z, queen + 1); //���ȣ��
			arr[z][y][x] = 0; //���� �ٽ� ����
		}
	}
}

void sub()
{
	init(); //�ʱ�ȭ
	scanf("%d %d", &n, &k); //n�� ü������ ũ��, k�� ���ϴ� ����� ��
	dfs(1, 1, 0); //y=1, z=1 ���� ����
	if (count < k) no_result(); //����� ������ -1 ���
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) sub();
	return 0;
}