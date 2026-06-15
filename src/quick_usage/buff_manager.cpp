// BuffManager Direct Access (Bypassing Wrapper)

void* buff_mgr = *(void**)((char*)obj + 0x28F0);
if (buff_mgr) 
{
    void* list_start = *(void**)((char*)buff_mgr + 0x90);
    void* list_end = *(void**)((char*)buff_mgr + 0x98);
}
