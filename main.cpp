#include "head.h"

// Ë³Ðò±íµÄÉ¾³ý

int main() {
    SeqList pl;
    Init_SeqList(pl);
    for (int i = 0; i < 6; ++i) {
        Increase_Value(pl,i);
    }
    printf("%d\n",pl.length);
    Insert_SeqList(pl,4,0);
    Show_SeqList(pl);
    Delete_SeqList(pl,2);
    Show_SeqList(pl);
    printf("%d\n",getValueByIndex(pl,2));
    printf("%d\n",getIndexByValue(pl,4));
    return 0;
};
