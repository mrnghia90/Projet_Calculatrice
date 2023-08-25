#include "repere.h"

void CRepere::traceOx(QPainter * p)
{
    QLineF  Ox(x, y, largeur, hauteur);
    p->drawLine(Ox);
}
