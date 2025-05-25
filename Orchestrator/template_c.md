# Les fondamentaux d'un template de projet en C (niveau débutant à intermédiaire)

Voici les éléments essentiels à connaître pour structurer un projet en C, des bases aux concepts plus avancés :

## Structure de base d'un projet

```
mon_projet/
├── src/               # Code source
│   ├── main.c         # Point d'entrée
│   └── fonctions.c    # Implémentation des fonctions
├── include/           # Fichiers d'en-tête
│   └── fonctions.h    # Déclarations
├── Makefile           # Système de compilation
└── README.md          # Documentation
```

## 1. Fichiers sources (.c)

- **main.c** : Point d'entrée du programme
```c
#include <stdio.h>
#include "fonctions.h"  // Vos propres headers

int main() {
    printf("Bonjour le monde!\n");
    ma_fonction();
    return 0;
}
```

- **fonctions.c** : Implémentation des fonctions
```c
#include "fonctions.h"

void ma_fonction() {
    // Implémentation
}
```

## 2. Fichiers d'en-tête (.h)

**fonctions.h** :
```c
#ifndef FONCTIONS_H  // Garde d'inclusion
#define FONCTIONS_H

// Déclarations
void ma_fonction();

#endif
```

## 3. Compilation avec Makefile

Exemple basique :
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/fonctions.c
OBJ = $(SRC:.c=.o)
EXEC = mon_programme

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
```

## Concepts intermédiaires

### Gestion des erreurs
```c
FILE *f = fopen("fichier.txt", "r");
if (f == NULL) {
    perror("Erreur d'ouverture");
    exit(EXIT_FAILURE);
}
```

### Modularité
- Séparer les fonctionnalités en modules logiques
- Un header (.h) et un fichier source (.c) par module

### Tests unitaires
Créer un fichier de tests séparé :
```c
#include "fonctions.h"
#include <assert.h>

void test_ma_fonction() {
    // Tests...
}

int main() {
    test_ma_fonction();
    printf("Tous les tests passés!\n");
    return 0;
}
```

### Documentation
Utiliser Doxygen pour commenter :
```c
/**
 * @brief Brève description
 * @param x Premier paramètre
 * @return Valeur de retour
 */
int exemple(int x) {
    return x * 2;
}
```

## Bonnes pratiques

1. Toujours protéger les headers avec `#ifndef`
2. Éviter les variables globales
3. Utiliser des noms significatifs
4. Vérifier les erreurs système
5. Commenter le code de manière utile
6. Séparer interface (header) et implémentation

Ce template couvre l'essentiel pour démarrer un projet bien structuré en C et évoluer vers des concepts plus avancés.
