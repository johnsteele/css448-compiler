program funcerror(input,output);

const
   size = 10;

type
   array1D = array [1..10] of integer;

var
   list: array1D;
   mycount: integer;
   i, j, k: integer;

(* ************************************************************************* *)
(* procedure readlist                                                        *)
(* ************************************************************************* *)

procedure readlist(var list: array1D;
                       size: integer);
var
    i: integer;

begin
    for i := 1 to size do 
       read(list[i])
end;

(* ************************************************************************* *)
(* function average                                                          *)
(* ************************************************************************* *)

function average(list: array1D; size: integer): integer;   
var
    i, sum : integer;

begin
    sum := 0;
    for i := 1 to size do
       sum := sum + list[i];
    average := sum div size;
end;

(* ************************************************************************* *)
(* function junk                                                          *)
(* ************************************************************************* *)

function junk(list: array1D; size: integer): integer;   
begin
end;

(* ************************************************************************** *)
(* main program                                                               *)
(* ************************************************************************** *)

begin
  writeln('Here are the numbers:'); writeln;
  for mycount := 1 to size do 
  begin
    writeln(list[mycount])
  end;
  writeln("average = ", average(list, size));

  i := 10;
  j := 20;
  junk := i + j;               (* illegal function on left *)
  junk(i,j) := i + j;          (* illegal function on left *)
  read(junk, junk(i,j))        (* illegal function in read *)
end.


