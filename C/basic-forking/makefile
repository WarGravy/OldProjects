#macros
Compiler=gcc
FileName=PA1_577343
Header=header

#targets: dependencies and commands
$(FileName).out: 		$(FileName).o 
				$(Compiler) -o $(FileName).out $(FileName).o

$(FileName).o:			$(FileName).c $(Header).h
				$(Compiler) -c $(FileName).c

clean:				
				-rm *.o $(FileName).out

