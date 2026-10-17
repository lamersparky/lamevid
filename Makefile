CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra -Wpedantic -std=c11
PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
.PHONY: all clean test install uninstall
all: lamevid
lamevid: src/lamevid.c
	$(CC) $(CFLAGS) -o $@ $<
test: lamevid
	./tests/test.sh
install: lamevid
	install -d "$(DESTDIR)$(BINDIR)"
	install -m 0755 lamevid "$(DESTDIR)$(BINDIR)/lamevid"
uninstall:
	rm -f "$(DESTDIR)$(BINDIR)/lamevid"
clean:
	rm -f lamevid
