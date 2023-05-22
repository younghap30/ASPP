int n; // ������ ��
double dist[MAX][MAX]; // �� ���� ���� �Ÿ��� �����ϴ� �迭
// path: ���ݱ��� ���� ���
// visited: �� ������ �湮 ����
// currentLength: ���ݱ��� ���� ����� ����
// ������ ���õ��� ��� �湮�ϴ� ��ε� �� ���� ª�� ���� ���̸� ��ȯ�Ѵ�.
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// ���� ���: ��� ���ø� �� �湮���� ���� ���� ���÷� ���ư��� �����Ѵ�.
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];
	double ret = INF; // �ſ� ū ������ �ʱ�ȭ
	// ���� �湮�� ���ø� ���� �õ��� ����.
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// ������ ��θ� ��� ȣ���� ���� �ϼ��ϰ� ���� ª�� ����� ���̸� ��´�.
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}