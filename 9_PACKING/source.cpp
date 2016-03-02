#include <iostream>
#include <string>
using namespace std;

int C;
int N;
int W;

string name[100];
int volume[100];
int need[100];
int cache[1001][100];
int hit[100];

int pack(int capacity, int item) {
  if (item == N) return 0;
  int& ret = cache[capacity][item];
  if (ret != -1) return ret; 

  ret = pack(capacity, item + 1);
  if (capacity >= volume[item])
    ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);

  return ret;
}

void reconstruct(int capacity, int item) {
  if (item == N) return;
  if (pack(capacity, item) == pack(capacity, item + 1)) {
    reconstruct(capacity, item + 1);
  } else {
    hit[item] = 1;
    reconstruct(capacity - volume[item], item + 1);
  }
}

int main() {
  int max_need;
  int need_num;
  string item[100];

  cin >> C;
  while (C--) {
    cin >> N >> W; 
    for (int i = 0; i < N; i++) {
      cin >> name[i] >> volume[i] >> need[i];
      hit[i] = 0;
    }
  
    //////////////////////////////////////////////  
    for (int i = 0; i < 1001; i++) {
      for (int j = 0; j < 100; j++) {
        cache[i][j] = -1;
      }
    }
 
    max_need = pack(W, 0);
    reconstruct(W, 0);

    need_num = 0;
    for (int i = 0; i < N; i++) {
      if (hit[i] == 1) {
        item[need_num] = name[i];
        need_num++;
      } 
    }

    //////////////////////////////////////////////  
    
    cout << max_need << " " << need_num << endl;
    for (int i = 0; i < need_num; i++) {
      cout << item[i] << endl;
    }
  }
}
