#include <iostream>
#include<vector>

using namespace std;

int n, m;
int tc = 1;
bool visited[501];
bool noTree;

void go(int root, vector<int> edge[501], int prev) {
	visited[root] = true;
	for (int e : edge[root]) {
		if (e == prev) {
			continue;
		}
		if (visited[e]) {
			noTree = true;
			continue;
		}
		go(e, edge, root);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    freopen("./input_file/4803.txt","rt",stdin);
	cin >> n >> m;
	while (n != 0 || m != 0) {
		int a, b;
		vector<int> edge[501];
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		int tree = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				continue;
			}
			noTree = false;
			go(i, edge, -1);
			if (!noTree) {
				tree++;
			}
		}

		cout << "Case " << tc << ": ";
		if (tree == 0) {
			cout << "No trees.\n";
		}
		else if (tree == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << tree << " trees.\n";
		}

		cin >> n >> m;
		tc++;
	}
} 


//출처 질문게시판