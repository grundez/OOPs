#pragma once
#include "Exhibit.h"
#include "Guide.h"

class ExhibitAdapter {
private:
    Exhibit& exhibit;
    Guide& guide;

public:
    ExhibitAdapter(Exhibit& exhibitRef, Guide& _guide);
    void getInfo() const;
};
