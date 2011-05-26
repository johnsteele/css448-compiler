program arrayerror(input,output);

(* Illegal to have string subscripts in array *)
(* Error that must be caught through action code, passes grammar *)
(* All of these are illegal *)

type
  array1 = array ['abcd'..'xyz'] of integer;
  array2 = array [5 .. 1] of integer;
  array3 = array [1 .. 8.5] of integer;
  array4 = array [2.6 .. 8.5] of integer;
  array5 = array ['ab' .. 8.5] of integer;

var
  a: array1;
  i: char;

begin
   for i := 'abcd' to 'xyz' do
   begin
      a[i] := i;
      write(a[i], " ");
   end;
   writeln;
end.

