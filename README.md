# Estruturas de Dados em C

Projeto desenvolvido em C com implementação de lista sequencial e lista encadeada, permitindo operações de inserção, remoção, busca e análise de desempenho.

## Funcionalidades
- Inserção de elementos (início, fim, posição N)
- Remoção de elementos
- Busca por RG
- Leitura de arquivos
- Exibição da lista
- Comparação entre lista sequencial e encadeada

## Linguagem utilizada
- Linguagem C

## Autor
João Guilherme Nascimento dos Santos

---

# Como Executar o Projeto (Listas em C)

## Pré-requisitos

Para rodar este projeto, é necessário ter um compilador de C instalado.

### Opção recomendada (Windows)

Você pode usar uma IDE:

 Code::Blocks (versão com MinGW incluso)

Baixe a versão:
codeblocks-20.03mingw-setup.exe

---

## Como executar pelo terminal

1. Abra o terminal na pasta do projeto

2. Compile o programa:
   
  gcc main.c -o listas

---

## ▶️ Funcionamento do programa

Após executar o programa, será exibido um menu interativo no terminal.

O usuário poderá escolher entre diferentes operações sobre as listas:

### 📥 1. Carregar dados
O programa pode ler um arquivo `.txt` contendo nomes e RGs e carregar esses dados na lista.

---

### ➕ 2. Inserção de elementos
O usuário pode inserir novos elementos na lista:
- No início
- No final
- Em uma posição específica (N)

---

### ➖ 3. Remoção de elementos
Também é possível remover elementos:
- Do início
- Do final
- De uma posição específica

---

### 🔍 4. Busca
Permite buscar um elemento pelo RG e exibir suas informações.

---

### 📋 5. Exibição da lista
Mostra todos os elementos armazenados na lista.

---

### 📊 6. Métricas de desempenho
A cada operação, o programa exibe:
- C(n): número de comparações realizadas
- M(n): número de movimentações na memória
- Tempo de execução

---

### ⚠️ Encerramento
O programa continua executando até que o usuário escolha sair.
