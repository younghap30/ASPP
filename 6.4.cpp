int n;
bool areFriends[10][10];
// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[10]) {
	// ���� ���: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	bool finished = true;
	for (int i = 0; i < n; ++i) if (!taken[i]) finished = false;
	if (finished) return 1;
	int ret = 0;
	// ���� ģ���� �� �л��� ã�� ¦�� �����ش�.
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
	return ret;
}