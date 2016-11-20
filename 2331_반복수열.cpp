#include <iostream>

using namespace std;

int num, p;
int chk[1000000];

int pow(int x) {
	int ans = 1;
	for (int i = 0; i<p; i++) {
		ans = ans * x;
	}
	return ans;
}
//123, 3�� ������� %10 (=>3), 3�� ������ /=10 (=>12)
//�Լ��̸��� next�� �ϸ� ������, �̸����Ҷ� �Ϲ����δܾ� ������!
int nextNum(int n) {
	int res = 0;
	while (n > 0) {
		res += pow(n % 10);
		n /= 10;
	}
	return res;
}

int find(int n, int cnt) {
	if (chk[n] != 0) return chk[n] - 1;
	chk[n] = cnt;

	int nNum = nextNum(n);
	return find(nNum, cnt + 1);
}
int main() {
	cin >> num >> p;
	cout << find(num, 1) << '\n';

	return 0;
}