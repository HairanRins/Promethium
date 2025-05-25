/* ========================================================
 * MACROS ET CONSTANTES - FONDAMENTAL EN ENVIRONNEMENT PRO
 * ======================================================== */

// Macros de configuration
#define VERSION "1.0.0"
#define MAX_BUFFER_SIZE 1024
#define MAX_FILENAME_LENGTH 256
#define MAX_USERS 100
#define DEBUG 1

// Macros utilitaires courantes en pro
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define UNUSED(x) ((void)(x))

// Macros de debug conditionnelles
#if DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        fprintf(stderr, "[DEBUG] %s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

// Codes de retour standardisés
typedef enum {
    SUCCESS = 0,
    ERROR_INVALID_ARGUMENT = -1,
    ERROR_MEMORY_ALLOCATION = -2,
    ERROR_FILE_NOT_FOUND = -3,
    ERROR_PERMISSION_DENIED = -4,
    ERROR_BUFFER_OVERFLOW = -5,
    ERROR_NULL_POINTER = -6
} error_code_t;



