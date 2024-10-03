

#include "unity.h"

#include "lg_i2c_regs.h"
#include "mock_i2c_stuff.h"

struct my_struct_t
{
    uint32_t my_uint32;
    uint8_t my_uint8;
    uint16_t my_uint16;
    float my_float;
} my_struct;


void setUp(void)
{
}

void tearDown(void)
{
}

void test_lg_i2c_regs(void)
{
    i2c_read_ExpectAndReturn(&my_struct.my_uint16, 42, offsetof(struct my_struct_t, my_uint16), sizeof my_struct.my_uint16, 0);

    if(LGI2C_update_member(my_struct, my_uint16))
    {
        printf("read failed");
    }
}

void test_lg_i2c_regs_all(void)
{
    i2c_read_ExpectAndReturn(&my_struct, 42, 0, sizeof my_struct, 0);

    if(LGI2C_update_all(my_struct))
    {
        printf("read failed");
    }
}

void test_lg_i2c_reg_read_value(void)
{
    uint32_t my_value;
    i2c_read_ExpectAndReturn(&my_value, 42, offsetof(struct my_struct_t, my_uint32), sizeof my_struct.my_uint32, 0);

    if(LGI2C_read_member_value(my_value, my_struct, my_uint32))
    {
        printf("read failed");
    }
}


