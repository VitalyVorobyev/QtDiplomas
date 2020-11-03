#ifndef CMLIB_GLOBAL_H
#define CMLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CMLIB_LIBRARY)
#  define CMLIB_EXPORT Q_DECL_EXPORT
#else
#  define CMLIB_EXPORT Q_DECL_IMPORT
#endif

#if defined(CMLIBSHAPED_LIBRARY)
#  define CMLIBSHAPED_LIBRARY Q_DECL_EXPORT
#else
#  define CMLIBSHAPED_LIBRARY Q_DECL_IMPORT
#endif

#endif // CMLIB_GLOBAL_H
