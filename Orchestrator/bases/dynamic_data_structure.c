/* ===============================================
 * LISTE CHAÎNÉE - STRUCTURE DE DONNÉES DYNAMIQUE
 * =============================================== */

// Création d'une liste chaînée
linked_list_t* list_create(void) {
    linked_list_t *list = safe_malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Destruction complète de la liste
void list_destroy(linked_list_t *list, void (*free_func)(void*)) {
    if (list == NULL) return;
    
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        if (free_func && current->data) {
            free_func(current->data);
        }
        free(current);
        current = next;
    }
    
    free(list);
    DEBUG_PRINT("Liste chaînée détruite");
}

// Ajout d'élément à la liste
error_code_t list_append(linked_list_t *list, void *data) {
    if (list == NULL || data == NULL) {
        return ERROR_INVALID_ARGUMENT;
    }
    
    node_t *new_node = safe_malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        // Parcours jusqu'au dernier élément
        node_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    list->size++;
    DEBUG_PRINT("Élément ajouté à la liste (taille: %zu)", list->size);
    return SUCCESS;
}
