#ifndef TYPES_H
#define TYPES_H

typedef struct KolorRGB {
    int R;
    int G;
    int B;
    KolorRGB(int R,int G,int B) {
        this->R = R;
        this->G = G;
        this->B = B;
    }
    KolorRGB() {
        R = 0;
        G = 0;
        B = 0;
    }
} KolorRGB;

#endif // TYPES_H
