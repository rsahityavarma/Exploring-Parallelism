CC = gcc
MPICC = mpicc
CFLAGS = -fopenmp -pthread -lm -Iinclude -g
MPICFLAGS = -lmpi -g
SRCS = src/main.c src/serial_model.c src/pthread_model.c src/openmp_model.c src/mpi_model.c src/data_loader.c
OBJS = $(SRCS:.c=.o)
TARGET = parallel_comparison

all: $(TARGET)

src/mpi_model.o: src/mpi_model.c
	$(MPICC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(MPICC) -o $@ $^ $(CFLAGS) $(MPICFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

