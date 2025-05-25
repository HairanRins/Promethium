/* =================================================
 * FONCTION PRINCIPALE - DÉMONSTRATION DES CONCEPTS
 * ================================================= */

int main(int argc, char *argv[]) {
    printf("=== TEMPLATE C PROFESSIONNEL v%s ===\n\n", VERSION);
    
    // 1. GESTION D'ARGUMENTS LIGNE DE COMMANDE
    if (argc > 1) {
        printf("Arguments reçus:\n");
        for (int i = 1; i < argc; i++) {
            printf("  argv[%d] = %s\n", i, argv[i]);
        }
        printf("\n");
    }
    
    // 2. DÉMONSTRATION GESTION UTILISATEURS
    printf("1. Création et gestion d'utilisateurs:\n");
    user_t *user1 = user_create(1, "Alice Dupont", "alice.dupont@example.com");
    user_t *user2 = user_create(2, "Bob Martin", "bob.martin@example.com");
    
    if (user1 && user2) {
        printf("   ✓ Utilisateurs créés avec succès\n");
        
        // Sauvegarde en fichier
        if (user_save_to_file(user1, "user1.txt") == SUCCESS) {
            printf("   ✓ Utilisateur sauvegardé en fichier\n");
        }
    }
    
    // 3. DÉMONSTRATION LISTE CHAÎNÉE
    printf("\n2. Gestion de liste chaînée:\n");
    linked_list_t *user_list = list_create();
    
    if (list_append(user_list, user1) == SUCCESS &&
        list_append(user_list, user2) == SUCCESS) {
        printf("   ✓ %zu utilisateurs ajoutés à la liste\n", user_list->size);
    }
    
    // 4. DÉMONSTRATION GESTION FICHIERS
    printf("\n3. Gestion de fichiers:\n");
    char *file_content;
    size_t content_size;
    
    // Créer un fichier de test
    const char *test_content = "Contenu de test pour démonstration\nLigne 2\nLigne 3";
    write_file_content("test.txt", test_content);
    
    if (read_file_content("test.txt", &file_content, &content_size) == SUCCESS) {
        printf("   ✓ Fichier lu (%zu bytes): %.50s...\n", content_size, file_content);
        free(file_content);
    }
    
    // 5. DÉMONSTRATION VALIDATION
    printf("\n4. Validation de données:\n");
    const char *emails[] = {
        "test@example.com",
        "invalid-email",
        "user@domain.co.uk",
        "@invalid.com"
    };
    
    for (size_t i = 0; i < ARRAY_SIZE(emails); i++) {
        printf("   %s: %s\n", emails[i], 
               validate_email(emails[i]) ? "✓ Valide" : "✗ Invalide");
    }
    
    // 6. DÉMONSTRATION GESTION D'ERREURS
    printf("\n5. Codes d'erreur:\n");
    error_code_t errors[] = {SUCCESS, ERROR_INVALID_ARGUMENT, ERROR_MEMORY_ALLOCATION};
    for (size_t i = 0; i < ARRAY_SIZE(errors); i++) {
        printf("   Code %d: ", errors[i]);
        print_error(errors[i]);
    }
    
    // 7. NETTOYAGE MÉMOIRE (CRUCIAL EN C PROFESSIONNEL)
    printf("\n6. Nettoyage mémoire...\n");
    
    // Destruction de la liste (libère automatiquement user1 et user2)
    list_destroy(user_list, (void(*)(void*))user_destroy);
    
    printf("   ✓ Mémoire libérée avec succès\n");
    printf("\n=== Programme terminé avec succès ===\n");
    
    return SUCCESS;
}

// Implémentation de write_file_content
error_code_t write_file_content(const char *filename, const char *content) {
    if (filename == NULL || content == NULL) {
        return ERROR_INVALID_ARGUMENT;
    }
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return ERROR_FILE_NOT_FOUND;
    }
    
    fprintf(file, "%s", content);
    fclose(file);
    
    return SUCCESS;
}
