create table Funcionario(
    idFuncion integer not null,
    nomeFuncion    Varchar(32) not null,
    salario    integer not null,
    Primary Key (idFuncion)
);

create table Aeronave(
    idAero    integer not null,
    nomeAero    Varchar(32) not null,
    distLimite    integer not null,
    Primary Key (idAero)
);

create table Voos(
    nroVoo    integer not null,
    origem    Varchar(32) not null,
    destino    VarChar(32) not null,
    preco    integer not null,
    distancia    integer not null,
    Primary Key (nroVoo)
);

create table Certificado(
    idFuncion    integer not null,
    idAero    integer,
    Primary Key (idFuncion, idAero),
    Foreign Key (idFuncion) references Funcionario(idFuncion),
    Foreign Key (idAero) references Aeronave(idAero)
);


