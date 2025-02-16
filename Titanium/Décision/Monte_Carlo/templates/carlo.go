package main

import (
	"fmt"
	"math/rand"
	"time"
)

func monteCarloSimulation(nSimulations int) float64 {
	rng := rand.New(rand.NewSource(time.Now().UnixNano()))
	pointsInsideCircle := 0

	for i := 0; i < nSimulations; i++ {
		x, y := rng.Float64(), rng.Float64()
		if x*x+y*y <= 1 {
			pointsInsideCircle++
		}
	}

	return 4 * float64(pointsInsideCircle) / float64(nSimulations)
}

func main() {
	nSimulations := 100_000 // Go 1.13+ permet le séparateur '_'
	piEstimate := monteCarloSimulation(nSimulations)
	fmt.Printf("Estimation de π : %.6f\n", piEstimate)  // Estimation de π : 3.133920
} 
