#include <stdio.h>
#define LONG_NAME 30
#define CANT_EMPLOYES 5

typedef struct empleado{
     char nombre[LONG_NAME];
     char edad;
     float salario;
} formato;

void Bienvenida (formato[]);
void ingresarDatos(formato[], int);
void procesarDatos(formato[], int);
void mostrarDatos(formato[], int);

int main (void){
    formato empleado[LONG_NAME];
    Bienvenida(empleado);
}
void Bienvenida (formato empleado[]){
    int eleccion, empleados;
    printf("\n-----Menu-----\nen esta parte puede ingresar y mostrar la informacion de los empleados.\nPor favor, ingrese 1, 2 o 3 sabiendo la información que desea ingresar.\n\n");
    do{
        printf("1. Ingrese los datos del empleado/a.\n");
        printf("2. Mostrar la informacion ingresada.\n");
        printf("3. Salir.\n");
    do{
        printf("ingrese su opcion: ");
        scanf("%i", &eleccion);
         if (eleccion != 1 && eleccion != 2 && eleccion != 3){
         printf("El numero/letra elegido/a no es válido");
            }
  } while (eleccion != 1 && eleccion != 2 && eleccion != 3);
        if (eleccion >= 1 && eleccion <= 3) {
            switch (eleccion){
                case 1:
                printf("\nCuantos empleados desea ingresar\n");
                do{
                printf("numeros de empleados a ingresar: ");
                scanf("%i", &empleados);
                if (empleados > CANT_EMPLOYES && empleados < 0){
                    printf("Cantidad no deseada. Por favor, ingrese un valor entre 1 y 5.\n");
                }
                } while (empleados > CANT_EMPLOYES && empleados < 0);
                ingresarDatos(empleado, empleados);
                break;
                case 2:
                procesarDatos(empleado, empleados);
                mostrarDatos(empleado, empleados);
                break;
            }
        }
    } while (eleccion != 3);
}


void ingresarDatos(formato empleado [], int empleados){
    for (int i = 0; i < empleados; i++){
        printf("Empleado/a N%c %i.\n", 167, i+1);
        printf("Nombre del empleado/a: ");
        scanf("\n%[^\n]s", &empleado[i].nombre);
        do{
            printf("Edad del empleado: ");
            scanf("%i", &empleado[i].edad);
            if (empleado[i].edad < 0){
                printf("La edad escrita no es posible. Por favor, ingresalo nuevamente.\n");
            }      
        } while (empleado[i].edad < 0);
        do{
            printf("Salario del empleado/a (en dolares): ");
            scanf("%f", &empleado[i].salario);
            if (empleado[i].salario < 1){
                printf("El salario ingresado es demasiado bajo. Por favor, ingresalo otra vez.\n");
            } 
        } while ((empleado[i].salario < 1));
        printf("\n");
    }
    printf("\nDatos ingresados correctamente.\n");
}


void procesarDatos(formato empleado[], int empleados){
    float prom = 0, prom2;
    int mayor = 0;
    for (int i = 0; i < empleados; i++){
        prom += empleado[i].salario;
    }
    prom /= empleados;
    prom2 = prom / empleado[0].salario;
    printf("\nEl promedio de salarios es de: %c%f\n",36, prom);
    if (prom2 != 1) {
        for (int i = 0; i < empleados; i++){
            if(empleado[i].salario > mayor){
                mayor = i;
            }
        }
        printf("El empleado con el mayor salario es: %s, con un valor de %c%f\n", empleado[mayor].nombre, 36, empleado[mayor].salario);
    } else {
        printf("Todos los salarios son iguales, con un valor de %f\n", empleado[0].salario);
    }
}



void mostrarDatos(formato empleado[], int empleados){
    for (int i = 0; i < empleados; i++){
        printf("Empleado %d: Nombre: %s, edad: %i, salario: %c%f\n", i + 1, empleado[i].nombre, empleado[i].edad, 36, empleado[i].salario);
    }
}

