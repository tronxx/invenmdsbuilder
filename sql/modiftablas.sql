
CREATE TABLE inv_edoanu (
	idedoanu	integer not null primary key,
	idart		integer not null,
	anu		integer not null,
	inicias		double precision,
	entrans		double precision,
	salens		double precision,
	inician		double precision,
	entrann		double precision,
	salenn		double precision,
	cia		integer not null
);

create table inv_edoinvanu (
	idedoinvanu		integer not null primary key,
	idart			integer not null,
	anu			integer not null,
	eos			varchar(1) not null,
	status			integer not null,
	tipomov			integer not null,
	canti			double precision,
	cia			integer not null
);

create index inv_edoinvanu_x01 on inv_edoinvanu (idart);

create table inv_exianu	(
	idexianu		integer not null primary key,
	idart			integer not null,
	idalm			integer not null,
	anu			integer not null,
	inicias		double precision,
	entrans		double precision,
	salens		double precision,
	inician		double precision,
	entrann		double precision,
	salenn		double precision,
	cia		integer not null
);
	
create table inv_edoexianu (
	idedoexianu		integer not null primary key,
	idart			integer not null,
	idalm			integer not null,
	anu			integer not null,
	eos			varchar(1) not null,
	status			integer not null,
	tipomov			integer not null,
	canti			double precision,
	cia			integer not null
);

---- Modificaciones del 21-Dic-2007 ------
---- Para agregar captura de relacion de ventas ----

create table inv_polizrelvta (
	idpolizrelvta		integer not null primary key,
	idubica			integer not null,
	fecha			date,
	feccap			timestamp,
	cia			integer not null,
	unique (idubica, fecha)
);

create table inv_relvtas (
  idrelvtas		integer not null primary key,
  folio			integer not null,
  fecha			date,
  hora			integer,
  idnombre		integer,
  tipocte		varchar(2),
  idtipoentrega		integer not null,
  ptovta		varchar(4),
  fechaent		date,
  entrega		varchar(3),
  vendedor		varchar(3),
  idpoblac		integer not null,
  idusuario		integer,
  feccap		timestamp,
  cia			integer not null,
  unique (folio, cia)
);

create index inv_relvtas_x01 on inv_relvtas ( idpoliza);


create table inv_tipoentrega (
  idtipoentrega		integer not null primary key,
  codigo		varchar(4) not null,
  descri		varchar(30),
  cia			integer not null,
  unique (codigo, cia)
);

create table inv_dirvta (
  iddirvta		integer not null primary key,
  idrelvtas		integer not null,
  idconcep		integer not null,
  conse			integer not null
);

create table inv_relvtaart (
	idrelvtaart		integer not null primary key,
	idrelvtas		integer not null,
	idart			integer not null,
	salede			varchar(4),
	preciolista		double precision,
	conse			integer not null
);


alter table inv_relvtaart add column idcodigo integer;
commit work;

alter table inv_relvtaart add column iddescri integer;
commit work;

alter table inv_relvtaart add column idreltransf integer;
commit work;

create table inv_reltransf (
	idreltransf		integer not null primary key,
	fecha			date,
	folio			integer not null,
	idusuario		integer not null,
	hora			integer,
	fechaini		date,
	horaini			integer,
	fechafin		date,
	horafin			integer,
	almenv			varchar(4),
	almrec			varchar(4),
	feccap			timestamp,
	cia			integer not null
			);

create table inv_datreltransf (
	iddatreltransf		integer not null primary key,
	idreltransf		integer not null,
	idrelvtaart		integer not null,
	cia			integer not null
			);

CREATE TABLE CAR_TIPOSCTES (
       IDTICTE INTEGER NOT NULL,
       IDTIPOCAR INTEGER NOT NULL,
       IDQOM INTEGER NOT NULL,
       TICTE VARCHAR(2),
       DESCRI VARCHAR(30),
       TASACOM DOUBLE PRECISION(15) NOT NULL,
       CIA INTEGER NOT NULL,
       PRIMARY KEY (IDTICTE)
)
;

insert into inv_tipoentrega ( idtipoentrega, codigo, descri, cia )
values ( 1, 'PRM', 'ENTREGA PROMOTOR', 1);
insert into inv_tipoentrega ( idtipoentrega, codigo, descri, cia )
values ( 2, 'OCU', 'EL CLIENTE LO LLEVA', 1);
insert into inv_tipoentrega ( idtipoentrega, codigo, descri, cia )
values ( 3, 'EMB', 'ENTREGA EMBARQUES', 1);
insert into inv_tipoentrega ( idtipoentrega, codigo, descri, cia )
values ( 4, 'FOR', 'CHOFER FORANEO', 1);

----- Consultas -----
--/ select b.salede, a.ptovta, d.codigo, d.descri, count(*)
--/ from inv_relvtas a join inv_relvtaart b
--/ on a.idrelvtas = b.idrelvtas
--/ join inv_invhist c on b.idart  = c.idart
--/ join inven d on c.codigo = d.codigo and c.cia = d.cia
--/ group by b.salede, a.ptovta, d.codigo, d.descri;

