const int INF = 9999, SWITHES = 10, CLOCKS = 16;
// linked[i][j] = 'x': i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�.
// linked[i][j] = '.': i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�.
const char linked[SWITHES][CLOCKS + 1] = {
	// 0123456789012345
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
// ��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ���Ѵ�.
bool areAligned(const vector<int>& clocks);
// swtch�� ����ġ�� ������.
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) {
				clocks[clock] = 3;
			}
		}
	}
}
// clocks: ���� �ð���� ����
// swtch: �̹��� ���� ����ġ�� ��ȣ
// �� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ�Ѵ�.
// ���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ�Ѵ�.
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITHES) {
		return areAligned(clocks) ? 0 : INF;
	}
	// �� ����ġ�� 0�� ������ ������ �� �� ������ �������� ��� �õ��Ѵ�.
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	// push(clocks, swtch)�� �� �� ȣ��Ǿ����� clocks�� ������ ���� ���°� �ȴ�.
	return ret;
}