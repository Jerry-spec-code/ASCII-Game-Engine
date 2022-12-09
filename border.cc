#include "border.h"

Border::Border() {
    for (int i = 0; i < borderLength; i++) {
        for (int j = 0; j < borderWidth; j++) {
            if (i == 0 || i == borderLength - 1) {
                shared_ptr<Bitmap> g = make_shared<Bitmap>(i, j, '-');
                borderInfo.push_back(g);
            }
            else if (j == 0 || j == borderWidth - 1) {
                shared_ptr<Bitmap> g = make_shared<Bitmap>(i, j, '|');
                borderInfo.push_back(g);
            }
        }
    }
}
Border::~Border() {}

vector<shared_ptr<Bitmap> > getBorderInfo() {
    
}
