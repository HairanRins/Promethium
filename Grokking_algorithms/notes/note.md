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
