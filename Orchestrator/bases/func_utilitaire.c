/* =======================================================
 * FONCTIONS UTILITAIRES - GESTION FICHIERS ET VALIDATION
 * ======================================================= */ 

// Lecture complète d'un fichier
error_code_t read_file_content(const char *filename, char **content, size_t *size) {
    if (filename == NULL || content == NULL || size == NULL) {
        return ERROR_INVALID_ARGUMENT;
    }
    
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        DEBUG_PRINT("Impossible d'ouvrir %s: %s", filename, strerror(errno));
        return ERROR_FILE_NOT_FOUND;
    }
    
    // Obtenir la taille du fichier
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (file_size < 0) {
        fclose(file);
        return ERROR_FILE_NOT_FOUND;
    }
    
    // Allocation du buffer
    *content = safe_malloc((size_t)file_size + 1);
    
    // Lecture du contenu
    size_t bytes_read = fread(*content, 1, (size_t)file_size, file);
    (*content)[bytes_read] = '\0';  // Terminateur null
    
    *size = bytes_read;
    fclose(file);
    
    DEBUG_PRINT("Fichier lu: %s (%zu bytes)", filename, bytes_read);
    return SUCCESS;
}

// Validation d'email simplifiée
bool validate_email(const char *email) {
    if (email == NULL) return false;
    
    // Vérifications basiques
    const char *at_sign = strchr(email, '@');
    if (at_sign == NULL) return false;
    
    const char *dot = strrchr(at_sign, '.');
    if (dot == NULL || dot <= at_sign + 1) return false;
    
    // Vérifier qu'il y a des caractères après le point
    if (strlen(dot) < 2) return false;
    
    return true;
}

// Fonction d'affichage d'erreur
void print_error(error_code_t error) {
    const char *error_messages[] = {
        [SUCCESS] = "Succès",
        [-ERROR_INVALID_ARGUMENT] = "Argument invalide",
        [-ERROR_MEMORY_ALLOCATION] = "Erreur d'allocation mémoire",
        [-ERROR_FILE_NOT_FOUND] = "Fichier non trouvé",
        [-ERROR_PERMISSION_DENIED] = "Permission refusée",
        [-ERROR_BUFFER_OVERFLOW] = "Débordement de buffer",
        [-ERROR_NULL_POINTER] = "Pointeur null"
    };
    
    if (error <= 0 && -error < (int)ARRAY_SIZE(error_messages)) {
        fprintf(stderr, "ERREUR [%d]: %s\n", error, error_messages[-error]);
    } else {
        fprintf(stderr, "ERREUR [%d]: Code d'erreur inconnu\n", error);
    }
}
