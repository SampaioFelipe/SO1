# Tarefa 2: Null Pointer protection
## O que mudar: 
##### 1. exec.c:
- Deixar a pagina 0 de memória zerada, carrega o código do programa na página 1
- antes: 
`sz = 0;` [linha 41]
- modificado: 
`sz = PGSIZE - 1;` 
---
##### 2. vm.c: 
- `copyuvm` deve copiar um página além do começo da page table do processo, para não ter múltiplas páginas 0. 
- **Antes:** 
 `for(i = 0; i < sz; i += PGSIZE) { [...] }` [linha 332]
- **Modificado:** 
`for(i = PGSIZE; i < sz; i += PGSIZE) { [...] }`
---
##### 3. Makefile: 
- Deve dizer para processos de usuários para começaram na página um e não na página zero. 
- **Antes**:
`	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^` [linha 144]
- **Modificado**: 
`	$(LD) $(LDFLAGS) -N -e main -Ttext 0x1000 -o $@ $^`
Obs: Considerando que o tamanho da página seja _0x1000_
 ----
##### 4. trap.c: 
- Com as modificações acima, ao tentar acessar a página _0x0_, é lançado um erro de Page Fault (pois aquela posição de memória, de fato, não existe). 
- Para gerar um erro mais significativo, foi feita uma pequena modificação no arquivo **trap.c**, adicionado o código abaixo: 
`if (rcr2() == 0) {
              cprintf("Segmentation Fault - Null Pointer Dereference\n");
            }` na [linha 96].
- Ele compara o endereço que gerou o erro com _0x0_, se for `true`, printa que o erro foi causado pelo desreferenciamento de um _null pointer_. 
