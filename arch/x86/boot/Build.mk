##
# Copyright (C) 2009 Renê de Souza Pinto
# TempOS - Tempos is an Educational and multi purposing Operating System
#
# Makefile
#

CDIR := arch/x86/boot
OBJS := karch.o  video.o


OBJFILES += $(CDIR)/boot.o
OBJA := $(CDIR)/boot.o


#--- DO NOT CHANGE HERE ---#

OBJDIRS += $(CDIR)

OBJS := $(patsubst %.o,$(CDIR)/%.o,$(OBJS))
SRC  := $(OBJS:.o=.c)
DEPS := $(OBJS:.o=.d)

OBJFILES += $(OBJS)

all: $(OBJS) $(OBJA)

$(CDIR)/%.o: $(CDIR)/%.c
	@echo + CC $<
	@$(CC) $(CFLAGS) -c $< -o $@

%.d: %.c 
	@$(CC) -MM $(CFLAGS) $< \
		| sed 's#\(.*\)\.o[ :]*#\1.o $@ : #g' > $@; \
		[ -s $@ ] || rm -f $@

include $(DEPS)

#--------------------------#


$(CDIR)/boot.o: $(CDIR)/boot.S $(CDIR)/../../include/x86/multiboot.h $(CDIR)/../../include/x86/karch.h
	@echo + AS $<
	@$(CC) $(CFLAGS) -DASM -c $< -o $@

