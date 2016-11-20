// 최솟값에 대한 정의 

const int MIN_INTEGER_VALUE = -100;

// 구간에 대한 정의
// s <= n <= e 를 만족하는 n의 범위를 [s,e] 라 한다.
// s < n < e 를 만족하는 n의 범위를 (s,e) 라 한다. 

int binary_search(int Arrays[], int start, int end, int key) { // 탐색 범위는 [start,end) 이다. 
	if (start == end) return start; // 탐색을 더 할 필요가 없는 경우 

	int middle = (start + end) / 2;
	if (Arrays[middle] < key) { // [middle+1,end) 구간으로 범위 축소
		return binary_search(Arrays, middle + 1, end, key);
	}
	else if (Arrays[middle] > key) { // [start,middle) 구간으로 범위 축소
		return binary_search(Arrays, start, middle, key);
	}
	else return middle;
}
// key보다 크거나 같은 최소 원소의 위치를 return하는 이진 탐색 소스 

int main() {
	int N = 9;
	int data[] = { 6, 2, 9, 8, 3, 4, 1, 7, 4 };

	int LIS[N + 1]; // LIS의 길이는 1이상 N이하이므로, 배열 크기는 N+1로 선언한다. 
	int maxLength = 0; // LIS 배열의 초기 높이. 

	LIS[0] = MIN_INTEGER_VALUE; // 편의상 최솟값을 가리키는 최소 원소를 삽입 

	for (int i = 0; i < N; i++){
		int position = binary_search(LIS, 0, maxLength + 1, data[i]); // 이진 탐색을 통해 삽입할 원소의 위치를 확인 
		LIS[position] = data[i]; // LIS 배열에 원소 갱신
		if (maxLength < position) maxLength = position; // maxLength 갱신 
	}
	int ans = maxLength; // ans : maxLength