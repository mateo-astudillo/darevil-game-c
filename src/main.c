#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum cmd {
	left = 1,
	rigth,
	up,
	down
};

typedef struct {
	int row;
	int col;
} POSITION;

typedef struct {
	POSITION pos;
	int command;
} QUERY;

int get_int(int min, int max, char *text) {
	char temp[16];
	int num = min - 1;
	while (num < min || num > max) {
		printf(" %s\n (%d a %d)\n > ", text, min, max);
		scanf("%s", temp);
		num = atoi(temp);
	}
	return num;
}

char get_char() {
	char c[32];
	while (c[0] != 'X' && c[0] != '.') {
		printf(" Insert \"X\" para enemigo y \".\" si no hay nadie\n > ");
		scanf(" %s", c);
	}
	return c[0];
}

void preview(char *map, int r, int c) {
	system("clear");
	//system("cls");
	for (int i = 0; i < c; i++)
		printf("  %d ", i + 1);
	printf("\n");
	for (int i = 0; i < (r * c); i++) {
		printf(" [%c]", map[i]);
		if ( (i + 1) % c == 0 )
			printf(" %d\n", (i + 1) / c);
	}
	printf("\n");
}

int compare_command(char *command) {
	int user_cmd = 0;
	char *commands[] = {
		"IZQUIERDA",
		"DERECHA",
		"ARRIBA",
		"ABAJO"
	};
	char *short_commands[] = {
		"iz",
		"de",
		"ar",
		"ab"
	};
	int s = sizeof(commands) / sizeof(*commands);
	for (int i = 0; i < s; i++) {
		if ( !strcmp( command, commands[i] ) || !strcmp( command, short_commands[i]) ) 
			user_cmd = i + 1;
	}
	return user_cmd;
}

int distance_of_enemy(char *map, QUERY q, int rows, int cols) {
	int distance = 0,
		increase = 0,
		stop = 0,
		counter = 0,
		position = ( (q.pos.row - 1) * cols ) + q.pos.col - 1; // -1 por cada dato
	char cmd[16];
	printf(" Posicion: %d-%d\n", q.pos.row, q.pos.col);
	switch (q.command) {
		case left:
			strcpy( cmd, "Izquierda");
			increase = -1;
			stop = cols - (cols - q.pos.col); 
			break;
		case rigth:
			strcpy( cmd, "Derecha");
			increase = 1;
			stop = cols - q.pos.col; 
			break;
		case up:
			strcpy( cmd, "Arriba");
			increase = -cols;
			stop = q.pos.row; 
			break; 
		case down:
			strcpy( cmd, "Abajo");
			increase = cols;
			stop = rows - q.pos.row; 
			break;
	}
	for (int i = 1; i < stop; i++) {
		position += increase;
		if ( map[position] == 'X' )
			distance = i;
	}
	printf(" Orden: %s\n", cmd);
	return distance;
}

int main() {
	int rows,
		columns,
		queries,
	  distance;
	rows = get_int(1, 100, "Filas");
	columns = get_int(1, 100, "Columnas");
	int t = rows * columns;
	char *map = malloc(t);
	
	for (int i = 0; i < t; i++) {
		map[i] = get_char();
		preview(map, rows, columns);
	}

	queries = get_int(1, 100, "Cantidad de consultas");
	QUERY q[queries];
	char user_command[16];
	for (int i = 0; i < queries; i++) {
		printf(" Inserte la posicion\n");
		q[i].pos.row = get_int(1, rows, "Fila");
		q[i].pos.col = get_int(1, columns, "Columna");
		do {
			printf(" Orden:\n > ");
			scanf("%s", user_command);
		} while( !compare_command(user_command) );
		q[i].command = compare_command(user_command);
		preview(map, rows, columns);
	}

	preview(map, rows, columns);
	for (int i = 0; i < queries; i++) {
		distance = distance_of_enemy(map, q[i], rows, columns);
		if (distance) 
			printf(" Enemigo a %d\n\n", distance);
		if (!distance)
			printf(" NINGUNO\n\n");
	}

	free(map);
	return 0;
}
