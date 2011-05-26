program setstuff(input, output);

(*** Demonstrate the set datatype. ***)

type
   Digit = set of 0..9;

var
   odds, evens, stuff, morestuff: Digit;

begin
   odds := [1, 3, 5, 7, 9];
   evens := [0, 2, 4, 6, 8];
   stuff := [];                (* empty set *)
   morestuff := odds + [2];    (* union of 2 sets *)

   if 3 in morestuff then
      writeln("3 in the set")
   else
      writeln("3 not in the set");

   if 4 in morestuff then
      writeln("4 in the set")
   else
      writeln("4 not in the set");
end.

