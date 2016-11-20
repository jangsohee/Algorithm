#include <iostream>

using namespace std;
//어떤 한 로봇이 감염되어도 K와 L을 만족시켜야 함 
//K = 각 로봇들이 K개 이상 연결, L = L개 이상의 로봇들이 살아남도록 
int K, L; 
//N = 정점의 개수, M = 간선의 개수
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
		
		//1~N 중 하나가 바이러스에 감염됬다고 가정
		for (int i = 1; i <= N; i++) {
			virus(i);
		}
	}

	return 0;
}