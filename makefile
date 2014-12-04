#macros
Compiler=g++
FileName=main
Header=header

#targets: dependencies and commands
$(FileName).out: 		$(FileName).o 
						$(Compiler) -o $(FileName).out $(FileName).o

$(FileName).o:			$(FileName).c $(Header).h
						$(Compiler) -c $(FileName).c

clean:				
				-rm *.o $(FileName).out

