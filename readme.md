# IPCone
 IPCone is an interprocess communication with a named pipe.


## 1. Introduction

Server can do various operation in the server:
##### Available Operations
#
| Operation | Description |
| ------ | ------ |
| Send Data|Send Supported Data Types|
| Call Function |Call Functions with arguments and receive the result|
| Create Object |Create Object and receive an object descriptor|
| Call Method on object|call method using object descriptors and method name |
| Get Attribute of object |call method using object descriptors and method name|


## 2. Protocol

-The protocol is designed according to the requirements.
It is flexible and can handle any kind of serilizable data and can be fitted to the new classes/functions easily.



-The Communication initiation is always comes from the client and the response is always generated.
It should be noted that both synchronous/asynchronous approaches are possible (can be seen in example part)/

![GUI](https://raw.githubusercontent.com/glaba13/ImageResources/master/ipcone.png)

-The message structure is protected with the start and end synchronisation and checker bytes/

-The supported types can be defined in the operation.h enums and can be handled in the OperatorResolve class.
In addition, there is no specific serialisation, so with this general solution  it is defined individually for each class.





## 3. Test

There are 2 simple test class for the protocol: Cinema and Movie.

In the client several test examples (for each operation) are made with the objects of the class and general functions.

There is also an example for asynchronous run.

At the start of the program all possible (1 or 2 for each operation) examples are run.

## 4. Build
The solution is created with CLION, but it doesn't have any dependencies,
So it can be imported and built in any IDEA.


The CMakeList file is included, where 2 targets are defined for cliend and server.


