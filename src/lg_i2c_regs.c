#include "lg_i2c_regs.h"
#include "i2c_stuff.h"

uint8_t dev_address = 42;

// get data from i2c and write it into the structure
int lg_i2c_reg_update_read(char *base, char *member, size_t length)
{
    uint32_t offset = member - base;
    int test = i2c_read(member,dev_address, offset, length);
    return test;
}

int lg_i2c_reg_update_read_all(char *base, size_t length)
{
    int test = i2c_read(base, dev_address, 0, length);
    return test;    
}

int lg_i2c_reg_read_value(void *value, char const *base, char const *member, size_t length)
{
    uint32_t offset = member - base;
    int test = i2c_read(value, dev_address, offset, length);
    return test;
}

int lg_i2c_reg_write_value(void *value, char const *base, char const *offset, size_t length);
int lg_i2c_reg_update_write(char *base, char const *offset, size_t length);
int lg_i2c_reg_update_write_all(char *base, size_t length);