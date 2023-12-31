#include <iostream>
using namespace std;

// 그래프- 정의
// • 그래프(Graph) G
// ✓ 정점(vertex, node)과 간선(edge, link)의 집합으로 이루어진 자료구조
// ✓ G = (V, E) 로 표현

// • 정점(vertex) V
// ✓ 연결 관계의 대상들
// ✓ V = { 1, 2, 3, 4, 5, 6, 7 }

// • 간선(edge) E
// ✓ 연결 관계
// ✓ E = { {1, 2}, {2, 3}, {1, 5}, {5, 2}, {5, 6}, {4, 7} }

// • 인접하다 (adjacent)
// ✓ 간선으로 이어진 두 정점
// ✓ ex) 정점 2와 5는 인접한다.

// • 차수(degree)
// ✓ 정점에 연결된 간선의 수
// ✓ ex) deg(2) = 3

// • 경로 (path) p
// ✓ 중복되지 않는 정점의 나열로서, 인접한 정점 사이에 간선이 있는 경우
// ✓ ex) p = { 3, 2, 5, 1 }

// • 연결 그래프 (connected graph) 
// ✓ 임의의 두 정점 사이에 경로가 존재하는 그래프

// • 비연결 그래프(disconnected graph)
// ✓ 연결 그래프가 아닌 그래프

// • 방향 그래프 (directed graph) 
// ✓ 간선의 방향이 존재하는 그래프
// ✓ E = { (1, 2), (2, 3), (1, 5), (5, 2), (5, 6), (4, 7) }

// • 무방향 그래프(undirected graph)
// ✓ 간선의 방향이 없는 그래프
// ✓ E = { {1, 2}, {2, 3}, {1, 5}, {5, 2}, {5, 6}, {4, 7} }

// • 진입차수 (indegree) 
// ✓ 해당 정점이 종점인 간선의 수
// ✓ 𝑑𝑒𝑔−(2) = 2

// • 진출차수 (outdegree) 
// ✓ 해당 정점이 시점인 간선의 수
// ✓ 𝑑𝑒𝑔 + (2) = 1

// • 루프 (loop) 
// ✓ 어떠한 정점에서 나와서 다시 그 정점으로 들어가는 간선



// 그래프 - 종류
// • 다중 그래프 (multigraph) 
// ✓ 간선의 중복과 루프를 허용하는 그래프

// • 단순 그래프(simple graph)
// ✓ 간선의 중복과 루프가 없는 그래프

// • 순환 (cycle) c 
// ✓ 시작점과 끝점만 동일한 정점의 나열로서, 인접한 정점 사이에 간선이 있는 경우
// ✓ ex) c = { 2, 5, 1, 2 }

// • 순환 그래프 (cycle graph) 
// ✓ 순환(cycle)을 가지고 있는 그래프

// • 비순환 그래프(acyclic graph)
// ✓ 순환(cycle)을 가지지 않는 그래프
// ✓ ex) Tree, DAG
// 방향 그래프
// - 유향 비순환 그래프 (directed acyclic graph, DAG)
// 무방향 그래프
// - 연결 그래프 : 트리 (tree)
// - 비연결 그래프 : 포레스트 (forest)

// • 가중 그래프(weighted graph)
// ✓ 간선에 가중치가 존재하는 그래프
// • 비가중 그래프(unweighted graph)
// ✓ 간선에 가중치가 없는 그래프



// 그래프 표현 – 인접 행렬
// • 인접 행렬 (adjacency matrix) 
// ✓ 이차원 배열을 이용하여 구현
// ✓ 인접하면 1, 인접하지 않으면 0을 저장함
// ✓ 가중 그래프에서는 간선의 가중치를 저장함
// ▪ 시간 복잡도 
// ✓ 간선 추가 O(1) 
// ✓ 간선 판별 O(1)
// ▪ 공간 복잡도 
// ✓ O(|𝑉|2)
// ➢ 간선 수가 많은 경우 사용

// 그래프 표현 – 인접 리스트
// • 인접 리스트 (adjacency list)
// ✓ 이차원 벡터를 이용하여 구현
// ✓ 해당 정점에서 나가는 간선과 연결된 정점을 저장함
// ✓ 가중 그래프에서는 간선의 가중치를 같이 담은 구조체를 저장함
// ▪ 시간 복잡도
// ✓ 간선 추가 O(1)
// ✓ 간선 판별 O( deg(𝑉) )
// ▪ 공간 복잡도 
// ✓ O(|𝐸| )
// ➢ 정점 수가 많은 경우 사용

// 그래프 표현 – 인접 행렬 vs 인접 리스트
// 대부분의 문제들이 간선에 비해 정점 개수가 많기도 하고,
// 특정 노드에 연결된 모든 노드를 찾는 경우가 많음.
// ➢ 공간도 적게 사용하며, 탐색시간도 빠른 인접 리스트를 주로 사용!



// 그래프 탐색 - 정의
// • 그래프 탐색(Graph Search)
// ✓ 그래프의 한 정점에서 출발해서 모든 정점을 한 번씩 방문하는 것
// ✓ 그래프에 대한 정보를 얻거나, 정점들을 방문한 순서를 이용하기 위해 사용함

// • 깊이 우선 탐색(Depth - First Search)
// ✓ ‘깊이’를 우선으로 탐색하는 알고리즘
// ✓ ex) 1 → 2 → 3 → 5 → 6

// • 너비 우선 탐색(Breadth - First Search)
// ✓ ‘너비’를 우선으로 탐색하는 알고리즘
// ✓ ex) 1 → 2 → 5 → 3 → 6



// 그래프 탐색 – DFS
// • 깊이 우선 탐색 (Depth-First Search) 
// ✓ 깊이가 깊어지는 방향으로 그래프를 탐색하는 알고리즘
// ✓ ex) 1 → 2 → 3 → 5 → 6

// • 구현 방법
// ✓ 스택
// ✓ 재귀 함수

// • 활용
// ✓ 백트래킹
// ✓ 사이클 검출



// N과 M은 50 이하인 자연수이다.
int n, m;
char arr[50][50];
int visit[50][50];

// 기훈이의 방 바닥을 장식하는데 필요한 나무 판자의 개수를 출력하는 프로그램을 작성하시오.
void dfs(int cnt, int r, int c) {
    visit[r][c] = cnt;

    // 만약 두 개의 ‘-’가 인접해 있고, 같은 행에 있다면, 두 개는 같은 나무 판자이고,
    if (arr[r][c] == '-') {
        if (c + 1 < m && arr[r][c + 1] == '-') {
            dfs(cnt, r, c + 1);
        }
    }
    // 두 개의 ‘|’가 인접해 있고, 같은 열에 있다면, 두 개는 같은 나무 판자이다.
    else {
        if (r + 1 < n && arr[r + 1][c] == '|') {
            dfs(cnt, r + 1, c);
        }
    }
}

int main() {
    // 첫째 줄에 방 바닥의 세로 크기N과 가로 크기 M이 주어진다. 
    cin >> n >> m;

    // 둘째 줄부터 N개의 줄에 M개의 문자가 주어진다.
    // 이것은 바닥 장식 모양이고, '-‘와 ’|‘로만 이루어져 있다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 아직 방문 안 했을 때
            if (visit[i][j] == 0) { 
                cnt++;

                dfs(cnt, i, j);
            }
        }
    }

    // 첫째 줄에 문제의 정답을 출력한다.
    cout << cnt;

    return 0;
}
