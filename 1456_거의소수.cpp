#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long num) {
	for (unsigned long long i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	unsigned long long a = 0;
	unsigned long long b = 0;
	cin >> a >> b;

	unsigned long long res = 0;
	for (unsigned long long i = a; i <= b; i++) {
		//i�� ���� �Ҽ��ΰ�? = �Ҽ��� N�������ΰ�? 
		unsigned long long temp = sqrt(i);
		while (temp >= 2) {
			
		}
	}

	cout << res << '\n';
	return 0;
}