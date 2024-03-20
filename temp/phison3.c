struct ListStruct
{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;

void function(unsigned int Data_A, unsigned int Data_B)
{
    unsigned int FoundEntry = ListHead;
    unsigned int PreEntry = NULL;
    unsigned char search_flag = 0;
    while (FoundEntry != NULL)
    {
        if (ListArray[FoundEntry].DataH == Data_A && ListArray[FoundEntry].DataL == Data_B)
        {
            // case 1 : PreEntry is null
            if (PreEntry == NULL)
            {
                printf("FoundEntry = %d, PreEntry = NULL", FoundEntry);
                search_flag = 1;
            }
            else
            { // case 2 : ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL > ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL
                unsigned int Next = ListArray[FoundEntry].NextPtr;
                if (ListArray[Next].DataH << 16 + ListArray->DataL > Data_A << 16 + Data_B)
                {
                    printf("FoundEntry = %d, PreEntry = %d", FoundEntry, PreEntry);
                    search_flag = 1;
                }
            }
        }
    }
    // if no search
    if (search_flag == 1)
    {
        printf("no found!");
    }
}