#include <iostream>
#include <string.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

int main()
{
    long long i = 208;
    unsigned char a[4];
    string s= to_string(i);
    //snprintf(a,5, "%d", i);
    long long j=htonl(i);
    memcpy(a, &j, sizeof(a)); //store as integer only nto ascii
    
    printf("%u%u%u%u\n", a[0],a[1],a[2],a[3]);
    cout<<"i, j" <<i<<", "<<j<<endl;
    for(int i=0;i<4;++i)
    {
        printf(" %p , %.2x\n", &a[i], a[i]);
        cout<<(int)a[i]<<endl;
    }
    cout<<sizeof(a)<<endl;
    
    uint32_t num = 208;
    uint32_t res = 0;
res |= (num & 0xff) << 24;        ; //least significant to most significant
res |= (num & 0xff00) << 8;       ; //2nd least sig. to 2nd most sig.
res |= (num & 0xff0000) >> 8;     ; //2nd most sig. to 2nd least sig.
res |= (num & 0xff000000) >> 24;  ; //most sig. to least sig.
cout<<"res: "<<res<<endl ;

    return 0;
    
}
