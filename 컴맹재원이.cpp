#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		char str[52];
		char res[52];
		memset(str, '0', sizeof(str));
		memset(res, '0', sizeof(str));
		scanf("%s", &str);
		int len = strlen(str);
		int cnt = 0;
		
		for (int i = 0; i < len; i++) {
			if (str[i] == res[i]) continue;
			else {
				cnt++;
				char c;
				if (str[i] == '1') c = '1';
				else c = '0';
				for (int j = i; j < len; j++) {
					res[j] = c;
				}
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}