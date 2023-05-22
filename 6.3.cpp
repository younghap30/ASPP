const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
// 5x5�� ���� ���� ���� �ش� ��ġ���� �־��� �ܾ �����ϴ����� ��ȯ
bool hasWord(int y, int x, const string& word) {
	// ���� ��� 1: ���� ��ġ�� ���� ���̸� ������ ����
	if (!inRange(y, x)) return false;
	// ���� ��� 2: ù ���ڰ� ��ġ���� ������ ����
	if (board[y][x] != word[0]) return false;
	// ���� ��� 3: �ܾ� ���̰� 1�̸� ����
	if (word.size() == 1) return true;
	// ������ ���� ĭ�� �˻��Ѵ�.
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		// ���� ĭ�� ���� �ȿ� �ִ���, ù ���ڴ� ��ġ�ϴ��� Ȯ���� �ʿ䰡 ����.
		if (hasWord(nextY, nextX, word.substr(1)))
			return true;
	}
	return false;
}