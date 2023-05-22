// n: ��ü ������ ��
// picked: ���ݱ��� �� ���ҵ��� ��ȣ
// toPick: �� �� ������ ��
// �� ��, ������ toPick���� ���Ҹ� ���� ��� ����� ����Ѵ�.
void pick(int n, vector<int>& picked, int toPick) {
	// ���� ���: �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (toPick == 0) { printPicked(picked); return; }
	// �� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// �� �ܰ迡�� ���� �ϳ��� ����.
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}