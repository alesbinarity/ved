# Makefile for BDS C 1.60 + ntvcm (Linux host)
# Safe cleanup: removes only this project's objects and output COM.

NTVCM   := ntvcm
CC      := CC.COM
LINK    := CLINK

PROG    := MAIN

# Project modules (no extensions)
MODS    := MAIN TERM UTIL KBD CPM

OBJEXT  := CRL
OBJ     := $(addsuffix .$(OBJEXT),$(MODS))
COM     := $(PROG).COM

all: $(COM)

$(COM): $(OBJ)
	$(NTVCM) $(LINK) $(MODS)

%.$(OBJEXT): %.C
	$(NTVCM) $(CC) $<

# Remove only our build artifacts (keeps CC.COM, CLINK, DEFF*.CRL, etc.)
clean:
	rm -f $(OBJ) $(COM) ntvcm.log

run: $(COM)
	$(NTVCM) $(COM)

run-d: $(COM)
	$(NTVCM) -d $(COM)

run-t: $(COM)
	$(NTVCM) -t -d $(COM)

.PHONY: all clean run run-d run-t

