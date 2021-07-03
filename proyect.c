#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimirInfo();
void leerInfo();
void realizarConsulta();
//void ordenarConsulta()

char resp[1];
	
int main(int argc, char *argv[]) {
	puts ("¿Desea agregar a un alumno a la base de datos? S/N");
	gets (resp);
	strupr(resp);
	
	if (strcmp (resp, "S")==0){
		leerInfo();
	}else{
		puts ("¿Desea realizar una consulta en la base de datos? S/N");
		gets (resp);
		strupr(resp);
		if (strcmp (resp, "S")==0){
			realizarConsulta();
			//ordenarConsulta();
		}else{
			puts ("No se hizo ninguna consulta :(\nPrograma finalizado con éxito :)");
		}
	}
	
	puts ("¿Desea visualizar la base de datos completa? S/N");
	gets (resp);
	strupr(resp);
	
	
	if (strcmp (resp, "S")==0){
		imprimirInfo(); 
	}else{
		puts ("Programa finalizado con éxito :(\nHasta luego :)");
		return 1;
	}
	
	
	return 0;
}

void imprimirInfo() {
	
	char *filename = "alumnos.txt";
	FILE *flujo = fopen(filename, "r");
	
	// Leer línea por lína, max 256 bytes
	const unsigned MAX = 256; // Constantente de bytes requeridos en la memoria
	char buffer[MAX]; // Buffer nos permite almacenar información en la memoria
	
	if (flujo == NULL)
	{
		printf("Error: no fue posible abrir el archivo %s", filename);
		return;
	}
	
	printf("\n");
	while (fgets(buffer, MAX, flujo)) {
		char * token = strtok(buffer, "|"); // strok divide el string en 'partes' separados por el símbolo a seleccionar 
		while( token != NULL ) {
			printf(" %s ", token); // imprime cada token
			token = strtok(NULL, " "); // separa cada linea
		}
		printf("\n\n");
	}
	
	fclose(flujo);
	
	return;
}

void leerInfo () {
	
	char  matricula[10], nombres[50], apPat[20], apMat[20], campus[50], carrera[50], ing[20], deporte[20];
	int semestre[1];
	float prom[1];
	
	FILE * flujo = fopen("alumnos.txt","a");
	
	if (flujo==NULL){
		perror("ERROR EN LA CREACION DEL ARCHIVO\n\n");
	} else {
		puts ("Ingrese la matricula del alumno:");
		gets (matricula);
		puts ("Ingrese los nombres del alumno:");
		gets (nombres);
		puts ("Ingrese el apellido paterno del alumno:");
		gets (apPat);
		puts ("Ingrese el apellido materno del alumno:");
		gets (apMat);
		puts ("Ingrese el campus del alumno:");
		gets (campus);
		puts ("Ingrese la carrera del alumno:");
		gets (carrera);
		puts ("Ingrese el semestre del alumno:");
		scanf ("%d", &semestre[0]);
		getchar();
		puts ("Ingrese el nivel de ingles del alumno:");
		gets (ing);
		puts ("Ingrese el promedio del alumno:");
		scanf ("%f", &prom[0]);
		getchar();
		puts ("Ingrese el deporte del alumno:");
		gets (deporte);
		
		fputc('\n', flujo); //Salto de línea de control
		
		fputs (matricula, flujo);
		fputs(" | ", flujo);
		fputs (nombres, flujo);
		fputs(" | ", flujo);
		fputs (apPat, flujo);
		fputs(" | ", flujo);
		fputs (apMat, flujo);
		fputs(" | ", flujo);
		fputs (campus, flujo);
		fputs(" | ", flujo);
		fputs (carrera, flujo);
		fputs(" | ", flujo);
		fprintf(flujo, "%d", semestre[0]);
		fputs(" | ", flujo);
		fputs (ing, flujo);
		fputs(" | ", flujo);
		fprintf (flujo, "%.2f", prom[0]);
		fputs(" | ", flujo);
		fputs (deporte, flujo);
		fputs(" | ", flujo);
		
	}
	
	fflush(flujo);
	fclose(flujo);
	
	puts("Proceso finalizado\n\n");
	
	system("pause");
	
	
	return;
}

void realizarConsulta(){
	char condicion1[20], condicion2[20], condicion3[20], c;
	int auxiliar=0;
	
	do{
		printf ("Seleccionar ");
		gets (condicion1);
		printf ("donde ");
		gets (condicion2);
		printf ("ordenado por ");
		gets (condicion3);
		
		system ("cls");
		
		printf ("Seleccionar %s donde %s ordenado por %s\n", condicion1, condicion2, condicion3);
		strupr(condicion1);
		strupr(condicion2);
		strupr(condicion3);
		
		switch(condicion2[5]){
		case '<':
			auxiliar=1;
			if(condicion2[6]=='='){
				auxiliar=3;
			}else{
				if (condicion2[6]=='>'){
					auxiliar=5;
				}
			}
			break;
			
		case '>':
			auxiliar=2;
			if (condicion2[6]=='='){
				auxiliar=4;
			}
			break;
		case '=':
			auxiliar=6;
			break;
		default:
			auxiliar=0;
			puts("La operacion indicada no es valida, favor de ingresar de nuevo las condiciones");
		}
	}while(auxiliar==0);
	
	FILE * flujo = fopen("alumnos.txt","r");//Archivo de origen (Base de datos).
	FILE * flujo2 = fopen("aux.txt","w");//Archivo donde se almacena la consulta.
	
	fscanf(flujo,"%c",&c);
	
	while(c!=EOF){
		fprintf(flujo2,"%c",c);
		fscanf(flujo,"%c",&c);
		fflush(flujo);
		fflush(flujo2);
	}
	
	fclose(flujo);
	fclose(flujo2);
	
	//FILE * flujo = fopen("consulta","wb");//Archivo final donde se almacena la consulta ordenada.
	
	//remove(aux.txt);//Eliminamos el archivo donde e guardó la consulta sin ser ordenado.
	
	return;
}
	
/*void ordenarConsulta(){
	
	
	return;
}*/
