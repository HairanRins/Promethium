import numpy as np

def monte_carlo_simulation(n_simulations: int) -> float:
    """
    Estime la valeur de π en utilisant la méthode de Monte-Carlo.
    """
    # Générer des points aléatoires en une seule opération pour optimiser la performance
    points = np.random.rand(n_simulations, 2)
    
    # Calculer le nombre de points à l'intérieur du cercle
    points_inside_circle = np.sum(np.sum(points**2, axis=1) <= 1)
    
    # Estimation de π
    return 4 * points_inside_circle / n_simulations

if __name__ == "__main__":
    n_simulations = 100_000  # Amélioration de la lisibilité avec un séparateur
    pi_estimate = monte_carlo_simulation(n_simulations)
    print(f"Estimation de π : {pi_estimate:.6f}")  # Estimation de π : 3.142880 
