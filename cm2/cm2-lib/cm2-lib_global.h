#ifndef CM2LIB_GLOBAL_H
#define CM2LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CM2LIB_LIBRARY)
#  define CM2LIB_EXPORT Q_DECL_EXPORT
#else
#  define CM2LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // CM2LIB_GLOBAL_H
