#include <iostream>

using namespace std;
//� �� �κ��� �����Ǿ K�� L�� �������Ѿ� �� 
//K = �� �κ����� K�� �̻� ����, L = L�� �̻��� �κ����� ��Ƴ����� 
int K, L; 
//N = ������ ����, M = ������ ����
int N, M;
int v[102][102];
int temp[102][102];
int chk[102];

void virus(int vNum) {

}

int main() {
	int tc = 0;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << '\n';
		cin >> K >> L;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int t1 = 0, t2 = 0;
			cin >> t1 >> t2;
			v[t1][t2] = v[t2][t1] = 1;
			temp[t1][t2] = temp[t2][t1] = 1;
			chk[t1]++;
		}
		
		//1~N �� �ϳ��� ���̷����� ������ٰ� ����
		for (int i = 1; i <= N; i++) {
			virus(i);
		}
	}

	return 0;
}