## Promethee Test Harness  
A bash script that runs promethee umbu-caja version and compares the output with the expected one.

## Usage

To run tests in your machine, you should use the following commands:

```
./setup
./run
```

Command 'setup' can also be used to generate a new random test.

## 
To personalise information about the test to be runned, you can use the '`environment.conf`' file:
```
test_name=random
test_size=1200 (dimensions of matrix to be generated for this test)

chunk_size=10000000 (number of elements a chunk can hold up)
function_type=linearWithIndifference (comparison function to be used in promethee)
is_max=1 (specify if it's desired to maximize or minimize results from alternatives) 
criterion_weight=1
p_parameter=1
q_parameter=0.5
```

Options for `function_type` are: linear and linearWithIndifference.