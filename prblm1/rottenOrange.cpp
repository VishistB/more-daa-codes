#include <cstdlib>
#include <queue>
#include <iostream>

struct Index{
  int i,j;
};

class Graph{
  private:
    std::queue<Index> q;
    int** arr;
		int m, n;
    Index source;
    int minDays = 0;
		// Gets the source for bfs 
    Index findSource(){
			Index d;
			d.i = -1;
			d.j = -1;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					if(arr[i][j] == 2){
            std::cout << arr[i][j] << std::endl;
						d.i = i;
						d.j = j;
						return d;
					}
				}
			}
			return d;
    }
    int bfs(){
      std::cout << "BFS" << q.front().i << "," << q.front().j << std::endl;
      if(q.empty()) return minDays;
      Index node = q.front();
      q.pop();
      Index nd;
      bool rot = false;
      // Left check
      if(node.j > 0){
        std::cout << node.i << " " << node.j-1 << std::endl;
        if(arr[node.i][node.j-1] == 1){
          arr[node.i][node.j-1] = 2;
          nd.i = node.i;
          nd.j = node.j-1;
          q.push(nd);
          rot = true;
        }
      }
      // Right check
      if(node.j < n-1){
        if(arr[node.i][node.j+1] == 1){
          arr[node.i][node.j+1] = 2;
          nd.i = node.i;
          nd.j = node.j+1;
          q.push(nd);
          rot = true;
        }
      }
      // Up check
      if(node.i > 0){
        if(arr[node.i-1][node.j] == 1){
          arr[node.i-1][node.j] = 2;
          nd.i = node.i-1;
          nd.j = node.j;
          q.push(nd);
          rot = true;
        }
      }
      // Down Check
      if(node.i < m-1){
        std::cout << node.i+1 << " " << node.j << std::endl;
        if(arr[node.i+1][node.j] == 1){
          arr[node.i+1][node.j] = 2;
          nd.i = node.i+1;
          nd.j = node.j;
          q.push(nd);
          rot = true;
        }
      }
      if(rot){
        minDays++;
        std::cout << minDays << std::endl;
        displayState();
      }
      return bfs();
    }
    int checkCrate(){
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(arr[i][j] == 1) return -1;
        }
      }
      return minDays;
    }
  public:
    Graph(int** arr, int m, int n){
      this->arr = arr;
			this->m = m;
			this->n = n;
      Index src = this->findSource();
      if(source.i == -1 || source.j == -1){
        std::cout << "No rotten oranges are present" << std::endl;
        std::exit(0);
      }else{
        std::cout << "Source : (" << src.i << " " << src.j << ")" << std::endl;
        this->source = src;
      }
    }
    // BFS
    void run(){
      if(checkCrate() != -1){
        std::cout << 0 << " as there are no fresh oranges that can rot" << std::endl;
      }
      q.push(source);
      std::cout << q.front().i;
      bfs();
      this->minDays = checkCrate();
      std::cout << "Minimum number of days = " << this->minDays << std::endl;
    }
    // display crate status
    void displayState(){
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
};


int main(){
  int m,n;
  std::cout << "Enter the number of rows and colums" << std::endl;
  std::cin >> m >> n;
  int** oranges = new int*[m];
  for(int i = 0; i < m; i++){
    oranges[i] = new int[n];
  }
  std::cout << "Enter initial condition" << std::endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      std::cout << "[" << i << ":" << j << "] : "; 
      std::cin >> oranges[i][j];
    }
  }
  Graph mg(oranges, m, n);
  mg.run();
  return 0;
}
