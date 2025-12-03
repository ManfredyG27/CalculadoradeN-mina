#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

// Función para leer y validar entrada numérica
int leerEntero(const char *mensaje, int *valor) {
    char buffer[MAX_INPUT];
    printf("%s", mensaje);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }
    if (sscanf(buffer, "%d", valor) != 1 || *valor < 0) {
        printf("Entrada inválida. Intente de nuevo.\n");
        return 0;
    }
    return 1;
}

float leerFloat(const char *mensaje, float *valor) {
    char buffer[MAX_INPUT];
    printf("%s", mensaje);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }
    if (sscanf(buffer, "%f", valor) != 1 || *valor < 0) {
        printf("Entrada inválida. Intente de nuevo.\n");
        return 0;
    }
    return 1;
}

int main() {
    int horas;
    float tarifa, deducciones;

    // Entrada validada
    while (!leerEntero("Ingrese horas trabajadas: ", &horas));
    while (!leerFloat("Ingrese tarifa por hora: ", &tarifa));
    while (!leerFloat("Ingrese deducciones: ", &deducciones));

    // Cálculos
    float salarioBruto = horas * tarifa;
    float salarioNeto = salarioBruto - deducciones;

    // Condicional simple
    if (salarioNeto < 0) {
        salarioNeto = 0;
        printf("⚠️ Las deducciones superan el salario bruto.\n");
    }

    // Salida
    printf("\n--- Resumen de Nomina ---\n");
    printf("Horas trabajadas: %d\n", horas);
    printf("Tarifa por hora:  %.2f\n", tarifa);
    printf("Salario bruto:    %.2f\n", salarioBruto);
    printf("Deducciones:      %.2f\n", deducciones);
    printf("Salario neto:     %.2f\n", salarioNeto);

    return 0;
}