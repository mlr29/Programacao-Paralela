#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

//Algumas funções para teste

//f(x) = x^2
float fQuadrado(float x){
    return x * x;
}

//f(x) = e^2
float fEuler(float x){
    return exp(x);
}

float calculaAreaTrapezio(float(*f)(float x), float x1, float x2){
    return (((*f)(x1) + (*f)(x2)) * (x2 - x1)) / 2;
}

float integracaoSequencialRegraTrapezios(float(*f)(float x), long long int n, float x1, float x2){
    int i;
    float hM = (x2 - x1) / n;
    float a, b, r = 0;
    double dif_tempo;
    clock_t t_inicio, t_fim;

    t_inicio = clock();

    for(i = 0; i < n; i++){
        a = i * hM + x1;
        b = a + hM;
        r += calculaAreaTrapezio(*f, a, b);
        // printf("\na: %.2f, b: %.2f, r': %.2f",a,b, calculaAreaTrapezio(*f, a, b));
        // printf("\nThread %d executa a iteração %d do loop\n",omp_get_thread_num(),i);
    }

    t_fim = clock();
    dif_tempo = difftime((double)t_fim, t_inicio);

    printf("\nClocks: %f", dif_tempo);
    return r;
}

float integracaoParalelaRegraTrapezios(float(*f)(float x), long long int n, float x1, float x2){
    float r = 0;
    double dif_tempo;
    clock_t t_inicio, t_fim;

    t_inicio = clock();
    #pragma omp parallel reduction(+:r)
    {
        int i;
        float hM = (x2 - x1) / n;
        float a, b;
        #pragma omp for
        for(i = 0; i < n; i++){
            a = i * hM + x1;
            b = a + hM;
            r += calculaAreaTrapezio(*f, a, b);
            // printf("\na: %.2f, b: %.2f, r': %.2f",a,b, calculaAreaTrapezio(*f, a, b));
            // printf("\nThread %d executa a iteração %d do loop\n",omp_get_thread_num(),i);
        }
    }
    
    t_fim = clock();
    dif_tempo = difftime((double)t_fim, t_inicio);

    printf("\nClocks: %f", dif_tempo);
    return r;
}

int main(int argc, char const *argv[]){

    //A programação paralela começa a ter vantagem em relação a sequencial para intervalo e "n" grandes 
    printf("\nIntegracao Regra do Trapezio: ");
    long int n = 1000000000;
    float x1 = 0, x2 = 1000, r;

    printf("\nNumero de trapezios: %ld, x1: %.2f, x2: %.0f\n",n,x1,x2);

    printf("\nResultado Sequencial: ");
    printf("\nr: %.10f", integracaoSequencialRegraTrapezios(fQuadrado, n, x1, x2));
    printf("\n");

    printf("\nResultado Parelela: ");
    printf("\nr: %.10f", integracaoParalelaRegraTrapezios(fQuadrado, n, x1, x2));
    printf("\n");
    return 0;
}