#include "q1.h"
#include <stdexcept>
#include <algorithm>

// Constructor (paso por valor y no por referencia)
/* ElectoralDistrict::ElectoralDistrict(std::string name, int voters)*/
ElectoralDistrict::ElectoralDistrict(const std::string& name, int voters) 
    : districtName(name), 
      totalVoters(voters), 
      MINIMUM_PARTICIPATION_THRESHOLD(0.5) {
    if (totalVoters <= 0) {
        throw std::invalid_argument("El número de votantes debe ser positivo");
    }
}

// Método para agregar votos de un candidato
void ElectoralDistrict::addCandidateVotes(int votes) {
    if (votes < 0) {
        throw std::invalid_argument("Los votos no pueden ser negativos");
    }
    votesPerCandidate.push_back(votes);// Trabaja igual para listas y vectores
}

// Método para calcular el porcentaje de participación
double ElectoralDistrict::calculateParticipationRate() const {
    int totalCastedVotes = 0;
    /*Trabaja igual para listas y vectores*/
    for (int votes : votesPerCandidate) {
        totalCastedVotes += votes;
    }
    return static_cast<double>(totalCastedVotes) / totalVoters;
}

// Método para determinar si el distrito cumple con el umbral mínimo de participación
bool ElectoralDistrict::meetsParticipationThreshold() const {
    return calculateParticipationRate() >= MINIMUM_PARTICIPATION_THRESHOLD;
}

// Método para encontrar al candidato con más votos
int ElectoralDistrict::findWinningCandidateIndex() const {
    if (votesPerCandidate.empty()) {
        throw std::runtime_error("No hay votos registrados");
    }

    /*return std::max_element(votesPerCandidate.begin(), votesPerCandidate.end()) - votesPerCandidate.begin();*/ // Línea se defino un vector
    /* Para listas se tendría que definir esto*/
    
    auto maxIt = std::max_element(votesPerCandidate.begin(), votesPerCandidate.end());
    if (maxIt == votesPerCandidate.end()) {
        throw std::runtime_error("No hay votos registrados");
    }

    int index = 0;
    for (auto it = votesPerCandidate.begin(); it != maxIt; ++it) {
        ++index;
    }
    return index;

}

// Getter para el nombre del distrito
std::string ElectoralDistrict::getDistrictName() const {
    return districtName;
}