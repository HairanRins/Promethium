/* =================================================
 * PROTOTYPES DE FONCTIONS - ORGANISATION MODULAIRE
 * ================================================= */

// Fonctions de gestion mémoire
void* safe_malloc(size_t size);
void* safe_realloc(void *ptr, size_t size);
char* safe_strdup(const char *str);

// Fonctions de gestion d'utilisateurs
user_t* user_create(uint32_t id, const char *name, const char *email);
void user_destroy(user_t *user);
error_code_t user_save_to_file(const user_t *user, const char *filename);
user_t* user_load_from_file(const char *filename);

// Fonctions de liste chaînée
linked_list_t* list_create(void);
void list_destroy(linked_list_t *list, void (*free_func)(void*));
error_code_t list_append(linked_list_t *list, void *data);
void* list_find(const linked_list_t *list, const void *key, 
                int (*compare_func)(const void*, const void*));

// Fonctions utilitaires
error_code_t read_file_content(const char *filename, char **content, size_t *size);
error_code_t write_file_content(const char *filename, const char *content);
bool validate_email(const char *email);
void print_error(error_code_t error);


/* ===========================================
 * IMPLÉMENTATION - GESTION MÉMOIRE SÉCURISÉE
 * =========================================== */

// Allocation mémoire avec vérification d'erreur (pratique pro essentielle)
void* safe_malloc(size_t size) {
    if (size == 0) {
        DEBUG_PRINT("Tentative d'allocation de 0 byte");
        return NULL;
    }
    
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "ERREUR: Échec allocation mémoire (%zu bytes)\n", size);
        exit(ERROR_MEMORY_ALLOCATION);
    }
    
    DEBUG_PRINT("Allocation réussie: %zu bytes à l'adresse %p", size, ptr);
    return ptr;
}

// Réallocation sécurisée
void* safe_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL && size > 0) {
        fprintf(stderr, "ERREUR: Échec réallocation mémoire (%zu bytes)\n", size);
        free(ptr);  // Libère l'ancien pointeur
        exit(ERROR_MEMORY_ALLOCATION);
    }
    return new_ptr;
}

// Duplication de chaîne sécurisée
char* safe_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str) + 1;
    char *copy = safe_malloc(len);
    strcpy(copy, str);
    return copy;
}
