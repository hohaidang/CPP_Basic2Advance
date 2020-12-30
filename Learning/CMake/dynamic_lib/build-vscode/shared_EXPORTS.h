
#ifndef SHARED_EXPORT_H
#define SHARED_EXPORT_H

#ifdef SHARED_EXPORTS_BUILT_AS_STATIC
#  define SHARED_EXPORT
#  define SHARED_NO_EXPORT
#else
#  ifndef SHARED_EXPORT
#    ifdef shared_EXPORTS
        /* We are building this library */
#      define SHARED_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define SHARED_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef SHARED_NO_EXPORT
#    define SHARED_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef SHARED_DEPRECATED
#  define SHARED_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef SHARED_DEPRECATED_EXPORT
#  define SHARED_DEPRECATED_EXPORT SHARED_EXPORT SHARED_DEPRECATED
#endif

#ifndef SHARED_DEPRECATED_NO_EXPORT
#  define SHARED_DEPRECATED_NO_EXPORT SHARED_NO_EXPORT SHARED_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef SHARED_NO_DEPRECATED
#    define SHARED_NO_DEPRECATED
#  endif
#endif

#endif /* SHARED_EXPORT_H */
