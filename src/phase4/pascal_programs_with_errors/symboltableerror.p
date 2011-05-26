program example(input, output);     (* program example with more errors *)
const  
   grades = 5;
   size = 4;
type 
   int3D = array [1..5,2..3,0..2] of integer;
   cellPtr = ^cell;
   cell = record 
      id: integer;
      info: int3D;
      id: real;                           (* produce error: id exists *)
      next: cellPtr;
      info: undefinedType                 (* redefine and type not defined *)
   end;
   anotherPtr = ^junk;                    (* junk never gets defined *)
   Digit = set of 0..9;
var  
   list: cellPtr;
   newrec: cellPtr;
   ptr: anotherPtr;                       (* problem with anotherPtr *)
   mycount: int3D;
   theSet: digit;                         (* okay, handle lower/uppercase *)
   classNum: integer;
   aaa: undefinedType;                    (* error, not defined *)

   procedure proc1(var list: cellPtr;     (* scopeEntry proc1 *)
                   var theA: int3D;
                       theA: integer;     (* redefine error *)
                       something: junk;   (* undefined type *)
                        rec: cellPtr);
   var  
      mycount: integer;
      x1: integer;
      y: integer;
      rec: cellPtr;                       (* redefine *)
   begin
   end;                                   (* scopeExit proc1 *)

   procedure proc2;                       (* scopeEntry proc2 *)
   var  
      mycount: int3D;
      x2: integer;
      y: integer;
      z: integer;
      y: integer;                          (* redefine *)
      x2: integer;                         (* redefine *)

      procedure proc2a;                       (* scopeEntry proc2a *)
      var  
         mycount: int3D;
         x2a: integer;
         y: integer;
         z: integer;
         x2a: integer;                        (* redefine *)

         procedure proc2b;                        (* scopeEntry proc2b *)
         var  
            x2b: integer;
            y: integer;
            x2b: integer;                         (* redefine *)
   
            procedure proc2c;                        (* scopeEntry proc2c *)
            const
               someConst = 10; 
               theConst = 20;
            var  
               x2c: integer;
               y: integer;
               x2c: real;                            (* redefine *)

               function func2d(                         (* scopeEntry func2d *)
                  newrec: cellPtr): integer;
               var
                  a: array [5..10] of real;
                  b: yetAnotherUndefinedType;           (* undefined type *)
               begin
               end;                                     (* scopeExit func2d *)

            begin
            end;                                    (* scopeExit proc2c *)
         begin
         end;                                    (* scopeExit proc2b *)
      begin
      end;                                    (* scopeExit proc2a *)
   begin
   end;                                    (* scopeExit proc2 *)
begin                                
end.                                   (* scopeExit example *)

