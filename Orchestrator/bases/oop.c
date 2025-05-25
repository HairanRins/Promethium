/* ===========================================
 * GESTION D'UTILISATEURS - CONCEPTS POO EN C
 * =========================================== */

 // Constructeur d'utilisateur
user_t* user_create(uint32_t id, const char *name, const char *email) {
    // Validation des paramètres
    if (name == NULL || email == NULL) {
        DEBUG_PRINT("Paramètres invalides pour user_create");
        return NULL;
    }
    
    if (!validate_email(email)) {
        DEBUG_PRINT("Email invalide: %s", email);
        return NULL;
    }
    
    user_t *user = safe_malloc(sizeof(user_t));
    
    user->id = id;
    user->name = safe_strdup(name);
    strncpy(user->email, email, sizeof(user->email) - 1);
    user->email[sizeof(user->email) - 1] = '\0';  // Sécurité buffer overflow
    user->creation_date = time(NULL);
    user->is_active = true;
    
    DEBUG_PRINT("Utilisateur créé: ID=%u, Name=%s", id, name);
    return user;
}

// Destructeur d'utilisateur
void user_destroy(user_t *user) {
    if (user != NULL) {
        DEBUG_PRINT("Destruction utilisateur ID=%u", user->id);
        free(user->name);  // Libération mémoire dynamique
        free(user);
    }
}

// Sauvegarde utilisateur en fichier (gestion I/O)
error_code_t user_save_to_file(const user_t *user, const char *filename) {
    if (user == NULL || filename == NULL) {
        return ERROR_INVALID_ARGUMENT;
    }
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        DEBUG_PRINT("Impossible d'ouvrir le fichier: %s (%s)", filename, strerror(errno));
        return ERROR_FILE_NOT_FOUND;
    }
    
    // Format de sérialisation simple
    fprintf(file, "ID: %u\n", user->id);
    fprintf(file, "Name: %s\n", user->name);
    fprintf(file, "Email: %s\n", user->email);
    fprintf(file, "Created: %ld\n", (long)user->creation_date);
    fprintf(file, "Active: %s\n", user->is_active ? "true" : "false");
    
    fclose(file);
    DEBUG_PRINT("Utilisateur sauvegardé dans %s", filename);
    return SUCCESS;
}