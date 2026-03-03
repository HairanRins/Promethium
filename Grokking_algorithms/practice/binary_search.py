# low = 0
# high = len(list) - 1
# mid = (low + high) / 2 
# guess = list[mid] 

# Si l'estimation est trop basse, vous mettez à jour bas en conséquence :
# if guess < item:
#   low = mid + 1

# Et si l'estimation est trop élevée, vous mettez à jour haut. Voici le code complet : 
def binary_search(list, item):
    low = 0                      # index de début de la liste
    high = len(list) - 1         # index de fin de la liste

    while low <= high:           # tant que la zone de recherche est valide
        mid = (low + high) // 2  # index du milieu (⚠ normalement on met // 2)
        guess = list[mid]        # valeur située au milieu

        if guess == item:        # si on trouve l'élément
            return mid           # on retourne sa position

        if guess > item:         # si la valeur est trop grande
            high = mid - 1       # on cherche dans la moitié gauche
        else:                    # sinon la valeur est trop petite
            low = mid + 1        # on cherche dans la moitié droite

    return None                  # élément non trouvé

my_list = [1, 3, 5, 7, 9]

print(binary_search(my_list, 3))  # 1
print(binary_search(my_list, -1)) # None

# 1. On définit la zone de recherche : du début à la fin de la liste. 
# [1, 3, 5, 7, 9]
# low       high
# 2. Boucle de recherche 
# while low <= high:   On continue tant qu'il reste une zone à explorer. 
# 3. Trouver le milieu
# mid = (low + high) 
# On prend un élément au milieu. 
# [1, 3, 5, 7, 9]
#      mid
# 4. Comparaison 
# guess = list[mid] 
# On compare : 
# guess == item  → trouvé
# guess > item   → chercher à gauche
# guess < item   → chercher à droite
# 5. Réduction de la zone 
# Si trop grand : high = mid - 1 
# Si trop petit : low = mid + 1

# La recherche binaire : fonctionne sur une liste triée, coupe la liste en deux à chaque étape, est très rapide
# Processus : 
# 1. Regarder au milieu
# 2. Comparer
# 3. Garder une moitié
# 4. Répéter
# Complexité : O(log n)