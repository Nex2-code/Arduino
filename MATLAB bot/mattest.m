%MATLAB Code for Serial Communication between Arduino and MATLAB
clear all
clc
x=serial('COM13','BAUD', 9600);

fopen(x);
go = true;
while go
                 
a= input('Press 1 to turn ON LED & 0 to turn OFF:');
fprintf(x,a);  

if (a == 2)
  go=false;
end
end