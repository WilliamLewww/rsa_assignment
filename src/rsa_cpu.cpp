#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
  int remainder = a % b;

  if (remainder == 0) {
    return b;
  }
  else {
    return gcd(b, remainder);
  }
}

int inverseMod(int e, int n) { 
  e = e % n;

  for (int x = 1; x < n; x++) {
    if ((e * x) % n == 1) {
      return x; 
    }
  }
}

double generateE(double e, double phi) {
  if (e < phi && gcd(e, phi) != 1) {
      return generateE(e + 1, phi);
  }

  return e;
}

// public key: c = m^e mod n
double encrypt(double message, double e, double n) {
  return fmod(pow(message, e), n);
}

// private key: m = c^d mod n
double decrypt(double encryptedMessage, double d, double n) {
  return fmod(pow(encryptedMessage, d), n);
}

int main(int argn, char** argv) {
  double p = 3;
  double q = 7;
  double n = p * q;
  double phi = (p - 1) * (q - 1);

  double e = generateE(2, phi);
  double d = inverseMod(e, n);

  double message = 12;
  double y = encrypt(message, e, n);
  double x = decrypt(y, d, n);

  printf("\n");

  printf("%-20s c(m) = m^%lf mod %lf\n", "public key: ", e, n);
  printf("%-20s %lf = %lf^%lf mod %lf\n", "public key: ", y, message, e, n);

  printf("\n");

  printf("%-20s m(c) = c^%lf mod %lf\n", "private key: ", d, n);
  printf("%-20s %lf = %lf^%lf mod %lf\n", "private key: ", x, y, d, n);

  printf("\n");

  printf("%-20s %lf\n", "original message: ", message);
  printf("%-20s %lf\n", "encrypted message: ", y);
  printf("%-20s %lf\n", "decrypted message: ", x);

  printf("\n");

  return 0;
}