#ifndef LG_I2C_REGS_H
#define LG_I2C_REGS_H

#include <stddef.h>
#include <stdint.h>

int lg_i2c_reg_read_value(void *value, char const *base, char const *member, size_t length);
int lg_i2c_reg_update_read(char *base, char *member, size_t length);
int lg_i2c_reg_update_read_all(char *base, size_t length);
int lg_i2c_reg_write_value(void *value, char const *base, char const *offset, size_t length);
int lg_i2c_reg_update_write(char *base, char const *offset, size_t length);
int lg_i2c_reg_update_write_all(char *base, size_t length);

#define LGI2C_update_member(st_name, member) \
lg_i2c_reg_update_read((char*)&st_name, (char *)&st_name.member, sizeof st_name.member)

#define LGI2C_update_all(st_name) \
lg_i2c_reg_update_read_all((char*)&st_name, sizeof st_name)

#define LGI2C_read_member_value(value, st_name, member) \
lg_i2c_reg_read_value((void*)&value, (char*)&st_name, (char *)&st_name.member, sizeof st_name.member)

#endif // LG_I2C_REGS_H
