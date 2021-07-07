#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimirInfo();
void leerInfo();
void realizarConsulta();
//void ordenarConsulta();
void copiarEnArreglo();
void seleccionarDatos();
void arregloaTXT();
int contarFilas();

char resp[1], c[5000], condicion1[20], condicion2[20], condicion3[20], condicion21[50], q;
int auxiliar=0, condicion22, contadorTokens=0, limiteInferior=10, filas;
float condicion23;
	
int main(int argc, char *argv[]) {
	puts ("¿Desea agregar a un alumno a la base de datos? S/N");
	gets (resp);
	strupr(resp);
	
	if (strcmp (resp, "S")==0){
		system ("cls");
		leerInfo();
	}else{
		system ("cls");
		puts ("¿Desea realizar una consulta en la base de datos? S/N");
		gets (resp);
		strupr(resp);
		if (strcmp (resp, "S")==0){
			system ("cls");
			realizarConsulta();
			//ordenarConsulta();
		}else{
			system ("cls");
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
	
	seleccionarDatos();
	
	filas=contarFilas();
	
	for (int k=0; k<filas; k++){
		copiarEnArreglo();
		
		if(condicion1[0]=='*'){
			int columna;
			
			switch (condicion2[4]){
				case '1':
					columna=1;
					break;
				case '2':
					columna=2;
					break;
				case '3':
					columna=3;
					break;
				case '4':
					columna=4;
					break;
				case '5':
					columna=5;
					break;
				case '6':
					columna=6;
					break;
				case '7':
					columna=7;
					break;
				case '8':
					columna=8;
					break;
				case '9':
					columna=9;
					break;
				default:
					columna=10;
					break;
			}
			
			int contadorExtra=1, /*posicion,*/ p=0;
			while (c[p]!='\0'){
				if(c[p]=='|'){
					contadorExtra++;
					if(contadorExtra==columna){
						//posicion=p;
						break;
					}
				}
				p++;
			}
			
			int number=(float)(c[p+2]);
			if ((c[p+3]>=48) && (c[p+3]<=57)){
				char nuevo=c[p+2]+c[p+3];
				number=(float)(nuevo);
			}
			
			switch(condicion2[4]){
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '8':
				case '0':
					//Me compara caracteres evaluando sobre (condicion21)
					
					break;
				case '7': //Evaluando enteros sobre el semestre (condicion22).
					switch (auxiliar){
						case 1:
							if((condicion22<number)){
								arregloaTXT();
							}
							break;
						case 2:
							if((condicion22>number)){
								arregloaTXT();
							}
							break;
						case 3:
							if((condicion22<=number)){
								arregloaTXT();
							}
							break;
						case 4:
							if((condicion22>=number)){
								arregloaTXT();
							}
							break;
						case 5:
							if((condicion22!=number)){
								arregloaTXT();
							}
							break;
						case 6:
							if((condicion22==number)){
								arregloaTXT();
							}
							break;
					}
				case '9'://Evaluando flotantes sobre calificaciones (condicion23)
					switch (auxiliar){
						case 1:
							if((condicion23<number)){
								arregloaTXT();
							}
							break;
						case 2:
							if((condicion23>number)){
								arregloaTXT();
							}
							break;
						case 3:
							if((condicion23<=number)){
								arregloaTXT();
							}
							break;
						case 4:
							if((condicion23>=number)){
								arregloaTXT();
							}
							break;
						case 5:
							if((condicion23!=number)){
								arregloaTXT();
							}
							break;
						case 6:
							if((condicion23==number)){
								arregloaTXT();
							}
							break;
					}
			}
		}else{
			
		}
	}
	
	return;
}
	
	
void seleccionarDatos(){
	do{
		printf ("Seleccionar ");
		gets (condicion1);
		printf ("donde (seleccione la columna a comparar y la operación a ejecutar)");
		gets (condicion2); //Ejemplo Col<>
		
		switch (condicion2[4]){
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '8':
		case '0':
			printf("Escriba el valor con el que se comparará la columna:");
			gets(condicion21); //Ejemplo A17000919
			break;
		case '7':
			printf("Escriba el valor con el que se comparará la columna:");
			scanf ("%d", &condicion22); //Ejemplo 5
			break;
		case '9':
			printf("Escriba el valor con el que se comparará la columna:");
			scanf ("%f", &condicion23); //Ejemplo 89.34
			break;
		}
		
		getchar();
		
		printf ("ordenado por ");
		gets (condicion3);
		
		switch (condicion2[4]){
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '8':
		case '0':
			printf ("Seleccionar %s donde %s%s ordenado por %s\n", condicion1, condicion2, condicion21, condicion3);
			strupr(condicion21);
			break;
		case '7':
			printf ("Seleccionar %s donde %s%d ordenado por %s\n", condicion1, condicion2, condicion22, condicion3);
			break;
		case '9':
			printf ("Seleccionar %s donde %s%f ordenado por %s\n", condicion1, condicion2, condicion23, condicion3);
			break;
		}
		
		system ("pause");
		system ("cls");
		
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
	return;
}
/*void ordenarConsulta(){
	
	//FILE * flujo = fopen("consulta","wb");//Archivo final donde se almacena la consulta ordenada.
	
	//remove(aux.txt);//Eliminamos el archivo donde e guardó la consulta sin ser ordenado.
	return;
}*/
	
void copiarEnArreglo(){
	
	FILE * flujo = fopen ("alumnos.txt", "r");
	if (flujo==NULL){
		perror("No se pudo localizar el archivo");
		return;
	}
	
	int i=0;
		
	while (feof(flujo)==0){
		q=fgetc(flujo);
		if(q=='|'){
			contadorTokens++;
		}
		
		if((contadorTokens>=limiteInferior)&&(contadorTokens<=(limiteInferior+10))){
			c[i]=q;
			i++;
		}
		
		if((limiteInferior+10)==contadorTokens){
			limiteInferior+=10;
			break;
		}
	}
	
	fclose(flujo);
	return;
}
	
void arregloaTXT(){
	FILE * flujo2 = fopen ("consulta.txt", "a");
	fputs(c,flujo2);
	fputs ("\n", flujo2);
	fclose(flujo2);
}

int contarFilas(){
	FILE * flujo = fopen ("alumnos.txt", "r");
	if (flujo==NULL){
		perror("No se pudo localizar el archivo");
		return 10;
	}
	
	int contadorTotal=0, a;
	
	while (feof(flujo)==0){
		q=fgetc(flujo);
		if(q=='|'){
			contadorTotal++;
		}
	}
	
	a=contadorTotal/10;
	
	fclose (flujo);
	return a;
}

