program harderror(input, output);
type
   cellPtr = ^cell;
   anotherPtr = ^junk;                    (* junk never gets defined *)
   cell = record
      id: integer;
      next: cellPtr;
      junkPtr: anotherPtr                 (* type not defined *)
   end;

var
   list: cellPtr;

begin
end.                                   (* scopeExit example *)

