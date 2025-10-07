# Programação Paralela

Projetos desenvolvidos na matéria de programação paralela.

## Projeto Integral.c

Este projeto contém o arquivo `integral.c`, cuja finalidade é calcular integrais definidas utilizando métodos numéricos.

### Descrição

O programa implementa uma técnica de integração numérica para aproximar o valor de integrais em um determinado intervalo. O método utilizado pode ser, por exemplo, a regra do trapézio ou a regra de Simpson, dependendo da implementação.

### Função Principal

- Leitura dos limites inferior e superior da integração;
- Definição do número de subdivisões (ou segmentos);
- Cálculo da aproximação da integral com base no método implementado;
- Exibição do resultado na tela.

### Pré-requisitos

- Compilador C (como GCC ou Clang)
- Ambiente de desenvolvimento compatível

### Compilação

Para compilar o programa, utilize um dos comandos abaixo no terminal:

```bash
gcc integral.c -o integral
```

ou

```bash
clang integral.c -o integral
```

### Execução

Depois de compilado, execute o programa pelo terminal:

```bash
./integral
```

Siga as instruções na tela para inserir os limites da integral e outras configurações necessárias.

### Estrutura do Código

- `main()`: Ponto de entrada do programa.
- Funções auxiliares para:
    - Cálculo de termos da soma
    - Implementação do método de integração numérica

### Possíveis Melhorias

- Inclusão de opções para escolher diferentes métodos de integração
- Validação de entrada mais robusta
- Implementação de testes unitários para as funções de cálculo

