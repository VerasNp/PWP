# PWP (Penguin With a Pencil)

> **Ainda em desenvolvimento, mas já é possível usar algumas funcionalidades**.

A mathematical toolkit designed to solve numerical problems.

## Derivadas

## Integrais

### Regras de quadratura

#### Regras de Newton-Cotes

- Regra do trapézio
- Regra de Simpson 1/3
- Regra de Simpson 3/8
- Regra de Milne

## Autovalores e autovetores

- Método da potência
  - Método da potência regular: encontra o autovalor dominante (maior em módulo) e seu autovetor associado.
  - Método da potência inversa: encontra o autovalor de menor módulo e seu autovetor associado.
- Método da potência com deslocamento;
- Métodos de transformação de similaridade

### Utilidades

- Fatoração LU: Uso do algoritmo de Crout para decomposição de matrizes em produtos de matrizes triangulares inferiores e superiores gerando uma matriz única que armazena as informações de ambas as matrizes.

## Teorema do valor intermediário

- Método de Rung-Kutta
  - Método Passos Simples
  - Método Passos Múltiplos

## PVC (Problema de valores de contorno)

- Diferenças finitas
- Método dis elementos finitos

##

`cmake -B build -G Ninja`

`cmake --build build`

`ctest --test-dir build`
