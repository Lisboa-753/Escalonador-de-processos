
**Gerenciamento de Processos com Algoritmos de Escalonamento**

Este projeto desenvolvido em grupo implementa um simulador de gerenciamento de processos, no qual processos são criados aleatoriamente com diferentes características e podem ser executados com base em diferentes algoritmos de escalonamento. O objetivo é comparar o desempenho de quatro algoritmos de escalonamento de processos: SJF (Shortest Job First), 
SRTF (Shortest Remaining Time First), RR (Round Robin) e FIFO (First In First Out).

**Funcionalidades**

O arquivo main.cpp é responsável pela criação e gerenciamento dos processos. Ele implementa a lógica principal do programa e utiliza um menu interativo para permitir ao usuário executar diferentes ações. A seguir estão os principais pontos abordados no código:

**Geração Aleatória de Processos:**

O programa solicita ao usuário quantos processos devem ser criados.
Para cada processo, atributos como PID, status (Running, Waiting, Stopped), memória usada, e tempo estimado de execução são gerados aleatoriamente usando a biblioteca <random>.
Os processos são instâncias das classes derivadas de Processo: Real_Time, Batch, IO_Bound e IO_Bound_Caching.
Interface de Menu:

**O usuário é apresentado a um menu com quatro opções:**

Mostrar lista de processos: Exibe todos os processos criados com seus atributos.
Escolher algoritmo de execução: O usuário pode selecionar entre os algoritmos de escalonamento SJF, SRTF, RR ou FIFO para executar os processos.
Comparar tempos de execução: Após a execução de todos os algoritmos, o programa compara e exibe o tempo total de execução de cada um.
Sair: Encerra o programa.

**Execução dos Processos:**

O usuário escolhe um algoritmo de escalonamento, e o programa ajusta o tempo de execução dos processos conforme o algoritmo selecionado.
Algoritmos disponíveis:
SJF (Shortest Job First): Processos com menor tempo de execução são priorizados.
SRTF (Shortest Remaining Time First): Semelhante ao SJF, mas considerando o tempo restante.
RR (Round Robin): Alterna entre os processos com um quantum de tempo fixo.
FIFO (First In First Out): Processos são executados na ordem em que foram criados.

**Comparação de Algoritmos:**

O código permite que o usuário execute cada algoritmo de escalonamento e compare os tempos totais de execução.

**Limpeza de Memória:**

Após o término do programa, todos os objetos alocados dinamicamente no vetor de processos são liberados, evitando vazamentos de memória.

Geração aleatória de processos com atributos como PID, status (Running, Waiting, Stopped), memória utilizada, e tempo de execução estimado.
Execução de processos com base em algoritmos de escalonamento de CPU:
SJF (Shortest Job First)
SRTF (Shortest Remaining Time First)
RR (Round Robin)
FIFO (First In First Out)
Comparação dos tempos de execução dos algoritmos após a execução de todos eles.
Interface de menu interativa que permite ao usuário visualizar os processos, escolher o algoritmo de escalonamento e comparar os tempos de execução.

**Estrutura do Projeto**

Processo: Classe base para representar processos, com atributos como PID, status e memória. É uma classe abstrata que define os métodos virtuais display(), getResult(), e adjustExecutionTime().
Classes derivadas: As classes derivadas da classe Processo implementam diferentes tipos de processos:
Batch: Representa processos do tipo batch.
Real_Time: Representa processos em tempo real.
IO_Bound: Representa processos limitados por operações de I/O.
IO_Bound_Caching: Variante de IO_Bound que incorpora caching para otimizar execuções.
Funções principais:
displayProcessList(): Exibe a lista de processos.
executeProcesses(): Executa os processos de acordo com o algoritmo selecionado.
