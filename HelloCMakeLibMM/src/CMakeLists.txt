#
# Copyright (C) 2008 Frank Cervenka
#
# This is free software, licensed under the GNU General Public License v2.
#
PROJECT(hellocmakemm)

#SET(CMAKE_VERBOSE_MAKEFILE ON)

ADD_SUBDIRECTORY(shared-lib)
ADD_SUBDIRECTORY(static-lib)

INSTALL(FILES shared-lib/libhellocmakemm.so DESTINATION /usr/lib)
INSTALL(FILES static-lib/libhellocmakemm.a DESTINATION /usr/lib)

FILE(GLOB headerFiles "*.hpp")
FOREACH(headerFile ${headerFiles})
INSTALL(FILES ${headerFile} DESTINATION /usr/include/libhellocmakemm)
ENDFOREACH(headerFile)

ADD_CUSTOM_TARGET(uninstall
COMMAND "rm" -f "/usr/lib/libhellocmakemm.so"
COMMAND "rm" -f "/usr/lib/libhellocmakemm.a"
COMMAND "rm" -fR "/usr/include/libhellocmakemm"
)
