program arrays2(input,output);

type
  array1D = array ['a'..'e'] of integer;

var
  a: array1D;
  i: char;

begin
   for i := 'a' to 'e' do
   begin
      a[i] := i;
      write(a[i], " ");
   end;
   writeln;
end.

