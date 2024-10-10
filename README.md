
**Gerenciamento de Processos com Algoritmos de Escalonamento**

Este projeto implementa um simulador de gerenciamento de processos, no qual processos são criados aleatoriamente com diferentes características e podem ser executados
 com base em diferentes algoritmos de escalonamento. O objetivo é comparar o desempenho de quatro algoritmos de escalonamento de processos: SJF (Shortest Job First), 
SRTF (Shortest Remaining Time First), RR (Round Robin) e FIFO (First In First Out).

**Funcionalidades**

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
