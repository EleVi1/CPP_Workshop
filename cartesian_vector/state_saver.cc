#include <iostream>
#include <ios>
#include <iomanip>

#include "state_saver.hh"

StateSaver::StateSaver(std::ostream &os)
    : saved_stream_(os) {
    this->saved_flags_ = os.flags();
    this->saved_precision_ = os.precision();
}

StateSaver::~StateSaver() {
    saved_stream_.flags(saved_flags_);
    saved_stream_.precision(saved_precision_);
}
