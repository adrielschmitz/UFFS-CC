1) create table Certificado(
    idFuncion    integer not null,
    idAero    integer,
    Primary Key (idFuncion, idAero),
    Foreign Key (idFuncion) references Funcionario(idFuncion),
    Foreign Key (idAero) references Aeronave(idAero)
);

2) insert into Certificado values (1, 2);

3) 
a) select count(nomeFuncion) from Funcionario where salario > 500;
b) select nomeFuncion from ((Funcionario f join Certificado c on f.idFuncion=c.idFuncion) join Aeronave a on c.idAero=a.idAero) where nomeAero = 'Space Pod';
c) select * from (Funcionario f join Certificado c on f.idFuncion=c.idFuncion) where idAero is not null;
d) select * from (Funcionario f left join Certificado c on f.idFuncion=c.idFuncion) where idAero is null;
e) select * from (Voos v full join Aeronave a on a.distLimite=v.distancia) where (origem='Chapecó') and (destino='Xaxim') and (distancia < (select distLimite from Aeronave));
f) select count(nomeFuncion) from (Certificado c join Funcionario f on c.idFuncion=f.idFuncion) where nomeFuncion = 'Rubens Barrichello';

4) 
a) select nomeFuncion, salario from Funcionario;
b) select nomeAero from Aeronave where distLimite > 500
c) select nomeFuncion, idFuncion from (Funcionario f join Certificado c on f.idFuncion=c.idFuncion) where idAero is not null;