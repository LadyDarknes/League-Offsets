#include <stdint.h>
#include <string.h>

struct MsvcString 
{
    union { char buf[16]; char* ptr; } u;
    uint64_t len, cap;
    MsvcString(const char* s) : len(strlen(s)), cap(15) {
        if (len > 15) { u.ptr = _strdup(s); cap = len; }
        else strcpy_s(u.buf, s);
    }
    ~MsvcString() { if (cap > 15) free(u.ptr); }
};

typedef void(__fastcall* PrintChat_t)(void* chat_client, MsvcString* msg, int color);

void PrintChat(uintptr_t base, const char* text, int color = 0xFFFFFF) 
{
    auto* client = *(void**)(base + 0x1EAE6A0);
    MsvcString msg(text);
    if (client) ((PrintChat_t)(base + 0x112C970))(client, &msg, color);
}
