#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

/*Definição de Variáveis Globais */

int num; /*Número de pontos inseridas por teclado*/
int numThreads; /*Número de threads que a simulação terá em conta */
int numc=0; /* Número de pontos dentro do circulo do 1º quadrante */
double x,y; /* As variáveis x e y para criar os pontos dentro do referencial */
double pi; /* Variável onde se vai inserir o valor calculado de pi */
double realpi; /* Número exato de pi obtido atravéz do módulo math.h */
double erro; /* Número aproximado do erro relativo, onde podemos ter um valor de exatidão em relação ao valor calculado do pi e do real */
clock_t start, end;  /* Variáveis associadas ao módulo clock */
double temp_cpu; /* Variáveis associadas ao módulo clock */

void *thread(void *arg) /*Função onde é exposto o cálculo do pi para ser usado em cada thread */
{
    pi=((double)numc/num)*4; /* Cálculo do valor de pi, através da multiplicação entre quatro e a divisão do número de pontos dentro do circulo pelo número de pontos total */
}

int main(void) { /* Função principal */

    int i=0; /* Contador Genérico */
    pthread_t* pth = malloc(numThreads*sizeof(pthread_t)); /* Criação de uma lista com os threads */

    printf("|---------------------------------|\n");
    printf("| -----Simulação Monte Carlo----- |\n");
    printf("|---------------------------------|\n");

    printf("\nInsira o número de pontos a inserir para o cálculo de pi: "); /* Introdução inicial com o pedido de o número de pontos pelo utilizador */
    scanf("%d",&num);

    /* Faz os números random de -1 a 1 em x e y */
    srand(time(NULL)); /*Seed para random com base no módulo time */
    for ( i=0; i<num; i++) {
        x = 1-2*(double)rand()/RAND_MAX; /* Gera valores de -1 a 1 em x */
        y = 1-2*(double)rand()/RAND_MAX; /* Gera valores de -1 a 1 em y */
        if (x*x+y*y < 1) numc++; /* Se os números gerados estiverem dentro da área do círculo então são contados para numc */
        }

    /* Print da parte inicial da simulação, comum a todas as simulações com n threads*/
    printf("\nNúmero de pontos totais = %d; \nNúmero de pontos introduzidos dentro do círculo = %d\n", num, numc);


    /* Simulações com 2 threads */
    start = clock(); /* Inicio do clock */
    numThreads=2; /* Declaração das threads a usar */
    printf("\nSimulação com 2 threads: \n");
    for (i=0; i<numThreads; i++) { /* Criação das threads */
        pthread_create(pth+i, NULL, &thread, NULL);
    }
    for (i=0; i<numThreads; i++) { /* União das threads criadas após conclusão do seu trabalho */
        (void)pthread_join(*(pth+i), NULL);
    }
    end = clock(); /* Término do clock */
    temp_cpu= ((double) (end - start)) / CLOCKS_PER_SEC*100000; /*Cálculo do tempo de CPU  */

    /*Cálculo da exatidão de pi*/
    realpi=M_PI; /* Usando o módulo math, conseguimos um valor exato de pi */
    erro=(((realpi-pi)/realpi)*100); /* Cálculo do erro relativo da simulação */

    /* Resultados */
    printf("Estimativa de pi = %g; \nErro Relativo em percentagem: %.3g %% \n",pi, erro); /* Estimativa de pi e Erro Relativo */
    printf("Tempo total de cálculo: %g ms\n", temp_cpu); /*Cálculo do tempo */


    /* Simulações com 4 threads */
    start = clock(); /* Inicio do clock */
    numThreads=4; /* Declaração das threads a usar */
    printf("\nSimulação com 4 threads: \n");
    for (i=0; i<numThreads; i++) { /* Criação das threads */
        pthread_create(pth+i, NULL, &thread, NULL);
    }
    for (i=0; i<numThreads; i++) { /* União das threads criadas após conclusão do seu trabalho */
        (void)pthread_join(*(pth+i), NULL);
    }
    end = clock(); /* Término do clock */
    temp_cpu= ((double) (end - start)) / CLOCKS_PER_SEC*100000; /*Cálculo do tempo de CPU  */

    /*Cálculo da exatidão de pi*/
    realpi=M_PI; /* Usando o módulo math, conseguimos um valor exato de pi */
    erro=(((realpi-pi)/realpi)*100); /* Cálculo do erro relativo da simulação */

    /* Resultados */
    printf("Estimativa de pi = %g; \nErro Relativo em percentagem: %.3g %% \n",pi, erro); /* Estimativa de pi e Erro Relativo */
    printf("Tempo total de cálculo: %g ms\n", temp_cpu); /*Cálculo do tempo */


    /* Simulações com 6 threads */
    start = clock(); /* Inicio do clock */
    numThreads=6; /* Declaração das threads a usar */
    printf("\nSimulação com 6 threads: \n");
    for (i=0; i<numThreads; i++) { /* Criação das threads */
        pthread_create(pth+i, NULL, &thread, NULL);
    }
    for (i=0; i<numThreads; i++) { /* União das threads criadas após conclusão do seu trabalho */
        (void)pthread_join(*(pth+i), NULL);
    }
    end = clock(); /* Término do clock */
    temp_cpu= ((double) (end - start)) / CLOCKS_PER_SEC*100000; /*Cálculo do tempo de CPU  */

    /*Cálculo da exatidão de pi*/
    realpi=M_PI; /* Usando o módulo math, conseguimos um valor exato de pi */
    erro=(((realpi-pi)/realpi)*100); /* Cálculo do erro relativo da simulação */

    /* Resultados */
    printf("Estimativa de pi = %g; \nErro Relativo em percentagem: %.3g %% \n",pi, erro); /* Estimativa de pi e Erro Relativo */
    printf("Tempo total de cálculo: %g ms\n", temp_cpu); /*Cálculo do tempo */


    /* Simulações com 8 threads */
    start = clock(); /* Inicio do clock */
    numThreads=8; /* Declaração das threads a usar */
    printf("\nSimulação com 8 threads: \n");
    for (i=0; i<numThreads; i++) { /* Criação das threads */
        pthread_create(pth+i, NULL, &thread, NULL);
    }
    for (i=0; i<numThreads; i++) { /* União das threads criadas após conclusão do seu trabalho */
        (void)pthread_join(*(pth+i), NULL);
    }
    end = clock(); /* Término do clock */
    temp_cpu= ((double) (end - start)) / CLOCKS_PER_SEC*100000; /*Cálculo do tempo de CPU  */

    /*Cálculo da exatidão de pi*/
    realpi=M_PI; /* Usando o módulo math, conseguimos um valor exato de pi */
    erro=(((realpi-pi)/realpi)*100); /* Cálculo do erro relativo da simulação */

    /* Resultados */

    printf("Estimativa de pi = %g; \nErro Relativo em percentagem: %.3g %% \n",pi, erro); /* Estimativa de pi e Erro Relativo */
    printf("Tempo total de cálculo: %g ms\n", temp_cpu); /*Cálculo do tempo */


    printf("\n|----------------------------|\n");
    printf("| -----Fim do Programa!----- |\n");
    printf("|----------------------------|\n");
}