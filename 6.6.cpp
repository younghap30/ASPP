/*
- 한 칸을 덮는 네 가지 방법을 각각의 코드로 구현하는 것이 아니라 coverType[] 배열에 저장했다.
- 이 배열은 네 가지 방법에서 새로 채워질 칸들의 상대 좌표(delta y, delta x)의 목록을 저장한다.

- set()은 delta에 따라 블록을 놓는 역할과 치우는 역할을 같이 할 수 있다.
- 블록을 놓는 것과 치우는 것을 별도로 짤 필요가 없어진다.

- set()은 해당 위치에 블록을 놓을 수 있는지 여부도 같이 판단한다.
- 단 이때 곧장 함수를 종료하는 것이 아니라 마지막까지 함수를 실행한다는 데 유의할 필요가 있다.
- 만약 블록을 구성하는 세 칸 중에 한 칸에 표시를 한 뒤 두 번째 칸에 이미 블록이 놓여 있다는 것을 발견했다고 하자.
- 이때 함수를 곧장 종료하면 나중에 덮었던 블록을 치울 때, 두 번째 칸에 이미 있던 블록마저 치워버리게 된다.
- 따라서 set()은 그 자리에 그냥 1을 더함으로써 이 칸에는 두 개의 블록이 겹쳐서 놓여 있다고 표시한다.
*/

// 주어진 칸을 덮을 수 있는 네 가지 방법
// 블록을 구성하는 세 칸의 상대적 위치 (dy, dx)의 목록
const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};
// board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다.
// delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
// 만약 블록이 제대로 덮이지 않은 경우(게임판이 밖으로 나가거나, 겹치거나, 검은 칸을 덮을 때) false를 반환한다.
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int>>& board) {
	// 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j)
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}
	// 기저 사례: 모든 칸을 채웠으면 1을 반환한다.
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		// 만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출한다.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		// 덮었던 블록을 치운다.
		set(board, y, x, type, -1);
	}
	return ret;
}