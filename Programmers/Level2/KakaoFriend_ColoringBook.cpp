#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool chk[101][101] = {0};
    int dy[] = { 0, 0, 1, -1};
    int dx[] = { 1, -1, 0, 0};
    
    queue<pair<int,int> > q;
    for(int i = 0; i < picture.size(); i++){
        for(int j = 0 ; j <picture[i].size(); j++){
            int cnt = 0;
            if(chk[i][j]) continue;
            if(picture[i][j] != 0){
                chk[i][j] = true;
                q.push({i,j});
                cnt++;
                number_of_area++;
            }
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
                    if(chk[ny][nx]) continue;
                    if(picture[ny][nx] != picture[y][x]) continue;
                    chk[ny][nx] = true;
                    q.push({ny,nx});
                    cnt++;
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, cnt);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}