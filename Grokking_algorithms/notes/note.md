Un algorithme est un ensemble d'instructions permettant d'accomplir une tâche.

## Binary search (Recherche binaire)

Imaginez que vous cherchiez une personne dans l'annuaire (quelle phrase désuète !). Son nom commence par K. Vous pourriez commencer par le début et feuilleter les pages jusqu'à trouver des K.
Mais vous êtes plus susceptible de commencer par une page au milieu, car vous savez que les K se trouvent généralement vers le centre de l'annuaire.
Ou supposons que vous cherchiez un mot dans un dictionnaire, et qu’il commence par O. Là encore, vous commencerez vers le milieu.

Maintenant, imaginez que vous vous connectiez à Facebook. Lorsque vous le faites, Facebook doit vérifier que vous possédez bien un compte sur le site. Il doit donc
rechercher votre nom d'utilisateur dans sa base de données. Supposons que votre nom d'utilisateur soit karlmageddon. Facebook pourrait commencer par les A et rechercher votre
nom, mais il est plus logique de commencer quelque part au milieu.

Il s'agit d'un problème de recherche. Tous ces cas utilisent le même algorithme pour le résoudre : **la recherche binaire**.
La recherche binaire est un algorithme qui prend en entrée une liste triée d'éléments. Si l'élément recherché est présent dans cette liste, la recherche binaire renvoie sa position. Sinon, elle renvoie `null`.

Voici un exemple de fonctionnement de la recherche binaire. Je pense à un nombre compris entre 1 et 100.
Vous devez deviner mon nombre en un minimum d'essais.
À chaque tentative, je vous dirai si votre réponse est trop basse, trop haute ou correcte.
Supposons que vous commenciez ainsi : 1, 2, 3, 4… Voici comment cela se passerait.
Il s'agit d'une recherche simple (ou plutôt d'une recherche simpliste).
À chaque tentative, vous éliminez un seul nombre. Si mon nombre était 99, il vous faudrait 99 tentatives pour y arriver !

### Une meilleure façon de rechercher

Voici une meilleure technique. Commencez par 50.

Trop bas, mais vous venez d'éliminer la _moitié_ des nombres ! Vous savez maintenant que :

1 à 50 sont tous trop bas. Prochaine tentative : 75.

Trop élevé, mais vous réduisez encore de moitié le nombre restant !

_Avec la recherche binaire, vous devinez le nombre du milieu et éliminez la moitié des nombres restants à chaque fois_. Le suivant est 63 (à mi-chemin entre 50 et 75).

Quel que soit le nombre auquel je pense, vous pouvez le deviner en sept essais maximum, car vous éliminez de nombreux nombres à chaque essai !

Supposons que vous cherchiez un mot dans le dictionnaire. Le dictionnaire contient :

240 000 mots. Dans le pire des cas, combien d’étapes pensez-vous que chaque recherche nécessitera ?

Une recherche simple peut nécessiter 240 000 étapes si le mot recherché est le tout dernier du livre. À chaque étape de la recherche binaire, vous divisez
le nombre de mots par deux jusqu’à ce qu’il n’en reste qu’un seul.

<img width="737" height="105" alt="binary-steps" src="https://github.com/user-attachments/assets/dabef2b3-6550-499c-a7f5-02ed39273885" />

<img width="558" height="212" alt="binary-steps2" src="https://github.com/user-attachments/assets/09b1423b-3dbe-44b5-9ed9-41243e44d512" />

La recherche binaire nécessitera donc 18 étapes, soit une différence significative ! En général, pour toute liste de _n_ éléments, la recherche binaire nécessitera log₂ _n_ étapes dans le pire des cas,
tandis que la recherche simple nécessitera _n_ étapes.

**Logarithmes**

_Calculer log₁₀ 100 revient à se demander : « Combien de fois faut-il multiplier 10 pour obtenir 100 ?»_ La réponse est 2 : 10 × 10. Donc log₁₀ 100 = 2. _Les logarithmes sont l’inverse des exponentielles._

10² = 100 ⇔ log₁₀ 100 = 2
10³ = 1000 ⇔ log₁₀ 1000 = 3

2³ = 8 ⇔ log₂ 8 = 3
2⁴ = 16 ⇔ log₂ 16 = 4
2⁵ = 32 ⇔ log₂ 32 = 5

Pour une recherche binaire, il faudra examiner logₙ éléments dans le pire des cas. Pour une liste de 8 éléments,
log₈ = 3, car 2³ = 8. Il faudra donc en examiner 3 au maximum. Pour une liste de 1 024 éléments, log₁₀₂₄ = 10, car 2¹⁰ = 1 024. Il faudra donc en examiner 10 au maximum.

**Remarque :**
La recherche binaire ne fonctionne que si votre liste est triée.
Par exemple,les noms d’un annuaire téléphonique sont triés par ordre alphabétique ; vous pouvez donc
utiliser la recherche binaire pour trouver un nom. Que se passerait-il si les noms n’étaient pas triés ?

### Temps d’exécution

En général, il est préférable de choisir l’algorithme le plus efficace, que l’on cherche à optimiser le temps ou l’espace.
Revenons à la recherche binaire. Combien de temps gagne-t-on en l'utilisant ?
La première approche consistait à vérifier chaque nombre, un par un.
Pour une liste de 100 nombres, il faut jusqu'à 100 essais.
Pour une liste de 4 milliards de nombres, il faut jusqu'à 4 milliards d'essais.
Le nombre maximal d'essais est donc égal à la taille de la liste. On parle alors de _temps linéaire_.
