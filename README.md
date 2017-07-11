# SO1
Repositório para o trabalho prático da Disciplina de Sistemas Operacionais 1

## Descrição do Projeto: Gerenciamento de Memória
**Proposta:** examinar como o SO xv6 lida com a memória e tentar extendê-lo.

**Apostila sobre o xv6:** [xv6](http://www.cs.umanitoba.ca/~comp4430/readings/book-rev8.pdf) (esse trabalho foca no capítulo 2)

Responder as perguntas:
* **Como o kernel sabe qual página física são usadas e quais não são?**
    Em [mmu.h](xv6/mmu.h), estão definidas as configurações para o gerenciamento de memória. Nele, está definido o descritor de segmento, uma estrutura de 64 bits que contém todas as informações sobre o espaço de endereços de memória a ser utilizado. Dentro desta estrutura, existe um bit *avl* que indica se aquele segmento de memória está disponível ou não para o uso do sistema.
* **Quais estruturas de dados são usadas para responder essa questão?**
    A estrutura de dados utilizada é um descritor de segmento, que armazena o endereço base e o endereço limite de memória do segmento, assim como diversas *flags* que indicam seu estado, incluindo a *flag avl*.
* **Onde essas estruturas residem?**
    Esta estrutura está implementada no código [mmu.h](xv6/mmu.h).
* **O mecanismo de memória do xv6 limita o número de processos do usuário?**
* **Qual número mais baixo de processos que o xv6 pode ter ao mesmo tempo?**


### Tarefa 1 (Marcio): Melhoramento do Visualizador de Detalhes de Processo
**Objetivo:** desenvolver uma ferramenta para auxiliar no teste do uso de memória dos processos no sistema original.

Tarefas a serem realizadas:
- [x] Encontrar onde está a função chamada pelo *ctrl+P*.

Está no arquivo [proc.c](xv6/proc.c), o nome da função é *procdump*.

- [x] Incrementar a função para mostrar detalhes do gerenciamento de memória.

### Tarefa 2 (Quécole): Proteção de Null Pointer
**Objetivo:** implementar exceção de null pointer (acesso a posição 0 da memória).

- [ ] Implementar a funcionalidade para programas do usuário (e fork_test).

- [ ] Atualizar o Makefile (tag -T)

- [ ] Escrever um programa que exibe o conteúdo de memória no enderesso 0.

### Tarefa 3 (Pedro): Proteção de Segmentos read-only
**Objetivo:** implementar a proteção de *read-only* no segmento de texto.

### Tarefa 4 (Sampaio): Copy-on-Write (COW)
**Objetivo:**

## Instruções para Execução
Para executar o projeto é necessário ter instalado o emulador [**QEMU**](http://www.qemu.org/) (no ubuntu: *apt-get install qemu*).

Após a instalação execute os seguintes comandos no diretório do projeto para compilar e executá-lo:
1. make
2. make qemu

Utilize o comando ***make clean*** após a execução para excluir os arquivos gerados pela compilação.

## Descrição do Repositório original (xv6)

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

### ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also http://pdos.csail.mit.edu/6.828/2016/xv6.html, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Cody Cutler, Mike CAT, Nelson Elhage, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron, Shivam Handa, Bryan Henry, Jim Huang, Anders Kaseorg,
kehao95, Wolfgang Keller, Eddie Kohler, Imbar Marinescu, Yandong Mao, Hitoshi
Mitake, Carmi Merimovich, Joel Nider, Greg Price, Ayan Shafqat, Eldar Sehayek,
Yongming Shen, Cam Tenny, Rafael Ubal, Warren Toomey, Stephen Tu, Pablo Ventura,
Xi Wang, Keiichi Watanabe, Nicolas Wolovick, Jindong Zhang, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2016 Frans Kaashoek, Robert Morris, and Russ Cox.

### ERROR REPORTS

If you spot errors or have suggestions for improvement, please send email to
Frans Kaashoek and Robert Morris (kaashoek,rtm@csail.mit.edu).  If you have
suggestions for improvements, please keep in mind that the main purpose of xv6
is as a teaching operating system for MIT's 6.828. For example, we are in
particular interested in simplifications and clarifications, instead of
suggestions for new systems calls, more portability, etc.

### BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run "make".
On non-x86 or non-ELF machines (like OS X, even on x86), you will
need to install a cross-compiler gcc suite capable of producing x86 ELF
binaries.  See http://pdos.csail.mit.edu/6.828/2016/tools.html.
Then run "make TOOLPREFIX=i386-jos-elf-".

To run xv6, install the QEMU PC simulators.  To run in QEMU, run "make qemu".

To create a typeset version of the code, run "make xv6.pdf".  This
requires the "mpage" utility.  See http://www.mesa.nl/pub/mpage/.
