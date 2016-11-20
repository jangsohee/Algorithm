// �ּڰ��� ���� ���� 

const int MIN_INTEGER_VALUE = -100;

// ������ ���� ����
// s <= n <= e �� �����ϴ� n�� ������ [s,e] �� �Ѵ�.
// s < n < e �� �����ϴ� n�� ������ (s,e) �� �Ѵ�. 

int binary_search(int Arrays[], int start, int end, int key) { // Ž�� ������ [start,end) �̴�. 
	if (start == end) return start; // Ž���� �� �� �ʿ䰡 ���� ��� 

	int middle = (start + end) / 2;
	if (Arrays[middle] < key) { // [middle+1,end) �������� ���� ���
		return binary_search(Arrays, middle + 1, end, key);
	}
	else if (Arrays[middle] > key) { // [start,middle) �������� ���� ���
		return binary_search(Arrays, start, middle, key);
	}
	else return middle;
}
// key���� ũ�ų� ���� �ּ� ������ ��ġ�� return�ϴ� ���� Ž�� �ҽ� 

int main() {
	int N = 9;
	int data[] = { 6, 2, 9, 8, 3, 4, 1, 7, 4 };

	int LIS[N + 1]; // LIS�� ���̴� 1�̻� N�����̹Ƿ�, �迭 ũ��� N+1�� �����Ѵ�. 
	int maxLength = 0; // LIS �迭�� �ʱ� ����. 

	LIS[0] = MIN_INTEGER_VALUE; // ���ǻ� �ּڰ��� ����Ű�� �ּ� ���Ҹ� ���� 

	for (int i = 0; i < N; i++){
		int position = binary_search(LIS, 0, maxLength + 1, data[i]); // ���� Ž���� ���� ������ ������ ��ġ�� Ȯ�� 
		LIS[position] = data[i]; // LIS �迭�� ���� ����
		if (maxLength < position) maxLength = position; // maxLength ���� 
	}
	int ans = maxLength; // ans : maxLength