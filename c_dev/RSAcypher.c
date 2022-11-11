#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define ull unsigned long long int

ull miniFerma(ull);
ull *readE();
ull *readD();
void extEvklid(ull, ull, long long int *);
void createKeys();
void decrypt();
void encrypt();
void hackTime();
ull fastMODpow(ull, ull, ull);

struct Key
{
    ull crypt;
    ull mod;
};

ull gcd = 0;
struct Key openKey;
struct Key privateKey;

ull main()
{
    srand(time(NULL));
    createKeys();
    printf("_____________________________RSA CYPHER______________________________\n");
    printf("OPEN KEY ---- GRADE=%llu ; MOD = %llu ---- OPEN KEY\n", openKey.crypt, openKey.mod);

    ull ans;
    char space[] = "                             ";

    while (1)
    {
        printf("%s1. Decrypt\n", space);
        printf("%s2. Encrypt\n", space);
        printf("%.28s3. HACK TIME!\n", space);
        printf("%s 4. EXIT\n", space);

        scanf("%llu", &ans);
        getchar();
        switch (ans) {
        case 1:
            decrypt();
            break;
        case 2:
            encrypt();
            break;
        case 3:
            hackTime();
            return 0;
        case 4:
            return 0;
        }
    }
}

void createKeys()
{
    ull p1 = 2147483647;
    // while (1)
    // {
    //     p1 = rand();
    //     if (miniFerma(p1))
    //     {
    //         break;
    //     }
    // }
    ull p2 = 426389;
    // while (1)
    // {
    //     p2 = rand();
    //     if (miniFerma(p2))
    //     {
    //         break;
    //     }
    // }

    long long int mas[3];

    ull fi = (p1 - 1) * (p2 - 1);
    ull e = 3;
    openKey.mod = privateKey.mod = p1 * p2;
    for (;; e += 2)
    {
        if (miniFerma(e))
        {
            extEvklid(e, fi, mas);
            if (mas[0] == 1)
                break;
        }
    }
    openKey.crypt = e;

    ull d = (mas[1] + fi * (ull)ceil(abs(mas[1]) / (double)fi)) % fi;
    privateKey.crypt = d;
    printf("private - {%llu, %llu} | open - {%llu, %llu}\n", privateKey.crypt, privateKey.mod, openKey.crypt, openKey.mod);
    printf("p1, p2 - {%llu, %llu} | fi - %llu\n", p1, p2, fi);
}

void decrypt()
{

    printf("Enter code to decode: ");
    ull *ans = readD();

    ull decr = privateKey.crypt;
    // ull decr = 1;
    printf("\nDecoding result: \n");

    for (ull i = 0; ans[i] != '\0'; i++)
    {
        printf("%c", fastMODpow(ans[i], decr, privateKey.mod));
    }

    printf("\n");
}

void hackTime(){
    printf("Enter public key's args: ");
    scanf("%lld %lld", &openKey.crypt, &openKey.mod);

    printf("\nEnter code to decode: ");
    ull *ans = readD();
    int p1 = 3;
    int p2;
    for(; p1 <= (ull)sqrt(openKey.mod); p1 += 2){
        if(!(openKey.mod % p1)){
            p2 = openKey.mod / p1;
            break;
        }
    }

    ull fi = (p1 - 1) * (p2 - 1);

    printf("%llu(p1) %llu(p2) %llu(n) %llu(fi)\n", p1, p2, p1 * p2, fi);
    printf("%llu(p1) %llu(p2)", miniFerma(p1), miniFerma(p2));
    long long int mas[3];
    privateKey.mod = openKey.mod;
    extEvklid(openKey.crypt, fi, mas);

    ull d = (mas[1] + fi * (ull)ceil(abs(mas[1]) / (double)fi)) % fi;
    privateKey.crypt = d;

    ull decr = privateKey.crypt;
    // ull decr = 1;
    printf("\nDecoding result: \n");

    for (ull i = 0; ans[i] != '\0'; i++) {
        printf("%c", fastMODpow(ans[i], decr, privateKey.mod));
    }

    printf("\n");
}

void encrypt()
{
    printf("Enter code to encode: ");
    ull *ans = readE();

    ull decr = openKey.crypt;
    printf("\nEncoding result: \n");

    for (ull i = 0; ans[i] != '\0'; i++)
    {
        printf("%llu, ", fastMODpow(ans[i], decr, openKey.mod));
    }
    printf("\n");
}

ull *readE()
{
    ull n = 0;
    ull size = 10;
    ull *resp = (ull *)calloc(10, sizeof(ull));
    ull c;

    while ((c = getchar()) != '\n')
    {
        if (n + 1 == size)
        {
            ull *copy = (ull *)calloc(++size, sizeof(ull));

            for (ull i = 0; i < n; i++)
            {
                copy[i] = resp[i];
            }

            resp = copy;
        }

        resp[n++] = c;
    }
    resp[n] = '\0';

    return resp;
}

ull *readD()
{
    ull n = 0;
    ull size = 10;
    ull *resp = (ull *)calloc(10, sizeof(ull));
    ull c;
    do
    {
        scanf("%llu", &c);
        if (n + 1 == size)
        {
            ull *copy = (ull *)calloc((size += 5), sizeof(ull));
            for (ull i = 0; i < n; i++)
            {
                copy[i] = resp[i];
            }
            resp = copy;
        }

        resp[n++] = c;
    } while ((c = getchar()) != '\n');

    resp[n] = '\0';
    return resp;
}

void extEvklid(ull a, ull b, long long int *mas)
{

    if (b == 0)
    {
        mas[0] = a;
        mas[1] = 1;
        mas[2] = 0;
        return;
    }
    extEvklid(b, a % b, mas);
    long long int g = mas[0], i = mas[1], j = mas[2];
    mas[1] = j;
    mas[2] = i - a / b * j;
    return;
}

ull fastMODpow(ull n, ull exp, ull mod) {
    ull res = n, res1 = (ull)pow(n, exp & 1) % mod;
    while (exp)
    {
        res = ((res % mod) * (res % mod)) % mod;
        exp >>= 1;
        res1 = (res1 * ((ull)pow(res, exp & 1) % mod)) % mod;
    }
    return res1;
}

ull miniFerma(ull n){
    srand(time(0));
    if (n >= 2){
        if (n < 4)
            return 1;
        if (n % 2 == 0)
            return 0;
        for (int i = 0; i < 100; ++i){
            ull a = 2 + rand() % (n - 4);
            if (fastMODpow(a, n - 1, n) != 1)
                return 0;
        }
        return 1;
    } else
        return 0;
}