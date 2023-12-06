## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = userproject

userproject_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	UserMgmnt.c UserMgmnt.h \
	fiche.c fiche.h \
	dons.c dons.h \
	ETSS.c ETS.h

userproject_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

