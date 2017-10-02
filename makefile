server: server.c program.h client.c
	gcc -o server server.c
	gcc -o client client.c

.PHONY: clean run
clean:
	rm server client
usage:
	@echo make
	@echo server \"Data to be shared\"
	@echo cilent
