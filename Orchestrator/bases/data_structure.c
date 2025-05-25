/* =================================================
 * STRUCTURES DE DONNÉES - CONCEPTS INTERMÉDIAIRES
 * ================================================= */

// Structure utilisateur avec gestion mémoire

typedef struct {
    uint32_t id;
    char *name;              // Allocation dynamique
    char email[64];          // Taille fixe
    time_t creation_date;
    bool is_active;
} user_t;

// Structure pour liste chaînée (concept intermédiaire important)
typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    size_t size;
} linked_list_t;

// Structure de configuration (pattern courant en pro)
typedef struct {
    char config_file[MAX_FILENAME_LENGTH];
    int max_connections;
    bool verbose_mode;
    double timeout_seconds;
} app_config_t;

