#include <stdio.h>

int n, k;
int count; //경우의 수 저장
int arr[12][12][12]; //퀸을 놓을 3차원 배열

int mv[] = { 0, -1, 1 }; //x,y,z 축마다 이동 방향

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
				//퀸이 있는자리를 출력
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
	//z, y, x 순으로 어느 방향으로 이동할지를 정함
	//(0, 0, 0), (0, 0, -1), (0, 0, 1) ~ (1, 1, 1)
	for (int move_z = 0; move_z < 3; ++move_z)
	{
		for (int move_y = 0; move_y < 3; ++move_y)
		{
			for (int move_x = 0; move_x < 3; ++move_x)
			{

				//x, y, z 모두 이동하지 않으면(제자리) 제외
				if (move_z == 0 && move_y == 0 && move_x == 0) continue;

				//검사하고자 하는 위치 기준
				int x = px;
				int y = py;
				int z = pz;

				while (1)
				{
					//해당하는 방향으로 한칸씩 이동하며 검사한다
					x += mv[move_x];
					y += mv[move_y];
					z += mv[move_z];

					//1~n 이 아닌 범위인 경우
					if (x < 1 || x > n) break;
					if (y < 1 || y > n) break;
					if (z < 1 || z > n) break;

					//해당 방향으로 이동해본 결과 퀸이 있어서 불가능한 경우
					if (arr[z][y][x] == 1) return 0;
				}
			}
		}
	}

	//해당 위치에 퀸 놓을 수 있음
	return 1;
}

void dfs(int y, int z, int queen)
{
	//이미 결과가 나온 경우 연산하지 않는다 (가지치기)
	if (count == k) return;

	//y가 n을 넘은 경우 
	//한 평면의 n퀸을 만든경우 다음 z축 평면의 n퀸을 완성한다
	if (y > n)
	{
		y = 1; //y값을 초기화 하고
		z = z + 1; //z값을 1 올린다
	}

	//퀸을 n*n개 놓은 경우
	if (queen == n * n)
	{
		count = count + 1; //경우의 수를 1 증가시킨다
		if (count == k) print(); //k번째인 경우 정답을 출력한다
		return;
	}

	//해당 y축에 퀸을 놓을 수 있는 x축을 찾는다
	for (int x = 1; x <= n; ++x)
	{
		if (check(x, y, z) == 1) //놓을 수 있는 위치이면
		{
			arr[z][y][x] = 1; //퀸을 놓는다
			dfs(y + 1, z, queen + 1); //재귀호출
			arr[z][y][x] = 0; //퀸을 다시 뺀다
		}
	}
}

void sub()
{
	init(); //초기화
	scanf("%d %d", &n, &k); //n은 체스판의 크기, k는 원하는 경우의 수
	dfs(1, 1, 0); //y=1, z=1 부터 시작
	if (count < k) no_result(); //결과가 없을때 -1 출력
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) sub();
	return 0;
}