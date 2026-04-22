# ProjetoSOdupla

Trabalho 1 - Sistemas Operacionais - Dupla:
- José Ruan Rodrigues da Silva
- Isaac de Brito Azevedo

## Descrição
Implementação de um shell simples em C, capaz de executar comandos do sistema operacional utilizando chamadas como `fork()`, `execvp()` e `waitpid()`.

## Funcionamento
O programa entra em um loop onde:
- Lê o comando do usuário
- Cria um processo filho com `fork()`
- O filho executa o comando com `execvp()`
- O pai espera a execução com `waitpid()`

## Estrutura
- **Leitura de comando**: captura e separa os argumentos  
- **fork()**: cria um novo processo  
- **execvp()**: executa o comando  
- **waitpid()**: sincroniza os processos  
