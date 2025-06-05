CC = cc
#CC = "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\gcc.exe" # (MinGW Windows)
CFLAGS = -O3 -Wall -Wextra -Wfloat-equal -Wvla -Wpedantic -std=c99
#CFLAGS = -O3 -Wall -Wextra -Wfloat-equal -Wvla -Wpedantic -std=c99 -mlong-double-64 # (MinGW Windows)

all: $(wildcard *.c)
	$(CC) $(CFLAGS) $(wildcard *.c) -o prova
clean:
	rm -f prova
