

#ifndef FUNARRG_ARCHCSV_H
#define FUNARRG_ARCHCSV_H

#ifdef __cplusplus
extern "C" {
#endif
/*
 * FUNCION QUE DEVUELVE UN ARREGLO DE STRING, LUEGO DE LEER EL
 * ARCHIVO CSV
 *
 * LOS PARAMETROS SON:
 *
 * dir= El cual es un puntero al path en donde se encuentra el archivo csv
 * rows= Son las filas con las cuales cuenta el archivo csv
 * cols= Son las columnas con las cuales cuenta el archivo cvs
 *
 * RETORNA:
 * UN PUNTERO TRIPLE, QUE HACE REFERENCIA A UNA MATRIZ DEL TIPO STRING CON TODO
 * LO QUE CONTIENE EL ARCHIVO CSV
 *
 */
char ***parseCsvFile(char *dir, int rows, int cols) {

  FILE *csvfile = fopen(dir, "r"); // se abre el archivo para su lectura
  char lines[rows][1024];          // Se crea arreglo para almacenar los datos

  for (int i = 0; i < rows;
       i++) { // se lee linea por linea y se almacena en el arreglo
    fscanf(csvfile, "%s,", lines[i]);
  }

  char ***stringmat =
      malloc(rows * sizeof(char **)); // Se crea una "matriz" para poder retorna
  for (int i = 0; i < rows; i++) {    // poder retornar la matriz tipo string
    stringmat[i] = malloc(cols * sizeof(char *));
  }

  for (int i = 0; i < rows; i++) {

    char *token = strtok(
        lines[i], ","); // se crea un token que separa las columnas del csv
    int j = 0;
    while (token != NULL) {
      stringmat[i][j] = malloc(strlen(token) * sizeof(char));
      strcpy(stringmat[i][j],
             token); // se almacena cada una de las columnas en el token
      token = strtok(NULL, ",");
      j++;
    }
  }

  return stringmat; // se retorna el arreglo de tipo string que contiene todos
                    // los datos
}

/*
 * FUNCION (COMPLEMENTARIA A LA ASIGNACION DEL PARCIAL) QUE DEVUELVE TODOS LOS
 * CARNETS DE LOS ESTUDIANTES PARAMETROS:
 *
 * ***mtrFile=Es un puntero triple que contiene el arreglo retornado
 * posiblemente por la funcion parseCsvFile
 * rows=El numero de filas qu genero el arreglo
 * cols=El numero de columnas que genero el arreglo
 *
 * RETORNA:
 *
 * UN PUNTERO DOBLE CON EL CARNET DE LOS ESTUDIANTES
 */
char **getsTitlesRows(char ***mtrFile, int rows, int cols) {

  char **getsRows = (char **)malloc(
      rows * sizeof(char *)); // se genera una reserva de memoria
  // con el objetivo de generar una matriz
  // dinamica
  for (int i = 0; i < rows - 1; i++) {
    getsRows[i] =
        mtrFile[i + 1]
               [0]; // se "almacena" los elementos pertenecientes a la columna 0
  }
  return getsRows; // se retorna dicho arreglo
}

/*
 * FUNCION (COMPLEMENTARIA A LA ASIGNACION DEL PARCIAL) QUE DEVUELVE TODOS LOS
 * NOMBRES DE LAS PELICULAS PARAMETROS:
 *
 * ***mtrFile=Es un puntero triple que contiene el arreglo retornado
 * posiblemente por la funcion parseCsvFile
 * rows=El numero de filas qu genero el arreglo
 * cols=El numero de columnas que genero el arreglo
 *
 * RETORNA:
 *
 * UN PUNTERO DOBLE CON EL NOMBRE DE LA PELICULA
 */
char **getsTitlesCols(char ***mtrFile, int rows, int cols) {

  char **getsCols = (char **)malloc(
      cols * sizeof(char *)); // se genera una reserva de memoria
  // con el objetivo de generar una matriz
  // dinamica
  for (int i = 0; i < cols - 1; i++) {
    getsCols[i] =
        mtrFile[0][i +
                   1]; // se "almacena" los elementos pertenecientes a la fila 0
  }
  return getsCols; // se retorna dicho arreglo
}

/*
 * FUNCION QUE OBTIENE LOS RESULTADOS DE LA ENCUESTA IGNORANDO LAS COLUMNA Y
 * FILA DE TEXTO (LA COLUMNA DEL NUMERO DE CARNET Y NOMBRE DE PELICULAS)
 *
 * PARAMETROS:
 * ***mtrFile=Es un puntero triple que contiene el arreglo retornado
 * posiblemente por la funcion parseCsvFile
 * rows=El numero de filas qu genero el arreglo
 * cols=El numero de columnas que genero el arreglo
 *
 * RETORNA:
 *
 * UN PUNTERO DOBLE, QUE REPRESENTA LOS DIGITOS OBTENIDOS DEL CSV
 */
int **getsResultPoll(char ***mtrFile, int rows, int cols) {

  int **getsPoll = (int **)malloc(
      rows * sizeof(int *)); // se reserva memoria para "matris dinamica"

  for (int i = 0; i < rows; i++) {
    getsPoll[i] = (int *)malloc(cols * sizeof(int));
  }

  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < cols; ++j) {
      getsPoll[i - 1][j - 1] =
          atoi(mtrFile[i][j]); // se asigna cada elemento y conviertiendolo en
                               // int a la "matriz"
    } // iniciando desde [1][1]
  }

  return getsPoll; // se retorna matriz obtenida
}

