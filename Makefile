CC		= avr-gcc
CFLAGS	= -mmcu=atmega328p -I.
_OBJ	= helloWorld.o serialcom.o gsh.o
OBJ		= $(patsubst %,$(ODIR)/%,$(_OBJ))
DEPS	= serialcom.h gsh.h

ODIR	= obj

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

helloworld_bin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: flash

flash:
	avrdude -v -c xplainedmini -p m328p -U flash:w:helloworld_bin
