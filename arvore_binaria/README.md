# 🌳 Árvore Binária de Busca (BST) em Linguagem C

Projeto desenvolvido para a **Renalf S/A** focado na implementação e manipulação de uma **Árvore Binária de Busca** (*Binary Search Tree - BST*) com alocação dinâmica de memória e os três percursos de busca em profundidade.

---

## 📌 Funcionalidades

1. **Inserção (Inclusão):** Adiciona nós respeitando a regra fundamental da BST (valores menores à esquerda, maiores à direita).
2. **Remoção de Nós:** Trata os três cenários de exclusão (nó folha, nó com 1 filho e nó com 2 filhos/sucessor em ordem).
3. **Percurso Pré-Ordem (RED):** Visita Raiz $\rightarrow$ Esquerda $\rightarrow$ Direita.
4. **Percurso Em Ordem (ERD):** Visita Esquerda $\rightarrow$ Raiz $\rightarrow$ Direita (exibe os dados em ordem crescente).
5. **Percurso Pós-Ordem (EDR):** Visita Esquerda $\rightarrow$ Direita $\rightarrow$ Raiz.
6. **Desalocação Dinâmica:** Liberação completa da memória via `free()` ao encerrar a aplicação.

---

## 🛠️ Como Executar no Terminal