// sensor_c.c
// Biblioteca legada em C que calcula checksum/calibração de hardware
// Compile como biblioteca estática:
//   gcc -c sensor_c.c -o sensor_c.o && ar rcs libsensor_c.a sensor_c.o

#include <stdint.h>

int32_t calibrar_leitura_c(int32_t valor_bruto, int32_t offset) {
    return (valor_bruto * 2) + offset;
}

