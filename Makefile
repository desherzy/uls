#CLANG = clang -std=gnu11 -Wall -Wextra -Werror -Wpedantic
CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
OD = obj
EFN = uls

all: install clean

install: 
	@make install -sC libmx
	@${CLANG} -L./libmx -o ${EFN} ${SF} -lmx #-lacl

uninstall: clean
	@make uninstall -sC libmx
	@rm -f ${EFN}

clean:
	@make clean -sC libmx
	@rm -rdf ${OD} 

reinstall: uninstall install clean 


