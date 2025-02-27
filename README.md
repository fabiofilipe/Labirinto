# Algoritmo de Resolução de Labirinto com Backtracking

Este projeto implementa a resolução de um labirinto utilizando **backtracking** com uma **pilha** em C++.

## 📌 Descrição
O programa busca encontrar um **tesouro** dentro de um **labirinto** representado por uma matriz, utilizando uma **estrutura de pilha** para armazenar as posições exploradas. A cada movimento, o caminho percorrido é marcado e o estado do labirinto é impresso no terminal.

## 🚀 Funcionamento do Algoritmo
1. Define-se um labirinto com posições livres (`.`), paredes (`#`), posição inicial (`S`) e o tesouro (`T`).
2. Utiliza-se **uma pilha** para armazenar as coordenadas exploradas.
3. O algoritmo segue as seguintes etapas:
   - Retira uma posição do topo da pilha.
   - Se for o **tesouro**, encerra a busca.
   - Caso contrário, adiciona as posições **vizinhas válidas** à pilha.
   - Marca as posições visitadas e imprime o labirinto atualizado.
4. Se a pilha esvaziar sem encontrar o tesouro, exibe uma mensagem de falha.

## 📂 Estrutura do Código
- **`struct Pos`**: Representa coordenadas (x, y) no labirinto.
- **`isValid`**: Verifica se uma posição pode ser visitada.
- **`printMaze`**: Imprime o estado do labirinto no terminal.
- **`solveMaze`**: Implementa o algoritmo de backtracking usando uma pilha.
- **`main`**: Inicializa o labirinto e chama `solveMaze`.

## 📌 Exemplo de Labirinto Utilizado
```cpp
char maze[N][N] = {
    {'S', '.', '#', '.', '.'},
    {'.', '#', '.', '#', '.'},
    {'.', '.', '.', '#', '.'},
    {'#', '#', '.', '.', '.'},
    {'.', '.', '#', 'T', '.'}
};
```

## 🛠️ Como Executar
1. Copie o código fonte para um arquivo `labirinto.cpp`.
2. Compile o programa:
   ```sh
   g++ labirinto.cpp -o labirinto
   ```
3. Execute:
   ```sh
   ./labirinto
   ```

## 🎯 Saída Esperada
O programa imprime o labirinto atualizado a cada movimento, mostrando o trajeto até encontrar o tesouro:
```
S * # . .
. # * # .
. . * # .
# # * * *
. . # T .
------------------
Tesouro encontrado em (4, 3)
```

## 📌 Melhorias Futuras
- Implementação de um labirinto maior e aleatório.
- Interface gráfica para visualização do caminho percorrido.
- Suporte para diferentes métodos de busca (ex: BFS, DFS recursivo).

---
**Desenvolvido com C++ para a disciplina de Estruturas de Dados.** 🚀


