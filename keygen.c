#include <sodium.h>
#include <stdio.h>

int main() {
    if (sodium_init() < 0) {
        return 1;
    }
    
    unsigned char pk[crypto_sign_PUBLICKEYBYTES];
    unsigned char sk[crypto_sign_SECRETKEYBYTES];
   
    //generate key pair
    crypto_sign_keypair(pk, sk);
    
    //store in files
    FILE *f = fopen("public.key", "wb");
    fwrite(pk, 1, sizeof(pk), f);
    fclose(f);

    f = fopen("private.key", "wb");
    fwrite(sk, 1, sizeof(sk), f);
    fclose(f);
    
    //terminal message
    printf("Ed25519 keys generated\n");
    return 0;
}
