#include "ExhibitAdapter.h"

ExhibitAdapter::ExhibitAdapter(Exhibit& exhibitRef, Guide& _guide) : exhibit(exhibitRef), guide(_guide) {
}

void ExhibitAdapter::getInfo() const {
    //рср лнцкю аш ашрэ ахакхнрейю дкъ йнмбепрюжхх х бняпопнхгбедемхъ юсдхн 
    std::vector<std::string> content;
    content.push_back("\tюСДХН БНЯОПНХГБЕДЕМХЕ:\n");
    content.push_back(exhibit.getInfo());
    guide.setContentToSpeech(content);
}
