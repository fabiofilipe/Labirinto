#include <iostream>
#include <stack>
using namespace std;

#define N 5  // Tamanho do labirinto (pode ser ajustado)

// Estrutura para armazenar coordenadas
struct Pos {
    int x, y;
};

// Função para verificar se a posição é válida
bool isValid(int x, int y, char maze[N][N], bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != '#' && !visited[x][y]);
}

// Função para exibir o labirinto
void printMaze(char maze[N][N], bool visited[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) {
                cout << "* ";  // Indica o caminho percorrido
            } else {
                cout << maze[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

// Função para resolver o labirinto usando backtracking com pilha
bool solveMaze(char maze[N][N], Pos start, Pos treasure) {
    stack<Pos> s;
    bool visited[N][N] = {false};
    
    s.push(start);
    visited[start.x][start.y] = true;
    
    // Direções: direita, baixo, esquerda, cima
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    while (!s.empty()) {
        Pos current = s.top();
        s.pop();
        
        // Exibir o estado atual do labirinto
        printMaze(maze, visited);
        
        // Se encontrou o tesouro, retorna verdadeiro
        if (current.x == treasure.x && current.y == treasure.y) {
            cout << "Tesouro encontrado em (" << current.x << ", " << current.y << ")" << endl;
            return true;
        }
        
        // Testa as quatro direções possíveis
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (isValid(newX, newY, maze, visited)) {
                s.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    cout << "Tesouro não encontrado!" << endl;
    return false;
}

int main() {
    char maze[N][N] = {
        {'S', '.', '#', '.', '.'},
        {'.', '#', '.', '#', '.'},
        {'.', '.', '.', '#', '.'},
        {'#', '#', '.', '.', '.'},
        {'.', '.', '#', 'T', '.'}
    };
    
    Pos start = {0, 0};  // Posição inicial do jogador
    Pos treasure = {4, 3}; // Posição do tesouro
    
    solveMaze(maze, start, treasure);
    
    return 0;
}
