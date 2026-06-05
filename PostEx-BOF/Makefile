CC64 = x86_64-w64-mingw32-gcc
CC86 = i686-w64-mingw32-gcc
STRIP64 = x86_64-w64-mingw32-strip --strip-unneeded
STRIP86 = i686-w64-mingw32-strip --strip-unneeded
CFLAGS = -I ../_include -I _include -w -Wno-incompatible-pointer-types -Os -DBOF -c

all: bof

bof: clean
	@(mkdir _bin 2>/dev/null) && echo 'creating _bin directory' || echo '_bin directory exists'
	@($(CC64) $(CFLAGS) find_flags/find_flags.c -o _bin/find_flags.x64.o && $(STRIP64) _bin/find_flags.x64.o) && echo '[+] find_flags x64' || echo '[!] find_flags x64'
	@($(CC86) $(CFLAGS) find_flags/find_flags.c -o _bin/find_flags.x32.o && $(STRIP86) _bin/find_flags.x32.o) && echo '[+] find_flags x32' || echo '[!] find_flags x32'

clean:
	@(rm -rf _bin)
