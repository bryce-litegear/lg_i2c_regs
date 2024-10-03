# C module to support i2c host (slave) register management

Setup on the controller and host systems consist of defining a structure
that is an overlay of the i2c "register space" that is being modeled.  
The controller api interface will use the structure names to read or write to
the host. Api calls are also available to read or write the entire space or
some sub portion like embedded arrays.  
The programming api uses macros to construct addresses and message lengths
based on dereferenced structure pointers.


