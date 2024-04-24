//
//  Reservation.cpp
//  aturel_the5
//
//  Created by Aybars TÜREL on 25.05.2021.
//

#include "Reservation.h"
#include <string>
#include <vector>
#include "date.h"

Sailor::Sailor(int SailorID, string SailorName, int SailorAge, int SailorRank)
{
    id = SailorID;
    name = SailorName;
    age = SailorAge;
    rank = SailorRank;
}
Boat::Boat(int BoatID, string BoatName, string BoatColor)
{
    id = BoatID;
    name = BoatName;
    color = BoatColor;
}

Reservation::Reservation (Sailor, Boat, Date a)
{
    sailor = Sailor();
    boat = Boat();
    resDate = a;
}

vector<Reservation>Reservations::AddReservation(Reservation)
{
    reservations.push_back(Reservation());
    return reservations;
    
}