/*FUNCIONE QUE TRANSPONE UNA MATRIZ, ES IMPORTANTE RECALCAR QUE SI ES UNA MATRIZ
 * POR EJEMPLO DE 2X3 AL TRANSPONERLA SE CONVIERTE EN UNA DE 3X2 ES DECIR
 * INTERCAMBIA FILAS POR COLUMNAS CON LA MATRIZ ORIGINAL
 *
 * PARAMETROS:
 * **mtr=Es un puntero doble a una matriz
 *  filas=Numero de filas
 *  Columnas= Numero de columnas
 *
 * RETORNA:
 * UN PUNTERO DOBLE CON LA MATRIZ YA TRANSPUESTA
 *
 *
 */
int **transponer_mtr(int **mtr, int filas, int columnas) {

  int **tran_mtr = (int **)malloc(filas * sizeof(int *));

  for (int i = 0; i < filas; i++) {
    tran_mtr[i] = (int *)malloc(columnas * sizeof(int));
  }

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      tran_mtr[j][i] = mtr[i][j];
    }
  }

  return tran_mtr;
}

/*
 * FUNCIONE QUE MULTIPLICA UNA MATRIZ A POR UNA MATRIZ B RECORDANDO LAS
 * SIGUIENTES CONDICIONES LAS COLUMNAS DE A TIENEN QUE SER IGUAL QUE B, EN CASO
 * CONTRARIO LA FUNCION DEVUELVE EL VALOR DE 1 HACIENDO REFERENCIA A QUE OCURRIO
 * UN ERROR, ADEMAS RECORDAR LO SIGUIENTE: 1.EL NUMERO DE FILAS DE A SERA EL
 * NUMERO DE FILAS DE LA MATRIZ RESULTANTE 2.EL NUMERO DE COLUMNAS DE B SERA EL
 * NUMERO DE COLUMNAS DE LA MATRIZ RESULTANTE 3.EN EL ALGEBRA LINEAL NO SE
 * CUMPLE EL PRINCIPIO CONMUTATIVO DE LA MULTIPLICACION DE LA ARTIMETICA
 * ELEMENTAL, POR LO QUE AXB ES DIFERENTE A BXA
 *
 * PARAMETROS:
 * **mtr_A=Es un puntero doble a una matriz
 * **mtr_B=Es un puntero doble a una matriz
 *  filas_A=Numero de filas de la matriz A
 *  Columnas_A= Numero de columnas de la matriz A
 *  filas_B=Numero de filas de la matriz B
 *  Columnas_B= Numero de columnas de la matriz B
 *
 * RETORNA:
 * Un puntero a una matriz de dimensiones (filas_A X columnas_B)
 *
 *
 */
int **multiplicar_mtr(int **mtr_A, int **mtr_B, int filas_A, int columnas_A,
                      int filas_B, int columnas_B) {

  if (columnas_A == filas_B) {
    int **result_mtr = (int **)malloc(filas_A * sizeof(int *));

    for (int i = 0; i < filas_A; i++) {
      result_mtr[i] = (int *)malloc(columnas_B * sizeof(int));
    }

    for (int i = 0; i < filas_A; i++) {
      for (int j = 0; j < columnas_A; j++) {
        for (int k = 0; k < columnas_B; k++) {
          result_mtr[i][k] += mtr_A[i][j] * mtr_B[j][k];
        }
      }
    }
    return result_mtr;
  } else {
    return 1;
  }
}

/*FUNCION COMPLEMENTARIA QUE MUESTRA LO QUE CONTIENEN LOS ARREGLOS DECLARADOS
 * POR OTRAS FUNCIONES
 *
 * PARAMETROS:
 * **mtr=Puntudero doble de la matriz a obsercar
 * filas=numero de filas
 * columnas=numero de columnas
 *
 */
void ver_mtr(int **mtr, int filas, int columnas) {

  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      printf("%d\t", mtr[i][j]);
    }
    printf("\n");
  }
}

/*FUNCION QUE RETORNA EL CARNET DE LOS ESTUDIANTES QUE DESARROLLARON
 * ESTAS FUNCIONES
 */
const char *integrantes() {

  char *carnetIntegrante = "#gs2002, #pr20028";

  return carnetIntegrante;
}

#ifdef __cplusplus
}
#endif

#endif /* FUNARRG_ARCHCSV_H */
