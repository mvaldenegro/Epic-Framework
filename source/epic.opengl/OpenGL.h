/*
 * OpenGL.h
 *
 *  Created on: 16-08-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_OPENGL_H_
#define EPIC_OPENGL_H_

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#define EPIC_OPENGL_CLEAR_ERROR_FLAG()  glGetError()
#define EPIC_OPENGL_CHECK_ERROR()

#endif /* EPIC_OPENGL_H_ */
