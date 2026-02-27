#ifndef UTILS_H
#define UTILS_H

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_VECTOR(vec)        \
    for (auto& p : (vec)) {            \
        delete p;                      \
        p = nullptr;                   \
    }                                  \
    (vec).clear(); 

#endif