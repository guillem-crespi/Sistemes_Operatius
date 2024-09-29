DROP DATABASE IF EXISTS JUGADAS;
CREATE DATABASE JUGADAS;
USE JUGADAS;

--Tablas--
CREATE TABLE  Jugador (
	idJugador integer NOT NULL,
	nombre varchar(20) NOT NULL,
	contraseña varchar(6) NOT NULL
);

CREATE TABLE  Partido (
	idPartido integer NOT NULL,
	fecha varchar(10) NOT NULL,
	duracion float NOT NULL,
	ganador integer,
	FOREIGN KEY (ganador) REFERENCES Jugador(idJugador)
);

CREATE TABLE participation(
	idJugador int,
	idPartido int,
	posicion int,
	FOREIGN KEY (idJugador) REFERENCES Jugador(idJugador),
	FOREIGN KEY (idPartido) REFERENCES Partido(idPartido)
);
--Insertamos datos en las tablas--
	INSERT INTO Jugador VALUES(1, 'Luis', 'Escuela');
	INSERT INTO Jugador VALUES(2, 'Marta', 'Libro');

	INSERT INTO Partido VALUES(1,'31/12/2024', 10, 1 );

	INSERT INTO participation VALUES (1,1,10);
	INSERT INTO participation VALUES (2,1,5);



