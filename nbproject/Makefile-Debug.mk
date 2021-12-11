#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/classes/Face.o \
	${OBJECTDIR}/src/classes/Game.o \
	${OBJECTDIR}/src/classes/Shader.o \
	${OBJECTDIR}/src/classes/Vector.o \
	${OBJECTDIR}/src/classes/camera.o \
	${OBJECTDIR}/src/classes/main.o \
	${OBJECTDIR}/src/classes/mat4.o \
	${OBJECTDIR}/src/classes/object3d.o \
	${OBJECTDIR}/src/classes/player.o \
	${OBJECTDIR}/src/classes/szene.o \
	${OBJECTDIR}/src/classes/texture.o \
	${OBJECTDIR}/src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes/Light.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lGL -lglut -lGLU -lGLEW
CXXFLAGS=-lGL -lglut -lGLU -lGLEW

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lglut -lGLU -lGL

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/glutgameengine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/glutgameengine: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/glutgameengine ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/classes/Face.o: src/classes/Face.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/Face.o src/classes/Face.cpp

${OBJECTDIR}/src/classes/Game.o: src/classes/Game.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/Game.o src/classes/Game.cpp

${OBJECTDIR}/src/classes/Shader.o: src/classes/Shader.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/Shader.o src/classes/Shader.cpp

${OBJECTDIR}/src/classes/Vector.o: src/classes/Vector.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/Vector.o src/classes/Vector.cpp

${OBJECTDIR}/src/classes/camera.o: src/classes/camera.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/camera.o src/classes/camera.cpp

${OBJECTDIR}/src/classes/main.o: src/classes/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/main.o src/classes/main.cpp

${OBJECTDIR}/src/classes/mat4.o: src/classes/mat4.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/mat4.o src/classes/mat4.cpp

${OBJECTDIR}/src/classes/object3d.o: src/classes/object3d.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/object3d.o src/classes/object3d.cpp

${OBJECTDIR}/src/classes/player.o: src/classes/player.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/player.o src/classes/player.cpp

${OBJECTDIR}/src/classes/szene.o: src/classes/szene.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/szene.o src/classes/szene.cpp

${OBJECTDIR}/src/classes/texture.o: src/classes/texture.cpp
	${MKDIR} -p ${OBJECTDIR}/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/classes/texture.o src/classes/texture.cpp

${OBJECTDIR}/src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes/Light.o: src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes/Light.cpp
	${MKDIR} -p ${OBJECTDIR}/src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc/classes -include src/headers/Game.h -include src/headers/camera.h -include src/headers/Face.h -include src/headers/mat4.h -include src/headers/object3d.h -include src/headers/player.h -include src/headers/szene.h -include src/headers/texture.h -include src/headers/Vector.h -include /usr/include/GL/freeglut.h -include /usr/include/GL/gl.h -include /usr/include/GL/glew.h -include /usr/include/GL/glext.h -include /usr/include/GL/glu.h -include /usr/include/GL/glut.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes/Light.o src/headers/home/marvin/NetbeansProjects/NonEuclidian/src/classes/Light.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
