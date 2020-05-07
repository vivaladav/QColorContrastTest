#pragma once

#include <QtCore/qglobal.h>

#if defined(QCOLORCONTRASTTEST_LIBRARY)
#  define QCOLORCONTRASTTEST_EXPORT Q_DECL_EXPORT
#else
#  define QCOLORCONTRASTTEST_EXPORT Q_DECL_IMPORT
#endif