--/ select a.entrega, d.codigo, d.descri, count(*)
--/ from inv_relvtas a join inv_relvtaart b
--/ on a.idrelvtas = b.idrelvtas
--/ join inv_invhist c on b.idart  = c.idart
--/ join inven d on c.codigo = d.codigo and c.cia = d.cia
--/ group by a.entrega, a.ptovta, d.codigo, d.descri;

--/ select * from promotor;
---------------------------------

-- Enero 2008 Modificaciones para agregar varios numeros de Telefono de Mayoristas -----
--create table may_relac (
--      idrelac         integer not null primary key,
--      idmayoris       integer,
--      mayoris         varchar(4),
--      idtiporel       integer,
--      iddato1         integer,
--      iddato2         integer,
--      cia             integer
--);


--create index may_relac_x01 in may_relac ( mayoris);
--create index may_relac_x02 in may_relac ( idmayoris);


--create table may_datosrel (
--      idmaydatosrel           integer not null primary key,
--      dato                    varchar(70) not null unique
--);

--create table may_tiposrel (
--      idtiporel               integer not null primary key,
--      descri                  varchar(30) not null unique
--);

--create table may_tipostel (
--      idtipotel               integer not null primary key,
--      descri                  varchar(30) not null unique
--);


--CREATE TABLE TELFAX (
--      IDTEL INTEGER NOT NULL,
--      TELFAX VARCHAR(50) NOT NULL,
--      PRIMARY KEY (IDTEL),
--      UNIQUE (TELFAX)
--);

--delete from may_tiposrel;
--delete from may_tipostel;
--insert into may_tiposrel ( idtiporel, descri ) values ( 160, 'TELEFONOS');
--commit work;


---- 20 Feb 2008  Modificaciones para grabar auxiliar en inv_relvtas --

---- 26 Feb 2008 -----
"CREATE PROCEDURE OLDBUSCONCEP (CONCEP VARCHAR(30) )
   RETURNS (NCON INTEGER, CONCEPTO VARCHAR(30))
   BEGIN
   EXEC SQL PREPARE BUSCONCEP1 SELECT NCON FROM CONCEPS WHERE CONCEPTO = ?;
   EXEC SQL PREPARE BUSCONCEP2  SELECT MAX(NCON) FROM CONCEPS WHERE NCON > 0;
   EXEC SQL PREPARE BUSCONCEP3 INSERT INTO CONCEPS (NCON, CONCEPTO) VALUES (?,?);
   EXEC SQL EXECUTE BUSCONCEP1 USING (CONCEP) INTO (NCON);
   EXEC SQL FETCH BUSCONCEP1;
   IF SQLSUCCESS = 1  THEN
       CONCEPTO := CONCEP;
       RETURN ROW;
   ELSE
     EXEC SQL EXECUTE BUSCONCEP2 INTO (NCON);
     EXEC SQL FETCH BUSCONCEP2;
     IF NCON IS NULL THEN
       NCON := 0;
     END IF
     NCON := NCON + 1;
     EXEC SQL EXECUTE BUSCONCEP3 USING (NCON, CONCEP);
     CONCEPTO :=CONCEP;
     RETURN ROW;
  END IF
  EXEC SQL DROP BUSCONCEP1;
  EXEC SQL DROP BUSCONCEP2;
  EXEC SQL DROP BUSCONCEP3;
   END
";

"CREATE PROCEDURE GRABA_IDCONCEP_RELVTAART 
   RETURNS (idrelvtaart_z integer, idart_z integer, codigo_z varchar(13), descri_z varchar(30), idcodigo_z integer, iddescri_z integer)
begin
   exec sql prepare busrelvta1 select a.idrelvtaart, a.idart, b.codigo, b.descri
   			from inv_relvtaart a join inv_invhist c on a.idart = c.idart
   			join inven b on c.codigo = b.codigo and c.cia = b.cia;
   exec sql prepare busidcod call oldbusconcep (?);
   exec sql prepare busiddes call oldbusconcep (?);
   exec sql prepare actualiza_relvtaart update inv_relvtaart 
   		set idcodigo = ?, iddescri = ? where idrelvtaart = ?;
   exec sql execute busrelvta1 into ( idrelvtaart_z, idart_z, codigo_z, descri_z);
   exec sql fetch   busrelvta1;
   while sqlsuccess loop
     exec sql execute busidcod using ( codigo_z ) into ( idcodigo_z );
     exec sql fetch   busidcod;
     exec sql execute busidcod using ( descri_z ) into ( iddescri_z );
     exec sql fetch   busidcod;
     exec sql execute actualiza_relvtaart using ( idcodigo_z, iddescri_z, idrelvtaart_z);
     return row;
     
     exec sql fetch   busrelvta1;
   end loop;
   exec sql drop busrelvta1;
   exec sql drop busidcod;
   exec sql drop busiddes;
   exec sql drop actualiza_relvtaart;
end";
