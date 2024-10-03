#ifndef I2C_STUFF_H
#define I2C_STUFF_H

#include <stdint.h>
#include <stddef.h>


int i2c_write(void *buf, uint8_t dev_address, uint32_t reg_address, size_t length);
int i2c_read(void *buf, uint8_t dev_address, uint32_t reg_address, size_t length);

#endif // I2C_STUFF_H
