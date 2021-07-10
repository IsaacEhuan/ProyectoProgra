#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxconst 5000

void leerInfo();
void imprimirInfo();
void escribirConsulta();
void realizarConsulta();
int contarFilas();
void copiarEnArreglo();
void arregloaTXT();
int validarConsulta(/*seleccion*/);
void vaciarCadena(char c[maxconst]);

char seleccion[150], resp[1], c[5000];
int limiteInferior=10, contadorTokens=0, columnaSeleccionada;

int main(int argc, char *argv[]) {
	
	do{
		puts ("¿Desea agregar a un alumno a la base de datos? S/N");
		gets (resp);
		strupr(resp);
	}while(resp[0]!='S' && resp[0]!='N');
	
	if (strcmp (resp, "S")==0){
		system ("cls");
		leerInfo();
	}else{
		system ("cls");
		do{
			puts ("¿Desea realizar una consulta en la base de datos? S/N");
			gets (resp);
			strupr(resp);
		}while(resp[0]!='S' && resp[0]!='N');
		
		if (strcmp (resp, "S")==0){
			system ("cls");
			escribirConsulta();
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

void leerInfo(){
	
	char  matricula[10], nombres[50], apPat[20], apMat[20], campus[50], carrera[50], ing[20], deporte[20];
	int semestre[1];
	float prom[1];
	
	FILE * flujo = fopen("alumnos.txt","a");
	
	if (flujo==NULL){
		perror("ERROR EN LA CREACION DEL ARCHIVO\n\n");
	} else {
		puts ("Ingrese la matricula del alumno:");
		gets (matricula);
		strupr (matricula);
		puts ("Ingrese los nombres del alumno:");
		gets (nombres);
		strupr (nombres);
		puts ("Ingrese el apellido paterno del alumno:");
		gets (apPat);
		strupr (apPat);
		puts ("Ingrese el apellido materno del alumno:");
		gets (apMat);
		strupr (apMat);
		puts ("Ingrese el campus del alumno:");
		gets (campus);
		strupr (campus);
		puts ("Ingrese la carrera del alumno:");
		gets (carrera);
		strupr (carrera);
		puts ("Ingrese el semestre del alumno:");
		scanf ("%d", &semestre[0]);
		getchar();
		puts ("Ingrese el nivel de ingles del alumno:");
		gets (ing);
		strupr (ing);
		puts ("Ingrese el promedio del alumno:");
		scanf ("%f", &prom[0]);
		getchar();
		puts ("Ingrese el deporte del alumno:");
		gets (deporte);
		strupr (deporte);
		
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

void imprimirInfo(){
	
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

void escribirConsulta(){
	int valida;
	do{
		puts("Ingrese su consulta (NOTA: separar las condiciones seguido de un ;):");
		gets(seleccion);
		strupr(seleccion);
		valida=validarConsulta(/*seleccion*/);
	}while(valida==0);
	
}
	
int validarConsulta(/*seleccion*/){
	/*char validacion[29]="SELECCIONAR DONDE ORDENADO POR * COL";
	int i=0, j=0, aux=1, receptor;
	while ((seleccion[i]!='\0') && (aux!=0)){
		
		if (seleccion[i]!=validacion[j]){
			aux=0;
		}
		
		if(validacion[j]==' '){
			receptor=j;
		}
		
		j++;
		i++;
	}*/
	int aux=1;
	
	return aux;
}

void realizarConsulta(){
	
	int i=0, posicionNumero=0, posicionCondicional, auxiliar, filas, z, numFinal=0;
	char colsel[1], numero[2];
	
	filas=contarFilas();
	
	while (seleccion[i]!='\0'){
		if(seleccion[i]=='<' || seleccion[i]=='>' || seleccion[i]=='='){
			posicionCondicional=i;
			colsel[0]=seleccion[i-1];
			columnaSeleccionada=(int)colsel[0];
			columnaSeleccionada-=48;
			break;
		}
		i++;
	}
	
	switch(seleccion[posicionCondicional]){ //Seleccionar * donde col7<=4 ordenado por...
		case '<':
			auxiliar=1;
			if(seleccion[posicionCondicional+1]=='='){
				auxiliar=3;
			}else{
				if (seleccion[posicionCondicional+1]=='>'){
					auxiliar=5;
				}
			}
			break;
			
		case '>':
			auxiliar=2;
			if (seleccion[posicionCondicional+1]=='='){
				auxiliar=4;
			}
			break;
		case '=':
			auxiliar=6;
			break;
	}
	
	for (int k=0; k<filas; k++){
		copiarEnArreglo();
		
		switch (columnaSeleccionada){
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 8:
				//Código para comparar caracteres.
				break;
			case 7:
				z=posicionCondicional+1;
				while (z<(posicionCondicional+4)){
					if((seleccion[z]>=48)&&(seleccion[z]<=57)){
						numero[posicionNumero]=seleccion[z];
						posicionNumero++;
					}
					z++;
				}
				
				numFinal=atoi(numero);
				
				char ColumnaParaEvaluarSemestre[5];
				int u=0, d=1, s;
				
				//While para guardar la posición del arreglo "c" donde empieza a almacenar el valor del semestre a comparar que está en el txt.
				while (d<=columnaSeleccionada){
					if(c[u]=='|'){
						d++;
					}
					u++;
					if(d==columnaSeleccionada){
						s=u+1;
					}
				}
				
				//While para almacenar en un string el valor del semestre (en char) a comparar que se encuentra en el txt.
				u=0;
				while (c[s]!='|'){
					ColumnaParaEvaluarSemestre[u]=c[s];
					u++;
					s++;
				}
				
				//While para almacenar el vlor numérico del semestre.
				int r=0, valorColumnaParaComparar;
				posicionNumero=0;
				while (ColumnaParaEvaluarSemestre[r]!='\0'){
					if((ColumnaParaEvaluarSemestre[r]>=48)&&(ColumnaParaEvaluarSemestre[r]<=57)){
						numero[posicionNumero]=ColumnaParaEvaluarSemestre[r];
						posicionNumero++;
					}
					r++;
				}
				
				valorColumnaParaComparar=atoi(numero);
				
				switch (auxiliar){
					case 1:
						if(valorColumnaParaComparar<numFinal){
							arregloaTXT();
							puts(c);
						}
						break;
					case 2:
						if(valorColumnaParaComparar>numFinal){
							arregloaTXT();
							puts(c);
						}
						break;
					case 3:
						if(valorColumnaParaComparar<=numFinal){
							arregloaTXT();
							puts(c);
							
						}
						break;
					case 4:
						if(valorColumnaParaComparar>=numFinal){
							arregloaTXT();
							puts(c);
						}
						break;
					case 5:
						if(valorColumnaParaComparar!=numFinal){
							arregloaTXT();
							puts(c);
						}
						break;
					case 6:
						if(valorColumnaParaComparar==numFinal){
							arregloaTXT();
							puts(c);
						}
						break;
				}
				break;
			case 9:
				//Código para comparar floats
				break;
		}
	}
	printf("%d",contadorTokens);
}
	
void copiarEnArreglo(){
	vaciarCadena(c);
	char q;
	FILE * flujo = fopen ("alumnos.txt", "r");
	if (flujo==NULL){
		perror("No se pudo localizar el archivo");
		return;
	}
	int conta=0;
	while (feof(flujo)==0){
		q=fgetc(flujo);
		if(q=='|'){
			contadorTokens++;
		}
		
		if((contadorTokens>=limiteInferior)&&(contadorTokens<=(limiteInferior+10))){
			c[conta]=q;
			conta++;
		}
		
		if(contadorTokens==(limiteInferior+10)){
			limiteInferior+=10;
			break;
		}
		
	}
	
	fclose(flujo);
	return;
}
	
int contarFilas(){
	
	char p;
	
	FILE * flujo = fopen ("alumnos.txt", "r");
	if (flujo==NULL){
		perror("No se pudo localizar el archivo");
		return 10;
	}
	
	int contadorTotal=0, a;
	
	while (feof(flujo)==0){
		p=fgetc(flujo);
		if(p=='|'){
			contadorTotal++;
		}
	}
	
	a=contadorTotal/10;

	fclose (flujo);
	return a;
}

void arregloaTXT(){
	FILE * flujo2 = fopen ("consulta.txt", "a");
	fputs(c,flujo2);
	fputs ("\n", flujo2);
	fclose(flujo2);
}
	
	
void vaciarCadena(char c[maxconst]){
	int conta2 = 0;
	while (c[conta2] != '\0') {
		c[conta2]=0;
		conta2++;
	}
}
