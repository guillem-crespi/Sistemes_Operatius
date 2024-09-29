#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void main() {
   
    MYSQL *conn;
    int err;
    MYSQL_RES *result;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error creating connection: %u %s\n", 
		mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    conn = mysql_real_connect(conn, "localhost", "root", "mysql", "Jugadas", 0, NULL, 0);
    if (conn == NULL) {
        printf("Error initializing connection: %u %s\n", 
		mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

	//Jugador 1
    strncpy(query, "SELECT participation.posicion FROM participation WHERE idJugador = 1");

    err = mysql_query(conn, query);
    if (err != 0) {
        printf("Error while querying data from database: %u %s\n", 
		mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);
    int posJ1 = row[0];
    mysql_free_result(result);

	//Jugador 2
    strncpy(query, "SELECT participation.posicion FROM participation WHERE idJugador = 2");

    err = mysql_query(conn, query);
    if (err != 0) {
        printf("Error while querying data from database: %u %s\n", 
		mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);
    int posJ2 = row[0];
    mysql_free_result(result);

   
    int diferencia = abs(posJ1 - posJ2);
    printf("La diferència de punts entre els dos jugadors és de: %d\n", diferencia);

  
    mysql_close(conn);

    return 0;
}

