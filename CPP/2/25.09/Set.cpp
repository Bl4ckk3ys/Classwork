#include "Set.h"

Set::Set(size_t mp){
    _maxPower = mp;
    _bitField = BitField(_maxPower);
};

Set::Set(const Set& set){
    _maxPower = set._maxPower;
    _bitField = set._bitField;
};

Set::Set(const BitField& bf){
    _maxPower = bf.GetSize();
    _bitField = BitField(bf);
};



std::vector<uint64_t> Set::GetPrimary(){

}