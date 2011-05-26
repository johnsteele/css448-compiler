program example(input, output);     (* program example *)
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
      next: cellPtr
   end;
   Digit = set of 0..9;
var  
   list: cellPtr;
   newrec: cellPtr;
   mycount: int3D;
   classNum: integer;

   procedure proc1(var list: cellPtr;     (* scopeEntry proc1 *)
                   var theA: int3D;
                        rec: cellPtr);
   var  
      mycount: integer;
      x1: integer;
      y: integer;
   begin
   end;                                   (* scopeExit proc1 *)

   procedure proc2;                       (* scopeEntry proc2 *)
   var  
      mycount: int3D;
      x2: integer;
      y: integer;
      z: integer;
      y: integer;                          (* produce error: y exists *)

      procedure proc2a;                       (* scopeEntry proc2a *)
      var  
         mycount: int3D;
         x2a: integer;
         y: integer;
         z: integer;

         procedure proc2b;                        (* scopeEntry proc2b *)
         var  
            x2b: integer;
            y: integer;
   
            procedure proc2c;                        (* scopeEntry proc2c *)
            const
               someConst = 10; 
               theConst = 20;
            var  
               x2c: integer;
               y: integer;
               x2c: integer;          (* produce error: x2c exists *)

               function func2d(                         (* scopeEntry func2d *)
                  newrec: cellPtr): integer;
               var
                  a: array [5..10] of real;
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

