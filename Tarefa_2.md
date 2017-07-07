# Tarefa 2: Null Pointer protection
## O que mudar: 
- exec: deixar a pagina 0 de memória zerada, carrega o código do programa na página 1
- syscall.c: lançar um erro quando null pointer são pedidos para o kernel
- vm.c: copyuvm deve copiar um página além do começo da page table do processo, para não ter múltiplas páginas 0. 
- Makefile: deve dizer para processos de usuários para começaram na página um e não na página zero. 