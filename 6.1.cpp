// �ʼ� ����: n >= 1
// ���: 1���� n������ ���� ��ȯ�Ѵ�.
int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret += i;
	return ret;
}
// �ʼ� ����: n >= 1
// ���: 1���� n������ ���� ��ȯ�Ѵ�.
int recursiveSum(int n) {
	if (n == 1) return 1; // ���̻� �ɰ����� ���� ��
	return n + recursiveSum(n - 1);
}