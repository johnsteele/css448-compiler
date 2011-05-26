program errors(input,output);

type
   chararray = array [0..30] of char;
   student = record
      id: integer;
      name: chararray
   end;

var
   somestudent: student;
   i, j: integer;
   x, y, z: real;

begin                  
   (* every line has at least one undefined variable in it *)
   read(classNum);
   k := n * m;
   size := 10;
   somestudent.gpa := 4.0;
   for i := 1 to size do          
     insert(list, newrec);
   writeln('Yet another undefined variable:', undefined); 
   displayInfo;

   (* every line has a type checking error in it *)
   y := i mod x;    
   y := x mod i;    
   y := i div x;    
   y := x div i;    
   z := x mod y;    
   z := x div y; 
   x := "string cannot be assigned to real";
   i := "string cannot be assigned to integer";
   if i > true then write('hello world');
end.


