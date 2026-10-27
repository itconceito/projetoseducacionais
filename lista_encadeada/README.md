# 🚀 Sistema de Gerenciamento de Lista Simplesmente Encadeada

Projeto desenvolvido em **Linguagem C** para a empresa **Renalf Mega Data**. O sistema implementa as operações elementares de uma estrutura de dados **Lista Linear Simplesmente Encadeada** com alocação dinâmica de memória.

---

## 📌 Funcionalidades

O sistema conta com um menu interativo via terminal que permite realizar as seguintes operações:

1. **Inclusão (Inserção):** Adiciona novos registros (ID e Nome) no final da lista encadeada.
2. **Listagem (Consulta Geral):** Exibe todos os dados armazenados sequencialmente.
3. **Consulta por ID:** Busca e exibe as informações de um registro específico.
4. **Alteração (Atualização):** Permite atualizar o nome de um registro existente mantendo o mesmo ID.
5. **Remoção (Exclusão):** Remove um nó da lista por ID, ajustando os ponteiros da estrutura e liberando a memória alocada.
6. **Gerenciamento de Memória:** Liberacao completa da memória dinâmica via `free()` ao encerrar o programa.

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**
- **Compilador GCC**
- **Alocação Dinâmica de Memória** (`malloc`, `free`)
- **Ponteiros e Estruturas** (`struct`, `typedef`)

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
Ter um compilador C instalado na máquina (ex: `gcc`) ou utilizar um ambiente como o **GitHub Codespaces**.

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git](https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git)
   cd NOME-DO-REPOSITORIO