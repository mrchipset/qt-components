#ifndef FOOAPI_GLOBAL_H
#define FOOAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FOOAPI_LIBRARY)
#  define FOOAPI_EXPORT Q_DECL_EXPORT
#else
#  define FOOAPI_EXPORT Q_DECL_IMPORT
#endif

#endif // FOOAPI_GLOBAL_H
